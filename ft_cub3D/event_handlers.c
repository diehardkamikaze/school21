/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 10:13:15 by mchau             #+#    #+#             */
/*   Updated: 2021/03/24 09:44:51 by mchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3D.h"

int	exit_handler(void *param)
{
	t_all   *t;

	t = (t_all *)param;

	mlx_destroy_image(t->game.mlx, t->game.img);
	mlx_destroy_window(t->game.mlx, t->game.win);
	free_wrapper(t);
	exit(1);
	return (1);
}

int	key_state_checker(void *param)
{
	t_all		*t;
	t_key_state	*pressed;
	int rerender;

	rerender = 0;
	t = (t_all *)param;
	pressed = &(t->pressed);
	if (pressed->key_w)
		rerender +=handle_moving_ws(1, t);
	if (pressed->key_a)
		rerender +=handle_moving_ad(1, t);
	if (pressed->key_s)
		rerender +=handle_moving_ws(-1, t);
	if (pressed->key_d)
		rerender +=handle_moving_ad(-1, t);
	if (pressed->key_arrow_left)
		rerender +=handle_rotating(1, t);
	if (pressed->key_arrow_right)
		rerender +=handle_rotating(-1, t);
	if (rerender)
	{
		fill_image_by_map(t);
		mlx_put_image_to_window(t->game.mlx, t->game.win, t->game.img, 0, 0);
	}
	return (1);
}

int	key_press_handler(int keycode, void *param)
{
	t_all	*t;
	t = (t_all *)param;

	if (keycode == 53)
		exit_handler(param);
	if (keycode == 2)
		t->pressed.key_d = 1;
	if (keycode == 0)
		t->pressed.key_a = 1;
	if (keycode == 13)
		t->pressed.key_w = 1;
	if (keycode == 1)
		t->pressed.key_s = 1;
	if (keycode == 123)
		t->pressed.key_arrow_left = 1;
	if (keycode == 124)
		t->pressed.key_arrow_right = 1;
	return (1);
}

int	key_release_handler(int keycode, void *param)
{
	t_all	*t;
	t = (t_all *)param;

	if (keycode == 2)
		t->pressed.key_d = 0;
	if (keycode == 0)
		t->pressed.key_a = 0;
	if (keycode == 13)
		t->pressed.key_w = 0;
	if (keycode == 1)
		t->pressed.key_s = 0;
	if (keycode == 123)
		t->pressed.key_arrow_left = 0;
	if (keycode == 124)
		t->pressed.key_arrow_right = 0;
	return (1);
}
