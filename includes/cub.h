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
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# define NO_TEXT 0
# define SO_TEXT 1
# define WE_TEXT 2
# define EA_TEXT 3

# define WINWIDTH 1920
# define WINHEIGHT 1080
# define TEXWIDTH 64
# define TEXHEIGHT 64

# define MOVESPEED 0.05
# define ROTSPEED 0.02

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
}			t_cub;

/*		TOOLS		*/
char	*ft_strnchr(const char *s, int c, int size);
int		ft_empty_line(char *str);
int		ft_is_char(char c, char *charset);
int		ft_is_char(char c, char *charset);
/*		ERRORS		*/
void	ft_map_error_msg(void);
/*		INIT		*/
void	game_init(t_cub *cub);
int		game_loop(t_cub *cub);
void	init_values(t_cub *cub);
void	get_first_orientation(t_cub *cub, char c);
/*		DRAW		*/
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	draw_textures(t_cub *cub, t_ray *ray, int x);
void	draw_lines(t_cub *cub, int line_height, int side, int x);
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
int		ft_check_NSEW(char **desc, char *dir);
int		ft_check_color(char *color, char FC, t_cub *cub);
int		ft_check_FC(char **desc, char FC, t_cub *cub);
int		ft_scan_desc(char **desc, t_cub *cub);
int		ft_scan_map(char **map, t_cub *cub);
// /*		MEMORY_MANAGER		*/
// void	free_list(t_mem *list_ptr);
// void	ft_list_remove_if(t_mem **begin_list, void *data_ref);
// void	ft_free(t_mem **memory, void *data);
// void	ft_memclear(t_mem **lst, int stop);
// void	exit_failure_malloc(void *data);
// t_mem	*ft_create_elem(void *data);
// void	ft_list_push_back(t_mem **begin_list, void *data);
// void	*malloc(size_t size, int clear, int clear_one, void *data);
/*		MAIN		*/
char	**ft_get_map(char **desc);
int		ft_argv_parsing(int ac, char **av);
int		keyboard_stuff(int keysym, t_cub *cub);
int		end_of_prog(t_cub *cub);

#endif