#include "../../includes/cub.h"

void	init_images_two(t_cub *cub)
{
	int		x;
	int		y;

	x = 64;
	y = 64;
	cub->textures[WE_TEXT].mlx_img
		= mlx_xpm_file_to_image(cub->mlx, &cub->desc[3][2], &x, &y);
	if (!cub->textures[WE_TEXT].mlx_img)
		end_of_prog(cub, 1);
	cub->textures[WE_TEXT].addr
		= mlx_get_data_addr(cub->textures[WE_TEXT].mlx_img,
			&cub->textures[WE_TEXT].bpp, &cub->textures[WE_TEXT].rowlen,
			&cub->textures[WE_TEXT].end);
	cub->textures[EA_TEXT].mlx_img
		= mlx_xpm_file_to_image(cub->mlx, &cub->desc[2][2], &x, &y);
	if (!cub->textures[EA_TEXT].mlx_img)
		end_of_prog(cub, 1);
	cub->textures[EA_TEXT].addr
		= mlx_get_data_addr(cub->textures[EA_TEXT].mlx_img,
			&cub->textures[EA_TEXT].bpp, &cub->textures[EA_TEXT].rowlen,
			&cub->textures[EA_TEXT].end);
}

void	init_images(t_cub *cub)
{
	int		x;
	int		y;

	x = 64;
	y = 64;
	cub->textures[NO_TEXT].mlx_img = mlx_xpm_file_to_image(cub->mlx,
			&cub->desc[0][2], &x, &y);
	if (!cub->textures[NO_TEXT].mlx_img)
		end_of_prog(cub, 1);
	cub->textures[NO_TEXT].addr
		= mlx_get_data_addr(cub->textures[NO_TEXT].mlx_img,
			&cub->textures[NO_TEXT].bpp, &cub->textures[NO_TEXT].rowlen,
			&cub->textures[NO_TEXT].end);
	cub->textures[SO_TEXT].mlx_img
		= mlx_xpm_file_to_image(cub->mlx, &cub->desc[1][2], &x, &y);
	if (!cub->textures[SO_TEXT].mlx_img)
		end_of_prog(cub, 1);
	cub->textures[SO_TEXT].addr
		= mlx_get_data_addr(cub->textures[SO_TEXT].mlx_img,
			&cub->textures[SO_TEXT].bpp, &cub->textures[SO_TEXT].rowlen,
			&cub->textures[SO_TEXT].end);
	init_images_two(cub);
}
