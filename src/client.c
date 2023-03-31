#include "../inc/minitalk.h"

void send_bits(int pid, char c)
{
    int count;

    count = 0;
    while (count < 8)
    {
        if (c << count & 1)
            kill (pid, SIGUSR1);
        else
            kill (pid, SIGUSR2);
        usleep(100);
        count++;
    }
}

int main(int argc, char **arg)
{
    int i;

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
    send_bits(ft_atoi(arg[1]), '\n');
    return (0);
}