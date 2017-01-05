/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:02:11 by jlangman          #+#    #+#             */
/*   Updated: 2016/12/05 11:02:17 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	list_push(t_env *env, t_item *item)
{
	t_item_list	*new;
	t_item_list	*lst;

	if (!(new = malloc(sizeof(*new))))
		error_quit("Failed to malloc new list item");
	new->item = item;
	new->next = NULL;
	if (!env->items)
	{
		new->prev = NULL;
		env->items = new;
	}
	else
	{
		lst = env->items;
		while (lst->next)
			lst = lst->next;
		new->prev = lst;
		lst->next = new;
	}
}
