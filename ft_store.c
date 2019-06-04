/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:53:22 by jmousset          #+#    #+#             */
/*   Updated: 2019/06/04 11:51:17 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_set_pos(t_tetro *tetro, char *buff, int i)
{
	int		b;
	int		x;
	int		y;

	b = 0;
	x = 0;
	while (buff[b])
	{
		y = 0;
		while (buff[b] != '\n')
		{
			tetro[i].pos[x][y] = buff[b];
			b++;
			y++;
		}
		x++;
		b++;
	}
}

char		*ft_up_left(char *f)
{
	int		i;

	i = 0;
	if (f[0] == '.' && f[5] == '.' && f[10] == '.' && f[15] == '.')
	{
		while (f[i])
		{
			(f[i] == '#' ? f[i - 1] = '#' : f[i]);
			(f[i] == '#' ? f[i] = '.' : f[i]);
			i++;
		}
	}
	if (f[0] == '.' && f[1] == '.' && f[2] == '.' && f[3] == '.')
	{
		while (f[i])
		{
			(f[i] == '#' ? f[i - 5] = '#' : f[i]);
			(f[i] == '#' ? f[i] = '.' : f[i]);
			i++;
		}
	}
	if ((f[0] == '.' && f[5] == '.' && f[10] == '.' && f[15] == '.')
			|| (f[0] == '.' && f[1] == '.' && f[2] == '.' && f[3] == '.'))
		f = ft_up_left(f);
	return (f);
}

t_tetro		ft_fill_coord(char *file, char letter, int col, int line)
{
	t_tetro	tetro;
	int		i;

	tetro.letter = letter;
	tetro.width = 0;
	tetro.height = 0;
	i = 0;
	file = ft_up_left(file);
	while (*(file))
	{
		(*(file - 1) == '\n' ? col = 0 : col);
		(*(file) == '\n' ? line++ : line);
		if (*(file) == '#')
		{
			tetro.width = tetro.width <= col ? col + 1 : tetro.width;
			tetro.height = tetro.height <= line ? line + 1 : tetro.height;
			i++;
		}
		col++;
		file++;
	}
	return (tetro);
}

t_tetro		*ft_save_tetro(char *file, int i)
{
	int		fd;
	int		ret;
	char	buff[BUFF_SIZE];
	char	letter;
	t_tetro	*tetro;

	letter = 'A';
	if (!(tetro = (t_tetro *)malloc(sizeof(t_tetro) * i)))
		return (NULL);
	i = 0;
	fd = open(file, O_RDONLY);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		tetro[i] = ft_fill_coord(buff, letter, 0, 0);
		ft_set_pos(tetro, buff, i);
		i++;
		letter++;
	}
	return (tetro);
}

t_tetro		*ft_store(char *file)
{
	int		i;
	int		fd;
	int		ret;
	char	buff[BUFF_SIZE];

	i = 0;
	fd = open(file, O_RDONLY);
	while ((ret = read(fd, buff, BUFF_SIZE)))
		i++;
	close(fd);
	return (ft_save_tetro(file, i));
}
