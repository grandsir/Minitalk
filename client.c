/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:44:49 by databey           #+#    #+#             */
/*   Updated: 2024/03/27 14:37:38 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_sendbit(int pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if (c >> bit & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit--;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		write(1, "Check Arguments!", 17);
		return (1);
	}
	pid = atoi(argv[1]);
	while (*argv[2])
		ft_sendbit(pid, *(argv[2]++));
	ft_sendbit(pid, '\n');
	return (0);
}
