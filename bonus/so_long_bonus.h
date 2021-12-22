/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:52:06 by hbourkan          #+#    #+#             */
/*   Updated: 2021/12/21 16:09:25 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <mlx.h>
# define BUFFER_SIZE 1
# define MARGE 100

typedef struct s_var
{
	void	*mlx;
	void	*win;
	void	*img1;
	void	*img2;
	void	*img3;
	void	*img4;
	void	*img5;
	void	*img6;
	void	*img7;
	void	*img8;
	void	*img9;
	void	*img10;
	char	*wall;
	char	*collectible;
	char	*player;
	char	*exit;
	char	*marron;
	char	*begin;
	char	*success;
	char	*storage;
	int		width;
	int		height;
	int		x;
	int		y;
	int		*tabx;
	int		*taby;
	int		oldx;
	int		oldy;
	int		compteur;
	int		counter_c;
	int		c;
	int		tab_index;
	char	*right;
	char	*middle;
	char	*fail;
	int		x2;
	int		y2;
}	t_var;

void	programme(t_var *vars);
void	success(t_var *vars);
void	fail(t_var *vars);
int		key_press(int keycode, t_var *vars);
int		key_press2(int keycode, t_var *vars);
int		key_press3(int keycode, t_var *vars);
int		cross_window(int keycode);
void	counter_collec(t_var *vars);
void	new_draw(t_var *vars, int keycode);
void	background(t_var *vars);
void	window_draw(t_var *vars, int keycode);
void	player_draw(t_var *vars);
void	movement(t_var *vars, int keycode);
void	next_lines(t_var *vars, int keycode, char *line);
void	first_linecheck(char *str);
void	last_linecheck(char *str);
void	linecheck(char *str);
void	check_characters(char *str);
void	collision(t_var *vars, int keycode);
int		checkxy(t_var *vars);
int		checktabs(t_var *vars);
void	check_rectangular_map(t_var *vars);
void	check_othercharacters(t_var *vars);
void	check_img(t_var *vars);
void	check_dup(t_var *vars);
void	alloc_fail(char **str);
void	free_tabs(t_var *vars);
size_t	ft_strlen(const char *str);
char	*ft_strdup(char *s1);
char	*ft_strndup(char const *s1, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
char	*get_next_line2(char **str);
char	*with_newline(char **storage);
char	*no_newline(char **storage);
void	loop(char **storage, char **buffer, int fd);
char	*ft_itoa(int n);
int		sprite(t_var *vars);
void	free_img(t_var *vars);
#endif