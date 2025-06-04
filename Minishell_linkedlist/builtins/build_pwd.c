/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_pwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:49:53 by thguimar          #+#    #+#             */
/*   Updated: 2025/06/03 00:22:27 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../libs/builtins.h"

#include <unistd.h>
#include <stdio.h>
#include <string.h>

void	build_pwd(int argc, char **argv, t_shell *utils)
{
	char	cwd[1024];

	(void)argv;
	(void)argc;
	getcwd(cwd, sizeof(cwd));
	if (utils->j == 1 || (utils->index == utils->j))
	{
		ft_putstr_fd(cwd, 1);
		ft_putchar_fd('\n', 1);
	}
	else
	{
		ft_putstr_fd(cwd, 1);
		ft_putchar_fd('\n', 1);
	}
}
