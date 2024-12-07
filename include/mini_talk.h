/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:45:11 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/07 15:14:43 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_TALK_H
# define MINI_TALK_H

# include "ft_printf.h"
# include "libft.h"
# include "libft_extra.h"
# include <signal.h>
# include <sys/types.h>

/*******************************/
/*          MINITALK           */
/*******************************/

void	ft_put_error(char *str);

/*******************************/
/*           COLORS            */
/*******************************/
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define CYAN "\033[36m"
# define BOLD "\033[1m"
# define C_RESET "\033[0m"

/********************************
◦ signal #include <signal.h>

◦ sigemptyset // MET ENSEMBLE DES SIGNAUX (DANS LA STRUCT) A ZERO
	// sigemptyset() initializes the signal set given by set to empty,
	with all signals excluded from the set

◦ sigaddset // SET UN SIGNAL EN PARTICULIER 
	// sigaddset() and sigdelset() add and delete respectively signal signum from set

◦ sigaction
	// The  sigaction()  system  call is used to change the action taken by a process on receipt of a
		specific signal.

◦ kill
	// Close processud with PID

◦ getpid  #include <sys/types.h>
	// getpid(void) returns the process ID (PID) of the calling process.  (This is often used by routines
		that generate unique temporary filenames.)

◦ pause  - wait for signal
	// pause()  causes  the calling process (or thread) to sleep until a signal is delivered that ei‐
		ther terminates the process or causes the invocation of a signal-catching function.

◦ sleep - delay for a specified amount of time
	//

◦ usleep - usleep(MICRO SECONDS);
	// The  usleep()  function suspends execution of the calling thread for (at least) usec microsec‐
		onds.

Affichons l’identifiant du processus ( PID),
	l’identifiant du processus père ( PPID) et l’identifiant du groupe de processus ( PGID) de tous les processus associés à notre shell à l’aide de la commande ps :
*******************************/

#endif