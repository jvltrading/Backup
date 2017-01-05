/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:08:01 by jlangman          #+#    #+#             */
/*   Updated: 2016/12/05 11:08:03 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	move_down(t_env *env)
{
	if (env->curr)
	{
		if (env->curr->next)
			env->curr = env->curr->next;
		else
			env->curr = env->items;
	}
}
