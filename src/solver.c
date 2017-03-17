/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apisotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 17:00:36 by apisotsk          #+#    #+#             */
/*   Updated: 2017/03/01 15:17:15 by apisotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

short		high_sqrt(short n)
{
	short	size;

	size = 2;
	while (size * size < n)
		size++;
	return (size);
}

short		solve_map(t_map *map, t_list *list)
{
	short	x;
	short	y;
	t_minus	*minus;

	if (list == NULL)
		return (1);
	y = -1;
	minus = (t_minus*)(list->content);
	while (++y < map->size - minus->height + 1)
	{
		x = -1;
		while (++x < map->size - minus->lenght + 1)
			if (can_fill(map, minus, new_point(x, y)))
			{
				if (solve_map(map, list->next))
					return (1);
				else
					fill(map, minus, new_point(x, y), '.');
			}
	}
	return (0);
}

t_map		*solve(t_list *list)
{
	t_map	*map;
	short	size;

	size = high_sqrt(ft_lstcount(list) * 4);
	map = create_map(size);
	while (!solve_map(map, list))
	{
		size++;
		free_map(map);
		map = create_map(size);
	}
	return (map);
}
