#include "cub3d.h"


int valid_char(char c)
{
    return (c == '1' || c == '0'
        || c == 'E' || c == 'S'
        || c == 'N' || c == 'W' || c == ' ');
}

int one_of_this(char c)
{
    return (c == '0' || c == 'S' || c == 'W'
        || c == 'E' || c == 'N');
}

int one_of_this2(char c)
{
    return (c == '0' || c == 'S' || c == 'W'
        || c == 'E' || c == 'N' || c == '1');
}

bool is_valid_map(char **map)
{
    int i = 0, k = 0;
    int j = 0;

    while (map[i])
    {
        if (map[i][0] == '1')
            break;
        i++;
    }
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (valid_char(map[i][j]))
            {
                if (diractions_f_c(map[i][j]))
                    k++;
                if (one_of_this(map[i][j]))
                {
                    if (!one_of_this2(map[i + 1][j]) || !one_of_this2(map[i - 1][j])
                    || !one_of_this2(map[i][j + 1]) || !one_of_this2(map[i][j - 1]))
                    {
                        printf("invalid char next to : i = %d j = %d \n", i, j);
                        return (false);
                    }
                }
            }
            else
            {
                printf("this is invalid char : i = %d j = %d", i, j);
                return (false);
            }
            j++;
        }
        i++;
    }
    if (k != 1)
    {
        printf("invalid diraction");
        return (false);
    }
    return (true);
}
