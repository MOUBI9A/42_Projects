#include "cub3d.h"


// int main(int argc, char const *argv[])
// {
//     int		fd;
//     char	*line;

//     if (argc == 2)
//     {
//         fd = open(argv[1], O_RDONLY);
//         while ((line = get_next_line(fd)))
//         {
//             printf("%s\n", line);
//             free(line);
//         }
//         close(fd);
//     }
//     return (0);
// }


char *ft_memcpy(void *dst, const void *src, size_t n)
{
    unsigned char *d;
    unsigned char *s;

    d = (unsigned char *)dst;
    s = (unsigned char *)src;
    if (!dst && !src)
        return (NULL);
    while (n--)
        *d++ = *s++;
    return (dst);
}

void print_error(char *str, int ext)
{
    printf("\x1b[31mError\n\x1b[0m%s\n", str);
    exit(ext);
}

int check_path(char *path)
{
    int i;

    i = 0;
    while (path[i])
        i++;
    if (path[i - 1] == 'b' && path[i - 2] == 'u' && path[i - 3] == 'c' && path[i - 4] == '.')
        return (0);
    return (1);
}

void *ft_realloc(void *ptr, size_t size)
{
    void *new_ptr;

    if (!ptr)
        return (malloc(size));
    if (!size)
    {
        free(ptr);
        return (NULL);
    }
    new_ptr = malloc(size);
    if (!new_ptr)
        return (NULL);
    ft_memcpy(new_ptr, ptr, size);
    free(ptr);
    return (new_ptr);
}

void first_check(int argc, char **argv, t_map *data)
{
    data->file_path = argv[1];
	if (check_path(data->file_path))
		print_error("File extension must finish by .cub\n", 1);
	data->fd_file = open(data->file_path, O_RDONLY);
	if (data->fd_file == -1)
		print_error("Error Can't open the file \n", 1);
    printf("File opened DONE\n");
    return;
}

void init_struct(t_map **data)
{
    (*data)->file_data = NULL;
    (*data)->data_size = 0;

    (*data)->no = NULL;
    (*data)->so = NULL;
    (*data)->we = NULL;
    (*data)->ea = NULL;

    (*data)->floor_rgb = NULL;
    (*data)->ceiling_rgb = NULL;
    
    (*data)->map = NULL;
    (*data)->map_size = 0;
    (*data)->map_exist = false;
    (*data)->map_finsh = false;

    (*data)->player_x = -1;
    (*data)->player_y = -1;
    printf("Struct initialized DONE\n");
}
char *ft_strchre(char *s1, char s2)
{
    int i;

    i = 0;
    while (s1[i])
    {
        if (s1[i] == s2)
            return (&s1[i]);
        i++;
    }
    return (NULL);
}

int ft_atoi(char *str)
{
    int i;
    int sign;
    int res;

    i = 0;
    sign = 1;
    res = 0;
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + str[i] - '0';
        i++;
    }
    return (res * sign);
}

char *ft_strtrim(char *s1, char *set)
{
    int i;
    int j;
    int k;
    char *str;

    i = 0;
    j = 0;
    k = 0;
    while (s1[i] && ft_strchre(set, s1[i]))
        i++;
    j = ft_strlen(s1) - 1;
    while (j > i && ft_strchre(set, s1[j]))
        j--;
    str = (char *)malloc(sizeof(char) * (j - i + 2));
    if (!str)
        return (NULL);
    while (i <= j)
    {
        str[k] = s1[i];
        i++;
        k++;
    }
    str[k] = '\0';
    free(s1);
    return (str);
}

void check_th(char *str)
{
    int i;

    i = 0;
    if (str[0] == 0)
        print_error("Path can't be empty\n", 1);
    if (str[0] != '.' || str[1] != '/')
        print_error("Path must start by ./\n", 1);
    while (str[i])
    {
        if (str[i] == ' ')
            print_error("Path can't contain space\n", 1);
        i++;
    }
}


