/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 11:24:48 by jlangman          #+#    #+#             */
/*   Updated: 2016/10/05 12:31:25 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hook(int keycode, t_env *e)
{
	if (keycode == EXIT)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
	if (keycode == STAR)
		e->iter += 20;
	if (keycode == SLASH)
		e->iter -= 20;
	if (keycode == PLUS)
		e->zoom *= 1.1;
	if (keycode == MOINS)
		e->zoom /= 1.1;
	if (keycode == UP)
		e->movey -= 0.1;
	if (keycode == DOWN)
		e->movey += 0.1;
	if (keycode == LEFT)
		e->movex -= 0.1;
	if (keycode == RIGHT)
		e->movex += 0.1;
	expose_hook(e);
	return (0);
}

int		mouse_all(int keycode, int x, int y, t_env *e)
{
	if (keycode == SCROLL_UP)
		e->zoom *= 1.1;
	if (keycode == SCROLL_DOWN)
		e->zoom /= 1.1;
	if (keycode == LEFT_CLICK || keycode == SCROLL_UP || keycode == SCROLL_DOWN)
	{
		e->movex = (HALFW / HALFH) * (x - HALFW) / (e->zoom * HALFW) + e->movex;
		e->movey = (y - HALFH) / (e->zoom * HALFH) + e->movey;
		expose_hook(e);
	}
	return (0);
}

int		mouse_moove(int x, int y, t_env *e)
{
	if (e->nbf == 2)
	{
		e->jcr = (x - HALFW) / HALFW;
		e->jci = (y - HALFH) / HALFH;
		expose_hook(e);
	}
	return (0);
}
