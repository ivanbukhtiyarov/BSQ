/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsqhead.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 14:49:17 by lfilius           #+#    #+#             */
/*   Updated: 2019/08/19 19:15:18 by lfilius          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQHEAD_H
# define BSQHEAD_H

int		ft_atoi(char *str);
int     ft_strlen(char *str);
void	error();
int     ft_valid_number(int n, char *adr, int *digit);
int     ft_valid_char(int *digit , char c);
int     *ft_solve(int n, char *adr, int *digit);
int     ft_fill_int(int *digit, char c);
int		min_val(int **hash, int i, int j);
int		*find_max_square(int **hash, int y, int x);
int		*line_process(char *str);
int		dif_sym(char x, char y, char z);
char	*first_line_cut(char **av);
#endif
