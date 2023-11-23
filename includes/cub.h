/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:22:31 by tbourdea          #+#    #+#             */
/*   Updated: 2023/11/23 17:02:02 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

// typedef struct s_mem
// {
// 	void				*data;
// 	struct s_mem		*next;
// }						t_mem;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		rowlen;
	int		end;
}			t_img;

typedef struct s_cub
{
	void	*mlx;
	void	*win;
	char	**desc;
	int		floor[4];
	int		ceiling[4];
	char	**map;
	t_img	img;
}			t_cub;

/*		TOOLS		*/
char	*ft_strnchr(const char *s, int c, int size);
int		ft_empty_line(char *str);
/*		ERRORS		*/
void	ft_map_error_msg(void);
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