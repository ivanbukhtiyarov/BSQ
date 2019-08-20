#include "bsqhead.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "stdlib.h"
#include "bsqhead.h"
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
    temp_max[0] = 0;
    len = ft_valid_number(n, adr, digit);
    arr = (int**)malloc(sizeof(int*) * 2);
    //len+1
    arr[0] = (int*)malloc(sizeof(int) * (len));
    arr[1] = (int*)malloc(sizeof(int) * (len));

	fd = open(adr, O_RDONLY);
	while (buf[0] != '\n')	
		read(fd, buf, 1);
	buf[0] = digit[1];

    i = 0;
    while(buf[0] != '\n' && ft_valid_char(digit, buf[0]))
	{
		read(fd, buf, 1);
        arr[0][i] = ft_fill_int(digit, buf[0]);
	}
	i = 1;
	while (i < n)
	{
		buf[0] = digit[1];
		j = 0;
		while(j < len - 1)
		{
			read(fd, buf, 1);
            arr[1][0] = ft_fill_int(digit, buf[0]);
		}
        max = find_max_square(arr, 2, len);
        if (max[2] > temp_max[2])
        {
            temp_max[0] = max[0];
            temp_max[1] = max[1];
        }
        arr[0] = arr[1];
		i++;
	}
    free(arr[0]);
    free(arr[1]);
    free(arr);
	close (fd);
	return (temp_max);
}