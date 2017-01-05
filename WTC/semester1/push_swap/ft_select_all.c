/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_all.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 11:02:59 by jlangman          #+#    #+#             */
/*   Updated: 2016/07/15 11:45:46 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_deselect_all(t_all *all)
{
	t_lst	*tmp;

	all->lst->select = 0;
	tmp = all->lst->next;
	while (tmp != all->lst)
	{
		tmp->select = 0;
		tmp = tmp->next;
	}
}

void	ft_select_all(t_all *all)
{
	t_lst	*tmp;
	int	i;

	i = 0;
	if (all->lst->select == 0)
	{
		all->lst->select = 1;
		i = 1;
	}
	tmp = all->lst->next;
	while (tmp != all->lst)
	{
		if (tmp->select == 0)
		{
			tmp->select = 1;
			i = 1;
		}
		tmp = tmp->next;
	}
	if (!i)
		ft_deselect_all(all);
}
