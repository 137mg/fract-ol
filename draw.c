/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgoedkoo <mgoedkoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/29 15:57:18 by mgoedkoo      #+#    #+#                 */
/*   Updated: 2023/06/06 12:45:26 by mgoedkoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pixel_put(t_vars *v, int x, int y)
{
	char	*dst;
	int		offset;

	offset = y * v->line_size + x * (v->bits_per_pixel / 8);
	dst = v->img_address + offset;
	*(unsigned int *)dst = v->colour;
}

static void	make_colour(t_vars *v, int iter)
{
	int	j;

	if (iter == 0)
	{
		v->colour = GREY;
		return ;
	}
	if (iter == v->iter_max)
	{
		v->colour = BLACK;
		return ;
	}
	j = 0;
	while (j < 10)
	{
		if (iter % 10 == j)
		{
			v->colour = v->rainbow[j];
			break ;
		}
		j++;
	}
}

static void	decide_colour(t_vars *v, int x, int y)
{
	t_cpx	tmp;
	t_cpx	z;
	int		n;

	tmp.r = (x * (v->r_max - v->r_min)) / WIDTH + v->r_min;
	tmp.i = (y * (v->i_max - v->i_min) * -1) / HEIGHT - v->i_min;
	if (v->set[0] == 'M')
		v->c = tmp;
	else
		v->z0 = tmp;
	z = v->z0;
	n = 0;
	while (n < v->iter_max)
	{
		if (pow(z.r, 2) + pow(z.i, 2) > 4)
			break ;
		z = cpx_multi(z, z);
		z = cpx_add(z, v->c);
		n++;
	}
	make_colour(v, n);
}

void	draw_fractal(t_vars *v)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			decide_colour(v, x, y);
			my_pixel_put(v, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->img_ptr, 0, 0);
}
