/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 11:35:04 by jlangman          #+#    #+#             */
/*   Updated: 2016/10/31 11:35:06 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOD1_H
# define MOD1_H

# define MAP_SIZE 500
# define RAIN_RAND 0.01
# define FLOW_FACTOR 2

# include "../libft/libft.h"
# include <limits.h>
# include <fcntl.h>
# include <math.h>
# include <time.h>
# include <mlx.h>

typedef struct			s_window
{
	void				*mlx_window;
	void				*mlx;
	void				*img;
	char				*data;
	int					width;
	int					height;
	int					bpp;
	int					endian;
}						t_window;

typedef enum	e_scenario
{
	WAVE,
	RAIN,
	UPRISING,
	NOTHING,
	EMPTYING,
	ESCAPING,
}				t_scenario;

typedef struct	s_env
{
	t_scenario	scenario;
	t_window	*window;
	double		**map;
	double		**water;
	double		**water_tmp;
	int			scenar_count;
	int			flow_pause;
	int			pause;
}				t_env;

void	window_init(t_env *env);
void	error_quit(char *msg);
int		key_listener(int key, void *data);
int		loop_listener(void *data);
void	pixel_put(t_env *env, int x, int y, int color);
void	map_init(t_env *env);
int		get_map_color(int height);
void	draw(t_env *env);
int		get_screen_x(int x, int y, int z);
int		get_screen_y(int x, int y, int z);
void	map_post_load(t_env *env);
void	map_parse(t_env *env, char *file);
void	map_place_mount_line(t_env *env, char *line);
void	map_place_mount(t_env *env, int x, int y, int z);
int		valid_int(char *val);
void	window_reset(t_env *env);
void	flow(t_env *env);
void	scenar_wave(t_env *env);
void	scenar_uprising(t_env *env);
void	scenar_rain(t_env *env);
void	scenar_emptying(t_env *env);
void	scenar_escaping(t_env *env);
void	water_bck(t_env *env);
void	water_reset(t_env *env);
void	flow_wave(t_env *env);
void	flow_rain(t_env *env);
void	flow_uprising(t_env *env);
void	flow_escaping(t_env *env);

#endif
