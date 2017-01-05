/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 11:28:56 by jlangman          #+#    #+#             */
/*   Updated: 2016/10/27 11:29:23 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

int		main(int ac, char **av)
{
	t_env	env;

	if (ac != 3)
	{
		ft_putendl("Usage: mod1 map [rain | wave | uprising]");
		exit(0);
	}
	env.pause = 0;
	env.flow_pause = 0;
	if (!ft_strcmp(av[2], "rain"))
		env.scenario = RAIN;
	else if (!ft_strcmp(av[2], "uprising"))
		env.scenario = UPRISING;
	else if (!ft_strcmp(av[2], "wave"))
		env.scenario = WAVE;
	else
	{
		ft_putendl("Invalid scenario: wave | rain | uprising");
		exit(-1);
	}
	srand(time(NULL));
	env.scenar_count = 0;
	if (!(env.window = malloc(sizeof(*env.window))))
		error_quit("Failed to malloc window");
	map_init(&env);
	map_parse(&env, av[1]);
	map_post_load(&env);
	env.window->width = 1000;
	env.window->height = 750;
	window_init(&env);
	scenar_wave(&env);
	mlx_loop_hook(env.window->mlx, loop_listener, &env);
	mlx_key_hook(env.window->mlx_window, key_listener, &env);
	mlx_loop(env.window->mlx);
	return (0);
}
