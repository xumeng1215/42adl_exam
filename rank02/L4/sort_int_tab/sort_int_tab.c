void sort_int_tab(int *tab, unsigned int size)
{
    unsigned int i = 0;
    int temp;

    while (i < (size - 1))
    {
        if (tab[i] > tab[i + 1])
        {
            temp = tab[i];
            tab[i] = tab[i + 1];
            tab[i + 1] = temp;
            i = 0;
        }
        else
            i++;
    }
}

// #include <stdio.h>
// int main(void)
// {
//     int tab[5] = {1, 2, 33, 4, 5};

//     sort_int_tab(tab, 5);
//     for (int i = 0; i < 5; i++)
//         printf("%d\n", tab[i]);
// }