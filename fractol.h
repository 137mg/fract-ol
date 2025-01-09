/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgoedkoo <mgoedkoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/27 22:26:49 by mgoedkoo      #+#    #+#                 */
/*   Updated: 2023/06/06 13:27:58 by mgoedkoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# define WIDTH 500
# define HEIGHT 375
# define ARG_FORMAT "Required format: [<set>] [opt: <no. of iterations>]\n\
Possible sets: [Mandelbrot] [Julia_1] [Julia_2] [Julia_3]\n\
No. of iterations must be a positive integer\n"
# define BLACK 0x00000000
# define GREY 0x007F7F7F
# define RED 0x00FF0000
# define ORANGE 0x00FF7F00
# define YELLOW 0x00FFFF00
# define GRASS 0x007FFF00
# define GREEN 0x0000FF00
# define CYAN 0x0000FFFF
# define BLUE 0x000000FF
# define PURPLE 0x007F00FF
# define MAGENTA 0x00FF00FF
# define PINK 0x00FF007F

typedef struct s_cpx
{
	double	r;
	double	i;
}	t_cpx;

typedef struct s_vars
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*img_address;
	char			*set;
	int				bits_per_pixel;
	int				line_size;
	int				endian;
	int				rainbow[10];
	unsigned int	colour;
	t_cpx			c;
	t_cpx			z0;
	double			r_min;
	double			r_max;
	double			i_min;
	double			i_max;
	int				iter_max;
}	t_vars;

int		close_window(t_vars *v);
t_cpx	cpx_add(t_cpx a, t_cpx b);
t_cpx	cpx_multi(t_cpx a, t_cpx b);
void	draw_fractal(t_vars *v);
void	exit_error(char *err_msg, int isarg);
void	init_fractal(t_vars *v);
int		key_press(int keycode, t_vars *v);
int		zoom(int button, int x, int y, t_vars *v);

#endif