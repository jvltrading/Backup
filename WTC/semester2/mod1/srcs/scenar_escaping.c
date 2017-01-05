/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenar_escaping.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 11:31:02 by jlangman          #+#    #+#             */
/*   Updated: 2016/10/27 11:31:03 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

void	scenar_escaping(t_env *env)
{
	int		x;
	int		y;

	y = 0;
	while (y < MAP_SIZE)
	{
		x = 0;
		while (x < MAP_SIZE)
		{
			if (x == 0 || y == 0 || x == MAP_SIZE - 1 || y == MAP_SIZE - 1)
				env->water[y][x] -= 1;
			x++;
		}
		y++;
	}
}
