/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 20:45:45 by hbourkan          #+#    #+#             */
/*   Updated: 2021/12/21 15:56:32 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	collision(t_var *vars, int keycode)
{
	if (vars->oldx == vars->x && vars->oldy == vars->y)
	{
		if (keycode == 0 || keycode == 123)
		{
			vars->oldx += MARGE;
			vars->compteur--;
		}
		else if (keycode == 1 || keycode == 125)
		{
			vars->oldy -= MARGE;
			vars->compteur--;
		}
		else if (keycode == 2 || keycode == 124)
		{
			vars->oldx -= MARGE;
			vars->compteur--;
		}
		else if (keycode == 13 || keycode == 126)
		{
			vars->oldy += MARGE;
			vars->compteur--;
		}
	}
}

int	checkxy(t_var *vars)
{
	int	i;

	i = 0;
	while (i < vars->counter_c)
	{
		if (vars->tabx[i] == vars->x && vars->taby[i] == vars->y)
			return (0);
		i++;
	}
	return (1);
}

int	checktabs(t_var *vars)
{
	int	i;

	i = 0;
	while (i < vars->counter_c)
	{
		if (vars->oldx == vars->tabx[i] && vars->oldy == vars->taby[i])
			return (0);
		i++;
	}
	return (1);
}

void	check_rectangular_map(t_var *vars)
{
	char	*temp;
	char	*line;
	int		i;

	temp = ft_strdup(vars->storage);
	alloc_fail(&temp);
	while (temp)
	{
		i = 0;
		line = get_next_line2(&temp);
		while (line[i])
			i++;
		if (i != vars->width)
		{
			printf("Error\nMap not rectangular !\n");
			exit(1);
		}
		free(line);
	}
}

void	check_othercharacters(t_var *vars)
{
	char	*temp;
	char	*line;
	int		i;

	temp = ft_strdup(vars->storage);
	alloc_fail(&temp);
	while (temp)
	{
		i = 0;
		line = get_next_line2(&temp);
		while (line[i])
		{
			if (line[i] != '1' && line[i] != '0' && line[i] != 'C'
				&& line[i] != 'P' && line[i] != 'E')
			{
				printf("Error\nother characters");
				exit(1);
			}
			i++;
		}
		free(line);
	}
}
