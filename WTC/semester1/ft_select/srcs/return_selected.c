/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_selected.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:06:16 by jlangman          #+#    #+#             */
/*   Updated: 2016/12/05 11:06:34 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	return_selected(t_env *env)
{
	t_item_list		*lst;
	int				printed;

	terminal_normal_mode();
	ft_putstr(tgetstr("te", 0));
	ft_putstr(tgetstr("ve", 0));
	printed = 0;
	lst = env->items;
	while (lst)
	{
		if (lst->item->selected)
		{
			if (printed)
				ft_putchar(' ');
			else
				printed = 1;
			ft_putstr(lst->item->name);
		}
		lst = lst->next;
	}
	exit(0);
}
