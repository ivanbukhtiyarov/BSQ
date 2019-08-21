/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlaurenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 16:50:54 by qlaurenc          #+#    #+#             */
/*   Updated: 2019/08/19 19:58:44 by qlaurenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "bsqhead.h"

int ft_valid_char(int *digit , char c)
{
	if (c == digit[1] || c == digit[2])
		return (1);
	return (0);
}

//work but 32 lines
int ft_valid_number(int n, char *adr, int *digit)
{
	int		fd;
	int		count;
	char	buf[1];
	int		length;
	int		i;
	
	length = 0;
	fd = open(adr, O_RDONLY);
	while (buf[0] != '\n')	
		read(fd, buf, 1);
	buf[0] = digit[1];
	while(buf[0] != '\n' && ft_valid_char(digit, buf[0]))
	{
		read(fd, buf, 1);
		length++;
	}
	i = 0;
	while (i < n - 1)
	{
		buf[0] = digit[1];
		count = 0;
		while(buf[0] != '\n' && ft_valid_char(digit, buf[0]))
		{
			//printf("%c" ,buf[0]);
			read(fd, buf, 1);
			count++;
		}
		//ßprintf("\n");
		i++;
		if(count != length)
			return (0);
	}
	close (fd);
	return (length - 1);
}