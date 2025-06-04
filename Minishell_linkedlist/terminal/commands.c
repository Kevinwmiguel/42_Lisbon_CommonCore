/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:12:32 by thguimar          #+#    #+#             */
/*   Updated: 2025/06/04 12:24:07 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"

int	builtin_not_command(char **argv)
{
	if (ft_strcmp2("echo", argv[0]) == 0)
		return (1);
	else if (ft_strcmp2("cd", argv[0]) == 0)
		return (1);
	else if (ft_strcmp2("pwd", argv[0]) == 0)
		return (1);
	else if (ft_strcmp2("export", argv[0]) == 0)
		return (1);
	else if (ft_strcmp2("unset", argv[0]) == 0)
		return (1);
	else if (ft_strcmp2("exit", argv[0]) == 0)
		return (1);
	else if (ft_strcmp2("env", argv[0]) == 0)
		return (1);
	return (0);
}

void	line_h_child(t_shell *utils, t_pipesort *piped, int flag, char **argv)
{
	if (flag == 0)
		pipex(ft_lstsize_pipesort(piped), piped, utils, argv[0]);
	else
		pipex(ft_lstsize_pipesort(piped), piped, utils, utils->resolved_path);
}

void	run_child_process(char **argv, t_shell *utils, t_pipesort *piped)
{
	int		j;
	int		flag;
	char	*temp;

	j = -1;
	flag = 0;
	utils->resolved_path = NULL;
	if (ft_strncmp(argv[0], "./", 2) == 0)
		utils->resolved_path = ft_substr(argv[0], 2, ft_strlen(argv[0]) - 2);
	else
	{
		utils->right_path = ft_split(PATH, ':');
		while (utils->right_path[++j])
		{
			temp = ft_strjoin(utils->right_path[j], "/");
			free(utils->resolved_path);
			utils->resolved_path = ft_strjoin(temp, argv[0]);
			free(temp);
			flag = 1;
		}
	}
	line_h_child(utils, piped, flag, argv);
	free_dptr(utils->right_path, 0);
	build_exit(argv, utils);
}

void	exec_external_command(char **argv, t_shell *utils, \
	t_pipesort *piped)
{
	utils->process_id = fork();
	if (utils->process_id == 0)
	{
		signal_search(CHILD);
		run_child_process(argv, utils, piped);
	}
	else
		waitpid(utils->process_id, NULL, 0);
}

void	handle_special_builtins(char **argv, t_shell *utils, t_pipesort *piped)
{
	int	ret;

	ret = builtins(argv[0], utils, -1);
	if (ret != 0)
	{
		if (ret == 2 || ret == 5)
			exec_builtin(ret, piped->content, utils->envr, utils);
		if (ret == 7)
		{
			exec_builtin(ret, utils->command, utils->envr, utils);
			exit(1);
		}
	}
}

void	path_comms(char **argv, t_shell *utils, t_pipesort *piped)
{
	if (ft_strncmp(argv[0], "export", 6) == 0 && \
	utils->pipe_bridge->redirection == false)
		exec_builtin(builtins(argv[0], utils, -1), \
		piped->content, utils->envr, utils);
	else if ((ft_strncmp(argv[0], "cd", 2) == 0)
		|| (ft_strncmp(argv[0], "unset", 5) == 0)
		|| ft_strncmp(argv[0], "exit", 4) == 0)
		handle_special_builtins(argv, utils, piped);
	else
		exec_external_command(argv, utils, piped);
}