void check_no(t_map **data, char *str)
{
    if ((*data)->no)
        print_error("NO path already defined\n", 1);
    (*data)->no = ft_strtrim(str, "NO ");
    check_th((*data)->no);
    printf("NO path checked\n");
    printf("==%s\n", (*data)->no);

}

void check_so(t_map **data, char *str)
{
    if ((*data)->so)
        print_error("SO path already defined\n", 1);
    (*data)->so = ft_strtrim(str, "SO ");
    check_th((*data)->so);
    printf("SO path checked\n");
    printf("==%s\n", (*data)->so);
}

void check_we(t_map **data, char *str)
{
    if ((*data)->we)
        print_error("WE path already defined\n", 1);
    (*data)->we = ft_strtrim(str, "WE ");
    check_th((*data)->we);
    printf("WE path checked\n");
    printf("==%s\n", (*data)->we);
}

void check_ea(t_map **data, char *str)
{
    if ((*data)->ea)
        print_error("EA path already defined\n", 1);
    (*data)->ea = ft_strtrim(str, "EA ");
    check_th((*data)->ea);
    printf("EA path checked\n");
    printf("==%s\n", (*data)->ea);
}

char **ft_split(char *s1, char c)
{
    int i;
    int j;
    int k;
    char **str;

    i = 0;
    j = 0;
    k = 0;
    str = (char **)malloc(sizeof(char *) * (ft_strlen(s1) + 1));
    if (!str)
        return (NULL);
    while (s1[i])
    {
        if (s1[i] == c)
            i++;
        else
        {
            j = i;
            while (s1[j] && s1[j] != c)
                j++;
            str[k] = (char *)malloc(sizeof(char) * (j - i + 1));
            if (!str[k])
                return (NULL);
            j = 0;
            while (s1[i] && s1[i] != c)
            {
                str[k][j] = s1[i];
                i++;
                j++;
            }
            str[k][j] = '\0';
            k++;
        }
    }
    str[k] = NULL;
    return (str);
}

int is_digit_str(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == '\n' && i == 0)
            return (0);
        if ((str[i] < '0' || str[i] > '9') && str[i] != '\n')
            return (0);
        i++;
    }
    return (1);
}

void check_floor(t_map **data, char *str)
{
    int i;
    int j;
    int k;
    char *str2;
    char **rgb;

    i = 0;
    j = 0;
    k = 0;
    str2 = ft_strtrim(str, "F ");
    rgb = ft_split(str2, ',');
    while (rgb[i])
    {
        if(is_digit_str(rgb[i]) == 0)
            print_error("Floor color must be in RGB format (F digit)\n", 1);
        i++;
    }
    if (i != 3)
        print_error("Floor color must be in RGB format\n", 1);
    (*data)->floor_rgb = (int *)ft_calloc(sizeof(int), 3);
    while (j < 3)
    {
        (*data)->floor_rgb[j] = ft_atoi(rgb[j]);
        if ((*data)->floor_rgb[j] < 0 || (*data)->floor_rgb[j] > 255)
            print_error("RGB value must be between 0 and 255\n", 1);
        j++;
    }
    printf("Floor color checked\n");
    printf("==%d %d %d\n", (*data)->floor_rgb[0], (*data)->floor_rgb[1], (*data)->floor_rgb[2]);
}

void check_ceiling(t_map **data, char *str)
{
    int i;
    int j;
    int k;
    char *str2;
    char **rgb;

    i = 0;
    j = 0;
    k = 0;
    str2 = ft_strtrim(str, "C ");
    rgb = ft_split(str2, ',');
    while (rgb[i])
    {
        if(is_digit_str(rgb[i]) == 0)
            print_error("Ceiling color must be in RGB format (C digit)\n", 1);
        i++;
    }
    if (i != 3)
        print_error("Ceiling color must be in RGB format\n", 1);
    (*data)->ceiling_rgb = (int *)ft_calloc(sizeof(int), 3);
    while (j < 3)
    {
        (*data)->ceiling_rgb[j] = ft_atoi(rgb[j]);
        if ((*data)->ceiling_rgb[j] < 0 || (*data)->ceiling_rgb[j] > 255)
            print_error("RGB value must be between 0 and 255\n", 1);
        j++;
    }
    printf("Ceiling color checked\n");
    printf("==%d %d %d\n", (*data)->ceiling_rgb[0], (*data)->ceiling_rgb[1], (*data)->ceiling_rgb[2]);
}


