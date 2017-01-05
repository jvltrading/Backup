/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 10:38:50 by jlangman          #+#    #+#             */
/*   Updated: 2016/07/08 12:15:20 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_error	get_err(int exit, char *err_str)
{
	t_error	e;

	e.exit = exit;
	e.err_str = err_str;
	return (e);
}

static void		get_errors(t_error e[NB_ERROR])
{
	e[BADCMD] = get_err(0, "shell: command not found: ");
	e[NSFOD] = get_err(0, "shell: cd: no such file or directory: ");
	e[INVPTH] = get_err(0, "shell: cd: invalid path.\n");
	e[NOENV] = get_err(0, "shell: env: environment is empty.\n");
	e[BADVAL] = get_err(0, NULL);
	e[FORK_FAIL] = get_err(1, "shell: fork failure.\n");
	e[EXIT] = get_err(1, NULL);
	e[RES_ERR] = get_err(0, "shell: Fatal error");
}

int				error(int err_num, char *arg)
{
	t_error	e[NB_ERROR];

	get_errors(e);
	if (err_num == BADVAL)
		ft_putendl(arg);
	else
	{
		if (e[err_num].err_str)
			ft_putstr(e[err_num].err_str);
		if (arg)
			ft_putendl(arg);
		if (e[err_num].exit)
			exit(1);
	}
	return (-1);
}
