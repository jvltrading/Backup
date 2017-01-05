/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 10:38:24 by jlangman          #+#    #+#             */
/*   Updated: 2016/07/08 12:03:37 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_builtin	get_builtin(char *name, t_resolver *p)
{
	t_builtin	tmp;

	tmp.name = name;
	tmp.builtin = p;
	return (tmp);
}

void		assign_builtin(t_builtin *tmp)
{
	tmp[0] = get_builtin("cd", &get_cd);
	tmp[1] = get_builtin("env", &resolve_env);
	tmp[2] = get_builtin("setenv", &get_setenv);
	tmp[3] = get_builtin("unsetenv", &get_unsetenv);
	tmp[4] = get_builtin("exit", &ft_exit);
	tmp[5] = get_builtin("echo", &get_echo);
}

void		builtin(char **av, char **envp, t_builtin *tmp)
{
	int	i;

	i = 0;
	while (i < NBR_BUILTIN)
	{
		if (ft_strcmp(tmp[i].name, av[0]) == 0)
		{
			tmp[i].builtin(av, envp);
			break;
		}
		i++;
	}
}
