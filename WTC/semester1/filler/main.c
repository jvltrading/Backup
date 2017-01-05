/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 11:39:09 by jlangman          #+#    #+#             */
/*   Updated: 2016/06/12 11:39:10 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print(t_info *d)
{
	ft_putstr(ft_itoa(d->y));
	ft_putchar(' ');
	ft_putstr(ft_itoa(d->x));
	ft_putchar('\n');

}

char	declare_player(char *line, t_info *d)
{
	static char	player = 'Z';

	if (player == 'Z')
	{
		player = line[10] == '1' ? P1 : P2;
		d->opponent = player == P1 ? P2 : P1;
	}
	free(line);
	line = NULL;
	return (player);
}

int		main()
{
	char	*line;
	t_info	d;

	while (get_next_line(0, &line) > 0)
	{
		ft_putstr_fd("main()\n", 2);
		ft_putstr_fd(line, 2);
		ft_putstr_fd("\n", 2);
		if (strstart(line, "$$$"))
		{
			d.player = declare_player(line, &d);
			ft_putstr_fd("$$$\n", 2);
		}
		if (strstart(line, "Plateau"))
		{
			d.map = save_map(&line, &d);
		}
		if (strstart(line, "Piece"))
		{
			d.piece = save_piece(&line, &d);
			analyse(&d);
			print(&d);
		}
	}
	return (0);
}
