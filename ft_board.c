/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_board.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 11:25:35 by jmousset          #+#    #+#             */
/*   Updated: 2019/06/04 17:02:56 by vrossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_board	*ft_create_board(int size)
{
	t_board	*board;
	int		i;
	int		j;

	board = (t_board *)ft_memalloc(sizeof(t_board));
	board->size = size;
	board->res = (char **)ft_memalloc(sizeof(char *) * size);
	i = 0;
	while (i < size)
	{
		board->res[i] = ft_strnew(size);
		j = 0;
		while (j < size)
		{
			board->res[i][j] = '.';
			j++;
		}
		i++;
	}
	return (board);
}

void	ft_free_board(t_board *board)
{
	int		i;

	i = 0;
	while (i < board->size)
	{
		ft_memdel((void **)&(board->res[i]));
		i++;
	}
	ft_memdel((void **)&(board->res));
	ft_memdel((void **)&board);
}

void	ft_print_board(t_board *board)
{
	int		i;

	i = 0;
	while (i < board->size)
	{
		ft_putstr(board->res[i]);
		ft_putchar('\n');
		i++;
	}
}

int		ft_free_buffer(char *buff, int fd)
{
	ft_memdel((void **)&buff);
	close(fd);
	return (0);
}
