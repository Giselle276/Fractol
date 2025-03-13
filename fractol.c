/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaccha- <gmaccha-@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-13 11:50:42 by gmaccha-          #+#    #+#             */
/*   Updated: 2025-03-13 11:50:42 by gmaccha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_valid_double(char *s)
{
	int	dot_count;

	dot_count = 0;
	if (*s == '-' || *s == '+')
		s++;
	while (*s)
	{
		if (*s == '.')
		{
			dot_count++;
			if (dot_count > 1)
				return (0);
		}
		else if (!ft_isdigit(*s))
		{
			return (0);
		}
		s++;
	}
	return (1);
}

void	valid_input(char *argv1, char *argv2)
{
	if (!is_valid_double(argv1) || !is_valid_double(argv2))
	{
		write(1, "Error: Julia parameters must be numbers\n", 40);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char *argv[])
{
	t_fractal	fractal;

	if ((2 == argc && (!ft_strncmp(argv[1], "mandelbrot", 10)
				|| !ft_strncmp(argv[1], "tricorn", 11)))
		|| (4 == argc && !ft_strncmp(argv[1], "julia", 5)))
	{
		fractal.name = argv[1];
		if (ft_strncmp(fractal.name, "julia", 5) == 0)
		{
			valid_input(argv[2], argv[3]);
			fractal.julia_x = atodbl(argv[2]);
			fractal.julia_y = atodbl(argv[3]);
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		write(2, "Run : ./fractol mandelbrot or julia <value_1> <value_2>"
			" or tricorn\n", 66);
		exit(EXIT_FAILURE);
	}
}
