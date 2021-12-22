/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:45:38 by hbourkan          #+#    #+#             */
/*   Updated: 2021/12/16 15:06:16 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_next_line2(char **str)
{
	char	*line;
	char	*temp;
	int		i;

	if (ft_strchr(*str, '\n') != -1)
	{
		i = ft_strchr(*str, '\n');
		line = ft_substr(*str, 0, i);
		temp = *str;
		*str = ft_substr(*str, i + 1, ft_strlen(*str + i));
		free(temp);
	}
	else
	{
		line = ft_substr(*str, 0, ft_strlen(*str));
		free(*str);
		*str = NULL;
	}
	return (line);
}
