/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 11:02:02 by jlangman          #+#    #+#             */
/*   Updated: 2016/07/15 11:02:14 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	ft_basic_key(t_all *all, char *buffer[5])
{
	if (BUFFER == DOWN_KEY)
		ft_down(all);
	if (BUFFER == UP_KEY)
		ft_up(all);
	if (BUFFER == SPACE)
		ft_space(all);
	if (BUFFER == HOME)
		ft_home(all);
	if (BUFFER == CRTL_A)
		ft_select_all(all);
	if (BUFFER == TAB)
		ft_tab(all);
}

int	ft_key(t_all *all)
{
	char	*buffer[5];

	ft_bzero(buffer, 5);
	read(0, buffer, 4);
	if (BUFFER == ESCAPE)
		return (0);
	if (ft_check_size(all))
	{
		ft_basic_key(all, buffer);
		if (BUFFER == DELETE || BUFFER == SUP)
		{
			if (!ft_delete(all))
				return (0);
		}
		if (BUFFER == RETURN)
		{
			ft_return(all);
			return (0);
		}
		ft_clear_screen();
		ft_print_list(all);
	}
	return (1);
}
