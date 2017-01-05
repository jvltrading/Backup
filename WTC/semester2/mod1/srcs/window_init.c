/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 11:31:59 by jlangman          #+#    #+#             */
/*   Updated: 2016/10/31 11:35:50 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

void	window_init(t_env *env)
{
	int		bob;

	env->window->bpp = 8 * 3;
	env->window->endian = 1;
	bob = env->window->width * env->window->bpp / 8;
	if (!(env->window->mlx = mlx_init()))
		error_quit("Failed to init mlx context");
	if (!(env->window->mlx_window = mlx_new_window(env->window->mlx
					, env->window->width
					, env->window->height, "MOD1")))
		error_quit("Failed to create window");
	if (!(env->window->img = mlx_new_image(env->window->mlx
					, env->window->width, env->window->height)))
		error_quit("Failed to create image");
	if (!(env->window->data = mlx_get_data_addr(env->window->img
					, &(env->window->bpp), &bob
					, &(env->window->endian))))
		error_quit("Failed to get image data");
}
