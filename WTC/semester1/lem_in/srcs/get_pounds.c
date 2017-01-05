/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pounds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 16:18:45 by jlangman          #+#    #+#             */
/*   Updated: 2016/07/21 11:36:40 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	get_pounds(t_env *env, t_room *room, int pound)
{
	t_room_list	*lst;

	if (pound < room->pound)
	{
		room->pound = pound;
		lst = room->links;
		while (lst)
		{
			get_pounds(env, lst->room, pound + 1);
			lst = lst->next;
		}
	}
}
