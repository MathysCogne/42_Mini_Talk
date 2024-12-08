/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:45:11 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/08 13:16:22 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_TALK_H
# define MINI_TALK_H

# define _POSIX_SOURCE 1
# define _POSIX_C_SOURCE 199309L

# include "ft_printf.h"
# include "libft.h"
# include <signal.h>
# include <sys/types.h>

/*******************************/
/*          MINITALK           */
/*******************************/

void	ft_put_error(char *str);
void	set_signal_action(void);
void	signal_handler(int signum, siginfo_t *info, void *context);

/*******************************/
/*           COLORS            */
/*******************************/
# define Y "\033[33m"
# define C "\033[36m"
# define B "\033[1m"
# define R "\033[0m"

#endif