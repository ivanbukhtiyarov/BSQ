/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   firstline.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 19:13:02 by lfilius           #+#    #+#             */
/*   Updated: 2019/08/19 19:34:04 by lfilius          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "bsqhead.h"

char	*first_line_cut(char **av)
{
	int		fl;
	int		ret;
	char	*str;

	str = (char*)malloc(sizeof(char) * 15);
	fl = open(av[1], O_RDONLY);
	ret = read(fl, str, 14);
	if (str[ft_strlen(str) - 1] != '\n' || ft_atoi(str) <= 0)
	{
		error();
		close(fl);
		return (NULL);
	}
	close(fl);
	return (str);
}

int		dif_sym(char x, char y, char z)
{
	if (x != y && y != z && z != x)
		return (1);
	else
		return (0);
}

int		*line_process(char *str)
{
	int	len;
	int	*val;
	int	i;

	i = 0;
	val = (int *)malloc(sizeof(int) * 4);
	len = ft_strlen(str);
	val[0] = ft_atoi(str);
	val[1] = str[len - 4];
	val[2] = str[len - 3];
	val[3] = str[len - 2];
	if (!dif_sym(str[len - 2], str[len - 3], str[len - 4]))
	{
		error();
		return (NULL);
	}
	else
		return (val);
}
