#include "cub3d.h"

int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] && s2[i])
    {
        if (s1[i] != s2[i])
            return (0);
        i++;
    }
    if (!s1[i] && !s2[i])
        return (1);
    return (0);
}

int ft_check(char *str)
{
    if (ft_strcmp(str, "NO ./path_to_the_north_texture"))
        return (1);
    if (ft_strcmp(str, "SO ./path_to_the_south_texture"))
        return (2);
    if (ft_strcmp(str, "WE ./path_to_the_west_texture"))
        return (3);
    if (ft_strcmp(str, "EA ./path_to_the_east_texture"))
        return (4);
    if (ft_strcmp(str, "F 220,100,0"))
        return (5);
    if (ft_strcmp(str, "C 225,30,0"))
        return (6);
    return (0);
}

int nswe_check(char **tab)
{
    int n;
    int s;
    int w;
    int e;
    int f;
    int c;
    int i;

    i = 0;
    f = 0;
    c = 0;
    n = 0;
    s = 0;
    w = 0;
    e = 0;
    while (tab[i])
    {
        if (ft_check(tab[i]) == 1)
            n++;
        if (ft_check(tab[i]) == 2)
            s++;
        if (ft_check(tab[i]) == 3)
            w++;
        if (ft_check(tab[i]) == 4)
            e++;
        if (ft_check(tab[i]) == 5)
            f++;
        if (ft_check(tab[i]) == 6)
            c++;
        i++;
    }
    if (!n || !s || !w || !e || !f || !c)
        return (0);
    return (1);
}