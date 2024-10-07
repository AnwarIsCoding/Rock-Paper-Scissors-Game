#include <unistd.h>

void ft_putnbr(int n)
{
    char c;
    if (n >= 10)
    {
        ft_putnbr(n / 10);
        ft_putnbr(n % 10);
    }
    else 
    {
        c = n % 10 + '0';
        write (1, &c, 1);
    }
}