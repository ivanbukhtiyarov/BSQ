#include "bsqhead.h"
#include <stdio.h>

int main(int argc, char** argv)
{
    int *params;
    int *solve;

    params = line_process(first_line_cut(argv));
    printf("1 %i 2 %c 3 %c 4 %c \n" , params[0],params[1],params[2],params[3]);

    solve = ft_solve(params[0], argv[1], params);
    printf("%i %i %i", solve[2],solve[0], solve[1]);
    printf("\n%i", ft_valid_number(params[0], argv[1], params));
    return (0);
}