#include "cub3d.h"
char *put_str(char *str)
{
    int i;
    int j;

    i = 0;
    while(str[i] && ft_isspace(str[i]))
        i++;
    while (str[j] && str[j] != '\n')
        j++;
    if (str[j] == '\n')
        str[j] = 0;
    ft_printf(2, ">>>>>>>>>>>>>>>>>>%s\n", str+i);
    return (str+i);
}

int *put_int_tab(char *str)
{
    int i;
    int j;
    int flag;
    int start;
    int *tab;

    flag = 0;
    j = 0;
    start = 0;
    i = 0;
    tab = (int *)malloc(3 * sizeof(int));
    if (!tab)
        return (NULL);
    while(str[i] && ft_isspace(str[i]))
        i++;
    while (str[i] && !flag)
    {
        start = i;
        while (str[i] && ft_isdigit(str[i]))
            i++;
        if (str[i] == ',' || !str[i])
        {
            if (!str[i])
                flag++;
            str[i] = '\0';
        }
        if (ft_isdigit(str[start]))
            tab[j++] = ft_atoi(str+start);
        if (!flag)
            i++;
    }
    return (tab);
}


t_map *pars(char *str, t_map *map)
{
    if (str[0] == 'N' && str[1] == 'O')
        map->NO = ft_strdup(put_str(str+2));
    if (str[0] == 'S' && str[1] == 'O')
        map->SO = ft_strdup(put_str(str+2));
    if (str[0] == 'W' && str[1] == 'E')
        map->WE = ft_strdup(put_str(str+2));
    if (str[0] == 'E' && str[1] == 'A')
        map->EA = ft_strdup(put_str(str+2));
    if (str[0] == 'F')
        map->F = put_int_tab(str+1);
    if (str[0] == 'C')
        map->C = put_int_tab(str+1);
    return (map);
}

t_map *ft_put_in_struct(char **map)
{
    int i;
    int j;
    t_map *s_map;

    s_map = ft_calloc(1, 1);
    i = 0;
    j = 0;
    while (map[i])
    {
        while(map[i][j])
        {
            while (map[i][j] && ft_isspace(map[i][j]))
                j++;
            s_map = pars(map[i]+j, *&s_map);
        }
    }
    return (s_map);
}