/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:48:46 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/07 17:42:12 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

// void	sigint_handler(int signum)
static void	signal_handler(int signum, siginfo_t *info, void *context)
{
	(void)signum;
	if (signum == SIGUSR1)
		ft_printf(NAME "1\n");
	else
		ft_printf(NAME "0\n");
}

static void	set_signal_action(void)
{
	struct sigaction	act;

	sigemptyset(&act.sa_mask);
	ft_bzero(&act, sizeof(act));
	act.sa_handler = &sigint_handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
}

static short	server(void)
{
	ft_printf(NAME "My PID is, " BOLD CYAN "%d\n", getpid());
	set_signal_action();
	while (1)
		pause();
	return (0);
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc > 1)
	{
		ft_put_error(NAME "Program not take args. Please use: ./server\n");
		return (1);
	}
	ft_printf(NAME "Hi 👋\n");
	if (server())
	{
		ft_put_error(NAME "DEBUG ERREUR\n");
		return (1);
	}
	return (0);
}