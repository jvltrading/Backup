/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 16:39:13 by jlangman          #+#    #+#             */
/*   Updated: 2016/08/07 17:09:01 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
**The restart function needs the origonal process to die,
** before being called.
**It will not be used for now.
*/

void		restart(void)
{
	t_env	*env;

	env = (t_env *)back_up_env(NULL);
	ft_putstr("\e[31mRestarting...");
	ft_putchar('\n');
	ft_putstr("\e[32m   Complete");
	ft_putchar('\n');
	execve("./21sh", NULL, E_EN);
	exit(0);
}

/*
**This function takes control of the terminal.
**
**	Debug lines:
**		new->c_lflag |= ISIG;
**		new->c_lflag &= ~();//ECHOK | ECHOE | ECHOPRT | ECHONL);
**		~(ICANON | ECHO | ECHOK | ECHOE | ECHONL | IEXTEN);
*/

static void	ft_signal_set(void)
{
	struct termios			*new;

	new = (struct termios *)malloc(sizeof(struct termios));
	tcgetattr(STDIN_FILENO, new);
	new->c_iflag |= IGNBRK;
	new->c_lflag = ECHONL;
	new->c_cc[VMIN] = 1;
	new->c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, new);
	return ;
}

/*
**This function recieves the signals.
**
**	Debug line (start)
**		printf("\e[93mSignal recieved: '%d'\n", signo);//debug
*/

void		sig_handler(int signo)
{
	if (signo == SIGKILL)
	{
		ft_putstr("\e[31mExiting Program.\n");
		exit(0);
	}
	if (signo == SIGTRAP || signo == SIGBUS || signo == SIGABRT ||
		signo == SIGSEGV || signo == SIGSYS)
	{
		ft_putstr("\033[2J\033[1;1H");
		ft_putstr("\e[31mError: an unexpected error occured.\n");
		exit(0);
	}
}

void		sigs(void)
{
	int		k;

	k = 0;
	while (++k < 32)
		signal(k, sig_handler);
	ft_signal_set();
}
