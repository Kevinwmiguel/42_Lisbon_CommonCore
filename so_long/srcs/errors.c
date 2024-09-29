/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 21:12:52 by kwillian          #+#    #+#             */
/*   Updated: 2024/09/29 15:33:33 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fmessage_error(t_vars *vars, int assets)
{
	ft_printf("Error");
	final_cleaner(vars, assets);
	exit(1);
}

void	ferror(char *file)
{
	ft_printf("can't open the file %s", file);
	exit(1);
}
