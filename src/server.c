#include "../inc/minitalk.h"

void signal_handler(int signal)
{
    static int  byte;
    static int  bit;

    if (signal == SIGUSR1)
        byte |= (1 << bit);
    bit++;
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
    while (1)
    {
        signal(SIGUSR1, &signal_handler);
        signal(SIGUSR2, &signal_handler);
        pause();
    }
    return (0);
}