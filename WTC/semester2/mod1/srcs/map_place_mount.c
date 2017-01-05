/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_place_mount.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 11:30:04 by jlangman          #+#    #+#             */
/*   Updated: 2016/10/27 11:30:08 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

static double	get_k(int dx, int dy, int z)
{
	double	hyp;

	if ((hyp = sqrt(dx * dx + dy * dy)) > z)
		return (0);
	return (((double)z / 2. * (1. + cos(hyp / (double)z * M_PI))));
}

void		map_place_mount(t_env *env, int x, int y, int z)
{
	int		i;
	int		j;
	int		k;

	x = x / 20000. * MAP_SIZE;
	y = y / 20000. * MAP_SIZE;
	z = z / 20000. * MAP_SIZE;
	if (x < 0 || x >= MAP_SIZE || y < 0 || y >= MAP_SIZE)
		error_quit("Invalid mount position");
	i = 0;
	while (i < MAP_SIZE)
	{
		j = 0;
		while (j < MAP_SIZE)
		{
			k = get_k(abs(x - i), abs(y - j), z);
			if (k > env->map[j][i])
				env->map[j][i] = k;
			j++;
		}
		i++;
	}
	(void)env;
}
