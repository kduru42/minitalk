/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 02:16:44 by kduru             #+#    #+#             */
/*   Updated: 2023/04/04 02:17:42 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	send_bits(int pid, char c)
{
	int	count;

	count = 7;
	while (count >= 0)
	{
		if ((c >> count) & 1)
			kill (pid, SIGUSR1);
		else
			kill (pid, SIGUSR2);
		usleep(100);
		count--;
	}
}

int	main(int argc, char **arg)
{
	int	i;

	i = 0;
	if (argc != 3)
	{
		ft_printf("Invalid argument\n");
		return (1);
	}
	while (arg[2][i])
	{
		send_bits(ft_atoi(arg[1]), arg[2][i]);
		i++;
	}
	return (0);
}
