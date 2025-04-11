#include <unistd.h>

void ft_putnbr(int i)
{
    if (i >= 10)
    {
        ft_putnbr(i / 10);
        i = i % 10;
    }
    char c = i + '0';
    write(1, &c, 1);
}

int main(void)
{
    for (int i = 1; i <= 100; i++)
    {
        if (i % 3 == 0 && i % 5 == 0)
            write(1, "fizzbuzz", 8);
        else if (i % 3 == 0)
            write(1, "fizz", 4);
        else if (i % 5 == 0)
            write(1, "buzz", 4);
        else
            ft_putnbr(i);
        write(1, "\n", 1);
    }
    return 0;
}