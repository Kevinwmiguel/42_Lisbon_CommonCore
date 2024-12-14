/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:18:22 by kwillian          #+#    #+#             */
/*   Updated: 2024/12/14 14:49:38 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    close_files(int *end, files file)
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
