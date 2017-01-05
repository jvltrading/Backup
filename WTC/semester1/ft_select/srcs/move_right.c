/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:10:56 by jlangman          #+#    #+#             */
/*   Updated: 2016/12/05 11:11:03 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	move_right(t_env *env)
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
		lst = lst->next;
	}
}
