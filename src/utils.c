/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:46:33 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/07 23:57:02 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	ft_put_error(char *str)
{
	ft_putstr_fd(str, 2);
}

/*
** Set action when received SIGUSR1 or SIGUSR2
** Action is call signal_handler()
*/
void	set_signal_action(void)
{
	struct sigaction	act;

	sigemptyset(&act.sa_mask);
	act.sa_sigaction = &signal_handler;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
}

/*
** Convertion a char in base 10 (one Octet) to str in base 2 (one Bit)
** - Remaind: Free return value, before use
*/
char	*char_to_bit(const char octet)
{
	char	*bit;
	int		i;

	bit = malloc(sizeof(char) * (8 + 1));
	if (!bit)
		return (NULL);
	i = 7;
	while (i >= 0)
	{
		if (octet & (1 << i))
			bit[7 - i] = '1';
		else
			bit[7 - i] = '0';
		i--;
	}
	bit[8] = '\0';
	return (bit);
}
