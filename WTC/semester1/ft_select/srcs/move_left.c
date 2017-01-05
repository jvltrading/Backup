/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:10:01 by jlangman          #+#    #+#             */
/*   Updated: 2016/12/05 11:10:19 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	move_left(t_env *env)
{
	t_item_list	*lst;
	int			i;

	lst = env->curr;
	i = 0;
	while (lst)
	{
		if (i == tgetnum("li"))
		{
			env->curr = lst;
			return ;
		}
		i++;
		lst = lst->prev;
	}
}
