/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:48:49 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/07 17:15:41 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

short	send_bit_to_server(size_t pid, char *bit)
{
	int	i;

	i = 0;
	while (bit[i])
	{
		usleep(100);
		if (bit[i] == '1')
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_printf("ERREUR LORS DE LENVOIE AVEC KILL");
				return (1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_printf("ERREUR LORS DE LENVOIE AVEC KILL");
				return (1);
			}
		}
		ft_printf(NAME "SEND OCTECT >> %c\n", bit[i]);
		i++;
	}
	return (0);
}

short	client(size_t pid, char *str)
{
	int	i;

	ft_printf(NAME "Send to %d: %s\n", pid, str);
	i = 0;
	while (str[i])
	{
		ft_printf(NAME "SEND %c >> %s\n", str[i], char_to_bit(str[i]));
		send_bit_to_server(pid, char_to_bit(str[i]));
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 3)
	{
		ft_put_error(NAME "Program takes two args. Please use: ./client [PID] [STR]\n");
		return (1);
	}
	// TODO GERER SI LE PID N'EST PAS VALIDE
	if (client(ft_atoi(argv[1]), argv[2]))
	{
		ft_put_error(NAME "DEBUG ERREUR\n");
		return (1);
	}
	return (0);
}