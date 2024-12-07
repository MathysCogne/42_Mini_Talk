/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:48:52 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/07 23:43:34 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "mini_talk.h"

/*******************************/
/*           CLIENT            */
/*******************************/

# define NAME YELLOW BOLD "[client] " C_RESET

char	*char_to_bit(const char octet);

#endif