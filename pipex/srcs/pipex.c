/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:37:03 by kwillian          #+#    #+#             */
/*   Updated: 2024/12/20 17:04:58 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_pipe(int *end, t_files file)
{
	if (pipe(end) == -1)
	{
		perror("Error in Pipe: \n");
		close_files(end, file);
		exit(1);
	}
}

void	check_start_child1(pid_t child1, int *end, char **argv, t_files file)
{
	if (child1 < 0)
	{
		close_files(end, file);
		ft_printf("Fork: child1 error\n");
		exit(1);
	}
	if (child1 == 0)
	{
		close(end[0]);
		end[0] = -1;
		file.cmd1 = ft_split(argv[2], ' ');
		if (!file.cmd1)
		{
			perror("ft_split: child 1");
			exit(1);
		}
		child_one(file, end[1], file.cmd1, argv[1]);
	}
}

void	check_start_child2(pid_t child2, int *end, char **argv, t_files file)
{
	if (child2 < 0)
	{
		close_files(end, file);
		ft_printf("Fork: child2 error\n");
		exit (1);
	}
	if (child2 == 0)
	{
		close(end[1]);
		end[1] = -1;
		file.cmd2 = ft_split(argv[3], ' ');
		if (!file.cmd2)
		{
			perror("ft_split: child 2");
			exit(1);
		}
		child_two(end[0], file, file.cmd2);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		end[2];
	pid_t	child1;
	pid_t	child2;
	t_files	file;

	file.envp = envp;
	checker(argc, envp);
	file.infile = open(argv[1], O_RDONLY);
	check_file(file.infile);
	file.outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	check_file(file.outfile);
	check_pipe(end, file);
	child1 = fork();
	check_start_child1(child1, end, argv, file);
	child2 = fork();
	check_start_child2(child2, end, argv, file);
	close_files(end, file);
	wait(&child1);
	wait(&child2);
	return (0);
}
