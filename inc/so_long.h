/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhristi <ikhristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:19:27 by ikhristi          #+#    #+#             */
/*   Updated: 2023/06/27 13:21:52 by ikhristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <limits.h>
# include <fcntl.h>
# include "../mlx/mlx.h"

# define WALL				'1'
# define FLOOR				'0'
# define COLLECTIBLE		'C'
# define PLAYER				'P'
# define MAP_EXIT			'E'

# define WALL_PATH "sprites/wall.xpm"
# define FLOOR_PATH "sprites/ground.xpm"
# define COLLECTIBLE_PATH "sprites/coin.xpm"
# define MAP_EXIT_PATH "sprites/exit.xpm"
# define PLAYER_LEFT_PATH "sprites/left.xpm"
# define PLAYER_RIGHT_PATH "sprites/right.xpm"
# define PLAYER_DOWN_PATH "sprites/down.xpm"
# define PLAYER_UP_PATH "sprites/up.xpm"

# define KEY_W              13
# define KEY_A              0
# define KEY_S              1
# define KEY_D              2
# define KEY_ESC            53

typedef struct s_comp
{
	int	exit;
	int	player;
	int	collect;
}	t_comp;

typedef struct t_image
{
	void	*xpm_ptr;
	int		x;
	int		y;
}	t_image;

typedef struct s_coords
{
	int		x;
	int		y;
}	t_coords;

typedef struct s_point
{
	int		x;
	int		y;
	int		dist;
}	t_point;

typedef struct s_game
{
	int			win_condition;
	int			movements;
	size_t		map_x;
	size_t		map_y;
	void		*mlx;
	void		*win;
	char		**map;
	int			direction;
	t_coords	player_pos;
	t_image		player_left;
	t_image		player_right;
	t_image		player_up;
	t_image		player_down;
	t_image		wall;
	t_image		floor;
	t_image		collectible;
	t_image		map_exit;
}	t_game;

//game_exit
void	free_game(t_game *game);
int		close_game(t_game *game);
//input_handling
int		check_win(t_game *game);
void	check_interaction(t_game *game);
int		move_player(int key, t_game *game);
int		key_hook(int key, t_game *game);
//map_check
int		check_rectangular(char **map);
int		check_walls(char **map);
t_comp	*check_comp(t_game *game, char **map);
void	map_check(t_game *game);
//map_parse_utils
void	init_comp(t_comp *comps);
void	throw_error(t_game *game, t_comp *comp, char *msg);
size_t	ft_strstr_len(char **str);
char	**ft_strstrdup(char **str, int size);
void	ft_strstr_free(char **str);
//map_path
int		compare_comps(t_comp *comps1, t_comp *comps2);
void	check_path(char **map, t_comp *comps, int x, int y);
int		find_path(t_game *game, t_comp *comps);
//map_read
int		lines_count(int fd);
char	**read_map(t_game *game, char *map);
//map_utils
void	count_components(t_game *game, char **map, t_comp *comps);
//pictures_parsing
t_image	read_xmp_image(void *mlx, char *file, t_game *game);
int		init_images(t_game *game);
//render
void	render_image(t_game *game, t_image sprite, int x, int y);
void	pick_image(char comp, t_game *game, int x, int y);
void	render_map(t_game *game, char **map);
int		game_loop(t_game *game);

#endif
