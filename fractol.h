/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaccha- <gmaccha-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:15:00 by gmaccha-          #+#    #+#             */
/*   Updated: 2025/02/04 12:49:47 by gmaccha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define WIDTH 800
# define HEIGHT 800

# define DEEP_BLUE       0x003366
# define DARK_SLATE_GREY 0x2F4F4F
# define CHARCOAL_GREY   0x36454F
# define MIDNIGHT_BLUE   0x191970
# define SLATE_BLUE      0x6A5ACD
# define OLIVE_DRAB      0x6B8E23
# define SADDLE_BROWN    0x8B4513
# define STEEL_BLUE      0x4682B4
# define DIM_GRAY        0x696969
# define INDIGO          0x4B0082

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	escape_value;
	int		iterations_definition;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
	int		color_scheme;
}	t_fractal;

int			ft_strncmp(const char *s1, const char *s2, size_t n);
double		atodbl(char *s);
void		fractal_init(t_fractal *fractal);
void		malloc_error(void);
void		data_init(t_fractal *fractal);
void		events_init(t_fractal *fractal);
void		fractal_render(t_fractal *fractal);
void		handle_pixel( int x, int y, t_fractal *fractal);
void		mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *fractal);
void		my_pixel_put(int x, int y, t_img *img, int color);
double		map(double unscaled_num, double new_min, double new_max,
				double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
int			close_handler(t_fractal *fractal);
int			key_handler(int keysym, t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
int			ft_isdigit(int c);
t_complex	tricorn(t_complex z, t_complex c);

#endif
