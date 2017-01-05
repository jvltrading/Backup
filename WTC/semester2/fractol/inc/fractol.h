/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 11:24:24 by jlangman          #+#    #+#             */
/*   Updated: 2016/10/05 12:07:55 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include <mlx.h>

# define SQRT(x) ((x) * (x))

# define WIDTH			(800.0)
# define HEIGHT			(600.0)
# define HALFW			(400.0)
# define HALFH			(300.0)

# define EXIT			53
# define LEFT_CLICK		1
# define RIGHT_CLICK	2
# define SCROLL_CLICK	3
# define SCROLL_UP		4
# define SCROLL_DOWN	5
# define NUM_1			18
# define NUM_2			19
# define NUM_3			20
# define NUM_4			21
# define NUM_5			23
# define NUM_6			22
# define NUM_7			26
# define NUM_8			28
# define NUM_9			25
# define NUM_0			29
# define PLUS			69
# define MOINS			78
# define SLASH			75
# define STAR			67
# define LEFT			123
# define RIGHT			124
# define DOWN			125
# define UP				126

typedef struct	s_env
{
	void		*img;
	char		*data;
	int			sl;
	int			bpp;
	int			endian;
	void		*mlx;
	void		*win;
	int			nbf;
	int			i;
	float		c_r;
	float		c_i;
	float		nreal;
	float		oreal;
	float		nimag;
	float		oimag;
	int			iter;
	float		zoom;
	float		movex;
	float		movey;
	int			x;
	int			y;
	int			color;
	float		jcr;
	float		jci;
}				t_env;

int				mouse_moove(int x, int y, t_env *e);
int				mouse_all(int keycode, int x, int y, t_env *e);
int				key_hook(int keycode, t_env *e);
int				parse(char *str);
void			init(t_env *e);
int				expose_hook(t_env *e);
void			mlx_pixel_to_image(t_env *e, int color);
int				colorrgb(int red, int green, int blue);
int				mandelbrot(t_env *e);
int				julia(t_env *e);
int				tricorn(t_env *e);
int				choose_fractal(t_env *e);
void			draw(t_env *e);

#endif
