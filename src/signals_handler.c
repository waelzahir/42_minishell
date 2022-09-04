/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 00:45:20 by sel-kham          #+#    #+#             */
/*   Updated: 2022/09/03 21:03:34 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"


void	handl(int sig)
{
	if (sig == SIGINT)
	{
		ft_putstr_fd("\b\b  ", 2);
		ft_putstr_fd("\n", 1);
		exit(130);
	}
}

void	ignore_signal(void)
{
	struct sigaction	sa;

	sa.sa_handler = SIG_IGN;
	sigaction(SIGINT, &sa, NULL);
}

static void	signals_router(int signal, siginfo_t *siginfo, void *content)
{
	content = NULL;
	siginfo = NULL;
	if (signal == SIGINT)
	{
		ft_putstr_fd("\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	signals_handler(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &signals_router;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
}
