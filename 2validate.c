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
	if (c == digit[1] || c == digit[2] || c == '\n')
		return (1);
	return (0);
}


int     skip(int *fd)
{
	char buf[1];
    int ret;

	while (buf[0] != '\n')
    {
		ret = read(*fd, buf, 1);
        if (ret == 0)
            return (0);
    }
    return (1);
}

int valid1(char *av, int *digit)
{
    char buf[1];
    int fd;
    int len;

    len = 0;
    fd = open(av, O_RDONLY);
    skip(&fd);
    if (fd == -1)
        return(0);
    if(!(read(fd, buf, 1)))
        return (0);
    while(read(fd, buf, 1))
    {
        if(!ft_valid_char(digit, buf[0]))
            return (0);
        if(buf[0] != '\n')
            len++;
        else
        {
            close(fd);
            return (len + 1);
        }
    }
    return(0);
}

int valid2(char *av, int *digit, int len, int a)
{
    int fd;
    char buf[1];
    int count;

    count = 0;
    fd = open(av, O_RDONLY);
    skip(&fd);
    if (!valid1(av, digit) || fd == -1)
        return(0);
    while(read(fd, buf, 1))
    {
        if(!ft_valid_char(digit, buf[0]))
            return (0);
        if(buf[0] != '\n')
            count++;
        else if (count == len && digit[0] > 0)
        {
            count = 0;
            digit[0]--;
        }
        else
           return (0);
    } 
    a = (digit[0] == 0) ? 1:  0;
    return(a);
}