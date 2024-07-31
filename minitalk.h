/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:22:08 by osredond          #+#    #+#             */
/*   Updated: 2024/07/09 20:22:19 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H

# define MINITALK_H

typedef struct s_signal_receiver
{
	char	signal_buffer [8];
	int		signal_count;

}	t_signal_receiver;

typedef struct s_msg_buffer_sender
{
	int	*signals;
	int	signal_counts;
	int	signal_index;
}	t_msg_buffer_sender;

#endif
