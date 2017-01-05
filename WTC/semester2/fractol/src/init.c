/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalaouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 20:23:25 by yalaouf           #+#    #+#             */
/*   Updated: 2016/04/27 20:49:24 by yalaouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init(t_env *e)
{
	e->i = 0;
	e->c_r = 0;
	e->c_i = 0;
	e->nreal = 0;
	e->oreal = 0;
	e->nimag = 0;
	e->oimag = 0;
	e->iter = 20;
	e->zoom = 0.5;
	e->movex = 0;
	e->movey = 0;
	e->x = 0;
	e->y = 0;
	e->jcr = -0.7;
	e->jci = 0.27015;
	e->color = 0x0000000;
}
