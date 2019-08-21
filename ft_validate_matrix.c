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

// int ft_valid_char(int *digit , char c)
// {
// 	if (c == digit[1] || c == digit[2])
// 		return (1);
// 	return (0);
// }


int skip_and_count(int *fd, char *adr, int *digit)
{
	char	buf[1];
	int		length;

	buf[0] = 'c';
	while (buf[0] != '\n')	
		read(*fd, buf, 1);
	buf[0] = digit[1];
	while(buf[0] != '\n' && ft_valid_char(digit, buf[0]))
	{
		read(*fd, buf, 1);
		length++;
	}
	return (length);
}
int ft_valid_number(int n, char *adr, int *digit)
{
	int		fd;
	int		count;
	char	buf[1];
	int		length;
	int		i;

	fd = open(adr, O_RDONLY);
	length = skip_and_count(&fd, adr, digit);

	count = 0;
	// printf("len %i\n", length);
	// printf("N %i\n", n);
	while (read(fd, buf, 1))
	{
		count++;
		//printf("N %i\n", n);
		//printf("%c",buf[0]);
		if (!ft_valid_char(digit, buf[0]))
		{

			if (buf[0] == '\n' && count == length && n >= 2)
			{
				// printf("count %i\n", count);
				count = 0;
				n = n - 1;
			}
			else
				return (0);
		}
	}
	close (fd);
	return (length - 1);
}

// int ft_valid_n(int n, char *adr, int *digit)
// {
// 	int		fd;
// 	int 	ret;
// 	char 	buf[1];
// 	int 	count;

// 	fd = open(adr, O_RDONLY);
// 	count = 0;
// 	while (buf[0] != '\n')	
// 		read(fd, buf, 1);
// 	buf[0] = digit[1];
// 	while ((ret = read(fd, buf, 1)))
// 	{
// 		if (!ft_valid_char(digit, buf[0]))
// 		{
// 			if (buf[0] == '\n')
// 				count++;
// 			else
// 				return (0);
// 		}
// 	}
// 	close (fd);
// 	printf("count %i ",count);	
// 	printf("n %i ",n);	
// 	if(count == n)
// 		return 1;
// 	else 
// 		return 0;
// }



// int full_validate(int n, char *adr, int *digit)
// {
// 	if(ft_valid_n(n, adr, digit) <= 0)
// 		return (0);
// 	if(!ft_valid_number(n, adr, digit) <= 0)
// 		return (0);
// 	return (1);
// }