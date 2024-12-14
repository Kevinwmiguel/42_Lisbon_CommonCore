/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:19:11 by kwillian          #+#    #+#             */
/*   Updated: 2024/12/14 18:17:25 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_split(char *split, char *msg)
{
	int i;

	ft_printf("%s\n", msg);
	if (!split)
		exit(1);
	i = 0;
	free(split);
	exit(1);
}
