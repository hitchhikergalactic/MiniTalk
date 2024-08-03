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

typedef struct s_signal_receiver
{
	char	signal_buffer [8];
	int		signal_count;

}	t_signal_receiver;

typedef struct s_msg_buffer_sender
{
	int		current_mask;
	int		msg_buffer_byte_index;
	char	*msg_buffer;
	int		transmission_complete;
}	t_msg_buffer_sender;

#endif
