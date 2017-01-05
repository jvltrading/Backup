/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_codes_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:11:11 by jlangman          #+#    #+#             */
/*   Updated: 2016/12/05 11:12:24 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	key_codes_init(t_env *env)
{
	if (!(env->key_code_delete = tgetstr("kD", 0)))
		error_quit(NULL);
	if (!(env->key_code_left = tgetstr("kl", 0)))
		error_quit(NULL);
	env->key_code_left[1] = 91;
	if (!(env->key_code_right = tgetstr("kr", 0)))
		error_quit(NULL);
	env->key_code_right[1] = 91;
	if (!(env->key_code_up = tgetstr("ku", 0)))
		error_quit(NULL);
	env->key_code_up[1] = 91;
	if (!(env->key_code_down = tgetstr("kd", 0)))
		error_quit(NULL);
	env->key_code_down[1] = 91;
}
