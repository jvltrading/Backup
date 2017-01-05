/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 11:02:39 by jlangman          #+#    #+#             */
/*   Updated: 2016/07/15 12:00:37 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	ft_main_select(char **av, t_all *all)
{
	ft_clear_screen();
	ft_populate_list(av, all);
	ft_count_col(all);
	ft_print_list(all);
	ft_check_size(all);
	ft_check(all, 0);
	while (1)
	{
		if (!ft_key(all))
			return (0);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_all	all;

	(void)ac;
	all.lst = NULL;
	ft_signal();
	if (!ft_init_termios(&all))
		return (-1);
	if (ac >= 2)
		ft_main_select(av, &all);
	if (!ft_end_termios(&all))
		return (-1);
	return (0);
}
