/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:48:49 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/08 13:21:12 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static volatile sig_atomic_t	g_received = 0;

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (signum == SIGUSR1)
		g_received = 1;
	else if (signum == SIGUSR2)
		ft_printf(Y B NAME R "Receipt notice ! "
			"Your message has been received.\n");
}

static void	send_bit_to_server(size_t pid, char *bit)
{
	int	i;

	i = 0;
	while (bit[i])
	{
		g_received = 0;
		if (bit[i] == '1')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_received)
			pause();
		i++;
	}
	free(bit);
}

void	client(size_t pid, char *str)
{
	size_t	i;

	ft_printf(Y B NAME R "Send to %d: %s\n", pid, str);
	i = 0;
	while (i <= ft_strlen(str))
	{
		send_bit_to_server(pid, char_to_bit(str[i]));
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_put_error(Y B NAME R "Program takes two args. Please use:"
			"./client [PID SERVER] [MESSAGE]\n");
		return (1);
	}
	if (!argv[2] || argv[2][0] == '\0')
	{
		ft_put_error(Y B NAME R "Message is empty. Please use: "
			"./client [PID] [STR]\n");
		return (1);
	}
	if (ft_atoi(argv[1]) <= 0 || kill(ft_atoi(argv[1]), 0))
	{
		ft_put_error(Y B NAME R "Invalid PID. Please use: "
			" ./client [PID SERVER] [MESSAGE]\n");
		return (1);
	}
	set_signal_action();
	client(ft_atoi(argv[1]), argv[2]);
	return (0);
}
