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

int ft_valid(int n, char *adr)
{
	int		fd;
	int		count;
	char	buf[1];
	int		length;
	int		i;
	
	length = 0;
	fd = open(adr, O_RDONLY);
	while (buf[0] != '\n')
	{
		read(fd, buf, 1);
	}
	buf[0] = '0';
	while(buf[0] != '\n')
	{
		read(fd, buf, 1);
		length++;
	}
	//printf("%c",buf[0]);
	i = 0;
	while (i < n)
	{
		buf[0] = '0';
		count = 0;
		while(buf[0] != '\n')
		{
			read(fd, buf, 1);
			count++;
			printf("%i",count);
		}
		read(fd, buf, 1);
		printf("\n");
		i++;
		if(count != length)
			return (0);
	}
	close (fd);
	return (1);
}

int main(int argc, char **argv)
{
	printf("%i", ft_valid(5, argv[1]));
	return (0);
}
