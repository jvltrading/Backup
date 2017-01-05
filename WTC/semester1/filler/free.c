/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 11:38:56 by jlangman          #+#    #+#             */
/*   Updated: 2016/06/12 11:38:57 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	freetab(char **tab)
{
	int	i;
	i = 0;

	while (tab[i] != 0)
	{
		free(tab[i]);
		i++;
	}
}