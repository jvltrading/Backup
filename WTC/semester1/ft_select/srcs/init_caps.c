/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_caps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:04:17 by jlangman          #+#    #+#             */
/*   Updated: 2016/12/05 11:04:34 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	init_caps(t_caps *caps)
{
	if (!(caps->underline_start = tgetstr("us", 0)))
		error_quit("Failed to load us cap");
	if (!(caps->underline_end = tgetstr("ue", 0)))
		error_quit("Failed to load ue cap");
	if (!(caps->highlight_start = tgetstr("so", 0)))
		error_quit("Failed to load so cap");
	if (!(caps->highlight_end = tgetstr("se", 0)))
		error_quit("Failed to load se cap");
	if (!(caps->bold_start = tgetstr("md", 0)))
		error_quit("Failed to load md cap");
	if (!(caps->bold_end = tgetstr("me", 0)))
		error_quit("Failed to load me cap");
	if (!(caps->move = tgetstr("cm", 0)))
		error_quit("Failed to load cm cap");
}
