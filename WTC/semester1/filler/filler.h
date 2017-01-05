/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 11:39:25 by jlangman          #+#    #+#             */
/*   Updated: 2016/06/12 11:39:27 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "./libft/libft.h"
# define P1 'O'
# define P2 'X'
typedef struct	s_info
{
	char		player;
	char		opponent;
	char		**map;
	char		**piece;
	int			mapcol;
	int			maprow;
	int			piececol;
	int			piecerow;
	int			y;
	int			x;
	int			opx;
	int			opy;
}				t_info;

void	analyse(t_info *d);
char	declare_player(char *line, t_info *d);
int		is_space(t_info *d);
char	**save_map(char **line, t_info *d);
char	**save_piece(char **line, t_info *d);
int		strstart(char *str, char *start);
int		place_piece(int y, int x, int i, t_info *d);
int		find_place_in_piece(int *y, int *x, int i, t_info *d);
int		test_case(t_info *d, int y, int x);
void	print(t_info *d);
void	freetab(char **tab);

#endif 
