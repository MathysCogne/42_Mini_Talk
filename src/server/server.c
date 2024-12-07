/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:48:46 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/08 00:32:51 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void	build_string(char c, siginfo_t *info)
{
	static char	*str = NULL;
	char		new_str[2];
	char		*temp;

	if (c)
	{
		new_str[0] = c;
		new_str[1] = '\0';
		if (!str)
			str = ft_strdup(new_str);
		else
		{
			temp = str;
			str = ft_strjoin(str, new_str);
			free(temp);
		}
	}
	if (c == '\0')
	{
		ft_printf(NAME "New message, by %d: %s\n", info->si_pid, str);
		free(str);
		str = NULL;
		kill(info->si_pid, SIGUSR2);
	}
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static unsigned char	c = 0;
	static int				bit = 0;

	(void)context;
	if (signum == SIGUSR1)
		c = (c << 1) | 1;
	else if (signum == SIGUSR2)
		c = c << 1;
	if (bit < 7)
		bit++;
	else
	{
		build_string(c, info);
		bit = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
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
	ft_printf(NAME "My PID is, " BOLD CYAN "%d\n", getpid());
	set_signal_action();
	while (1)
		pause();
	return (0);
}
