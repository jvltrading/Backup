/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 13:50:51 by jlangman          #+#    #+#             */
/*   Updated: 2016/12/05 11:23:10 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "../libft/libft.h"
# include <sys/stat.h>
# include <termios.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <stdio.h>
# include <fcntl.h>
# include <term.h>
# include <sys/ioctl.h>

typedef struct				s_item
{
	char					*name;
	int						selected;
	int						is_bright;
	int						color;
}							t_item;

typedef struct s_item_list	t_item_list;

struct						s_item_list
{
	t_item					*item;
	t_item_list				*next;
	t_item_list				*prev;
};

typedef struct				s_caps
{
	char					*underline_start;
	char					*underline_end;
	char					*highlight_start;
	char					*highlight_end;
	char					*bold_start;
	char					*bold_end;
	char					*clear;
	char					*move;
}							t_caps;

typedef struct 				s_env
{
	t_item_list				*items;
	t_item_list				*curr;
	t_caps					*caps;
	char					*key_code_delete;
	char					*key_code_left;
	char					*key_code_right;
	char					*key_code_up;
	char					*key_code_down;
	int						old_width;
	int						old_height;
	int						list_size;
	int						fd;
}							t_env;

void						signal_handler(int signal);
void						terminal_normal_mode(void);
void						terminal_catch_mode(void);
void						init_signals(void);
void						init_caps(t_caps *caps);
void						key_codes_init(t_env *env);
void						error_quit(char *message);
void						draw_list(t_env *env);
void						build_list(t_env *env, int ac, char **av);
t_item						*item_create(void);
void						list_push(t_env *env, t_item *item);
void						move_down(t_env *env);
void						move_up(t_env *env);
void						move_left(t_env *env);
void						move_right(t_env *env);
void						return_selected(t_env *env);
void						terminal_catch(void);
void						terminal_default(void);
void						delete_current(t_env *env);
void						free_item_list(t_item_list *list);
void						get_tty_fd(t_env *env);

#endif
