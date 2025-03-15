/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaccha- <gmaccha-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:18:45 by gmaccha-          #+#    #+#             */
/*   Updated: 2025/02/04 13:37:25 by gmaccha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

void	mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (ft_strncmp(fractal->name, "julia", 5) == 0)
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

void	color_pixel(int i, int x, int y, t_fractal *fractal)
{
	int			color;

	color = map(i, STEEL_BLUE, CHARCOAL_GREY,
			fractal->iterations_definition);
	if (fractal->color_scheme == 0)
		color = map(i, STEEL_BLUE, CHARCOAL_GREY,
				fractal->iterations_definition);
	else if (fractal->color_scheme == 1)
		color = map(i, STEEL_BLUE, INDIGO,
				fractal->iterations_definition);
	else if (fractal->color_scheme == 2)
		color = map(i, STEEL_BLUE, SADDLE_BROWN,
				fractal->iterations_definition);
	else if (fractal->color_scheme == 3)
		color = map(i, STEEL_BLUE, DIM_GRAY,
				fractal->iterations_definition);
	my_pixel_put(x, y, &fractal->img, color);
}

void	handle_pixel( int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;

	i = 0;
	z.x = (map(x, -2, +2, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.y = (map(y, +2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	mandel_vs_julia(&z, &c, fractal);
	while (i < fractal->iterations_definition)
	{
		if (!ft_strncmp(fractal->name, "tricorn", 7))
			z = tricorn(z, c);
		else
			z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color_pixel(i, x, y, fractal);
			return ;
		}
		++i;
	}
	my_pixel_put(x, y, &fractal->img, MIDNIGHT_BLUE);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (HEIGHT > y++)
	{
		x = -1;
		while (WIDTH > x++)
		{
			handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection,
		fractal->mlx_window,
		fractal->img.img_ptr,
		0, 0);
}
