#include <unistd.h>

void ft_putchar_rot13(char c)
{
    if (c >= 'a' && c <= 'z')
        c = ((c - 'a') + 13) % 26 + 'a';
    if (c >= 'A' && c <= 'Z')
        c = ((c - 'A') + 13) % 26 + 'A';
    write(1, &c, 1);
}

int main(int argc, char **argv)
{
    int i = 0;

    if (argc == 2)
    {
        while (argv[1][i])
        {
            ft_putchar_rot13(argv[1][i]);
            i++;
        }
    }
    write(1, "\n", 1);
    return 0;
}