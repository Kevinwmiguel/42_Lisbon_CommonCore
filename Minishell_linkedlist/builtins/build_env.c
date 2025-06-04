/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:22:26 by thguimar          #+#    #+#             */
/*   Updated: 2025/06/03 00:23:27 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"

int	compare_exp_env(t_shell *utils, int i, int j)
{
	while (utils->envr[i])
	{
		if (ft_strcmp2(utils->exp[j], utils->envr[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	write_exp_to_env(t_shell *utils, int j, int i)
{
	while (j > -1)
	{
		while (utils->exp[j][i])
		{
			if (utils->exp[j][i] == '=' && compare_exp_env(utils, 0, j) == 1)
			{
				ft_putstr_fd(utils->exp[j], 1);
				ft_putstr_fd("\n", 1);
				break ;
			}
			i++;
		}
		j--;
		i = 0;
	}
}

void	build_env(int argc, char **argv, t_shell *utils)
{
	int	j;
	int	outfd;

	(void)argv;
	j = 0;
	if (argc == 1)
	{
		outfd = STDOUT_FILENO;
		if (utils->pipe_bridge && utils->pipe_bridge->outfd > STDERR_FILENO)
			outfd = utils->pipe_bridge->outfd;
		while (utils->envr && utils->envr[j])
		{
			ft_putstr_fd(utils->envr[j], outfd);
			ft_putstr_fd("\n", outfd);
			j++;
		}
		write_exp_to_env(utils, outfd, mlc_size(0, utils->exp) - 1);
	}
}
