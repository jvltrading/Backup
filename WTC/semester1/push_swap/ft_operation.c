/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 11:03:22 by jlangman          #+#    #+#             */
/*   Updated: 2016/07/15 11:03:24 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_home(t_all *all)
{
	t_lst	*tmp;

	tmp = all->lst;
	while (tmp->line != 1)
		tmp = tmp->next;
	tmp->line = 0;
	all->lst->line = 1;
}

void	ft_end(t_all *all)
{
	t_lst	*tmp;

	tmp = all->lst;
	while (tmp->line != 1)
		tmp = tmp->next;
	tmp->line = 0;
	all->lst->prev->line = 1;
}

void	ft_space(t_all *all)
{
	t_lst	*tmp;

	tmp = all->lst;
	while (tmp->line != 1)
		tmp = tmp->next;
	if (tmp->select == 0)
		tmp->select = 1;
	else
		tmp->select = 0;
	tmp->line = 0;
	tmp->next->line = 1;
}

int	ft_delete(t_all *all)
{
	t_lst	*tmp;

	if (all->lst == all->lst->next)
	{
		free(all->lst);
		return (0);
	}
	tmp = all->lst;
	if (all->lst->line == 1)
		all->lst = tmp->next;
	else
	{
		while (tmp->line != 1)
			tmp = tmp->next;
	}
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	tmp->next->line = 1;
	free(tmp->val);
	free(tmp);
	ft_count_col(all);
	all->count[LINE] -= 1;
	return (1);
}

void	ft_tab(t_all *all)
{
	ft_deselect_all(all);
	ft_space(all);
}
