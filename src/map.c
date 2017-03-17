/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apisotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 17:00:07 by apisotsk          #+#    #+#             */
/*   Updated: 2017/02/23 02:50:51 by apisotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void		print_map(t_map *map)
{
	short	i;

	i = -1;
	while (++i < map->size)
		ft_putendl(map->arr[(int)i]);
}

t_map		*create_map(char size)
{
	t_map	*map;
	short	i;

	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	map->size = size;
	if (!(map->arr = (char**)malloc(sizeof(char*) * size)))
		return (NULL);
	i = -1;
	while (++i < size)
	{
		if (!(map->arr[i] = ft_strnew(size)))
			return (NULL);
		ft_memset(map->arr[i], '.', size);
	}
	return (map);
}

void		free_map(t_map *map)
{
	short	i;

	i = -1;
	while (++i < map->size)
		ft_memdel((void**)&(map->arr[i]));
	ft_memdel((void**)&(map->arr));
	ft_memdel((void**)&map);
}

void		fill(t_map *map, t_minus *minus, t_point *p, char fill_)
{
	short	i;
	short	j;

	i = -1;
	while (++i < minus->height)
	{
		j = -1;
		while (++j < minus->lenght)
			if (minus->tet[i][j] == '#')
				map->arr[p->y + i][p->x + j] = fill_;
	}
	ft_memdel((void**)&p);
}

char		can_fill(t_map *map, t_minus *minus, t_point *p)
{
	short	i;
	short	j;

	i = -1;
	while (++i < minus->height)
	{
		j = -1;
		while (++j < minus->lenght)
			if (minus->tet[i][j] == '#' && map->arr[i + p->y][j + p->x] != '.')
				return (0);
	}
	fill(map, minus, p, minus->fill);
	return (1);
}
