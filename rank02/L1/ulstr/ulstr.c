#include <unistd.h>

void ft_putchar_altercase(char c)
{
    if (c >= 'a' && c <= 'z')
        c = c - 32;
    else if (c >= 'A' && c <= 'Z')
        c = c + 32;
    write(1, &c, 1);
}

int main(int argc, char **argv)
{
    int i = 0;
    if (argc == 2)
    {
        while (argv[1][i] != '\0')
        {
            ft_putchar_altercase(argv[1][i]);
            i++;
        }
    }
    write(1, "\n", 1);
    return 0;
}