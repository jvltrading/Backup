/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 12:20:38 by jlangman          #+#    #+#             */
/*   Updated: 2016/07/15 12:20:45 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	ft_signal_stop(void)
{
	t_all	*all;
	char	cp[2];

	all = NULL;
	all = ft_check(all, 1);
	cp[0] = all->term.c_cc[VSUSP];
	cp[1] = 0;
	all->term.c_lflag |= (ICANON | ECHO);
	signal(SIGTSTP, SIG_DFL);
	ft_clear_screen();
	tcsetattr(0, 0, &(all->term));
	tputs(tgetstr("te", NULL), 1, display);
	tputs(tgetstr("ve", NULL), 1, display);
	ioctl(0, TIOCSTI, cp);
}

static void	ft_signal_continue(void)
{
	t_all	*all;

	all = NULL;
	all = ft_check(all, 1);
	all->term.c_lflag &= ~(ICANON | ECHO);
	all->term.c_cc[VMIN] = 1;
	all->term.c_cc[VTIME] = 0;
	tcsetattr(0, 0, &(all->term));
	tputs(tgetstr("ti", NULL), 1, display);
	tputs(tgetstr("vi", NULL), 1, display);
	signal(SIGTSTP, ft_get_signal);
	ft_resize();
	ft_check_size(all);
}

static void	ft_interrupt(void)
{
	t_all	*all;

	all = NULL;
	all = ft_check(all, 1);
	ft_end_termios(all);
	exit(0);
}

void	ft_get_signal(int i)
{
	if (i == SIGCONT)
		ft_signal_continue();
	else if (i == SIGTSTP)
		ft_signal_stop();
	else if (i == SIGWINCH)
		ft_resize();
	else
		ft_interrupt();
}

void	ft_signal(void)
{
	int	i;

	i = 1;
	while (i < 32)
	{
		signal(i, ft_get_signal);
		i++;
	}
}
