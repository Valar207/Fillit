/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 09:52:47 by jmousset          #+#    #+#             */
/*   Updated: 2019/06/04 16:56:56 by vrossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

# define BUFF_SIZE 21

typedef struct	s_tetro
{
	char		pos[4][4];
	int			width;
	int			height;
	char		letter;
}				t_tetro;

typedef struct	s_board
{
	int			size;
	char		**res;
	int			count;
}				t_board;

int				ft_check_file(char *file);
int				ft_check_line(char *buff);
int				ft_check_char(char *buff);
int				ft_check_hash(char *buff);
int				ft_check_tetro(char *buff);
t_board			*ft_create_board(int size);
void			ft_free_board(t_board *board);
void			ft_print_board(t_board *board);
int				ft_free_buffer(char *buff, int fd);
t_tetro			*ft_store(char *file);
t_tetro			*ft_save_tetro(char *file, int i);
t_tetro			ft_fill_coord(char *file, char letter, int col, int line);
char			*ft_up_left(char *f);
void			ft_set_pos(t_tetro *tetro, char *buff, int i);
t_board			*ft_solve(t_tetro *tetro, char *file, int count, int size);
int				ft_fillit(t_tetro *tetro, t_board *board, int count, int size);
int				ft_is_safe(t_tetro *tetro, t_board *board, int x, int y);
void			ft_place_tetro(t_tetro *tetro, t_board *board, int x, int y);
void			ft_remove_tetro(t_tetro *tetro, t_board *board, int x, int y);

#endif
