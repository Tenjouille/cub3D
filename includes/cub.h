/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:22:31 by tbourdea          #+#    #+#             */
/*   Updated: 2023/11/21 12:47:14 by tbourdea         ###   ########.fr       */
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
# include "get_next_line.h"

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
	t_img	img;
}			t_cub;

/*		TOOLS		*/
void	ft_putstr_fd(char *txt, int fd);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strnchr(const char *s, int c, int size);

#endif