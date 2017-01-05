/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 11:26:39 by jlangman          #+#    #+#             */
/*   Updated: 2016/10/05 12:24:39 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	parse(char *str)
{
	int ret;

	ret = 0;
	if (ft_strcmp(str, "mandelbrot") == 0)
		ret = 1;
	else if (ft_strcmp(str, "julia") == 0)
		ret = 2;
	else if (ft_strcmp(str, "tricorn") == 0)
		ret = 3;
	else
	{
		ft_putendl("These are the available fractals");
		ft_putendl("Mandelbrot, Julia and Tricorn");
		ft_putendl("Exemple: ./fractol mandelbrot for Mandelbrot");
		exit(0);
	}
	return (ret);
}
