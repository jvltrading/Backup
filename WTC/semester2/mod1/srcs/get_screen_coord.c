/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_screen_coord.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 11:28:49 by jlangman          #+#    #+#             */
/*   Updated: 2016/10/27 11:28:50 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

int		get_screen_x(int x, int y, int z)
{
	return ((int)(x / (double)MAP_SIZE * 500. + y / (double)MAP_SIZE * 500.));
	(void)z;
}

int		get_screen_y(int x, int y, int z)
{
	return (500 + (int)(x / (double)MAP_SIZE * -250. + y
				/ (double)MAP_SIZE * 250. - z / (double)MAP_SIZE * 500.));
}
