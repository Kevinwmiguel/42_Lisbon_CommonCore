/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:21:43 by thguimar          #+#    #+#             */
/*   Updated: 2024/10/17 17:57:13 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"

void	ignore_signal(struct sigaction *sa, int signal)
{
	struct sigaction	sa2;
	int					original_flags;

	original_flags = sa->sa_flags;
	sa->sa_handler = SIG_IGN;
	sa->sa_flags |= SA_SIGINFO;
	if (sigemptyset(&sa->sa_mask) != 0)
		return ;
	sigaction(signal, sa, &sa2);
	sa->sa_flags = original_flags;
}

void	root_signal(int signal, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signal == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		global_status()->status = 130;
	}
}

void	here_signal(int signal, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signal == SIGINT)
	{
		printf("\n");
		global_status()->status = 130;
		exit(130);
	}
}

void	signal_search2(t_signal_type t)
{
	static struct sigaction	sa;

	if (t == HEREDOC)
	{
		sa.sa_sigaction = here_signal;
		sa.sa_flags = SA_SIGINFO;
		if (sigemptyset(&sa.sa_mask) != 0)
			return ;
		sigaction(SIGINT, &sa, NULL);
		global_status()->status = 130;
	}
	else if (t == IGNORE)
	{
		ignore_signal(&sa, SIGQUIT);
		ignore_signal(&sa, SIGINT);
	}
}

void	signal_search(t_signal_type t)
{
	static struct sigaction	sa;

	if (t == ROOT)
	{
		sa.sa_sigaction = root_signal;
		sa.sa_flags = SA_SIGINFO;
		if (sigemptyset(&sa.sa_mask) != 0)
			return ;
		sigaction(SIGINT, &sa, NULL);
	}
	else if (t == CHILD)
	{
		sa.sa_handler = SIG_DFL;
		sa.sa_flags = 0;
		if (sigemptyset(&sa.sa_mask) != 0)
			return ;
		sigaction(SIGINT, &sa, NULL);
		global_status()->status = 130;
		sigaction(SIGQUIT, &sa, NULL);
	}
	else
		signal_search2(t);
}
