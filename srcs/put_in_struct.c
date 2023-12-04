#include "cub3d.h"
char *put_str(char *str)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(str[i] && ft_isspace(str[i]))
        i++;
    while (str[j] && str[j] != '\n')
        j++;
    if (str[j] == '\n')
        str[j] = 0;
    return (str+i);
}

void put_int_tab(char *str, int tab[3])
{
    int i;
    int j;
    int flag;
    int start;
    // int *tab;

    flag = 0;
    j = 0;
    start = 0;
    i = 0;
    // tab = ft_calloc(3, sizeof(int*));
    // if (!tab)
    //     return (NULL);
    while(str[i] && ft_isspace(str[i]))
        i++;
    while (str[i] && !flag)
    {
        start = i;
        while (str[i] && ft_isdigit(str[i]))
            i++;
        if (str[i] == ',' || !str[i] || str[i] == '\n')
        {
            if (!str[i])
                flag++;
            str[i] = '\0';
        }
        if (ft_isdigit(str[start]))
        {
            tab[j] = ft_atoi(str+start);
            ft_printf(1, "{%d}{%d}\n", j, tab[j]);
            j++;
        }
        if (!flag)
            i++;
    }
    // return (tab);
}


t_map *pars(char *str, t_map *map)
{
    int i;

    i = 0;
    while(str[i] && ft_isspace(str[i]))
        i++;
    if (str[i] == 'N' && str[i+1] == 'O')
        map->NO = ft_strdup(put_str(str+2));
    else if (str[i] == 'S' && str[i+1] == 'O')
        map->SO = ft_strdup(put_str(str+2));
    else if (str[i] == 'W' && str[i+1] == 'E')
        map->WE = ft_strdup(put_str(str+2));
    else if (str[i] == 'E' && str[i+1] == 'A')
        map->EA = ft_strdup(put_str(str+2));
    else if (str[i] == 'F')
        put_int_tab(str+1, map->F);
    else if (str[i] == 'C')
        put_int_tab(str+1, map->C);
    return (map);
}

int check_pars(char *str)
{
    int i;

    i = 0;
    while(str[i] && ft_isspace(str[i]))
        i++;
    if (str[i] == 'N' && str[i+1] == 'O')
        return (1);
    if (str[i] == 'S' && str[i+1] == 'O')
        return (1);
    if (str[i] == 'W' && str[i+1] == 'E')
        return (1);
    if (str[i] == 'E' && str[i+1] == 'A')
        return (1);
    if (str[i] == 'F')
        return (1); 
    if (str[i] == 'C')
        return (1); 
    return (0);
}

t_map *ft_put_in_struct(char **map)
{
    int i;
    t_map *s_map;

    s_map = ft_calloc(1, 1);
    // s_map->F = ft_calloc(3, sizeof(int*));
    // s_map->C = ft_calloc(3, sizeof(int*));
    i = 0;
    while (map[i])
    {
        if (check_pars(map[i]))
        {
            ft_printf(2, ">>>>>>>>>>>>>>>>>%p|%d|>%s\n", map[i]);
            s_map = pars(map[i], *&s_map);
            ft_printf(2, "%p|%d|>%s\n", s_map , i, s_map->NO);

        }
        // if (s_map->NO)
        //     ft_printf(2, ">>>>>>>>>>>>>>>>>||||>%s\n", s_map->NO);
        // if (s_map->SO)
        //     ft_printf(2, ">>>>>>>>>>>>>>>>>||||>%s\n", s_map->SO);
        // if (s_map->WE)
        //     ft_printf(2, ">>>>>>>>>>>>>>>>>||||>%s\n", s_map->WE);
        // if (s_map->EA)
        //     ft_printf(2, ">>>>>>>>>>>>>>>>>||||>%s\n", s_map->EA);

        i++;
    }
    return (s_map);
}