/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:11:22 by fallouch          #+#    #+#             */
/*   Updated: 2018/12/03 19:05:32 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/includes/libft.h"
# define BUFF_SIZE 21

typedef struct		s_etris
{
	int					n;
	char				*content;
	struct s_etris		*next;
}					t_etris;

t_etris				*read_file(char *file);
t_etris				*check(char *file);
char				*push_up(char *str);
char				*push_left(char *str);
void				free_tab(char **tab);
char				*tab_to_str(char **tab);
char				**str_to_tab(char *str);
void				shaping(t_etris *begin);
int					ft_sqrt(t_etris *begin);
void				free_list(t_etris **begin);
int					replace(char **str, char a, char b);
int					solve(char *map, int size, t_etris *begin, char x);
int					print_map(char *map, int size, t_etris *begin);
char				*new_map(int size);
void				initialize(int *a, int *b, int *c);
int					lstlen(t_etris *begin);

#endif
