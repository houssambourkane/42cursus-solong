/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 14:47:35 by hbourkan          #+#    #+#             */
/*   Updated: 2021/12/21 16:13:20 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	background(t_var *vars)
{
	int	i;

	i = 0;
	vars->x = 0;
	vars->y = 0;
	while ((vars->storage)[i])
	{
		if ((vars->storage)[i] == '\n')
		{
			vars->y += MARGE;
			vars->x = 0;
		}
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img5, vars->x, vars->y);
		vars->x += MARGE;
		i++;
	}
}

void	window_draw(t_var *vars, int keycode)
{
	char		*line;
	char		*temp;

	vars->x = 0;
	vars->y = 0;
	temp = ft_strdup(vars->storage);
	alloc_fail(&temp);
	while (temp)
	{
		vars->x = 0;
		line = get_next_line2(&temp);
		next_lines(vars, keycode, line);
		free(line);
	}
	free(temp);
}

void	new_draw(t_var *vars, int keycode)
{
	vars->compteur = 0;
	vars->x = 0;
	vars->y = 0;
	vars->oldx = 0;
	vars->oldy = 0;
	vars->tab_index = 0;
	vars->c = vars->counter_c;
	vars->tabx = malloc(sizeof(int) * vars->counter_c);
	vars->taby = malloc(sizeof(int) * vars->counter_c);
	if (!vars->tabx || !vars->taby)
	{
		printf("Error\nAllocation failed !\n");
		exit(1);
	}
	background(vars);
	window_draw(vars, keycode);
	player_draw(vars);
}

void	free_img(t_var *vars)
{
	free(vars->wall);
	free(vars->collectible);
	free(vars->player);
	free(vars->exit);
	free(vars->marron);
	free(vars->begin);
	free(vars->success);
	free(vars->right);
	free(vars->middle);
	free(vars->fail);
}
