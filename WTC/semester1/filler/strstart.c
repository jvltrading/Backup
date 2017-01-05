/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstart.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 11:40:02 by jlangman          #+#    #+#             */
/*   Updated: 2016/06/12 11:40:03 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		strstart(char *str, char *start)
{
	int		i;

	i = 0;
	while(str[i] && start[i])
	{
		if (start[i] != str[i])
			return (0);
		i++;
	}
	if (start[i])
		return (0);
	return (1);
}
