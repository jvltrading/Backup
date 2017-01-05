/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 11:25:30 by jlangman          #+#    #+#             */
/*   Updated: 2016/10/27 11:25:33 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

static void		draw_water(t_env *env, int x, int y)
{
	double	t;
	int		r;
	int		g;
	int		b;
	int		xd;
	int		yd;
	int		i;

	i = 0;
	if (env->water[y][x] < 1)
		return ;
	if (y < MAP_SIZE - 1 && x > 0 && env->map[y + 1][x - 1]
			+ env->water[y + 1][x - 1] > env->map[y][x])
		i = env->map[y + 1][x - 1] + env->water[y + 1][x - 1]
			- env->map[y][x] - 1;
	while (i < env->water[y][x])
	{
		b = 255;
		t = (25. - (double)env->water[y][x]) / 25.;
		if (t < 0)
			t = 0;
		r = t * 128;
		g = r;
		xd = get_screen_x(x, y, env->map[y][x] + i + 1);
		yd = get_screen_y(x, y, env->map[y][x] + i + 1);
		pixel_put(env, xd, yd, (r << 16) + (g << 8) + b);
		//pixel_put(env, xd, yd + 1, (r << 16) + (g << 8) + b);
		i++;
	}
}

void			draw(t_env *env)
{
	int		dx;
	int		dy;
	int		y;
	int		x;

	window_reset(env);
	y = 0;
	while (y < MAP_SIZE)
	{
		x = 0;
		while (x < MAP_SIZE)
		{
			dx = get_screen_x(x, y, env->map[y][x]);
			dy = get_screen_y(x, y, env->map[y][x]);
			int togoy;
			if (x == 1 || y == MAP_SIZE - 2)
				togoy = get_screen_y(x, y, 0) - dy;
			else
				togoy = 1;
			int i = 0;
			while (i < togoy)
			{
				pixel_put(env, dx, dy + i, get_map_color(env->map[y][x]));
				pixel_put(env, dx, dy + i + 1, get_map_color(env->map[y][x]));
				pixel_put(env, dx, dy + i + 2, get_map_color(env->map[y][x]));
				pixel_put(env, dx, dy + i + 3, get_map_color(env->map[y][x]));
				i++;
			}
			draw_water(env, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(env->window->mlx, env->window->mlx_window
			, env->window->img, 0, 0);
	char	*str;
	str = env->scenario == RAIN ? "Rain" : (env->scenario == UPRISING ? "Uprising" : (env->scenario == WAVE ? "Wave" : (env->scenario == EMPTYING ? "Emptying" : "Escaping")));
	mlx_string_put(env->window->mlx, env->window->mlx_window, 11, 11, 0, str);
	mlx_string_put(env->window->mlx, env->window->mlx_window, 10, 10, 0xFFFFFF, str);

}
