/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 11:26:20 by jlangman          #+#    #+#             */
/*   Updated: 2016/10/05 12:38:29 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define N (e->movex - 0.5)

int		mandelbrot(t_env *e)
{
	e->c_r = (HALFW / HALFH) * (e->x - HALFW) / (e->zoom * HALFW) + N;
	e->c_i = (e->y - HALFH) / (e->zoom * HALFH) + e->movey - N;
	e->nreal = 0;
	e->nimag = 0;
	e->i = 0;
	while (e->i < e->iter)
	{
		e->oreal = e->nreal;
		e->oimag = e->nimag;
		e->nreal = SQRT(e->oreal) - SQRT(e->oimag) + e->c_r;
		e->nimag = 2.0 * e->oreal * e->oimag + e->c_i;
		if (SQRT(e->nreal) + SQRT(e->nimag) > 4)
			return (e->i);
		e->i++;
	}
	return (e->iter);
}

int		julia(t_env *e)
{
	e->nreal = (HALFW / HALFH) * (e->x - HALFW) / (e->zoom * HALFW) + e->movex;
	e->nimag = (e->y - HALFH) / (e->zoom * HALFH) + e->movey;
	e->i = 0;
	while (e->i < e->iter)
	{
		e->oreal = e->nreal;
		e->oimag = e->nimag;
		e->nreal = SQRT(e->oreal) - SQRT(e->oimag) + e->jcr;
		e->nimag = 2.0 * e->oreal * e->oimag + e->jci;
		if (SQRT(e->nreal) + SQRT(e->nimag) > 4)
			return (e->i);
		e->i++;
	}
	return (e->iter);
}

int		tricorn(t_env *e)
{
	e->c_r = (HALFW / HALFH) * (e->x - HALFW) / (e->zoom * HALFW) + N;
	e->c_i = (e->y - HALFH) / (e->zoom * HALFH) + e->movey - 0.5;
	e->nreal = 0;
	e->nimag = 0;
	e->i = 0;
	while (e->i < e->iter)
	{
		e->oreal = e->nreal;
		e->oimag = e->nimag;
		e->nreal = SQRT(e->oreal) - SQRT(e->oimag) + e->c_r;
		e->nimag = -(2.0 * e->oreal * e->oimag + e->c_i);
		if (SQRT(e->nreal) + SQRT(e->nimag) > 4)
			return (e->i);
		e->i++;
	}
	return (e->iter);
}
