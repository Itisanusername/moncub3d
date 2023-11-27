#include "cub3d.h"

int ft_check_2(char *s1, char *s2)
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

int ft_check_name(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == '.' && i > 0)
            if (ft_check_2(str+i, ".cub"))
                return (0);
        i++;
    }
    return (1);
}

int main(int argc, char **argv)
{
    char *s_line;
    char **map;

    if (argc != 2 || (argc == 2 && (!argv[1] || !*argv[1])))
    {
        printf("wrong\n");
        return (1);
    }
    if (ft_check_name(argv[1]))
    {
        printf("wrong\n");
        return (1);
    }
    s_line = ft_extract_file(argv[1]);
    if (!s_line)
    {
        printf("STRIKE");
        return (0);
    }
    printf("%s\n", s_line);
    map = ft_split(s_line, '\n');
    if (!nswe_check(map))
    {
        printf("Invalid Map !\n");
        return (1);
    }
    return (0);
}
