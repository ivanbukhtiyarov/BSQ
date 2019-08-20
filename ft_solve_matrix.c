#include "bsqhead.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "stdlib.h"
#include "bsqhead.h"
#include <stdio.h> 
int     ft_fill_int(int *digit, char c)
{
        if (c == digit[1])
            return (1);
        else
            return (0);
}
int    *ft_solve(int n, char *adr, int *digit)
{
    int     len;
    int     **arr;
    int		fd;
	int		*max;
	char	buf[1];
	int		j;
	int		i;
    int     *temp_max;

    temp_max = (int*)malloc(sizeof(int) * 4);
    temp_max[2] = 0;
    len = ft_valid_number(n, adr, digit);
    printf("len = %i\n" , len);
    arr = (int**)malloc(sizeof(int*) * 2);
    //len+1
    arr[0] = (int*)malloc(sizeof(int) * (len));
    arr[1] = (int*)malloc(sizeof(int) * (len));

	fd = open(adr, O_RDONLY);

	while (buf[0] != '\n')
    {	        
		read(fd, buf, 1);
    }
	buf[0] = digit[1];

    i = 0;
    while(buf[0] != '\n')
	{
		read(fd, buf, 1);
        if(buf[0] != '\n')
        {
            arr[0][i] = ft_fill_int(digit, buf[0]);
          //  printf(" index %i %i ", i,arr[0][i]);
        i++;
        }
	}
    printf("\n");
	i = 1;

    buf[0] = digit[1];
	while (i < n)
	{
		j = 0;
		while(j < len)
		{
			read(fd, buf, 1);
            arr[1][j] = ft_fill_int(digit, buf[0]);
                j++;
		}
        read(fd, buf, 1);
        j = 0;
       // printf("\narr[0]******************\n");
    	while(j < len)
		{
//printf("%i",arr[0][j]);
                j++;
		}
        j = 0;
       // printf("\narr[1]******************\n");
    	while(j < len)
		{
           //     printf("%i",arr[1][j]);
                j++;
		}
        max = find_max_square(arr, len, 2);
    
        j = 0;
       // printf("\narr[0]***after***************\n");
    	while(j < len)
		{
               // printf("%i",arr[0][j]);
                j++;
		}

        j = 0;
       // printf("\narr[1]********after**********\n");
    	while(j < len)
		{
                //printf("%i",arr[1][j]);
                j++;
		}
		j = 0;

        if (max[2] > temp_max[2])
        {
            temp_max[0] = i;
            temp_max[1] = max[1];
            temp_max[2] = max[2];
        }
 //       printf("sq %i \n", temp_max[2]);
         j = 0;
        // printf("\narr[1]********after**********\n");
    	while(j < len)
		{
            arr[0][j] = arr[1][j];
                j++;
		}

		i++;
	}
    // free(arr[0]);
    // free(arr[1]);
    free(arr);
	close (fd);
	return (temp_max);
}