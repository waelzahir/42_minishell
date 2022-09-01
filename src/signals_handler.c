/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 00:45:20 by sel-kham          #+#    #+#             */
/*   Updated: 2022/09/01 02:02:16 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

void	herdoc_int(int sig)
{
	if (sig == SIGINT)
	{
		ft_putstr_fd("\b\b  \n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		// rl_redisplay();
		
		exit(130);
	}
}

void	deflt_signal(void)
{
	struct sigaction	sa; 

	// sa.sa_handler = SIG_DFL;
	sa.sa_handler = herdoc_int;
	sigaction(SIGINT, &sa, NULL);
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
		// ft_putstr_fd("test2\n", 1);
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
