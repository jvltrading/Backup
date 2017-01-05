/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 11:02:50 by jlangman          #+#    #+#             */
/*   Updated: 2016/07/15 12:04:29 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_lst	*ft_init_list(void)
{
	t_lst	*tmp;

	tmp = (t_lst *)malloc(sizeof(t_lst));
	tmp->val = NULL;
	tmp->select = 0;
	tmp->line = 0;
	tmp->len = 0;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

t_lst	*ft_fill_list(char *str)
{
	t_lst	*tmp;

	tmp = ft_init_list();
	tmp->val = ft_strdup(str);
	tmp->len = ft_strlen(tmp->val);
	return (tmp);
}

void	ft_push_list(t_all *all, t_lst *lst)
{
	t_lst	*tmp;

	if (all->lst == NULL)
	{
		lst->prev = lst;
		lst->next = lst;
		all->lst = lst;
		lst->line = 1;
	}
	else
	{
		tmp = all->lst->prev;
		tmp->next = lst;
		lst->next = all->lst;
		lst->prev = tmp;
		all->lst->prev = lst;
	}
}

void	ft_populate_list(char **av, t_all *all)
{
	int	i;
	t_lst	*tmp;

	i = 1;
	while (av[i])
	{
		tmp = ft_fill_list(av[i]);
		ft_push_list(all, tmp);
		i++;
	}
	all->count[LINE] = i;
}
