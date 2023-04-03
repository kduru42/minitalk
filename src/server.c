#include "../inc/minitalk.h"


void signal_handler(int signal)
{
    static int  byte;
    static int  bit;
    static int  length;

    if (signal == SIGUSR1)
    {
        byte |= 1 << (7 - bit);
    }
    bit++;
    length += bit;
    if (bit == 8)
    {
        ft_printf("%c", byte);
        bit = 0;
        byte = 0;
    }
}

int main()
{
    int pid;
    pid = getpid();
    ft_printf("%d\n", pid);
    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);
    while (1)
        pause();
    return (0);
}