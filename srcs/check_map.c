// #include "cub3d.h"

// int    check_enter(t_game *game, char **tab)
// {
//     int    entree;
//     int    i[2];

//     entree = 0;
//     i[0] = 0;
//     while (tab[i[0]])
//     {
//         i[1] = 0;
//         while (tab[i[0]][i[1]])
//         {
//             if (tab[i[0]][i[1]] == 'N' || tab[i[0]][i[1]] == 'S'
//                 || tab[i[0]][i[1]] == 'W' || tab[i[0]][i[1]] == 'E')
//             {
//                 game->start_line = i[0];
//                 game->start_colonne = i[1];
//                 game->start_direction = tab[i[0]][i[1]];
//                 entree++;
//             }
//             i[1]++;
//         }
//         i[0]++;
//     }
//     if (entree != 1)
//         return (printf("Error\nIl faut exactement une seule entree\n"), 0);
//     return (1);
// }

// int    check_wall(char **tab)
// {
//     int    i;
//     int    j;

//     i = 0;
//     while (tab[i])
//     {
//         j = 0;
//         while (tab[i][j])
//         {
//             if (tab[i][j] == '0' && !check_wall2(tab, i, j))
//                 return (0);
//             else if (!chek_char(tab[i][j]))
//                 return (0);
//             j++;
//         }
//     }
//     return (1);
// }

// int    check_wall2(char **tab, int i, int j)
// {
//     if (!tab[i - 1][j] || !tab[i + 1][j] || !tab[i][j - 1] || !tab[i][j + 1])
//         return (printf("Error\nLa map doit etre entourer de murs\n"), 0);
//     if (tab[i - 1][j] != '0' && tab[i - 1][j] != '1')
//         return (printf("Error\nLa map doit etre entourer de murs\n"), 0);
//     if (tab[i + 1][j] != '0' && tab[i + 1][j] != '1')
//         return (printf("Error\nLa map doit etre entourer de murs\n"), 0);
//     if (tab[i][j - 1] != '0' && tab[i][j - 1] != '1')
//         return (printf("Error\nLa map doit etre entourer de murs\n"), 0);
//     if (tab[i][j + 1] != '0' && tab[i][j + 1] != '1')
//         return (printf("Error\nLa map doit etre entourer de murs\n"), 0);
//     return (1);
// }

// int    check_char(char c)
// {
//     if (c != '0' && c !'1' && c != ' ' && c != '\t'
//         && c != 'N' && c != 'S' && c != 'W' && c != 'E')
//         return (printf("Error\nUn charactere non identifiable a ete trouver\n"),
//             0);
//     return (1);
// }