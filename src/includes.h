/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwadie-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:20:08 by jwadie-a          #+#    #+#             */
/*   Updated: 2024/01/02 21:23:39 by jwadie-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# include <stdarg.h>
# include <errno.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

# define TRUE					1
# define FALSE					0

# define EMPTY_MAP				1
# define EMPTY_LINE				2
# define UNRECOGNIZED			3
# define NOT_RECTANGULAR		4
# define MAP_TOO_LARGE			5
# define NOT_SURROUNDED			6
# define MISSING_COMPONENT		7
# define DUPLICATE				8
# define NO_VALID_PATH			9
# define VALID_MAP				0

# define NO_ERROR				0
# define MLX_PTR_FAIL			1
# define WIN_PTR_FAIL			2
# define SPRITES_FAIL			3
# define DIGITS_FAIL			4

# define COMPONENTS				"01PCE<>v^\n"
# define ESSENTIAL_COMPONENTS	"1PCE"
# define ACCESSIBLE				"0XC<^>v"
# define ENEMY_DIRECTIONS		"<^>v"
# define ENEMY_CHAR				'X'
# define WALL_CHAR				'1'
# define COLLECTIBLE_CHAR		'C'
# define FLOOR_CHAR				'0'
# define PLAYER_CHAR			'P'
# define EXIT_CHAR				'E'

# define TILE_LENGTH			32

# define DEATH_RIGHT_0_XPM		"./assets/sprites/death/death_right_0.xpm"
# define DEATH_RIGHT_1_XPM		"./assets/sprites/death/death_right_1.xpm"
# define DEATH_RIGHT_2_XPM		"./assets/sprites/death/death_right_2.xpm"
# define DEATH_RIGHT_3_XPM		"./assets/sprites/death/death_right_3.xpm"
# define DEATH_RIGHT_4_XPM		"./assets/sprites/death/death_right_4.xpm"
# define DEATH_RIGHT_5_XPM		"./assets/sprites/death/death_right_5.xpm"
# define DEATH_LEFT_0_XPM		"./assets/sprites/death/death_left_0.xpm"
# define DEATH_LEFT_1_XPM		"./assets/sprites/death/death_left_1.xpm"
# define DEATH_LEFT_2_XPM		"./assets/sprites/death/death_left_2.xpm"
# define DEATH_LEFT_3_XPM		"./assets/sprites/death/death_left_3.xpm"
# define DEATH_LEFT_4_XPM		"./assets/sprites/death/death_left_4.xpm"
# define DEATH_LEFT_5_XPM		"./assets/sprites/death/death_left_5.xpm"
# define DEATH_SP_COUNT			12

# define P_RIGHT_0_XPM			"./assets/sprites/player/player_right_0.xpm"
# define P_RIGHT_1_XPM			"./assets/sprites/player/player_right_1.xpm"
# define P_RIGHT_2_XPM			"./assets/sprites/player/player_right_2.xpm"
# define P_RIGHT_3_XPM			"./assets/sprites/player/player_right_3.xpm"
# define P_LEFT_0_XPM			"./assets/sprites/player/player_left_0.xpm"
# define P_LEFT_1_XPM			"./assets/sprites/player/player_left_1.xpm"
# define P_LEFT_2_XPM			"./assets/sprites/player/player_left_2.xpm"
# define P_LEFT_3_XPM			"./assets/sprites/player/player_left_3.xpm"
# define PLAYER_SP_COUNT		8

# define E_RIGHT_IDLE_0_XPM		"./assets/sprites/enemy/enemy_right_idle_0.xpm"
# define E_RIGHT_IDLE_1_XPM		"./assets/sprites/enemy/enemy_right_idle_1.xpm"
# define E_RIGHT_IDLE_2_XPM		"./assets/sprites/enemy/enemy_right_idle_2.xpm"
# define E_RIGHT_IDLE_3_XPM		"./assets/sprites/enemy/enemy_right_idle_3.xpm"
# define E_RIGHT_RUN_0_XPM		"./assets/sprites/enemy/enemy_right_run_0.xpm"
# define E_RIGHT_RUN_1_XPM		"./assets/sprites/enemy/enemy_right_run_1.xpm"
# define E_RIGHT_RUN_2_XPM		"./assets/sprites/enemy/enemy_right_run_2.xpm"
# define E_RIGHT_RUN_3_XPM		"./assets/sprites/enemy/enemy_right_run_3.xpm"
# define E_RIGHT_RUN_4_XPM		"./assets/sprites/enemy/enemy_right_run_4.xpm"
# define E_RIGHT_RUN_5_XPM		"./assets/sprites/enemy/enemy_right_run_5.xpm"
# define E_LEFT_IDLE_0_XPM		"./assets/sprites/enemy/enemy_left_idle_0.xpm"
# define E_LEFT_IDLE_1_XPM		"./assets/sprites/enemy/enemy_left_idle_1.xpm"
# define E_LEFT_IDLE_2_XPM		"./assets/sprites/enemy/enemy_left_idle_2.xpm"
# define E_LEFT_IDLE_3_XPM		"./assets/sprites/enemy/enemy_left_idle_3.xpm"
# define E_LEFT_RUN_0_XPM		"./assets/sprites/enemy/enemy_left_run_0.xpm"
# define E_LEFT_RUN_1_XPM		"./assets/sprites/enemy/enemy_left_run_1.xpm"
# define E_LEFT_RUN_2_XPM		"./assets/sprites/enemy/enemy_left_run_2.xpm"
# define E_LEFT_RUN_3_XPM		"./assets/sprites/enemy/enemy_left_run_3.xpm"
# define E_LEFT_RUN_4_XPM		"./assets/sprites/enemy/enemy_left_run_4.xpm"
# define E_LEFT_RUN_5_XPM		"./assets/sprites/enemy/enemy_left_run_5.xpm"
# define ENEMY_SP_COUNT			20	

# define COLLECTIBLE_0_XPM		"./assets/sprites/collectible/collectible_0.xpm"
# define COLLECTIBLE_1_XPM		"./assets/sprites/collectible/collectible_1.xpm"
# define COLLECTIBLE_2_XPM		"./assets/sprites/collectible/collectible_2.xpm"
# define COLLECTIBLE_3_XPM		"./assets/sprites/collectible/collectible_3.xpm"
# define COLLECTIBLE_SP_COUNT	4

# define FLOOR_XPM				"./assets/sprites/other/floor.xpm"
# define WALL_XPM				"./assets/sprites/other/wall.xpm"
# define EXIT_CLOSED_XPM		"./assets/sprites/other/exit_closed.xpm"
# define EXIT_OPEN_XPM			"./assets/sprites/other/exit_open.xpm"
# define OTHER_SP_COUNT			4

# define DISP_0_XPM				"./assets/digits/0.xpm"
# define DISP_1_XPM				"./assets/digits/1.xpm"
# define DISP_2_XPM				"./assets/digits/2.xpm"
# define DISP_3_XPM				"./assets/digits/3.xpm"
# define DISP_4_XPM				"./assets/digits/4.xpm"
# define DISP_5_XPM				"./assets/digits/5.xpm"
# define DISP_6_XPM				"./assets/digits/6.xpm"
# define DISP_7_XPM				"./assets/digits/7.xpm"
# define DISP_8_XPM				"./assets/digits/8.xpm"
# define DISP_9_XPM				"./assets/digits/9.xpm"

# define FLOOR_INDEX			0
# define WALL_INDEX				1
# define EXIT_CLOSED_INDEX		2
# define EXIT_OPEN_INDEX		3
# define COLLECTIBLE_INDEX		0
# define PLAYER_RIGHT_INDEX		0
# define PLAYER_LEFT_INDEX		4
# define ENEMY_RIGHT_IDLE_INDEX	0
# define ENEMY_RIGHT_RUN_INDEX	4
# define ENEMY_LEFT_IDLE_INDEX	10
# define ENEMY_LEFT_RUN_INDEX	14
# define DEATH_RIGHT_INDEX		0
# define DEATH_LEFT_INDEX		6

# define P_RENDER_INTERVAL		10000
# define C_RENDER_INTERVAL		10000
# define E_IDLE_RENDER_INTERVAL	10000
# define E_RUN_RENDER_INTERVAL	10000
# define ENEMY_RUN_PERIOD		50000			
# define ENEMY_REST_PERIOD		50000
# define DEATH_RENDER_INTERVAL	20000

# define KEY_ESC				65307
# define KEY_LEFT				65361
# define KEY_UP					65362
# define KEY_RIGHT				65363
# define KEY_DOWN				65364
# define KEY_W					119
# define KEY_A					97
# define KEY_S					115
# define KEY_D					100

# define OPEN					0
# define CLOSED					1

# define LEFT					1
# define RIGHT					2
# define UP						3
# define DOWN					4

# define IDLE					0
# define RUNNING				1

# define PLAYER_SPRITES			1
# define ENEMY_SPRITES			2
# define COLLECTIBLE_SPRITES	3
# define OTHER_SPRITES			4
# define DEATH_SPRITES			5
# define DIGITS					6

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_render
{
	t_point			point;
	struct s_render	*next;
}	t_render;

typedef struct s_enemy
{
	t_point			position;
	t_point			destination;
	int				status;
	int				direction;
	int				orientation;
	int				offset;
	size_t			counter;
	struct s_enemy	*next;
}	t_enemy;

typedef struct s_map
{
	char		*line_map;
	char		**map;
	int			width;
	int			height;
	int			collectibles;
	t_enemy		*enemies;
	t_point		player;
	t_point		exit;
}	t_map;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*player_sprites[PLAYER_SP_COUNT];
	void		*collectible_sprites[COLLECTIBLE_SP_COUNT];
	void		*death_sprites[DEATH_SP_COUNT];
	void		*enemy_sprites[ENEMY_SP_COUNT];
	void		*other_sprites[OTHER_SP_COUNT];
	void		*digits[10];
	t_map		*map;
	t_render	*points_to_render;
	int			render;
	int			game_lost;
	int			exit_status;
	int			orientation;
	size_t		counter;
	size_t		moves;
}	t_game;

void	parse_map_file(char *map_file, t_map *map);
void	parse_enemies(t_map *map);
void	ft_mlx_init(t_game *game);
int		load_sprites(t_game *game);
int		load_enemy_sprites(t_game *game);
int		load_death_sprites(t_game *game);
void	destroy_images(t_game *game, int i, int type);
int		handle_keypress(int keysym, t_game *game);
void	update_enemies_status(t_game *game);
void	render_enemies(t_game *game);
void	render_frame(t_game *game);
int		check_render(t_game *t_game);
void	die(t_game *game);
void	lose_game(t_game *game);
void	win_game(t_game *game);

int		close_game(t_game *game);
int		get_index(t_game *game, char c);
int		get_enemy_index(t_enemy *enemy);
void	free_2d(char **arr);
char	*replace_char(char *string, char replace, char c);

int		check_empty(t_map *map);
int		check_components(t_map *map);
int		check_rectangular(t_map *map);
int		check_large_map(t_map *map);
int		check_surrounding(t_map *map);
int		check_missing_components(t_map *map);
int		check_duplicates(t_map *map);
int		check_valid_path(t_map *map);

void	append_to_render(t_game *game, t_point point);
void	clear_render_list(t_render **list);
void	clear_node(t_render **list, t_render *node);

t_point	get_enemy_destination(t_point position, int direction);
void	append_to_enemy_list(t_enemy **list, int x, int y, int direction);
void	clear_enemy_list(t_enemy **list);

#endif
