/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 10:38:43 by jlangman          #+#    #+#             */
/*   Updated: 2016/07/08 11:52:49 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_env(char **envp)
{
	int	i;

	check_envp(envp);
	i = 0;
	while (envp[i])
		ft_putendl(envp[i++]);
}

void		resolve_env(char **av, char **envp)
{
	(void)av;
	ft_env(envp);
}
