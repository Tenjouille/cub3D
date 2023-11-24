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
# define MOVESPEED 0.05

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
	double	fov_length;
	double	fov_width;
	double	cur_time;
	double	old_time;
	int		key_w;
	int		key_s;
	int		key_a;
	int		key_d;
}			t_game;

typedef struct s_textures
{
	void	*no;
	void	*so;
	void	*we;
	void	*ea;
}			t_textures;

typedef struct s_cub
{
	void		*mlx;
	void		*win;
	int			window_x;
	int			window_y;
	char		**desc;
	char		**map;
	t_game		*game;
	t_textures	*textures;
	t_img		*img;
}			t_cub;

/*		TOOLS		*/
char	*ft_strnchr(const char *s, int c, int size);
/*		ERRORS		*/
void	ft_map_error_msg(void);
/*		INIT		*/
void	game_init(t_cub *cub);
int		game_loop(t_cub *cub);
/*		DRAW		*/
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
/*		MOVES		*/
void	move_up(t_cub *cub);
void	move_left(t_cub *cub);
void	move_down(t_cub *cub);
void	move_right(t_cub *cub);
#endif