void check_theline_map(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] != '\n' && str[i] != 13 && str[i] != '1' && str[i] != '0' && str[i] != ' ' && str[i] != 'N' && str[i] != 'S' && str[i] != 'W' && str[i] != 'E' )
            print_error("Invalid character in map\n", 1);
        i++;
    }
}

char *ft_strdup(char *s1)
{
    int i;
    char *str;

    i = 0;
    while (s1[i])
        i++;
    str = (char *)malloc(sizeof(char) * (i + 1));
    if (!str)
        return (NULL);
    i = 0;
    while (s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

#include <string.h>
void file_to_arr(t_map **data)
{
    char *line;
    int i = 0;
    char *str;

    while ((line = get_next_line((*data)->fd_file)))
    {
        (*data)->data_size++;
        free(line);
    }

    close((*data)->fd_file);
    (*data)->fd_file = open((*data)->file_path, O_RDONLY);

    (*data)->file_data = (char **)malloc(sizeof(char *) * ((*data)->data_size + 1));
    int j = 0;

    while (j < (*data)->data_size)
    {
        (*data)->file_data[j] = NULL;
        j++;
    }

    while (((*data)->file_data[i] = get_next_line((*data)->fd_file)))
    {
        str = ft_strtrim((*data)->file_data[i], " \t");
        if (str[0] != 'N' && str[0] != 'S' && str[0] != 'W' && str[0] != 'E' && str[0] != 'F' && str[0] != 'C' && str[0] != '1' && str[0] != '0' && str[0] != '\0' && str[0] != '\n' && str[0] != 13)
            print_error("Invalid line\n", 1);
        if (str[0] == 'N' && str[1] == 'O' && str[2] == ' ')
            check_no(data, str);
        else if (str[0] == 'S' && str[1] == 'O' && str[2] == ' ')
            check_so(data, str);
        else if (str[0] == 'W' && str[1] == 'E' && str[2] == ' ')
            check_we(data, str);
        else if (str[0] == 'E' && str[1] == 'A' && str[2] == ' ')
            check_ea(data, str);
        else if (str[0] == 'F' && str[1] == ' ')
            check_floor(data, str);
        else if (str[0] == 'C' && str[1] == ' ')
            check_ceiling(data, str);
        else if ((str[0] == '1' || str[0] == '0'))
        {
            if ((*data)->no && (*data)->so && (*data)->we && (*data)->ea && (*data)->floor_rgb && (*data)->ceiling_rgb)
            {
                if (!(*data)->map)
                {
                    (*data)->map = (char **)malloc(sizeof(char *) * ((*data)->data_size - i + 1));
                    int j = 0;
                    while (j < (*data)->data_size - i)
                    {
                        (*data)->map[j] = NULL;
                        j++;
                    }
                    (*data)->map_exist = true;
                }
                if((*data)->map_finsh == true)
                    print_error("Map not at the end\n", 1);
                (*data)->map[(*data)->map_size] = ft_strdup((*data)->file_data[i]);
                (*data)->map_size++;
            }
            else
                print_error("BAD MAP", 1);
        }
        else if (str[0] == '\n' && (*data)->map_exist == true)
            (*data)->map_finsh = true;
        
        i++;
    }
    free(str);
    close((*data)->fd_file);
    printf("File to array DONE\n");
    return;
}

void player_check(t_map *data)
{
    int i;
    int j;


    i = 0;
    while (data->map[i])
    {
        j = 0;
        while (data->map[i][j])
        {
            if (data->map[i][j] == 'N' || data->map[i][j] == 'S' || data->map[i][j] == 'W' || data->map[i][j] == 'E')
            {
                if (data->player_x != -1 || data->player_y != -1)
                    print_error("Multiple player\n", 1);
                data->player_x = i;
                data->player_y = j;
            }
            else if (data->map[i][j] != '1' && data->map[i][j] != '0' && data->map[i][j] != ' ' && data->map[i][j] != '\n' && data->map[i][j] != 13)
            {
                print_error("Invalid character in map\n", 1);
            }
            j++;
        }
        i++;
    }
    if (data->player_x == -1 || data->player_y == -1)
        print_error("No player\n", 1);
    printf("Player checked\n");
}

void check_valid_map(char **map, int player_x, int player_y, int map_size)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == '.')
            {
                if (i == 0 || i == map_size - 1 || j == 0 || j == ft_strlen(map[i]) - 1)
                    print_error("Map not closed\n", 1);
                if (map[i - 1][j] == NULL || map[i + 1][j] == NULL || map[i][j - 1] == NULL || map[i][j + 1] == NULL)
                    print_error("Map not closed\n", 1);
                if (map[i - 1][j] == ' ' || map[i + 1][j] == ' ' || map[i][j - 1] == ' ' || map[i][j + 1] == ' ')
                    print_error("Map not closed\n", 1);
            }
            // else if (map[i][j] == '0')
            // {
            //     if (i == 0 || i == map_size - 1 || j == 0 || j == ft_strlen(map[i]) - 1)
            //         print_error("Map not closed\n", 1);
            //     if (map[i - 1][j] == ' ' || map[i + 1][j] == ' ' || map[i][j - 1] == ' ' || map[i][j + 1] == ' ')
            //         print_error("Map not closed\n", 1);
            // }
            j++;
        }
        i++;
    }
    printf("Map Valid\n");

}



