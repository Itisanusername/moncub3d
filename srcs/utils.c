#include "cub3d.h"


void    free_tab(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}

void print_struct(t_map map)
{
    int i;

    i = 0;
    printf("%s\n", map.NO);
    printf("%s\n", map.SO);
    printf("%s\n", map.WE);
    printf("%s\n", map.EA);

    while (i < 3)
    {
        printf("%d\n", map.F[i++]);
    }
    i = 0;
    while (i < 3)
    {
        printf("%d\n", map.C[i++]);
    }
    

}
