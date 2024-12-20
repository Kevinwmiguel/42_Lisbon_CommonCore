/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:19:11 by kwillian          #+#    #+#             */
/*   Updated: 2024/12/16 16:43:24 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_accessible(const char *path)
{
	if (access(path, F_OK) != 0)
	{
		perror("Arquivo/Diretório não encontrado");
		return (0);
	}
	if (access(path, R_OK) != 0)
	{
		perror("Sem permissão de leitura");
		return (0);
	}
	if (access(path, X_OK) != 0)
	{
		printf("leitura n da %s\n", path);
		ft_printf("Tudo bem passei por aqui\n");
		return (0);
	}
	return (1);
}

void	ft_free_split(char *split, char *msg)
{
	ft_printf("%s\n", msg);
	if (!split)
		exit(1);
	free(split);
	exit(1);
}
