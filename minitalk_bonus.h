/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:22:41 by osredond          #+#    #+#             */
/*   Updated: 2024/07/10 16:12:59 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H

# define MINITALK_BONUS_H

typedef struct s_server
{
	char	signals_received [8];
	int		num_signal;

}	t_server;

typedef struct s_client
{
	int		mask;
	int		byte_index;
	char	*message;
	int		is_finished;
}	t_client;

#endif
