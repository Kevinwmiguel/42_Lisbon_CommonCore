/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:14:03 by kwillian          #+#    #+#             */
/*   Updated: 2025/01/24 21:46:38 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// int	**pipes_creator(int num_pipes)
// {
// 	int **fd;
// 	int	i;

// 	i = 0;
// 	fd = (int **)malloc(num_pipes * sizeof(int *));
// 	if (!fd)
// 	{
// 		perror("malloc failed");
// 		exit(1);
// 	}
// 	while (i++ < num_pipes)
// 	{
// 		fd[i] = (int *)malloc(2 * sizeof(int));
// 		if (!fd[i])
// 		{
// 			perror("malloc failed");
// 			exit(1);
// 		}
// 		if (pipe(fd[i]) == -1)
// 		{
// 			perror("pipe failed");
// 			exit(1);
// 		}
// 	}
// 	return (fd);
// }
// void	adding_nodes()
// {
// }

// void	pass_args(char **argv, t_multip file)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (argv[i] != '\0')
// 	{
// 		while (argv[i][j] != '\0')
// 			if (argv[i][j] == '-')
// 			{
// 				file.token = 'A';
// 			}
// 			else if (argv[i][j] == '|')
// 			{
// 				file.token = 'P';
// 			}
// 			else if ((argv[i][j] >= 'a' && argv[i][j] <= 'z')
// 				&& ((argv[i][j] >= 'A' && argv[i][j] <= 'Z')) && argv[i][j - 1] != '-')
// 				{
// 					file.token = 'C';
// 				}
// 			j++;
// 		i++;
// 	}
// }

// int	get_envp_size(char **envp)
// {
//     int	count = 0;
//     while (envp[count])
//         count++;
//     return (count);
// }

char	**init_nodes(char **env)
{
	char	**path;
	int		index;

	path = NULL;
	index = 0;
	while (env && env[index])
	{
		if (ft_strncmp(env[index], "PATH=", 5) == 0)
		{
			path = ft_split(env[index], ':');
			if (!path)
				cleaner_double(path);
			else
				path[0] = path[0] + 5;
			break ;
		}
		index++;
	}
	return (path);
}

void	file_init(t_multip *file, char **envp)
{
	file->argv = NULL;
	file->envp = NULL;
	file->limiter = NULL;
	file->path = NULL;
	file->envp = init_nodes(envp);

	int i = 0;
	while (envp[i])
	{
		printf("\n%s", envp[i]);
		i++;
	}
}

void	file_clean(t_multip *file)
{
	int	i;

	i = 0;
	while (file->argv[i])
	{
		free(file->argv[i]);
		i++;
	}
	free(file->argv);
	free(file->path);
	free(file->envp);
	free(file->limiter);
	exit(1);
}

void	multiple_pipes_flow(char **argv, char **envp)
{
	t_multip	*file;

	file = (t_multip *)malloc(sizeof(t_multip));
	if (!file)
		file_clean(file);
	file_init(file, envp);
	checker2(file);

	printf("teste %s\n", argv[0]);

	//pegar caminho
	// check_accessible();
	// //num_pipes = count_pipes(argv);
	// //checa se é comandos ou se não
	// //opção sem redirection
	// checker(file.envp);
	// pass_args(argv, file);
	//redirection(argc, argv, file, fd);
	exit(1);
}

//INPUT COMANDOS OUTPUT UTILS.EXP - envp a partir do export