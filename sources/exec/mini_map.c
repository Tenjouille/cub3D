#include "../../includes/cub.h"

void	draw_char(t_cub *cub, int x)
{
	int		i;

	i = cub->mini->size_y / 2 + 5;
	while (i <= cub->mini->size_y / 2 + 15)
	{
		if ((x >= cub->window_x - 15 - (cub->mini->size_x / 2)) && (x <= cub->window_x - (cub->mini->size_x / 2) - 5))
			my_mlx_pixel_put(cub->img, x, i, 0x00FF0000);
		i++;
	}
}

// int	get_coords(t_cub *cub, int x, int y)
// {
// 	int		dist_x;
// 	int		dist_y;
// 	double	coord_x;
// 	double	coord_y;
// 	int		real_coord_x;
// 	int		real_coord_y;

// 	dist_x = cub->mini->mini_map_x + cub->mini->size_x / 2 - x;
// 	dist_y = 10 + cub->mini->size_y / 2 - y;
// 	coord_x = cub->game->p_pos_x - dist_x / cub->mini->wall_size - (double)(dist_x % cub->mini->wall_size) / cub->mini->wall_size;
// 	coord_y = cub->game->p_pos_y - dist_y / cub->mini->wall_size - (double)(dist_y % cub->mini->wall_size) / cub->mini->wall_size;
// 	real_coord_x = (int)coord_x;
// 	real_coord_y = (int)coord_y;
// 	// if (x == cub->mini->mini_map_x + 120 && y == cub->mini->mini_map_y - 1)
// 	// {
// 	// 	// printf("wall_size : %d\n", cub->mini->wall_size);
// 	// 	printf("map height : %d \n", cub->map_height);
// 	// 	printf("dist_x : %d\ncoord_x : %f\n", dist_x, coord_x);
// 	// 	printf("dist_y : %d\ncoord_y : %f\n\n", dist_y, coord_y);
// 	// 	printf("real_coord_y : %d\n\n", real_coord_y);
// 	// 	// printf("dist_x / cub->mini->wall_size : %d\n", dist_x / cub->mini->wall_size);
// 	// 	// printf("dist_x %% cub->mini->wall_size : %d\n", dist_x % cub->mini->wall_size);
// 	// }
// 	if (coord_y >= 0 && real_coord_y <= (double)cub->map_height)
// 	{
// 		if (coord_x >= 0 && coord_x <= (double)ft_strlen(cub->map[real_coord_y]))
// 		{
// 			if (cub->map[real_coord_y][real_coord_x] == '1')
// 				return (1);
// 			if (cub->map[real_coord_y][real_coord_x] == 'F' || cub->map[real_coord_y][real_coord_x] == 'N'
// 				|| cub->map[real_coord_y][real_coord_x] == 'S' || cub->map[real_coord_y][real_coord_x] == 'E'
// 					|| cub->map[real_coord_y][real_coord_x] == 'W')
// 				return (2);
// 		}
// 	}
// 	return (0);
// }

