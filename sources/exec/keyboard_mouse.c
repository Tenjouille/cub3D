#include "../../includes/cub.h"


int	keyboard_stuff(int keysym, t_cub *cub)
{
	if (keysym == XK_Escape)
		end_of_prog(cub);
	if (keysym == KEY_W)
		cub->game->key_w = 1;
	if (keysym == KEY_S)
		cub->game->key_s = 1;
	if (keysym == KEY_A)
		cub->game->key_a = 1;
	if (keysym == KEY_D)
		cub->game->key_d = 1;
	if (keysym == KEY_RIGHT)
		cub->game->key_right = 1;
	if (keysym == KEY_LEFT)
		cub->game->key_left = 1;
	else
		return (0);
	return (42);
}

int	keyboard_release(int keysym, t_cub *cub)
{
	if (keysym == KEY_W)
		cub->game->key_w = 0;
	if (keysym == KEY_S)
		cub->game->key_s = 0;
	if (keysym == KEY_A)
		cub->game->key_a = 0;
	if (keysym == KEY_D)
		cub->game->key_d = 0;
	if (keysym == KEY_RIGHT)
		cub->game->key_right = 0;
	if (keysym == KEY_LEFT)
		cub->game->key_left = 0;
	else
		return (0);
	return (42);
}
