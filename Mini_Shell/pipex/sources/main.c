/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:37:42 by thiago-camp       #+#    #+#             */
/*   Updated: 2025/01/16 22:46:17 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_p(t_pipe *p)
{
	int	n;
	int	i;

	n = 0;
	if (!p)
		return ;
	while (n <= p[0].n)
	{
		if (p[n].command)
		{
			i = 0;
			while (p[n].command && p[n].command[i])
			{
				if (p[n].command[i])
					free(p[n].command[i]);
				i++;
			}
			free(p[n].command);
		}
		if (p[n].path_p)
			free(p[n].path_p);
		n++;
	}
	free(p);
}

void	execute(char *argv, char **env, t_pipe *p, int i)
{
	if (ft_strncmp(argv, "/", 1) == 0)
	{
		if (access(argv, X_OK) == 0)
		{
			if (!env || !env[0])
				p[i].path_p = ft_strdup(argv);
			p[i].command = ft_calloc (2, sizeof(char *));
			p[i].command[0] = ft_strdup(ft_strrchr(argv, '/') + 1);
			p[i].command[1] = NULL;
		}
		else
		{
			ft_putstr_fd("command \"", 2);
			ft_putstr_fd(argv, 2);
			ft_putendl_fd("\" not found", 2);
		}
	}
	else
	{
		p[i].command = ft_split(argv, ' ');
		if (!p[i].command || !p[i].command[0])
			error_handler(p, i, 3);
		p[i].path_p = NULL;
	}
}

void	struct_initialize(t_pipe *p, int i, char **argv, int argc)
{
	int	n;

	if (any_here_doc(argv) == 1)
	{
		p[0].heredoc = true;
		p[0].limiter = ft_strdup2(argv[2]);
	}
	else
		p[0].heredoc = false;
	while (++i < p[0].n)
	{
		p[i].id = 0;
		p[i].command = NULL;
		p[i].path_p = NULL;
	}
	fd_detector(p, argv, argc, i);
	n = 1;
	while (n < p[0].n)
	{
		if (pipe(p[n].fd) == -1)
			final_cleaner2(p);
		n++;
	}
}

t_pipe	*cmd_creator(int argc, char **argv, char **env)
{
	t_pipe	*p;
	char	**paths;
	int		i;

	i = 0;
	p = malloc((argc - 2) * sizeof(t_pipe));
	if (!p)
		final_cleaner2(p);
	p[0].n = 2;
	struct_initialize(p, -1, argv, argc);
	while (++i <= p[0].n)
	{
		if (p[0].heredoc == true)
			execute(argv[i + 2], env, p, i);
		else
			execute(argv[i + 1], env, p, i);
	}
	paths = pick_path(env);
	search_path(p, paths);
	return (p);
}

int	main(int argc, char **argv, char **env)
{
	t_pipe	*p;

	if (any_here_doc(argv) == 1 && argc < 6)
	{
		ft_putstr_fd("not enough arguments\n", 2);
		return (0);
	}
	if (argc < 5)
	{
		ft_putstr_fd("not enough arguments\n", 2);
		return (0);
	}
	p = cmd_creator(argc, argv, env);
	if (!p)
		final_cleaner2(p);
	exec_fork(p, env);
	fd_shut(p, p[0].n);
	free_p(p);
	return (0);
}
