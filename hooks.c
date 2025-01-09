/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgoedkoo <mgoedkoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/29 16:01:37 by mgoedkoo      #+#    #+#                 */
/*   Updated: 2023/06/04 20:37:12 by mgoedkoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_vars *v)
{
	mlx_destroy_window(v->mlx_ptr, v->win_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}

static void	move_arrows(int keycode, t_vars *v)
{
	if (keycode == 123)
	{
		v->r_min -= 10 * fabs(v->r_max - v->r_min) / WIDTH;
		v->r_max -= 10 * fabs(v->r_max - v->r_min) / WIDTH;
	}
	else if (keycode == 124)
	{
		v->r_min += 10 * fabs(v->r_max - v->r_min) / WIDTH;
		v->r_max += 10 * fabs(v->r_max - v->r_min) / WIDTH;
	}
	else if (keycode == 125)
	{
		v->i_min += 10 * fabs(v->i_max - v->i_min) / WIDTH;
		v->i_max += 10 * fabs(v->i_max - v->i_min) / WIDTH;
	}
	else
	{
		v->i_min -= 10 * fabs(v->i_max - v->i_min) / WIDTH;
		v->i_max -= 10 * fabs(v->i_max - v->i_min) / WIDTH;
	}
}

int	key_press(int keycode, t_vars *v)
{
	if (keycode == 53)
		close_window(v);
	if (!(keycode >= 123 && keycode <= 126))
		return (0);
	move_arrows(keycode, v);
	draw_fractal(v);
	return (0);
}

int	zoom(int button, int x, int y, t_vars *v)
{
	(void)x;
	(void)y;
	if (button != 4 && button != 5)
		return (0);
	if (button == 4)
	{
		v->r_min -= 10 * fabs(v->r_max - v->r_min) / WIDTH;
		v->r_max += 10 * fabs(v->r_max - v->r_min) / WIDTH;
		v->i_min -= 10 * fabs(v->i_max - v->i_min) / WIDTH;
		v->i_max += 10 * fabs(v->i_max - v->i_min) / WIDTH;
	}
	else
	{
		v->r_min += 10 * fabs(v->r_max - v->r_min) / WIDTH;
		v->r_max -= 10 * fabs(v->r_max - v->r_min) / WIDTH;
		v->i_min += 10 * fabs(v->i_max - v->i_min) / WIDTH;
		v->i_max -= 10 * fabs(v->i_max - v->i_min) / WIDTH;
	}
	draw_fractal(v);
	return (0);
}
