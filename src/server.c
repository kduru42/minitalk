/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 02:24:07 by kduru             #+#    #+#             */
/*   Updated: 2023/04/04 02:25:36 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	signal_handler(int signal)
{
	static int	byte;
	static int	bit;

	if (signal == SIGUSR1)
		byte |= 1 << (7 - bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", byte);
		bit = 0;
		byte = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("%d\n", pid);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
