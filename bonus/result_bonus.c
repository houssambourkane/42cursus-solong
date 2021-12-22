/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:52:54 by hbourkan          #+#    #+#             */
/*   Updated: 2021/12/18 14:40:36 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	fail(t_var *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	vars->win = mlx_new_window(vars->mlx, 1000, 600, "So Long");
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img10, 0, 0);
	mlx_key_hook(vars->win, key_press3, vars);
	mlx_hook(vars->win, 17, 0, cross_window, (void *)0);
	mlx_loop(vars->mlx);
}

void	success(t_var *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	vars->win = mlx_new_window(vars->mlx, 1000, 600, "So Long");
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img7, 0, 0);
	mlx_key_hook(vars->win, key_press3, vars);
	mlx_hook(vars->win, 17, 0, cross_window, (void *)0);
	mlx_loop(vars->mlx);
}
