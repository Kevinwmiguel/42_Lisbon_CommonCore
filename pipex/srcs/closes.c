/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:18:22 by kwillian          #+#    #+#             */
/*   Updated: 2024/12/09 20:21:35 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void closes(int end1, int end2,int infile, int outfile)
{
    close(end1);
    close(end2);
    close(infile);
    close(outfile);
}