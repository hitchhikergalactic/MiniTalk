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

typedef struct s_server
{
	char	signals_received [8];
	int		num_signal;

}	t_server;

typedef struct s_client
{
	int	*signals;
	int	num_signals;
	int	signal_index;
}	t_client;

#endif
