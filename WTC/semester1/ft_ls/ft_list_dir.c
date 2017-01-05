/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 10:48:08 by jlangman          #+#    #+#             */
/*   Updated: 2016/06/18 10:43:11 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdlib.h>
#include "./libft/includes/libft.h"

int		ft_list_dir(void)
{
	DIR				*dir;
	struct dirent	*dirread;

	if ((dir = opendir(".")) == NULL)
		return (0);
	dir = opendir(".");
	while ((dirread = readdir(dir)) != NULL)
	{
		if (dirread->d_name[0] != '.')
			ft_putendl(dirread->d_name);
	}
	closedir(dir);
	return (0);
}
