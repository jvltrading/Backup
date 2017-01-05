/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:02:27 by jlangman          #+#    #+#             */
/*   Updated: 2016/12/05 11:02:45 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	move_up(t_env *env)
{
	t_item_list		*lst;

	if (env->curr)
	{
		if (env->curr->prev)
			env->curr = env->curr->prev;
		else
		{
			lst = env->items;
			while (lst->next)
				lst = lst->next;
			env->curr = lst;
		}
	}
}
