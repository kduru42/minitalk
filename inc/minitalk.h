/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 01:48:10 by kduru             #+#    #+#             */
/*   Updated: 2023/04/04 02:29:31 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../ft_printf/ft_printf.h"
# include <signal.h>

void	send_bits(int pid, char c);
void	signal_handler(int signal);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);

#endif