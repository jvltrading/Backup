/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:09:36 by jlangman          #+#    #+#             */
/*   Updated: 2016/12/05 11:09:38 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_item	*item_create(void)
{
	t_item	*new;

	if (!(new = malloc(sizeof(*new))))
		error_quit("Failed to create new list item");
	new->selected = 0;
	return (new);
}
