#include <unistd.h>

void ft_putchar_rotone(char c)
{
    if (c >= 'a' && c <= 'z')
        c = ((c - 'a') + 1) % 26 + 'a';
    if (c >= 'A' && c <= 'Z')
        c = ((c - 'A') + 1) % 26 + 'A';
    write(1, &c, 1);
}

int main(int argc, char **argv)
{
    int i = 0;

    if (argc == 2)
    {
        while (argv[1][i])
        {
            ft_putchar_rotone(argv[1][i]);
            i++;
        }
    }
    write(1, "\n", 1);
    return 0;
}