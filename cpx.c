/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cpx.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgoedkoo <mgoedkoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/30 17:07:06 by mgoedkoo      #+#    #+#                 */
/*   Updated: 2023/06/01 20:37:33 by mgoedkoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_cpx	cpx_add(t_cpx a, t_cpx b)
{
	t_cpx	tmp;

	tmp.r = a.r + b.r;
	tmp.i = a.i + b.i;
	return (tmp);
}

t_cpx	cpx_multi(t_cpx a, t_cpx b)
{
	t_cpx	tmp;

	tmp.r = (a.r * b.r) - (a.i * b.i);
	tmp.i = (a.r * b.i) + (a.i * b.r);
	return (tmp);
}
