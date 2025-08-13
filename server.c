/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 10:01:45 by diana             #+#    #+#             */
/*   Updated: 2025/08/13 13:27:08 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// Append character to dynamic string
static void	append_char(char c, char **message)
{
	char	*new_msg;
	int		i;

	if (!*message)
	{
		*message = malloc(1);
		if (!*message)
			return ;
		(*message)[0] = '\0';
	}
	new_msg = malloc(ft_strlen(*message) + 2);
	if (!new_msg)
		return ;
	i = 0;
	while ((*message)[i])
	{
		new_msg[i] = (*message)[i];
		i++;
	}
	new_msg[i] = c;
	new_msg[i + 1] = '\0';
	free(*message);
	*message = new_msg;
}

// Signal handler: build chars from bits
static void	handle_signal(int signum)
{
	static char		c = 0;
	static int		bit_count = 0;
	static char		*msg = NULL;
	int				bit;

	bit = (signum == SIGUSR2);
	c = (c << 1) | bit;
	bit_count++;
	if (bit_count == BIT_COUNT)
	{
		append_char(c, &msg);
		if (c == '\0')
		{
			ft_printf("%s\n", msg);
			free(msg);
			msg = NULL;
		}
		c = 0;
		bit_count = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Welcome to Dianita server ;)\n");
	ft_printf("Server PID: %d\n", getpid());
	sa.sa_handler = handle_signal;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
