#include "window.h"
#include "structs.h"
#include "info.h"
#include "thread.h"
#include "parse.h"

static void	key_hook_arrows(int key, t_window *win)
{
	if (key == KEY_ARROW_LEFT)
		(void)win;
	else if (key == KEY_ARROW_RIGHT)
		(void)win;
	else if (key == KEY_ARROW_DOWN)
		(void)win;
	else if (key == KEY_ARROW_UP)
		(void)win;
}

void	move_coordinate(t_vec3 *coor, int key)
{
	if (key == KEY_Q)
		coor->x -= 1;
	else if (key == KEY_W)
		coor->x += 1;
	else if (key == KEY_A)
		coor->y -= 1;
	else if (key == KEY_S)
		coor->y += 1;
	else if (key == KEY_Z)
		coor->z -= 1;
	else if (key == KEY_X)
		coor->z += 1;
}

int	binding_key_events(int key, t_info *info)
{
	t_window	*win;

	win = &(info->win);
	ft_printf("key - %d\n", key);
	if (key == KEY_ESC)
		exit_event(win);
	else if (key == KEY_1 && win->terminal.cam_on == false)
		key_hook_camera(win);
	else if (key == KEY_2 && win->terminal.light_on == false)
		key_hook_light(win, info);
	else if (win->terminal.light_on && win->terminal.light_select == false && \
		(key == KEY_B || key == KEY_N || key == KEY_O || key == KEY_2))
		select_light(key, info);
	else if (win->terminal.light_select && (key == KEY_Q || key == KEY_W || \
		key == KEY_A || key == KEY_S || key == KEY_Z || key == KEY_X))
		move_light(key, info);
	else if (win->terminal.cam_on && (key == KEY_Q || key == KEY_W || \
		key == KEY_A || key == KEY_S || key == KEY_Z || key == KEY_X))
		move_camera(key, info);
	else if (KEY_ARROW_LEFT <= key && key <= KEY_ARROW_UP)
		key_hook_arrows(key, win);
	return (0);
}
