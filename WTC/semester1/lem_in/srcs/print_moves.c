/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 16:17:29 by jlangman          #+#    #+#             */
/*   Updated: 2016/07/21 11:02:35 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_room	*get_best_move(t_room *room)
{
	t_room_list	*lst;
	t_room		*bestmove;

	bestmove = NULL;
	lst = room->links;
	while (lst)
	{
		if (!bestmove || bestmove->pound > lst->room->pound)
			bestmove = lst->room;
		lst = lst->next;
	}
	return (bestmove);
}

void			print_moves(t_env *env)
{
	t_room		*current;

	while (env->ants > 0)
	{
		current = env->start;
		while (current != env->end)
		{
			current = get_best_move(current);
			ft_putchar('L');
			ft_putnbr(env->total_ants + 1 - env->ants);
			ft_putchar('-');
			ft_putendl(current->name);
		}
		env->ants--;
	}
}
