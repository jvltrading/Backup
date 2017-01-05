/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 10:38:37 by jlangman          #+#    #+#             */
/*   Updated: 2016/07/08 10:38:38 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

static int	echo_b(int ac, char **av, char **envp, int new_line)
{
	int	i;

	i = -1;
	(void)envp;
	while (++i < ac)
	{
		ft_putstr(av[i]);
		if (i + 1 < ac)
			ft_putstr(" ");
	}
	if (!new_line)
		ft_putendl("");
	return (0);
}

static int	echo_no_b(int ac, char **av, char **envp, int new_line)
{
	int	i;
	
	i = -1;
	(void)envp;
	while (++i < ac)
	{
		ft_putstr(av[i]);
		if (i + 1 < ac)
			ft_putstr(" ");
	}
	if (!new_line)
		ft_putendl("");
	return (0);
}

static int	echo_all(int ac, char **av, char **envp)
{
	int	i;
	int	new_line;
	int	back_slash;

	i = -1;
	new_line = 0;
	back_slash = 1;
	while (++i < ac)
	{
		if (av[i][0] == '-')
		{
			if (av[i][1] == 'e')
				back_slash = 2;
			else if (av[i][1] == 'E' && back_slash != 2)
				back_slash = 0;
			else if (av[i][1] == 'n')
				new_line = 1;
		}
		else
			break;
	}
	if (back_slash)
		return (echo_b(ac - i, &av[i], envp, new_line));
	else
		return (echo_no_b(ac - i, &av[i], envp, new_line));
}

static int	echo(int ac, char **av, char **envp)
{
	if (ac == 1)
	{
		ft_putendl("");
		return (0);
	}
	else
		return (echo_all(ac - 1, &av[1], envp));
}

void		get_echo(char **av, char **envp)
{
	echo(count_split(av), av, envp);
}

