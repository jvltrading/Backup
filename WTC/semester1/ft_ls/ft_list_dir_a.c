/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_dir_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 10:44:50 by jlangman          #+#    #+#             */
/*   Updated: 2016/06/10 10:48:00 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdlib.h>
#include "./libft/includes/libft.h"

int		ft_list_dir_a(void)
{
	DIR				*dir;
	struct dirent	*dirread;

	if ((dir = opendir(".")) == NULL)
		return (0);
	dir = opendir(".");
	while ((dirread = readdir(dir)) != NULL)
		ft_putendl(dirread->d_name);
	closedir(dir);
	return (0);
}
