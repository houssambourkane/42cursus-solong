/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 20:52:21 by hbourkan          #+#    #+#             */
/*   Updated: 2021/12/21 16:17:39 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw(t_var *vars, int keycode)
{
	background(vars);
	window_draw(vars, keycode);
	player_draw(vars);
	vars->compteur += 1;
}

void	movement(t_var *vars, int keycode)
{
	if (keycode == 0 || keycode == 123)
	{
		mlx_clear_window(vars->mlx, vars->win);
		vars->oldx -= MARGE;
		draw(vars, keycode);
	}
	if (keycode == 1 || keycode == 125)
	{
		mlx_clear_window(vars->mlx, vars->win);
		vars->oldy += MARGE;
		draw(vars, keycode);
	}
	if (keycode == 2 || keycode == 124)
	{
		mlx_clear_window(vars->mlx, vars->win);
		vars->oldx += MARGE;
		draw(vars, keycode);
	}
	if (keycode == 13 || keycode == 126)
	{
		mlx_clear_window(vars->mlx, vars->win);
		vars->oldy -= MARGE;
		draw(vars, keycode);
	}
}

static void	player_loop(t_var *vars, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'P')
		{
			if (vars->oldx == 0 && vars->oldy == 0)
			{
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->img3, vars->x, vars->y);
				vars->oldx = vars->x;
				vars->oldy = vars->y;
			}
			else
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->img3, vars->oldx, vars->oldy);
		}
		vars->x += MARGE;
		i++;
	}
}

void	player_draw(t_var *vars)
{
	char	*line;
	char	*temp;

	vars->x = 0;
	vars->y = 0;
	temp = ft_strdup(vars->storage);
	alloc_fail(&temp);
	while (temp)
	{
		vars->x = 0;
		line = get_next_line2(&temp);
		player_loop(vars, line);
		vars->y += MARGE;
		free(line);
	}
}
