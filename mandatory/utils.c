/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 14:59:14 by hbourkan          #+#    #+#             */
/*   Updated: 2021/12/21 16:12:31 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	free_img(t_var *vars)
{
	free(vars->wall);
	free(vars->collectible);
	free(vars->player);
	free(vars->exit);
	free(vars->marron);
	free(vars->begin);
	free(vars->success);
}
