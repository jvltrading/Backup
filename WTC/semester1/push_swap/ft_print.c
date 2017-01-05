/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 11:02:19 by jlangman          #+#    #+#             */
/*   Updated: 2016/07/15 11:02:28 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_underline(char *str)
{
	tputs(tgetstr("us", NULL), 1, display);
	ft_putstr_fd("\033[32m", 2);
	ft_putendl_fd(str, 2);
	ft_putstr_fd("\033[00m", 2);
	tputs(tgetstr("ue", NULL), 1, display);
}

void	ft_reverse_video(char *str)
{
	tputs(tgetstr("so", NULL), 1, display);
	ft_putstr_fd("\033[1;32m", 2);
	ft_putendl_fd(str, 2);
	ft_putstr_fd("\033[00m", 2);
	tputs(tgetstr("se", NULL), 1, display);
}

void	ft_under_rev(char *str)
{
	tputs(tgetstr("us", NULL), 1, display);
	tputs(tgetstr("so", NULL), 1, display);
	ft_putstr_fd("\033[1;32m", 2);
	ft_putendl_fd(str, 2);
	ft_putstr_fd("\033[00m", 2);
	tputs(tgetstr("se", NULL), 1, display);
	tputs(tgetstr("ue", NULL), 1, display);
}

void	ft_select_mode(t_lst *lst)
{
	if (lst->line == 1 && lst->select == 1)
		ft_under_rev(lst->val);
	else if (lst->line == 1)
		ft_underline(lst->val);
	else if (lst->select == 1)
		ft_reverse_video(lst->val);
	else
		ft_putendl_fd(lst->val, 2);
}

void	ft_print_list(t_all *all)
{
	t_lst	*tmp;

	tmp = NULL;
	ft_select_mode(all->lst);
	tmp = all->lst->next;
	while (tmp != all->lst)
	{
		ft_select_mode(tmp);
		tmp = tmp->next;
	}
}
