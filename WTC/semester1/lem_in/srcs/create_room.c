/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 16:17:58 by jlangman          #+#    #+#             */
/*   Updated: 2016/07/21 10:59:40 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*create_room(void)
{
	t_room	*room;

	if (!(room = malloc(sizeof(*room))))
		error_quit("Failed to malloc room");
	room->name = NULL;
	room->links = NULL;
	room->pound = INT_MAX;
	return (room);
}
