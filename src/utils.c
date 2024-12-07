/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:46:33 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/07 15:57:52 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	ft_put_error(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
}

/*
** Convertion a char in base 10 (ont Octet) to str in base 2 (one Bit)
** - Remaind: Free return value, before use
*/
char	*char_to_bit(char octet)
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
