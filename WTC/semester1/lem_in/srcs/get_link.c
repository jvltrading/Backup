/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 16:19:25 by jlangman          #+#    #+#             */
/*   Updated: 2016/07/21 11:28:48 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_room	*find_room(t_env *env, char *name)
{
	t_room_list		*lst;

	lst = env->rooms;
	while (lst)
	{
		if (!ft_strcmp(lst->room->name, name))
			return (lst->room);
		lst = lst->next;
	}
	return (NULL);
}

static int		are_linked(t_room *r1, t_room *r2)
{
	t_room_list		*lst;

	lst = r1->links;
	while (lst)
	{
		if (lst->room == r2)
			return (1);
		lst = lst->next;
	}
	lst = r2->links;
	while (lst)
	{
		if (lst->room == r1)
			return (1);
		lst = lst->next;
	}
	return (0);
}

static void		add_link(t_room *r1, t_room *r2)
{
	t_room_list		*lst;

	if (!(lst = malloc(sizeof(*lst))))
		error_quit("Failed to malloc room for list");
	lst->room = r2;
	lst->next = r1->links;
	r1->links = lst;
	if (!(lst = malloc(sizeof(*lst))))
		error_quit("Failed to malloc room for list");
	lst->room = r1;
	lst->next = r2->links;
	r2->links = lst;
}

int				get_link(t_env *env, t_parser *p, char **split)
{
	t_room	*r1;
	t_room	*r2;

	p->link_part = 1;
	if (p->is_start || p->is_end)
		return (0);
	if (!(r1 = find_room(env, split[0])))
		return (0);
	if (!(r2 = find_room(env, split[1])))
		return (0);
	if (are_linked(r1, r2))
		return (0);
	add_link(r1, r2);
	return (1);
}
