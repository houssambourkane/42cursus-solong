/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:52:07 by hbourkan          #+#    #+#             */
/*   Updated: 2021/12/21 16:15:21 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	success(t_var *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	vars->win = mlx_new_window(vars->mlx, 1000, 600, "So Long");
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img7, 0, 0);
	mlx_key_hook(vars->win, key_press3, vars);
	mlx_hook(vars->win, 17, 0, cross_window, (void *)0);
	mlx_loop(vars->mlx);
}

void	programme(t_var *vars)
{
	int	w;
	int	h;

	vars->c = vars->counter_c;
	vars->oldx = 0;
	vars->oldy = 0;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 1000, 600, "So Long");
	vars->img1 = mlx_xpm_file_to_image(vars->mlx, vars->wall, &w, &h);
	vars->img2 = mlx_xpm_file_to_image(vars->mlx, vars->collectible, &w, &h);
	vars->img3 = mlx_xpm_file_to_image(vars->mlx, vars->player, &w, &h);
	vars->img4 = mlx_xpm_file_to_image(vars->mlx, vars->exit, &w, &h);
	vars->img5 = mlx_xpm_file_to_image(vars->mlx, vars->marron, &w, &h);
	vars->img6 = mlx_xpm_file_to_image(vars->mlx, vars->begin, &w, &h);
	vars->img7 = mlx_xpm_file_to_image(vars->mlx, vars->success, &w, &h);
	if (!vars->img1 || !vars->img2 || !vars->img3 || !vars->img4
		|| !vars->img5 || !vars->img6 || !vars->img7)
	{
		perror("Error\nXPM IS DAMAGED");
		exit(1);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img6, 0, 0);
	mlx_key_hook(vars->win, key_press2, vars);
	mlx_hook(vars->win, 17, 0, cross_window, (void *)0);
	mlx_loop(vars->mlx);
}

void	map_dimension(t_var *vars, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (line)
		first_linecheck(line);
	while (line)
	{
		vars->storage = ft_strjoin(vars->storage, line);
		free(line);
		line = get_next_line(fd);
		if (line)
		{
			if (ft_strchr(line, '\n') == -1)
			{
				while (line[vars->width])
					vars->width++;
				last_linecheck(line);
			}
			else if (ft_strchr(line, '\n') != -1)
				linecheck(line);
		}
		(vars->height)++;
	}
}

void	get_map(t_var *vars, char *argv)
{
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		perror("Error\nMAP NOT FOUND");
		exit(1);
	}
	vars->storage = ft_strdup("");
	alloc_fail(&vars->storage);
	map_dimension(vars, fd);
	check_characters(vars->storage);
	check_rectangular_map(vars);
	check_othercharacters(vars);
	vars->counter_c = 0;
	counter_collec(vars);
	if (close(fd) == -1)
	{
		perror("Error\n");
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_var	vars;

	if (argc == 2)
	{
		vars.wall = ft_strdup("../img/wall.xpm");
		vars.collectible = ft_strdup("../img/deka.xpm");
		vars.player = ft_strdup("../img/molndader2.xpm");
		vars.exit = ft_strdup("../img/sewer.xpm");
		vars.marron = ft_strdup("../img/cloud.xpm");
		vars.begin = ft_strdup("../img/start.xpm");
		vars.success = ft_strdup("../img/success.xpm");
		if (!vars.wall || !vars.collectible || !vars.player
			|| !vars.exit || !vars.marron || !vars.begin || !vars.success)
		{
			printf("Error\nAllocation failed !\n");
			exit(1);
		}
		vars.width = 0;
		vars.height = 0;
		get_map(&vars, argv[1]);
		programme(&vars);
		free_img(&vars);
	}
	else
		return (0);
}
