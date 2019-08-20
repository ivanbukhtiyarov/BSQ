/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 17:42:00 by lfilius           #+#    #+#             */
/*   Updated: 2019/08/20 18:40:34 by lfilius          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "bsqhead.h"

void	error()
{
	write(2, "map error\n", 10);
}

int		is_digits(char *str, int len )
{
	int i;

	i = 0;
	while (i < len - 4)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

char		*first_line_cut(char **av)
{
	int		fl;
	int		ret;
	char	*s;
	int		i;

	i = 0;
	s = (char*)malloc(sizeof(char) * 15);
	fl = open(av[1], O_RDONLY);
	ret = read(fl, s, 14);
	close (fl);
	if (s[ft_strlen(s) - 1] != '\n' || ft_atoi(s) < 0 || ret < 5 ||
			(ret == 5 && s[0] == '0'))
	{
		error();
		return (NULL);
	}
	if (!is_digits(s, ft_strlen(s)))
	{
		error();
		return (NULL);
	}
	return (s);
}

int		dif_sym(char x, char y, char z)
{
	if (x != y && y != z && z != x)
		return (1);
	else
	{
		error();
		return (0);
	}
}

int		*line_process(char *str)
{
	int		len;
	int		*val;
	int		i;

	if (str)
	{
		i = 0;
		val = (int *)malloc(sizeof(int) * 4);
		val[0] = 0;
		len = ft_strlen(str);
		while (i < len - 4)
		{
			val[0] = val[0] * 10 + (str[i] - '0');
			i++;
		}
		val[1] = str[len - 4];
		val[2] = str[len - 3];
		val[3] = str[len - 2];
		if (!dif_sym(str[len - 2], str[len - 3], str[len - 4]))
			return (NULL);
		else
			return (val);
	}
	else
		return (NULL);
}
