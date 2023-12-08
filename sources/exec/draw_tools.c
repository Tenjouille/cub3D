/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:42:50 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/08 11:42:51 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (y < 0 || y > WINHEIGHT - 1 || x < 0 || x > WINWIDTH - 1)
		return ;
	dst = img->addr + (y * img->rowlen + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	get_color(t_cub *cub, int x, int y, int texture)
{
	(void)texture;
	return (*(int *)(cub->textures[cub->game->texture].addr
		+ (y * cub->textures[cub->game->texture].rowlen + x
			* (cub->textures[cub->game->texture].bpp / 8))));
}

int	get_rgb(int *color)
{
	return (color[0] * 0x10000 + color[1] * 0x100 + color[2]);
}
