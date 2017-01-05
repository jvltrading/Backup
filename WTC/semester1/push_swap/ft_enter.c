/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 11:05:04 by jlangman          #+#    #+#             */
/*   Updated: 2016/07/15 13:46:15 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_print_enter(t_all *all)
{
	int	i;

	i = 0;
	while (all->ret[i])
	{
		ft_putstr(all->ret[i]);
		if (all->ret[i + 1])
			ft_putchar(32);
		i++;
	}
}

void	ft_populate_tab(t_all *all)
{
	t_lst	*tmp;
	int	i;

	i = 0;
	if (all->lst->select == 1)
	{
		all->ret[i] = ft_strdup(all->lst->val);
		i++;
	}
	tmp = all->lst->next;
	while (tmp != all->lst)
	{
		if (tmp->select == 1)
		{
			all->ret[i] = ft_strdup(tmp->val);
			i++;
		}
		tmp = tmp->next;
	}
	all->ret[i] = 0;
}

void	ft_return(t_all *all)
{
	t_lst	*tmp;
	int	count;

	count = 0;
	all->enter = 1;
	if (all->lst->select == 1)
		count++;
	tmp = all->lst->next;
	while (tmp != all->lst)
	{
		if (tmp->select == 1)
			count++;
		tmp = tmp->next;
	}
	all->ret = (char **)malloc(sizeof(char *) * (count + 1));
	ft_populate_tab(all);
}
