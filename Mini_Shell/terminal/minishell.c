/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:42:24 by thguimar          #+#    #+#             */
/*   Updated: 2025/01/13 21:20:43 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"

//utils->input = readline("minishell"); 
//prompt escreve por cima por causa do prompt ser interativo

void	main2_helper(t_pipe_comms *pcomms, t_shell *utils)
{
	int	flag;

	flag = builtins(pcomms->args[0], utils, -1);
	if (flag == 0)
		path_comms(utils->command, utils, -1, -1);
	if (flag != 0)
		exec_builtin(flag, pcomms, utils->envr, utils);
}

void	init_pcomms(t_pipe_comms *pcomms)
{
	if (pcomms->strp)
		free (pcomms->strp);
	pcomms->strp = ft_calloc(1,1);
	pcomms->args = NULL;
	pcomms->argc = 0;
	pcomms->fd_in = NULL;
	pcomms->fd_out = NULL;
	pcomms->next = NULL;
}

int	main2(t_shell *utils)
{
	t_pipe_comms	*pcomms;

	pcomms = ft_calloc(1, sizeof(t_pipe_comms));
	init_pcomms(pcomms);
	free_dptr(utils->command, 0);
	signal_search(ROOT);
	index_reset(utils);
	utils->input = readline("\x1b[5;95mpanic_shell> \x1b[0m");
	if (utils->input)
		add_history(utils->input);
	else
		return (free_dptr(utils->envr, 0), free(utils->export), \
		free_dptr(utils->exp, 0), free(utils), 0);
	if (quotes_verify(utils->input) == 0)
	{
		if (pipe_verify(utils->input, -1, 0) == 0)
		{
			utils->command = pipping_commands(utils->input, pcomms);
			ft_split_args_in_comms(pcomms, utils);
			pcomms_arg_count(pcomms);
			main2_helper(pcomms, utils);
			free_dptr(utils->command, 0);
		}
		utils->command = NULL;
	}
	return (1);
}

int	main(int argc, char **argv, char **env)
{
	t_shell	*utils;

	utils = ft_calloc(1, sizeof(t_shell));
	utils->export = ft_calloc(1, sizeof(t_builtvars));
	utils->j = 0;
	utils->envr = dptr_dup(env);
	increase_shlvl(utils);
	utils->exp = bubble_sort(0, utils->envr, 0, argc);
	if (argc != 1 || argv[1])
	{
		printf("invalid args (no args should be used)\n");
		exit (1);
	}
	signal_search(IGNORE);
	while (main2(utils))
		;
	return (0);
}
