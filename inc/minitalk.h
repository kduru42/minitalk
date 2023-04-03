#ifndef MINITALK_H
#define MINITALK_H

#include "../ft_printf/ft_printf.h"
#include <signal.h>

void send_bits(int pid, char c);
void signal_handler(int signal);
int	ft_isdigit(int c);
int	ft_atoi(const char *str);

#endif