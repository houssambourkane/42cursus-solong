/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:57:57 by hbourkan          #+#    #+#             */
/*   Updated: 2021/12/21 15:55:34 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	cross_window(int keycode)
{
	(void)keycode;
	printf("Exit !\n");
	exit(0);
}

int	key_press(int keycode, t_var *vars)
{
	if (keycode == 53)
	{
		printf("Exit !\n");
		exit(0);
	}
	if (keycode == 15)
	{
		printf("Game restarted !\n");
		free_tabs(vars);
		new_draw(vars, keycode);
	}
	movement(vars, keycode);
	printf("Compteur =  %d\n", vars->compteur);
	return (0);
}

int	key_press2(int keycode, t_var *vars)
{
	if (keycode == 53)
	{
		printf("Exit !\n");
		exit(0);
	}
	if (keycode == 11)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		vars->win = mlx_new_window(vars->mlx, vars->width * 100,
				vars->height * 100, "So Long");
		new_draw(vars, keycode);
		mlx_hook(vars->win, 2, 0, key_press, vars);
		mlx_hook(vars->win, 17, 0, cross_window, (void *)0);
	}
	return (0);
}

int	key_press3(int keycode, t_var *vars)
{
	if (keycode == 53)
	{
		printf("Exit !\n");
		exit(0);
	}
	if (keycode == 15)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		free_tabs(vars);
		vars->win = mlx_new_window(vars->mlx, vars->width * 100,
				vars->height * 100, "So Long");
		new_draw(vars, keycode);
		mlx_hook(vars->win, 2, 0, key_press, vars);
		mlx_hook(vars->win, 17, 0, cross_window, (void *)0);
	}
	return (0);
}
