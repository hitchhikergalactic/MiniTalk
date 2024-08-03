/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:21:29 by osredond          #+#    #+#             */
/*   Updated: 2024/07/10 16:11:41 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include "libft/libft.h"
#include "minitalk.h"

t_msg_buffer_sender	g_sig_cont;

static void	translate_byte_to_signals(char byte, int start_index)
{
	int	current_mask;
	int	bit_index;
	int	bit;

	current_mask = 128;
	bit_index = 0;
	while (bit_index < 8)
	{
		bit = (byte & current_mask);
		if (bit == 0)
			g_sig_cont.signals[start_index] = SIGUSR1;
		else
			g_sig_cont.signals[start_index] = SIGUSR2;
		start_index++;
		current_mask = current_mask / 2;
		bit_index++;
	}
}

static void	convert_msg_buffer_to_signals(const char *msg_buffer)
{
	int		num_bytes;
	int		msg_buffer_byte_index;
	int		start_index;

	num_bytes = ft_strlen (msg_buffer) + 1;
	g_sig_cont.signal_counts = num_bytes * 8;
	g_sig_cont.signals = malloc (g_sig_cont.signal_counts * sizeof(int));
	if (g_sig_cont.signals == NULL)
	{
		free (g_sig_cont.signals);
		return ;
	}
	msg_buffer_byte_index = 0;
	start_index = 0;
	while (msg_buffer_byte_index < num_bytes)
	{
		translate_byte_to_signals(msg_buffer[msg_buffer_byte_index], start_index);
		msg_buffer_byte_index++;
		start_index = start_index + 8;
	}
}

void	process_sigusr1(int sign, siginfo_t *siginfo, void *context)
{
	(void)sign;
	(void)context;
	if (g_sig_cont.signal_index >= g_sig_cont.signal_counts)
		return ;
	usleep(10);
	if (kill(siginfo->si_pid, g_sig_cont.signals[g_sig_cont.signal_index]) < 0)
	{
		ft_printf("Error signal to server PID %d\n", siginfo->si_pid);
		exit(-1);
	}
	g_sig_cont.signal_index++;
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					pid;

	if (argc < 3)
		return (1);
	pid = ft_atoi(argv[1]);
	if (pid == 0)
		return (-1);
	ft_memset (&sa, 0, sizeof(sa));
	sa.sa_sigaction = process_sigusr1;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) < 0)
		return (-1);
	convert_msg_buffer_to_signals(argv[2]);
	g_sig_cont.signal_index = 1;
	if (kill(pid, g_sig_cont.signals[0]) < 0)
	{
		free (g_sig_cont.signals);
		return (-1);
	}
	while (g_sig_cont.signal_index < g_sig_cont.signal_counts)
		pause ();
	free (g_sig_cont.signals);
	return (0);
}