void flood_fill(char **map, int player_x, int player_y, int map_size)
{
    if (player_x < 0 || player_x >= map_size || player_y < 0 || player_y >= ft_strlen(map[player_x]) || map[player_x][player_y] == '1' || map[player_x][player_y] == ' ' || map[player_x][player_y] == '.')
        return;
    map[player_x][player_y] = '.';
    flood_fill(map, player_x + 1, player_y, map_size);
    flood_fill(map, player_x - 1, player_y, map_size);
    flood_fill(map, player_x, player_y + 1, map_size);
    flood_fill(map, player_x, player_y - 1, map_size);
}

void check_withflood_fill(char **map, int player_x, int player_y, int map_size)
{
    char **mapcpy;

    mapcpy = (char **)malloc(sizeof(char *) * map_size);
    int i = 0;
    while (i < map_size)
    {
        mapcpy[i] = ft_strdup(map[i]);
        i++;
    }
    flood_fill(mapcpy, player_x, player_y, map_size);
    check_valid_map(mapcpy, player_x, player_y, map_size);
    while (i < map_size)
    {
        free(mapcpy[i]);
        i++;
    }
    free(mapcpy);
    printf("Flood fill DONE\n");
}


void map_check(t_map *data)
{
    init_struct(&data);
    file_to_arr(&data);
    player_check(data);
    check_withflood_fill(data->map, data->player_x, data->player_y, data->map_size);
    // check_valid_map(data->map, data->player_x, data->player_y, data->map_size);
    
    // pause();
    
        

    // check_valid_map(data->map, data->player_x, data->player_y, data->map_size);
}

int main(int argc, char **argv)
{
    t_map data;

    if (argc == 2)
    {
        first_check(argc, argv, &data);
        map_check(&data);
        // for (int i = 0; i < data.data_size; i++)
        // {
        //     printf("%s\n", data.file_data[i]);
        // }
    }
    else
        print_error("the programme he need just the map \n", 1);
    return (0);
}