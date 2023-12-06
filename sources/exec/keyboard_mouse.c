#include "../../includes/cub.h"


int	keyboard_stuff(int keysym, t_cub *cub)
{
	if (keysym == XK_Escape)
		end_of_prog(cub, 0);
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
	if (keysym == KEY_M && cub->mini->display == 0)
		cub->mini->display = 1;
	else if (keysym == KEY_M && cub->mini->display == 1)
		cub->mini->display = 0;
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
	return (42);
}

// int	mouse_press(int keycode, int x, int y, t_cub *cub)
// {
// 	// (void)keycode;
// 	(void)y;

// 	printf("x : %d\n", x);
// 	if (keycode == 1)
// 	{
// 		cub->mouse_dir = -1;
// 		// cub->mouse_x = x;
// 	}
// 	else if (keycode == 3)
// 	{
// 		cub->mouse_dir = 1;
// 		// cub->mouse_x = x;
// 	}
// 	return (0);
// }

// int	mouse_press(int keycode, int x, int y, t_cub *cub)
// {
// 	(void)keycode;
// 	(void)y;
// 	cub->mouse_press = 1;
// 	cub->mouse_x = x;
// 	return (0);
// }

// int	mouse_release(int keycode, int x, int y, t_cub *cub)
// {
// 	(void)x;
// 	(void)y;
// 	(void)keycode;

// 	// if (keycode == 1)
// 	// 	cub->mouse_dir = 0;
// 	// if (keycode == 1)
// 	cub->mouse_dir = 0;
// 	return (0);
// }

// int	mouse_release(int keycode, int x, int y, t_cub *cub)
// {
// 	(void)x;
// 	(void)y;
// 	(void)keycode;

// 	cub->mouse_press = 0;
// 	return (0);
// }

// int	mouse_move(int keycode, int x, int y, t_cub *cub)
// {
// 	(void)keycode;
// 	(void)y;

// 	printf("x : %d\n", x);
// 	printf("press : %d\n", cub->mouse_press);
// 	if (cub->mouse_press == 1 && x < cub->mouse_x)
// 	{
// 		cub->mouse_dir = -1;
// 		cub->mouse_x = x;
// 	}
// 	else if (cub->mouse_press == 1 && x > cub->mouse_x)
// 	{
// 		cub->mouse_dir = 1;
// 		cub->mouse_x = x;
// 	}
// 	return (0);
// }