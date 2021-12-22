/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:52:31 by hbourkan          #+#    #+#             */
/*   Updated: 2021/12/21 14:07:42 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	draw_enemy(t_var *vars)
{
	if ((vars->x2 / 100) % 2 == 0)
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img8, vars->x2, vars->y2);
	else
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img9, vars->x2, vars->y2);
	usleep(60000);
}

int	sprite(t_var *vars)
{
	char	*cpt;

	if (vars->x2 >= (vars->width * MARGE) - MARGE)
		vars->x2 = MARGE;
	mlx_clear_window(vars->mlx, vars->win);
	background(vars);
	window_draw(vars, -1);
	draw_enemy(vars);
	player_draw(vars);
	cpt = ft_itoa(vars->compteur);
	mlx_string_put(vars->mlx, vars->win, 50, 50, 0xFFFF00,
		cpt);
	free(cpt);
	if (vars->x2 == vars->oldx && vars->y2 == vars->oldy)
	{
		usleep(500000);
		fail(vars);
	}
	vars->x2 += MARGE;
	return (0);
}
