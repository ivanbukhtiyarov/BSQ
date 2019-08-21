#include "bsqhead.h"
#include <stdio.h>

int main(int argc, char** argv)
{
    int *params;
    int *solve;

    params = line_process(first_line_cut(argv));
  //  printf("1 %i 2 %c 3 %c 4 %c \n" , params[0],params[1],params[2],params[3]);
    ft_valid_number(params[0], argv[1], params);
    solve = ft_solve(params[0], argv[1], params);
    // printf("2: %i  0: %i 1: %i \n", solve[2],solve[0], solve[1]);
    //printf("\n");
    draw(argv, solve, params, 1);
    return (0);
}
