/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:18:22 by kwillian          #+#    #+#             */
/*   Updated: 2025/01/31 23:44:45 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_files(int *end, t_files file)
{
	if (end[0])
		close(end[0]);
	if (end[1])
		close(end[1]);
	if (end[2])
		close(end[2]);
	if (file.outfile)
		close(file.outfile);
	if (file.infile)
		close(file.infile);
}

void	close_inout(t_files *file)
{
	if (file->infile >= 0)
		close(file->infile);
	if (file->outfile >= 0)
		close(file->outfile);
}
