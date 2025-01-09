/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgoedkoo <mgoedkoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/04 16:47:02 by mgoedkoo      #+#    #+#                 */
/*   Updated: 2023/06/06 13:12:38 by mgoedkoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_rainbow(t_vars *v)
{
	v->rainbow[0] = PINK;
	v->rainbow[1] = RED;
	v->rainbow[2] = ORANGE;
	v->rainbow[3] = YELLOW;
	v->rainbow[4] = GRASS;
	v->rainbow[5] = GREEN;
	v->rainbow[6] = CYAN;
	v->rainbow[7] = BLUE;
	v->rainbow[8] = PURPLE;
	v->rainbow[9] = MAGENTA;
}

static void	init_julia(t_vars *v)
{
	if (v->set[6] == '1')
	{
		v->c.r = -0.55;
		v->c.i = -0.4894;
	}
	else if (v->set[6] == '2')
	{
		v->c.r = 0.285;
		v->c.i = 0.01;
	}
	else
	{
		v->c.r = 0;
		v->c.i = 0;
	}
}

void	init_fractal(t_vars *v)
{
	v->img_ptr = mlx_new_image(v->mlx_ptr, WIDTH, HEIGHT);
	if (!v->img_ptr)
		exit_error("mlx_new_image() failed", 0);
	v->img_address = mlx_get_data_addr(v->img_ptr, &v->bits_per_pixel,
			&v->line_size, &v->endian);
	if (!v->img_address)
		exit_error("mlx_get_data_addr() failed", 0);
	v->r_min = -2;
	v->r_max = 2;
	v->i_min = -1.5;
	v->i_max = 1.5;
	init_rainbow(v);
	if (v->set[0] == 'M')
	{
		v->z0.r = 0;
		v->z0.i = 0;
	}
	else
		init_julia(v);
}
