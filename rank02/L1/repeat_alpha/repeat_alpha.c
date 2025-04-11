#include <unistd.h>

void ft_putchar_multi(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        for (int i = c - 'a'; i >= 0; i--)
            write(1, &c, 1);
    }
    else if (c >= 'A' && c <= 'Z')
    {
        for (int j = c - 'A'; j >= 0; j--)
            write(1, &c, 1);
    }
    else
        write(1, &c, 1);
}

int main(int argc, char **argv)
{
    int i = 0;

    if (argc == 2)
    {
        while (argv[1][i] != '\0')
        {
            ft_putchar_multi(argv[1][i]);
            i++;
        }
    }
    write(1, "\n", 1);
    return 0;
}