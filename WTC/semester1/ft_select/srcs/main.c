/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:04:42 by jlangman          #+#    #+#             */
/*   Updated: 2016/12/05 11:51:18 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_env		*g_env = NULL;

static void		read_stdin(t_env *env)
{
	char	buffer[20];
	int		rd;

	ft_memset(buffer, 0, 20);
	rd = read(0, buffer, 20);
	if (rd == 1 && buffer[0] == 27)
		error_quit(NULL);
	else if (rd == 1 && buffer[0] == 10)
		return_selected(env);
	else if ((rd == 1 && buffer[0] == 127)
			|| !ft_strcmp(buffer, env->key_code_delete))
		delete_current(env);
	else if (rd == 1 && buffer[0] == ' ')
	{
		if (env->curr)
			env->curr->item->selected = !env->curr->item->selected;
	}
	else if (!ft_strcmp(buffer, env->key_code_down))
		move_down(env);
	else if (!ft_strcmp(buffer, env->key_code_up))
		move_up(env);
	else if (!ft_strcmp(buffer, env->key_code_left))
		move_left(env);
	else if (!ft_strcmp(buffer, env->key_code_right))
		move_right(env);
}

int				main(int ac, char **av)
{
	t_env	env;

	if (!(isatty(0)))
		error_quit("Invalid input");
	g_env = &env;
	env.old_width = 0;
	env.old_height = 0;
	env.list_size = ac - 1;
	env.items = NULL;
	get_tty_fd(&env);
	build_list(&env, ac, av);
	env.curr = env.items;
	init_signals();
	tgetent(0, getenv("TERM"));
	if (!(env.caps = malloc(sizeof(*env.caps))))
		error_quit("Failed to malloc env caps");
	init_caps(env.caps);
	key_codes_init(&env);
	terminal_catch();
	env.fd = 2;
	while (1)
	{
		draw_list(&env);
		read_stdin(&env);
	}
}
