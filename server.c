/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:45:13 by databey           #+#    #+#             */
/*   Updated: 2024/03/27 14:37:28 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handle(int sig)
{
	static int	bit = 128;
	static int	c = 0;

	if (sig == SIGUSR1)
		c = c + bit;
	bit = bit / 2;
	if (bit == 0)
	{
		write(1, &c, 1);
		bit = 128;
		c = 0;
	}
}

int	main(void)
{
	putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, ft_handle);
	signal(SIGUSR2, ft_handle);
	while (1)
		pause();
}
