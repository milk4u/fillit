/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apisotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 03:13:22 by apisotsk          #+#    #+#             */
/*   Updated: 2017/02/23 03:13:23 by apisotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../includes/fillit.h"

int		main(int argc, char **argv)
{
	t_list	*head;
	t_map	*map;

	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (1);
	}
	if ((head = (t_list*)read_m(open(argv[1], O_RDONLY))) == NULL)
	{
		ft_putstr("error\n");
		return (2);
	}
	map = solve(head);
	print_map(map);
	free_map(map);
	free_list(head);
	return (0);
}
