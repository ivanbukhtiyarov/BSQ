/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 10:59:52 by lfilius           #+#    #+#             */
/*   Updated: 2019/08/21 13:36:37 by lfilius          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includehead.h"
#include "bsqhead.h"

int		is_square(int *cord, int i, int j)
{
	int i_loc;
	int j_loc;

	i_loc = cord[0] - cord[2] + 1;
	j_loc = cord[1] - cord[2] + 1;
	if ((i >= i_loc && i <= cord[0]) && (j >= j_loc && j <= cord[1]))
		return (1);
	else
		return (0);
}

void	skip(int *fd)
{
	char buf[1];

	while (buf[0] != '\n')
		read(*fd, buf, 1);
}

void	draw(char *av, int *cord, int *symb)
{
	int fl;
	char buf[1];
	int i;
	int j;

	i = 0;
	j = 0;
	fl = open(av, O_RDONLY);
	if (fl == -1)
		error();
	skip(&fl);
	while (read(fl, buf, 1))
	{
		if (!is_square(cord, i, j))
			write(1, &buf[0], 1);
		else
			write(1, &symb[3], 1);
		if (buf[0] == '\n')
		{
			i++;
			j = -1;
		}
		j++;
	}
	close(fl);
}
