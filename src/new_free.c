/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apisotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 17:00:17 by apisotsk          #+#    #+#             */
/*   Updated: 2017/02/22 17:00:19 by apisotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

t_point		*new_point(char x, char y)
{
	t_point	*new;

	if (!(new = (t_point*)malloc(sizeof(t_point))))
		return (NULL);
	new->x = x;
	new->y = y;
	return (new);
}

t_minus		*new_minus(char **arr, char fill, char lenght, char height)
{
	t_minus *minus;

	if (!(minus = (t_minus*)malloc(sizeof(t_minus))))
		return (NULL);
	minus->tet = arr;
	minus->fill = fill;
	minus->lenght = lenght;
	minus->height = height;
	minus->is_used = 0;
	return (minus);
}

static void	free_minus(t_minus *minus)
{
	short	i;

	i = -1;
	while (++i < minus->height)
		ft_memdel((void**)&(minus->tet[i]));
	ft_memdel((void**)&(minus->tet));
	ft_memdel((void**)&minus);
}

t_list		*free_list(t_list *head)
{
	t_minus	*minus;
	t_list	*next;

	while (head)
	{
		minus = (t_minus*)head->content;
		free_minus(minus);
		next = head->next;
		ft_memdel((void**)&head);
		head = next;
	}
	return (NULL);
}
