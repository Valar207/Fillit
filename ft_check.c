/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 14:02:11 by vrossi            #+#    #+#             */
/*   Updated: 2019/06/04 16:57:46 by vrossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_line(char *buff)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buff[i])
	{
		i = i + 4;
		if (buff[i] == '\n')
			j++;
		i++;
	}
	if (j != 4)
		return (0);
	return (1);
}

int		ft_check_char(char *buff)
{
	int		i;
	int		ischar;

	i = 0;
	ischar = 0;
	while (buff[i])
	{
		if (buff[i] == '.' || buff[i] == '#')
		{
			ischar++;
			i++;
		}
		else
			i++;
	}
	if (ischar != 16)
		return (0);
	return (1);
}

int		ft_check_hash(char *buff)
{
	int		i;
	int		h;

	i = 0;
	h = 0;
	while (buff[i])
	{
		if (buff[i] == '#')
			h++;
		i++;
	}
	if (h != 4)
		return (0);
	return (1);
}

int		ft_check_tetro(char *buff)
{
	int		i;
	int		link;

	i = 0;
	link = 0;
	while (buff[i])
	{
		if (buff[i] == '#')
		{
			if (buff[i + 1] == '#')
				link++;
			if (buff[i - 1] == '#')
				link++;
			if (buff[i + 5] == '#')
				link++;
			if (buff[i - 5] == '#')
				link++;
		}
		i++;
	}
	if (link != 6 && link != 8)
		return (0);
	return (1);
}

int		ft_check_file(char *file)
{
	char	*buff;
	int		fd;
	int		ret;
	int		i;

	i = 0;
	buff = ft_strnew(BUFF_SIZE);
	fd = open(file, O_RDONLY);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		if (ft_check_line(buff) == 0 || ft_check_char(buff) == 0 ||
				ft_check_hash(buff) == 0 || ft_check_tetro(buff) == 0 || i > 25)
			return (ft_free_buffer(buff, fd));
		i++;
	}
	if ((buff[BUFF_SIZE] != '\0' || buff[BUFF_SIZE - 1] == '\n') ||
		(buff[0] != '.' && buff[0] != '#'))
		return (ft_free_buffer(buff, fd));
	close(fd);
	ft_memdel((void **)&buff);
	return (1);
}
