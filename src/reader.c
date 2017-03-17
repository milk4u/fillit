/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apisotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 17:00:26 by apisotsk          #+#    #+#             */
/*   Updated: 2017/02/23 02:49:43 by apisotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static char			check_border(char *str, char size)
{
	short	i;
	short	borders;

	i = -1;
	borders = 0;
	while (++i < size)
		if (str[i] == '#')
		{
			if ((str[i + 1] == '#') && (i + 1 < size))
				borders++;
			if ((str[i + 5] == '#') && (i + 5 < size))
				borders++;
		}
	if (borders == 3 || borders == 4)
		return (1);
	return (0);
}

static char			check_count(char *str, char size)
{
	short			i;
	char			count;

	i = -1;
	count = 0;
	while (++i < size)
	{
		if (str[i] == '\n' && i == 20)
			;
		else if (((i % 5 < 4) && (str[i] != '.' && str[i] != '#'))
				|| ((i % 5 == 4) && (str[i] != '\n')))
			return (0);
		if (str[i] == '#')
			count++;
	}
	if (count == 4)
		return (1);
	return (0);
}

static void			get_points(char *str, t_point *left_up, t_point *right_down)
{
	short			i;

	i = -1;
	while (++i < 20)
		if (str[i] == '#')
		{
			if ((i / 5) < left_up->y)
				left_up->y = i / 5;
			if ((i % 5) < left_up->x)
				left_up->x = i % 5;
			if ((i / 5) > right_down->y)
				right_down->y = i / 5;
			if ((i % 5) > right_down->x)
				right_down->x = i % 5;
		}
}

static t_minus		*cut(char *str, char fill, short size)
{
	t_minus			*minus;
	short			i;
	char			**arr;
	t_point			*st;
	t_point			*ed;

	st = new_point(3, 3);
	ed = new_point(0, 0);
	get_points(str, st, ed);
	if (!(arr = (char**)malloc(sizeof(char*) * (ed->y - st->y + 1))))
		return (NULL);
	i = -1;
	while (++i < ed->y - st->y + 1)
	{
		arr[i] = ft_strnew(ed->x - st->x + 1);
		ft_strncpy(arr[i], str + st->x + (i + st->y) * 5, ed->x - st->x + 1);
	}
	minus = new_minus(arr, fill, ed->x - st->x + 1, ed->y - st->y + 1);
	ft_memdel((void**)&st);
	ft_memdel((void**)&ed);
	str[20] = size;
	return (minus);
}

t_list				*read_m(int fd)
{
	char			*buff;
	t_list			*head;
	t_minus			*minus;
	char			fill;
	short			count;

	buff = ft_strnew(21);
	head = NULL;
	fill = 'A';
	while (((count = read(fd, buff, 21)) >= 20) && (fill <= 'Z'))
	{
		if (!check_count(buff, count) || !check_border(buff, count))
			break ;
		minus = cut(buff, fill++, count);
		ft_lstadd(&head, ft_lstnew(minus, sizeof(t_minus)));
		ft_memdel((void**)&minus);
	}
	if (count > 0 || buff[20] == 21)
		return (free_list(head));
	ft_memdel((void**)&buff);
	ft_lstrev(&head);
	return (head);
}
