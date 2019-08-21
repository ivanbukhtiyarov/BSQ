/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 18:32:41 by lfilius           #+#    #+#             */
/*   Updated: 2019/08/21 19:17:42 by lfilius          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsqhead.h"
#include "includehead.h"

// char	*file_name(void)
// {
// 	char *str;

// 	str = (char *)malloc(sizeof(char) * 8);
// 	str[0] = 's';
// 	str[1] = 't';
// 	str[2] = 'd';
// 	str[3] = 'm';
// 	str[4] = '.';
// 	str[5] = 't';
// 	str[6] = 'x';
// 	str[7] = 't';
// 	str[8] = '\0';
// 	return (str);
// }

int main(int argc, char** argv)
{
	int *params;
	int *solve;
	int i;

 	params = line_process(first_line_cut(argv[1]));
  	// printf("1 %i 2 %c 3 %c 4 %c \n" , params[0],params[1],params[2],params[3]);
	printf("%i", valid2(argv[1], params,valid1(argv[1], params),i));
//printf("Full validate : %i\n",full_validate(params[0], argv[1], params));
 //	solve = ft_solve(params[0], argv[1], params);
	// printf(" n number %i%i",k,l);
    // printf("2: %i  0: %i 1: %i \n", solve[2],solve[0], solve[1]);
    //printf("\n");
   // draw(argv[1], solve, params);
    return (0);
}
