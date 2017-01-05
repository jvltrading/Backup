/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 11:03:39 by jlangman          #+#    #+#             */
/*   Updated: 2016/07/15 13:07:42 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "libft/libft.h"
# include <signal.h>
# include <term.h>
# include <curses.h>
# include <termios.h>
# include <termcap.h>
# include <sys/ioctl.h>
# define BUFFER *(unsigned int *)buffer
# define LINE 0
# define COL 1

typedef struct		s_lst
{
	char			*val;
	int				select;
	int				line;
	struct s_lst	*next;
	struct s_lst	*prev;
	int				len;
}					t_lst;

typedef enum		e_enum
{
	LEFT_KEY = 4479771,
	RIGHT_KEY = 4414235,
	UP_KEY = 4283163,
	DOWN_KEY = 4348699,
	ESCAPE = 27,
	SPACE = 32,
	DELETE = 127,
	RETURN = 10,
	SUP = 2117294875,
	HOME = 4741915,
	END = 4610843,
	PAGE_UP = 2117425947,
	PAGE_DOWN = 2117491483,
	TAB = 9,
	CRTL_A = 1,
}					t_enum;

typedef struct		s_all
{
	struct termios	term;
	char			*name_term;
	int				nb_col;
	int				nb_row;
	int				enter;
	int				count[2];
	char			**ret;
	t_lst			*lst;
}					t_all;

int					ft_init_termios(t_all *all);
int					ft_end_termios(t_all *all);
void				ft_clear_screen(void);
t_all				*ft_check(t_all *all, int i);
void				ft_get_signal(int i);
void				ft_signal(void);
void				ft_select_all(t_all *all);
void				ft_deselect_all(t_all *all);
int					ft_main_select(char **av, t_all *all);
int					display(int c);
void				ft_resize(void);
void				ft_count_col(t_all *all);
int					ft_check_size(t_all *all);
void				ft_print_enter(t_all *all);
void				ft_populate_tab(t_all *all);
void				ft_return(t_all *all);
void				ft_space(t_all *all);
int					ft_delete(t_all *all);
void				ft_home(t_all *all);
void				ft_end(t_all *all);
void				ft_up(t_all *all);
void				ft_down(t_all *all);
void				ft_tab(t_all *all);
int					ft_key(t_all *all);
void				ft_populate_list(char **av, t_all *all);
void				ft_print_list(t_all *all);
void				ft_select_mode(t_lst *lst);
void				ft_under_rev(char *str);
void				ft_reverse_video(char *str);
void				ft_underline(char *str);

#endif
