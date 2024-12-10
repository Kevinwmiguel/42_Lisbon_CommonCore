/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:43:27 by kwillian          #+#    #+#             */
/*   Updated: 2024/12/10 21:58:30 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    checker(int argc, char **envp)
{
    if (!envp)
    {
        ft_printf("Error\n No Path\n");
        exit(1);
    }
    if (argc != 5)
    {
        fprintf(stderr, "Usage: ./pipex infile <cmd1> <cmd2> outfile\n");
        exit(1);
    }
}

void    check_file(int file)
{
    if (file < 0)
    {
        perror("Error get the file: \n");
        close(file);
        exit(1);
    }    
}
