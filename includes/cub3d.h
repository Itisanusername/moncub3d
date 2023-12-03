#ifndef CUB3D_H
# define CUB3D_H
#endif

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
    int         *F[3];
    int         *C[3];
    char        **map;
}				t_map;


char *ft_extract_file(char *path);


int nswe_check(char **tab);


void    free_tab(char **tab);


int    check_wall(char **tab)