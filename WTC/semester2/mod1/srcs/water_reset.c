/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   water_reset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 11:31:53 by jlangman          #+#    #+#             */
/*   Updated: 2016/10/27 11:31:54 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

void	water_reset(t_env *env)
{
	int		x;
	int		y;

	x = 0;
	while (x < MAP_SIZE)
	{
		y = 0;
		while (y < MAP_SIZE)
		{
			env->water[y][x] = 0;
			y++;
		}
		x++;
	}
}
