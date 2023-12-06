#ifndef CUB_H
# define CUB_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"
# include "get_next_line.h"

# define KEY_W 119
# define KEY_A 97
# define KEY_D 100
# define KEY_S 115
# define KEY_M 109
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# define NO_TEXT 0
# define SO_TEXT 1
# define WE_TEXT 2
# define EA_TEXT 3

# define WINWIDTH 1920
# define WINHEIGHT 1080
# define TEXWIDTH 100
# define TEXHEIGHT 100

# define MOVESPEED 0.05
# define ROTSPEED 0.02

# define MINIRATIO 10

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		rowlen;
	int		end;
}			t_img;

typedef struct s_game
{
	double	p_pos_x;
	double	p_pos_y;
	double	p_ori_x;
	double	p_ori_y;
	double	plane_x;
	double	plane_y;
	double	cur_time;
	double	old_time;
	int		key_w;
	int		key_s;
	int		key_a;
	int		key_d;
	int		key_right;
	int		key_left;
	int		texture;
}			t_game;

typedef struct s_textures
{
	t_img	*no;
	t_img	*so;
	t_img	*we;
	t_img	*ea;
}			t_textures;

typedef	struct s_ray
{
	double	camera;
	double	diray_x;
	double	diray_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	ray_length;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	double	wall_x;
	int		tex_x;
	double	step;
	double	tex_pos;
	int		draw_start;
	int		draw_end;
}			t_ray;

typedef	struct s_mini
{
	int			size_x;
	int			size_y;
	int			wall_size;
	int			mini_map_x;
	int			mini_map_y;
	int			map_x;
	int			map_y;
	int			display;
	int			dist_x;
	int			dist_y;
	double		coord_x;
	double		coord_y;
	int			real_coord_x;
	int			real_coord_y;
}			t_mini;

typedef struct s_cub
{
	void		*mlx;
	void		*win;
	int			window_x;
	int			window_y;
	char		**desc;
	t_game		*game;
	t_img		textures[4];
	t_img		*img;
	t_ray		*ray;
	int			floor[4];
	int			ceiling[4];
	char		**map;
	t_mini		*mini;
	t_img		*mini_img;
	int			map_height;
	int			mouse_x;
	double		rotation_speed;
}			t_cub;

/*		TOOLS		*/
char	*ft_strnchr(const char *s, int c, int size);
int		ft_strcount(char *str, char *to_count);
int		ft_empty_line(char *str);
int		ft_is_char(char c, char *charset);
int		ft_is_char(char c, char *charset);
/*		ERRORS		*/
void	ft_map_error_msg(void);
/*		INIT		*/
int		game_init(t_cub *cub);
void	cub_init(t_cub *cub);
int		game_loop(t_cub *cub);
void	init_values(t_cub *cub);
void	get_first_orientation(t_cub *cub, char c);
void	init_images(t_cub *cub);
/*		DRAW		*/
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	draw_textures(t_cub *cub, t_ray *ray, int x);
void	draw_lines(t_cub *cub, int line_height, int side, int x);
int		get_rgb(int *color);
void	draw_mini_map(t_cub *cub, int x);
int		get_color(t_cub *cub, int x, int y, int texture);
/*		MOVES		*/
int		keyboard_stuff(int keysym, t_cub *cub);
int		keyboard_release(int keysym, t_cub *cub);
void	move_up(t_cub *cub);
void	move_left(t_cub *cub);
void	move_down(t_cub *cub);
void	move_right(t_cub *cub);
void	rotate_right(t_cub *cub);
void	rotate_left(t_cub *cub);
/*		RAYCASTING		*/
void	ray_cast(t_cub *cub);
/*		FILE_CUB	*/
char	*ft_strdup_better(char *str);
char	**ft_sorting_tab(char **unsort, char **res);
char	**ft_sort_desc(char	**unsort);
int		ft_desclen(char *desc);
char	**ft_get_desc(char *file);
/*		PARSING		*/
int		ft_parsing(int ac, char **av, t_cub *cub);
int		ft_find_not_digit(char *str);
int		ft_check_texture_path(char *path);
int		ft_check_nsew(char *desc, char *dir);
int		ft_check_color(char *color, char FC, t_cub *cub);
int		ft_check_fc(char *desc, char FC, t_cub *cub);
int		ft_scan_desc(char **desc, t_cub *cub);
int		ft_scan_map(char **map, t_cub *cub);
int		ft_fill_map(char **map, int x, int y);
// /*		MEMORY_MANAGER		*/
int		free_mlx(t_cub *cub);
/*		MAIN		*/
char	**ft_get_map(t_cub *cub, char **desc);
int		ft_argv_parsing(int ac, char **av);
int		keyboard_stuff(int keysym, t_cub *cub);
int		end_of_prog(t_cub *cub, int ret);

#endif