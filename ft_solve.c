/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 14:14:53 by jmousset          #+#    #+#             */
/*   Updated: 2019/06/04 08:32:11 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_is_safe(t_tetro *tetro, t_board *board, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	while (i < tetro->width)
	{
		j = 0;
		while (j < tetro->height)
		{
			if (board->res[y + j][x + i] != '.' && tetro->pos[j][i] == '#')
				return (0);
			j++;
		}
		i++;
	}
	ft_place_tetro(tetro, board, x, y);
	return (1);
}

void		ft_place_tetro(t_tetro *tetro, t_board *board, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	while (i < tetro->width)
	{
		j = 0;
		while (j < tetro->height)
		{
			if (tetro->pos[j][i] == '#')
				board->res[y + j][x + i] = tetro->letter;
			j++;
		}
		i++;
	}
}

void		ft_remove_tetro(t_tetro *tetro, t_board *board, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	while (i < tetro->width)
	{
		j = 0;
		while (j < tetro->height)
		{
			if (tetro->pos[j][i] == '#')
				board->res[y + j][x + i] = '.';
			j++;
		}
		i++;
	}
}

int			ft_fillit(t_tetro *tetro, t_board *board, int count, int size)
{
	int		x;
	int		y;

	if (count == board->count)
		return (1);
	y = 0;
	while (y < size - tetro[count].height + 1)
	{
		x = 0;
		while (x < size - tetro[count].width + 1)
		{
			if (ft_is_safe(&tetro[count], board, x, y))
			{
				count++;
				if (ft_fillit(tetro, board, count, size))
					return (1);
				ft_remove_tetro(&tetro[--count], board, x, y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

t_board		*ft_solve(t_tetro *tetro, char *file, int count, int size)
{
	t_board	*board;
	int		i;
	int		fd;
	int		ret;
	char	buff[BUFF_SIZE];

	i = 0;
	board = ft_create_board(size);
	fd = open(file, O_RDONLY);
	while ((ret = read(fd, buff, BUFF_SIZE)))
		i++;
	board->count = i;
	while (!ft_fillit(tetro, board, count, size))
	{
		size++;
		ft_free_board(board);
		board = ft_create_board(size);
		board->count = i;
	}
	return (board);
}
