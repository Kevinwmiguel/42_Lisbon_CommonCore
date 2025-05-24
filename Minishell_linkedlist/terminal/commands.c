/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:12:32 by thguimar          #+#    #+#             */
/*   Updated: 2025/05/24 20:31:35 by kwillian         ###   ########.fr       */
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


void	path_comms(char **argv, t_shell *utils, t_pipesort *piped)
{
	char	**right_path;
	int		j;
	int		flag;
	char	*test;
	char	*test2;

	j = -1;
	right_path = NULL;
	test = NULL;

	if (builtins(argv[0], utils, -1) != 0)
		exec_builtin(builtins(argv[0], utils, -1), piped->content,
		 utils->envr, utils); // PROBLEMAS AQUI - THIAGO -- precisa ser dentro para ver caso seja no segundo comando - se for dentro tem problemas com o EXIT, UNSET, EXPORT, ENV
	utils->process_id = fork();
	signal_search(CHILD);
	if (utils->process_id == 0)
	{
		signal_search(CHILD);
		flag = 0;
		if (ft_strncmp(argv[0], "./", 2) == 0)
			test2 = ft_substr(argv[0], 2, ft_strlen(argv[0]) - 2);
		else
		{
			right_path = ft_split(PATH, ':');
			while (right_path[++j])
			{
				test = ft_strjoin(right_path[j], "/");
				test2 = ft_strjoin(test, argv[0]);
				flag = 1;
			}
			pipex(ft_lstsize_pipesort(piped), piped, utils, test);
		}
		if (flag == 0)
			pipex(ft_lstsize_pipesort(piped), piped, utils, test2);
		free_dptr(right_path, 0);
		build_exit(argv, utils);
	}
	else
		waitpid(utils->process_id, NULL, 0);
	return ;
}
