/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 14:59:14 by hbourkan          #+#    #+#             */
/*   Updated: 2021/12/21 16:03:21 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	counter_collec(t_var *vars)
{
	int	i;

	i = 0;
	while (vars->storage[i])
	{
		if (vars->storage[i] == 'C')
			vars->counter_c += 1;
		i++;
	}
}

void	alloc_fail(char **str)
{
	if (!*str)
	{
		printf("Error\nAllocation failed");
		exit(1);
	}
}

void	free_tabs(t_var *vars)
{
	free(vars->tabx);
	free(vars->taby);
	vars->tabx = NULL;
	vars->taby = NULL;
}

void	check_img(t_var *vars)
{
	if (!vars->img1 || !vars->img2 || !vars->img3 || !vars->img4
		|| !vars->img5 || !vars->img6 || !vars->img7 || !vars->img8
		|| !vars->img9 || !vars->img10)
	{
		perror("Error\nXPM IS DAMAGED");
		exit(1);
	}
}

void	check_dup(t_var *vars)
{
	if (!vars->wall || !vars->collectible || !vars->player || !vars->exit
		|| !vars->marron || !vars->begin || !vars->success || !vars->right
		|| !vars->middle || !vars->fail)
	{
		printf("Error\nAllocation failed !\n");
		exit(1);
	}
}
