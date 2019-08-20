/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 11:50:44 by lfilius           #+#    #+#             */
/*   Updated: 2019/08/20 15:03:40 by lfilius          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsqhead.h"
#include <stdlib.h>

int		min_val(int **hash, int i, int j)
{
	int p;

	if (hash[i][j] == 0)
		return (hash[i][j]);
	if (i == 0 || j == 0)
		return (hash[i][j]);
	else
	{
		p = hash[i - 1][j - 1];
		if (p > hash[i - 1][j])
			p = hash[i - 1][j];
		if (p > hash[i][j - 1])
			p = hash[i][j - 1];
		return (p + 1);
	}
}

int		*find_max_square(int **hash, int y, int x)
{
	int i;
	int n;
	int *cord;

	i = 0;
	n = 0;
	cord = (int*)malloc(sizeof(int) * 3);
	cord[2] = 0;
	while (n < y)
	{
		while (i < x)
		{
			hash[i][n] = min_val(hash, i, n);
			if (cord[2] < hash[i][n])
			{
				cord[0] = i;
				cord[1] = n;
				cord[2] = hash[i][n];
			}
			++i;
		}
		++n;
		i = 0;
	}
	return (cord);
}
