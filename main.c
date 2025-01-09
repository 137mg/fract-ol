/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgoedkoo <mgoedkoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/19 20:46:05 by mgoedkoo      #+#    #+#                 */
/*   Updated: 2023/06/06 13:10:12 by mgoedkoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	exit_error(char *err_msg, int isarg)
{
	ft_printf(2, "Error: %s\n"ARG_FORMAT, err_msg);
	if (isarg == 1)
		ft_printf(2, ARG_FORMAT);
	exit(EXIT_FAILURE);
}

static int	check_set(char *set)
{
	if (ft_strncmp(set, "Mandelbrot", 11) == 0)
		return (1);
	if (ft_strncmp(set, "Julia_1", 8) == 0)
		return (1);
	if (ft_strncmp(set, "Julia_2", 8) == 0)
		return (1);
	if (ft_strncmp(set, "Julia_3", 8) == 0)
		return (1);
	return (0);
}

static void	check_param(int argc, char **argv)
{
	if (argc != 2 && argc != 3)
		exit_error("Wrong number of arguments (1 required, 2 max)", 1);
	if (check_set(argv[1]) == 0)
		exit_error("Invalid set name", 1);
	if (argc == 3 && ft_atoi(argv[2]) <= 0)
		exit_error("Invalid no. of iterations", 1);
}

int	main(int argc, char **argv)
{
	t_vars	v;

	check_param(argc, argv);
	v.set = argv[1];
	if (argv[2])
		v.iter_max = ft_atoi(argv[2]);
	else
		v.iter_max = 100;
	v.mlx_ptr = mlx_init();
	if (!v.mlx_ptr)
		exit_error("mlx_init() failed", 0);
	v.win_ptr = mlx_new_window(v.mlx_ptr, WIDTH, HEIGHT, argv[1]);
	if (!v.win_ptr)
		exit_error("mlx_new_window() failed", 0);
	init_fractal(&v);
	draw_fractal(&v);
	mlx_hook(v.win_ptr, 4, (1L << 2), zoom, &v);
	mlx_hook(v.win_ptr, 2, (1L << 0), key_press, &v);
	mlx_hook(v.win_ptr, 17, (1L << 5), close_window, &v);
	mlx_loop(v.mlx_ptr);
	return (0);
}
