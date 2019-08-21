#include "bsqhead.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h> 

int     ft_fill_int(int *digit, char c)
{
        if (c == digit[1])
            return (1);
        else
            return (0);
}

void    aloc_mem(int len, int ***arr)
{
    *arr = (int**)malloc(sizeof(int*) * 2);
    (*arr)[0] = (int*)malloc(sizeof(int) * (len));
    (*arr)[1] = (int*)malloc(sizeof(int) * (len));
}

void    free_mem(int ***arr)
{
    free((*arr)[0]);
    free((*arr)[1]);
    free(*arr);
}

void skip_and_fill(int *fd, char *adr, int *digit, int ***arr)
{
    char	buf[1];
    int     i;

    while (buf[0] != '\n')
    {	        
		read(*fd, buf, 1);
    }
	buf[0] = digit[1];
    i = 0;
    while(buf[0] != '\n')
	{
		read(*fd, buf, 1);
        if(buf[0] != '\n')
        {
            (*arr)[0][i] = ft_fill_int(digit, buf[0]);
        i++;
        }
	}
}



void swap_max_and_str(int **max,int **temp_max , int *i, int ***arr, int len)
{
    int j;

    if ((*max)[2] > (*temp_max)[2])
    {
        (*temp_max)[0] = *i;
        (*temp_max)[1] = (*max)[1];
        (*temp_max)[2] = (*max)[2];
    }
    j = 0;
    while(j < len)
	{
        (*arr)[0][j] = (*arr)[1][j];
        j++;
	}
}
int    *fill_another(int *fd, int *digit, int ***arr, int len)
{
    int		j;
	int		i;
    int     *temp_max;
    char    buf[i];
    int     *max;


    temp_max = (int*)malloc(sizeof(int) * 4);
    temp_max[2] = 0;

    while (i < digit[0])
	{
		j = 0;
		while(j < len)
		{
			read(*fd, buf, 1);
            (*arr)[1][j] = ft_fill_int(digit, buf[0]);
                j++;
		}
        read(*fd, buf, 1);
        max = find_max_square(*arr, len, 2);
        swap_max_and_str(&max, &temp_max, &i, arr, len);
		i++;
	}
    return (temp_max);
}
int    *ft_solve(int n, char *adr, int *digit)
{
    int     len;
    int     **arr;
    int		fd;
	// int		*max;
	// char	buf[1];
	// int		j;
	// int		i;
     int     *temp_max;

    temp_max = (int*)malloc(sizeof(int) * 4);
    temp_max[2] = 0;
    len = ft_valid_number(n, adr, digit);
    aloc_mem(len, &arr);
	fd = open(adr, O_RDONLY);
    skip_and_fill(&fd, adr, digit, &arr);
	// i = 1;
    // buf[0] = digit[1];
	// while (i < n)
	// {
	// 	j = 0;
	// 	while(j < len)
	// 	{
	// 		read(fd, buf, 1);
    //         arr[1][j] = ft_fill_int(digit, buf[0]);
    //             j++;
	// 	}
    //     read(fd, buf, 1);
    //     max = find_max_square(arr, len, 2);
    //     swap_max_and_str(&max, &temp_max, &i, &arr, len);
	// 	i++;
	// }
    temp_max = fill_another(&fd, digit, &arr, len);
    free_mem(&arr);
	close (fd);
	return (temp_max);
}