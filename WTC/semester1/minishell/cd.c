/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 10:38:31 by jlangman          #+#    #+#             */
/*   Updated: 2016/07/08 12:02:39 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	home(char **envp)
{
	if (chdir(ft_getenv(envp, "HOME")))
		return (error(NSFOD, ft_getenv(envp, "HOME")));
	envp = ft_setenv(envp, "OLDPWD", ft_getenv(envp, "PWD"), 1);
	envp = ft_setenv(envp, "PWD", ft_getenv(envp, "HOME"), 1);
	return (0);
}

static int	prev(char **envp)
{
	char	*pwd;

	pwd = ft_strdup(ft_getenv(envp, "PWD"));
	if (chdir(ft_getenv(envp, "OLDPWD")) < 0)
		return (error(NSFOD, ft_getenv(envp, "OLDPWD")));
	envp = ft_setenv(envp, "PWD", ft_getenv(envp, "OLDPWD"), 1);
	envp = ft_setenv(envp, "OLDPWD", pwd, 1);
	ft_putendl(ft_getenv(envp, "PWD"));
	ft_strdel(&pwd);
	return (0);
}

static int	path(char **envp, char *av)
{
	char	*pwd;
	char	*tmp;

	if (chdir(av))
		return (error(NSFOD, av));
	if (av[0] == '/')
	{
		envp = ft_setenv(envp, "OLDPWD", ft_getenv(envp, "PWD"), 1);
		envp = ft_setenv(envp, "PWD", av, 1);
	}
	else
	{
		tmp = ft_strjoin(ft_getenv(envp, "PWD"), "/");
		pwd = ft_strjoin(tmp, av);
		envp = ft_setenv(envp, "OLDPWD", ft_getenv(envp, "PWD"), 1);
		envp = ft_setenv(envp, "PWD", pwd, 1);
		ft_strdel(&tmp);
		ft_strdel(&pwd);
	}
	return (0);
}

void		get_cd(char **av, char **envp)
{
	int	ac;

	ac = count_split(av);
	if (ac == 1)
		home(envp);
	else if (ac == 2 && !ft_strcmp(av[1], "-") && !av[2])
		prev(envp);
	else if (ac == 2 && av[1][0] == '~' && !av[2])
		ft_putendl("tilde not recognised");
	else if (ac == 2)
		path(envp, av[1]);
	else
		error(INVPTH, NULL);
}
