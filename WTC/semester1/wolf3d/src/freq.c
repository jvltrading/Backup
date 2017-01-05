/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freq.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 10:55:09 by jlangman          #+#    #+#             */
/*   Updated: 2016/11/21 10:55:12 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		frequency(t_env *te)
{
	double	i;
	double	res;

	i = 0;
	res = te->time - te->oldtime;
	while ((res * i) < 1000)
		i = i + 1;
	return (i);
}
