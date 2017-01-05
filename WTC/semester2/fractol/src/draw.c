/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalaouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 20:29:15 by yalaouf           #+#    #+#             */
/*   Updated: 2016/10/05 12:24:26 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_pixel_to_image(t_env *e, int color)
{
	unsigned char	color1;
	unsigned char	color2;
	unsigned char	color3;

	color1 = color >> 0;
	color2 = color >> 8;
	color3 = color >> 16;
	e->data[e->y * e->sl + e->x * e->bpp / 8] = color1;
	e->data[e->y * e->sl + e->x * e->bpp / 8 + 1] = color2;
	e->data[e->y * e->sl + e->x * e->bpp / 8 + 2] = color3;
}

int		colorrgb(int red, int green, int blue)
{
	return ((red & 0xff) << 16) + ((green & 0xff) << 8) + (blue & 0xff);
}

int		choose_fractal(t_env *e)
{
	int i;

	i = 0;
	if (e->nbf == 1)
		i = mandelbrot(e);
	if (e->nbf == 2)
		i = julia(e);
	if (e->nbf == 3)
		i = tricorn(e);
	return (i);
}

void	draw(t_env *e)
{
	e->y = 0;
	while (e->y < HEIGHT)
	{
		e->x = 0;
		while (e->x < WIDTH)
		{
			e->i = choose_fractal(e);
			if (e->i == e->iter)
				mlx_pixel_to_image(e, 0);
			else
			{
				e->color = colorrgb(0, e->i * 255 / e->iter, 0);
				mlx_pixel_to_image(e, e->color);
			}
			e->x++;
		}
		e->y++;
	}
}