int	get_coords(t_cub *cub, int x, int y)
{
	int		dist_x;
	int		dist_y;
	double	coord_x;
	double	coord_y;
	int		real_coord_x;
	int		real_coord_y;
	double	angle;
	double	turn_x;
	double	turn_y;
	int		x_centre;
	int		y_centre;

	if (cub->game->p_ori_y < 0)
		angle = atan(cub->game->p_ori_y / cub->game->p_ori_x);
	else
		angle = -atan(cub->game->p_ori_y / cub->game->p_ori_x);
	x_centre = cub->mini->mini_map_x + cub->mini->size_x / 2;
	y_centre = 10 + cub->mini->size_y / 2;
	turn_x = (x - x_centre) * cos(angle) + (y - y_centre) * sin(angle) + x_centre;
	turn_y = -((x - x_centre) * sin(angle)) + (y - y_centre) * cos(angle) + y_centre;
	dist_x = cub->mini->mini_map_x + cub->mini->size_x / 2 - (int)turn_x;
	dist_y = 10 + cub->mini->size_y / 2 - (int)turn_y;
	coord_x = cub->game->p_pos_x - dist_x / cub->mini->wall_size - (double)(dist_x % cub->mini->wall_size) / cub->mini->wall_size;
	coord_y = cub->game->p_pos_y - dist_y / cub->mini->wall_size - (double)(dist_y % cub->mini->wall_size) / cub->mini->wall_size;
	real_coord_x = (int)coord_x;
	real_coord_y = (int)coord_y;
	if (x == cub->mini->mini_map_x + 120 && y == cub->mini->mini_map_y - 1)
	{
		// printf("wall_size : %d\n", cub->mini->wall_size);
		// printf("map height : %d \n", cub->map_height);
		// printf("dist_x : %d\ncoord_x : %f\n", dist_x, coord_x);
		// printf("dist_y : %d\ncoord_y : %f\n\n", dist_y, coord_y);
		// printf("real_coord_y : %d\n\n", real_coord_y);
		// printf("dist_x / cub->mini->wall_size : %d\n", dist_x / cub->mini->wall_size);
		// printf("dist_x %% cub->mini->wall_size : %d\n", dist_x % cub->mini->wall_size);
	}
	if (coord_y >= 0 && real_coord_y <= (double)cub->map_height)
	{
		if (coord_x >= 0 && coord_x <= (double)ft_strlen(cub->map[real_coord_y]))
		{
			if (cub->map[real_coord_y][real_coord_x] == '1')
				return (1);
			if (cub->map[real_coord_y][real_coord_x] == 'F' || cub->map[real_coord_y][real_coord_x] == 'N'
				|| cub->map[real_coord_y][real_coord_x] == 'S' || cub->map[real_coord_y][real_coord_x] == 'E'
					|| cub->map[real_coord_y][real_coord_x] == 'W')
				return (2);
		}
	}
	return (0);
}

void	draw_mini_map(t_cub *cub, int x)
{
	int		y;
	int		coords;

	y = 10;
	coords = 0;
	cub->mini->size_y = cub->mini->mini_map_y - 10;
	cub->mini->size_x = cub->window_x - 10 - cub->mini->mini_map_x;
	cub->mini->wall_size = cub->mini->size_x / MINIRATIO;
	cub->mini->map_x = (int)cub->game->p_pos_x;
	cub->mini->map_y = (int)cub->game->p_pos_y;
	// printf("p_pos_y : %f\n", cub->game->p_pos_y);
	// printf("map_y : %d\n", cub->mini->map_y);
	while (y <= cub->mini->mini_map_y && x >= cub->mini->mini_map_x && x <= cub->window_x - 10)
	{
		coords = get_coords(cub, x, y);
		if (coords == 1)
			my_mlx_pixel_put(cub->img, x, y, 0x0000FF00);
		else if (coords == 2)
			my_mlx_pixel_put(cub->img, x, y, 0x00555455);
		else
			my_mlx_pixel_put(cub->img, x, y, 0x00000000);
		y++;
	}
	draw_char(cub, x);
}

// // Exemple de pseudo-code pour la rotation d'une image
// void rotateImage(void *src_image, int src_width, int src_height, void *dst_image, int dst_width, int dst_height, double angle) {
//     // Convertir l'angle en radians
//     double radians = angle * (M_PI / 180.0);

//     // Parcourir chaque pixel de la nouvelle image
//     for (int y = 0; y < dst_height; y++) {
//         for (int x = 0; x < dst_width; x++) {
//             // Appliquer la formule de rotation inverse pour obtenir les coordonnées dans l'image originale
//             double src_x = cos(-radians) * (x - dst_width / 2.0) - sin(-radians) * (y - dst_height / 2.0) + src_width / 2.0;
//             double src_y = sin(-radians) * (x - dst_width / 2.0) + cos(-radians) * (y - dst_height / 2.0) + src_height / 2.0;

//             // Utiliser des méthodes d'interpolation pour obtenir les valeurs des pixels dans la nouvelle image
//             // Copier les valeurs des pixels de l'image d'origine dans la nouvelle image
//             // Assurez-vous de gérer les cas où les coordonnées sont en dehors des limites de l'image
//         }
//     }
// }
