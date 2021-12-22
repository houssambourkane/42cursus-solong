/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_draw_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:42:51 by hbourkan          #+#    #+#             */
/*   Updated: 2021/12/21 12:59:19 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	found_wall(t_var *vars, int keycode)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img1, vars->x, vars->y);
	collision(vars, keycode);
	vars->x += MARGE;
}

static void	found_collectible(t_var *vars)
{
	if (vars->oldx == vars->x && vars->oldy == vars->y)
	{
		if (checktabs(vars))
		{
			vars->tabx[vars->tab_index] = vars->x;
			vars->taby[vars->tab_index] = vars->y;
			vars->c--;
			vars->tab_index++;
		}
	}
	else if (checkxy(vars))
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img2, vars->x, vars->y);
	vars->x += MARGE;
}

static void	found_exit(t_var *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img4, vars->x, vars->y);
	if ((vars->oldx == vars->x && vars->oldy == vars->y))
	{
		if (vars->c == 0)
		{
			usleep(500000);
			success(vars);
		}	
		else
			printf("Drink all the tea before exiting ! \n");
	}
	vars->x += MARGE;
}

void	next_lines(t_var *vars, int keycode, char *line)
{
	int	i;

	i = 0;
	if (line)
	{
		while (line[i])
		{
			if (line[i] == '0' || line[i] == 'P')
				vars->x += MARGE;
			else if (line[i] == '1')
				found_wall(vars, keycode);
			else if (line[i] == 'C')
				found_collectible(vars);
			else if (line[i] == 'E')
				found_exit(vars);
			i++;
		}
		vars->y = vars->y + MARGE;
	}
}
