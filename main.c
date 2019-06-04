/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 17:39:14 by jmousset          #+#    #+#             */
/*   Updated: 2019/06/04 11:44:03 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	t_tetro	*tetro;
	t_board	*board;
	int		count;
	int		size;

	count = 0;
	size = 2;
	if (ac != 2)
	{
		ft_putstr("usage: fillit source_file\n");
		exit(EXIT_FAILURE);
	}
	if (!ft_check_file(av[1]))
	{
		ft_putstr("error\n");
		exit(EXIT_FAILURE);
	}
	tetro = ft_store(av[1]);
	board = ft_solve(tetro, av[1], count, size);
	ft_print_board(board);
	ft_free_board(board);
	exit(EXIT_SUCCESS);
}
