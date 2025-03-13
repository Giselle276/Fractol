/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaccha- <gmaccha-@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-13 12:34:54 by gmaccha-          #+#    #+#             */
/*   Updated: 2025-03-13 12:34:54 by gmaccha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	tricorn(t_complex z, t_complex c)
{
	t_complex	new_z;

	new_z.x = (z.x * z.x) - (z.y * z.y) + c.x;
	new_z.y = -2 * z.x * z.y + c.y;
	return (new_z);
}
