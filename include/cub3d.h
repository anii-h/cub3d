#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>
# include <sys/time.h>
# include "../lib/minilibx-linux/mlx.h"
# include "../lib/libft/libft.h"
# include "structs.h"

/* window size*/

# define WIN_WIDTH 1280
# define WIN_HEIGHT 960

/* movement and rotation speed */

# define MOVE_SPEED 0.05
# define ROT_SPEED 0.03  // for now

/*for gnel*/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/*functions*/


/*init*/

int	init_mlx(t_game *game, t_map *map);

/*utils*/

void	free_map(t_map *map);
void	cleanup_and_exit(t_game *game, int exit_code);

//get_next_line
t_list	*find_last_node(t_list *list);
int	has_new_line(t_list *list);
int	length_of_new_line(t_list *list);
void	str_copy(t_list *list, char *str);
void	free_the_list(t_list **list, t_list *clean_node, char *buf);
char	*get_next_line(int fd);


/*validation*/

/*parsing*/

int parse_map(t_game *game, const char *map_file);
int	parse_texture(t_game *game, char *line, char *temp);
int	parse_color(t_game *game, char *line, char *temp);

/*game*/


#endif