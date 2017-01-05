/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:08:27 by jlangman          #+#    #+#             */
/*   Updated: 2016/12/05 11:09:06 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		draw_color(t_env *env, t_item *item, int x)
{
	int		i;

	ft_putstr_fd("\033[", env->fd);
	ft_putnbr_fd(item->is_bright ? 1 : 0, env->fd);
	ft_putchar_fd(';', env->fd);
	ft_putnbr_fd(item->color, env->fd);
	ft_putchar_fd('m', env->fd);
	if ((int)(x + ft_strlen(item->name)) >= tgetnum("co"))
	{
		i = 0;
		while (x + i < tgetnum("co"))
		{
			ft_putchar_fd(item->name[i], env->fd);
			i++;
		}
	}
	else
		ft_putstr_fd(item->name, env->fd);
	ft_putstr_fd("\033[0;0m", env->fd);
}

static void		print_value(t_env *env, t_item_list *lst, int x)
{
	if (lst->item->selected)
		ft_putstr_fd(env->caps->highlight_start, env->fd);
	if (lst == env->curr)
		ft_putstr_fd(env->caps->underline_start, env->fd);
	draw_color(env, lst->item, x);
	if (lst == env->curr)
		ft_putstr_fd(env->caps->underline_end, env->fd);
	if (lst->item->selected)
		ft_putstr_fd(env->caps->highlight_end, env->fd);
}

static void		check_column(int *x, int *y, size_t *max_width)
{
	if (*y >= tgetnum("li"))
	{
		*x += *max_width + 1;
		*y = 0;
		*max_width = 0;
	}
}

static void		check_resize(t_env *env)
{
	if (env->old_width != tgetnum("co")
			|| env->old_height != tgetnum("li"))
	{
		ft_putstr_fd(tgetstr("cl", 0), env->fd);
		env->old_width = tgetnum("co");
		env->old_height = tgetnum("li");
	}
}

void			draw_list(t_env *env)
{
	t_item_list		*lst;
	size_t			max_width;
	int				x;
	int				y;

	check_resize(env);
	x = 0;
	y = 0;
	max_width = 0;
	lst = env->items;
	while (lst)
	{
		check_column(&x, &y, &max_width);
		if (x >= tgetnum("co"))
			return ;
		ft_putstr_fd(tgoto(env->caps->move, x, y), env->fd);
		print_value(env, lst, x);
		if (ft_strlen(lst->item->name) > max_width)
			max_width = ft_strlen(lst->item->name);
		y++;
		lst = lst->next;
	}
}
