#ifndef CUB3D_H
# define CUB3D_H

//---------get-next-line Header---------//
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
// # include <sys/syslimits.h>

char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
int		ft_strchr(char	*s1, char s2);
void	*ft_calloc(unsigned int size, unsigned int len);
char	*get_next_line(int fd);

//---------cub3d Header---------//

typedef struct s_map
{
	char	*file_path;
	int		fd_file;
	char	**file_data;
	char	**data_filtered;
	int 	data_size;

	char	**map;
	int		map_size;
	bool	map_exist;
	bool	map_finsh;
	
	int		player_x;
	int		player_y;

	char	*no;
	char	*so;
	char	*we;
	char	*ea;

	int 	*floor_rgb;
	int		*ceiling_rgb;

}t_map;



typedef struct t_player 
{
	// char			**map;
	double			player_x;
	double			player_y;
}t_player;

#endif