/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linechecks_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 13:45:16 by hbourkan          #+#    #+#             */
/*   Updated: 2021/12/21 15:57:55 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	first_linecheck(char *str)
{
	int	i;

	i = 0;
	if (ft_strchr(str, '\n') != -1)
	{
		while (str[i] != '\n')
		{
			if (str[i] == '1')
				i++;
			else
			{
				printf("Error\nNO WALL IN THE FIRST LINE\n");
				exit(1);
			}
		}
	}
}

void	last_linecheck(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '1')
			i++;
		else
		{
			printf("Error\nNO WALL IN THE LAST LINE\n");
			exit(1);
		}
	}
}

void	linecheck(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	if (str[i] != '1' || str[len - 2] != '1')
	{
		printf("Error\nNO WALL IN THE EDGES\n");
		exit(1);
	}
}

void	check_characters(char *str)
{
	if (ft_strchr(str, 'E') == -1 || ft_strchr(str, 'C') == -1
		|| ft_strchr(str, 'P') == -1)
	{
		printf("Error\nA CHARACTER OR MORE IS/ARE NOT AVAILABLE !\n");
		exit(1);
	}
}
