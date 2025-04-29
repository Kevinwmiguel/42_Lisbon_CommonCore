/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 21:54:34 by kwillian          #+#    #+#             */
/*   Updated: 2025/04/27 19:00:16 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/builtins.h"

int	pipex_start(t_pipesort *piped, t_shell *utils) 
{
	int flag;

	flag = 0; // retirado um while
		while (utils->command[utils->j])
			utils->j++;
		flag = builtins(piped->content[0], utils, -1);
		if (flag == 0)
			path_comms(piped->content, utils, piped);
		utils->j = 0;
	return (0);
}
