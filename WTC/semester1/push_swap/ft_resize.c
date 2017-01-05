/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 11:05:20 by jlangman          #+#    #+#             */
/*   Updated: 2016/07/15 11:58:57 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	ft_check_size(t_all *all)
{
	if (all->nb_row - 2 < all->count[LINE] || all->nb_col - 2 < all->count[COL])
	{
		ft_clear_screen();
		ft_putendl_fd("Window size is too small.", 2);
		return (0);
	}
	else
	{
		ft_clear_screen();
		ft_print_list(all);
	}
	return (1);
}

void	ft_resize(void)
{
	t_all		*all;
	struct winsize	win;

	all = NULL;
	all = ft_check(all, 1);
	ft_clear_screen();
	ioctl(0, TIOCGWINSZ, &win);
	all->nb_col = win.ws_col;
	all->nb_row = win.ws_row;
	ft_check_size(all);
}

void	ft_count_col(t_all *all)
{
	t_lst	*tmp;

	all->count[COL] = all->lst->len;
	tmp = all->lst->next;
	while (tmp != all->lst)
	{
		if (tmp->len > all->count[COL])
			all->count[COL] = tmp->len;
		tmp = tmp->next;
	}
}
