#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include "../minilibx-linux/mlx.h"
# include "libft.h"
# include <fcntl.h>

typedef struct s_map
{
	char        *NO;
	char        *SO;
	char        *WE;
	char        *EA;
    int         *F;
    int         *C;
    char        **map;
}				t_map;


char *ft_extract_file(char *path);


int nswe_check(char **tab);


void    free_tab(char **tab);

t_map *ft_put_in_struct(char **map);

void print_struct(t_map map);


int    check_wall(char **tab);

#endif