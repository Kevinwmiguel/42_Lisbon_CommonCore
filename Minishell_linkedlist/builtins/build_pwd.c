/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_pwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:49:53 by thguimar          #+#    #+#             */
/*   Updated: 2025/05/24 20:24:27 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../libs/builtins.h"

#include <unistd.h>
#include <stdio.h>
#include <string.h>

void build_pwd(int argc, char **argv, t_shell *utils)
{
    char cwd[1024];
    int pipe_fds[2];

    (void)argv;
    getcwd(cwd, sizeof(cwd));

    if (argc == 1)
    {
        ft_putstr_fd(cwd, 1);
        ft_putchar_fd('\n', 1);
    }
    else
    {
        if (pipe(pipe_fds) == -1)
            return;

        // Escreve no lado de escrita
        write(pipe_fds[1], cwd, strlen(cwd));
        write(pipe_fds[1], "\n", 1);
        close(pipe_fds[1]);
        utils->pipe_bridge->pwd_storage = pipe_fds[0];
    }
}
