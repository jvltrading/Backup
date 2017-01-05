/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 10:38:50 by jlangman          #+#    #+#             */
/*   Updated: 2016/06/18 10:42:58 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	main(int argc, char **argv)
{
	if (argc == 1 || argv[0])
		ft_list_dir();
	if (argc > 1)
		ft_list_dir_a();
	return (0);
}