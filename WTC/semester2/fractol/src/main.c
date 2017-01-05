/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalaouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 17:32:04 by yalaouf           #+#    #+#             */
/*   Updated: 2016/10/05 12:32:00 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		expose_hook(t_env *e)
{
	if (e->iter < 10)
		e->iter = 10;
	if (e->zoom < 0.5)
		e->zoom = 0.5;
	if (e->movex < -2)
		e->movex = -2;
	if (e->movey < -2)
		e->movey = -2;
	if (e->movex > 2)
		e->movex = 2;
	if (e->movey > 2)
		e->movey = 2;
	draw(e);
	mlx_do_sync(e->mlx);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_string_put(e->mlx, e->win, 10, 10, 0x0FFFFFF, "Iterations: ");
	mlx_string_put(e->mlx, e->win, 130, 10, 0x0FFFFFF, ft_itoa(e->iter));
	mlx_string_put(e->mlx, e->win, 10, 30, 0x0FFFFFF, "Zoom: ");
	mlx_string_put(e->mlx, e->win, 70, 30, 0x0FFFFFF, ft_itoa(e->zoom * 200));
	return (0);
}

int		main(int argc, char **argv)
{
	t_env e;

	if (argc == 1)
	{
		ft_putendl("These are the available fractals:");
		ft_putendl("Mandelbrot (m) and Julia (j) and tricorn (t)");
		ft_putendl("Exemple: ./fractol m for Mandelbrot");
		exit(0);
	}
	if ((e.nbf = parse(argv[1])))
	{
		init(&e);
		e.mlx = mlx_init();
		e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, "fractol");
		e.img = mlx_new_image(e.mlx, WIDTH, HEIGHT);
		e.data = mlx_get_data_addr(e.img, &e.bpp, &e.sl, &e.endian);
		mlx_mouse_hook(e.win, mouse_all, &e);
		mlx_key_hook(e.win, key_hook, &e);
		mlx_hook(e.win, 6, 5, &mouse_moove, &e);
		mlx_expose_hook(e.win, expose_hook, &e);
		mlx_loop(e.mlx);
	}
	return (0);
}
