/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 10:01:47 by diana             #+#    #+#             */
/*   Updated: 2025/08/13 13:33:31 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_char_bits(int pid, unsigned char c)
{
	int	bit;
	int	bit_value;

	bit = 0;
	while (bit < BIT_COUNT)
	{
		bit_value = (c >> (7 - bit)) & 1;
		if (bit_value == 0)
		{
			if (kill(pid, SIGUSR1) == -1)
				return ;
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				return ;
		}
		usleep(SIGNAL_DELAY);
		bit++;
	}
}

static void	send_message(int pid, const char *message)
{
	int	i;

	i = 0;
	while (message[i])
	{
		send_char_bits(pid, (unsigned char)message[i]);
		i++;
	}
	send_char_bits(pid, '\0');
}

int	main(int argc, char **argv)
{
	int	server_id;

	if (argc != 3)
	{
		ft_printf("[ERROR] Usage: ./client <PID> <MESSAGE>\n");
		return (1);
	}
	server_id = ft_atoi(argv[1]);
	if (server_id <= 0)
	{
		ft_printf("[ERROR] Invalid PID: %s\n", argv[1]);
		return (1);
	}
	if (argv[2][0] == '\0')
	{
		ft_printf("[ERROR] Empty message.\n");
		return (1);
	}
	send_message(server_id, argv[2]);
	return (0);
}
