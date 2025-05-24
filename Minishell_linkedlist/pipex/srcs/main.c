/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 21:54:34 by kwillian          #+#    #+#             */
/*   Updated: 2025/05/23 21:58:47 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/builtins.h"

int	pipex_start(t_pipesort *piped, t_shell *utils) 
{
	while (utils->command[utils->j])
		utils->j++;
	path_comms(piped->content, utils, piped);
	utils->j = 0;
	return (0);
}
