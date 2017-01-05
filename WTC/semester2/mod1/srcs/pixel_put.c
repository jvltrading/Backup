/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 11:30:23 by jlangman          #+#    #+#             */
/*   Updated: 2016/10/27 11:30:39 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

void	pixel_put(t_env *env, int x, int y, int color)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned int	c;

	c = mlx_get_color_value(env->window->mlx, color);
	r = (color & 0xFF0000) >> 16;
	g = (color & 0x00FF00) >> 8;
	b = (color & 0x0000FF);
	if (x >= 0 && x < env->window->width
			&& y >= 0 && y < env->window->height)
	{
		env->window->data[y * env->window->width * env->window->bpp / 8
			+ env->window->bpp / 8 * x] = b;
		env->window->data[y * env->window->width * env->window->bpp / 8
			+ env->window->bpp / 8 * x + 1] = g;
		env->window->data[y * env->window->width * env->window->bpp / 8
			+ env->window->bpp / 8 * x + 2] = r;
	}
}
