/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apisotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 18:35:19 by apisotsk          #+#    #+#             */
/*   Updated: 2016/12/23 19:02:57 by apisotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./libft.h"

typedef struct	s_map
{
	char		**arr;
	short		size;
}				t_map;

typedef struct	s_point
{
	short		x;
	short		y;
}				t_point;

typedef	struct	s_minus
{
	char		**tet;

	char		fill;
	char		is_used;
	short		lenght;
	short		height;
}				t_minus;

t_list			*free_list(t_list *head);
void			print_map(t_map *map);
void			free_map(t_map *map);
void			fill(t_map *map, t_minus *minus, t_point *p, char ill);
t_map			*create_map(char size);
t_map			*solve(t_list *list);
t_list			*read_m(int fd);
t_minus			*new_minus(char **str, char fill, char l, char h);
t_point			*new_point(char x, char y);
char			can_fill(t_map *map, t_minus *minus, t_point *p);

#endif
