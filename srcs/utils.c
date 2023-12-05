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

void *struct_init()
{
    static t_map map = {0};
    map.F = malloc(sizeof(int) * 3);
    map.C = malloc(sizeof(int) * 3);

    return (&map);
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
        printf("%d\n", map.F[i++]);
    i = 0;
    while (i < 3)
        printf("%d\n", map.C[i++]);
    i = 0;
    while (map.map[i])
        printf("%s\n", map.map[i++]);
}

void    freestruc(t_map *map)
{
    // int i;

    // i = 0;
    free(map->NO);
    free(map->SO);
    free(map->WE);
    free(map->EA);
    // while (i < 3)
    // {
    //     free(&map->F[i]);
    //     i++;
    // }
    free(map->F);
    // i = 0;
    // while (i < 3)
    //     free((void*)map->C[i++]);
    free(map->C);
}

char	*ft_strduup(const char *source)
{
	int		size;
	int		i;
	char	*dup;

	size = ft_strlen(source);
	i = 0;
	dup = ft_calloc(sizeof (char), size + 1);
	if (!(dup))
	{
		return (NULL);
	}
	while (source[i] != '\0' && source[i] != '\n')
	{
		dup[i] = source[i];
		i++;
	}
	return (dup);
}
