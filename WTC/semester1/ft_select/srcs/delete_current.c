/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_current.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:03:17 by jlangman          #+#    #+#             */
/*   Updated: 2016/12/05 11:04:06 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	delete_current(t_env *env)
{
	t_item_list	*prv;
	t_item_list	*nxt;

	if (!env->curr)
		error_quit(NULL);
	prv = env->curr->prev;
	nxt = env->curr->next;
	if (prv)
		prv->next = nxt;
	if (nxt)
		nxt->prev = prv;
	free_item_list(env->curr);
	if (env->items == env->curr)
		env->items = nxt;
	if (!nxt && prv)
		env->curr = prv;
	else if (nxt)
		env->curr = nxt;
	else
		env->curr = NULL;
	ft_putstr(tgetstr("cl", 0));
}
