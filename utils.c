/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:53:58 by databey           #+#    #+#             */
/*   Updated: 2024/03/27 13:49:30 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	check_digit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

int	atoi(const char *str)
{
	int	rt;
	int	i;

	rt = 0;
	i = 0;
	while (check_digit(str[i]))
	{
		rt = (rt * 10) + (str[i] - '0');
		i++;
	}
	return (rt);
}

void	putnbr(int nbr)
{
	if (nbr > 9)
	{
		putnbr(nbr / 10);
		putnbr(nbr % 10);
	}
	else
	{
		nbr += 48;
		write(1, &nbr, 1);
	}
}
