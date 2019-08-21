/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 18:32:41 by lfilius           #+#    #+#             */
/*   Updated: 2019/08/21 19:03:07 by lfilius          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsqhead.h"
#include "includehead.h"

char	*file_name(void)
{
	char *str;

	str = (char *)malloc(sizeof(char) * 8);
	str[0] = 's';
	str[1] = 't';
	str[2] = 'd';
	str[3] = 'm';
	str[4] = '.';
	str[5] = 't';
	str[6] = 'x';
	str[7] = 't';
	str[8] = '\0';
	return (str);
}

int main(int argc, char** argv)
{
	int *params;
	int *solve;
	int i;

	i = 1;
	if (argc == 1)
	{
		read_std_out(file_name());
		params = line_process(first_line_cut(argv));
		ft_valid_number(params[0], file_name(), params);
		solve = ft_solve(params[0], file_name(), params);
		draw(file_name(), solve, params);
	}
	else
	{
		while (i < argc)
		{
			params = line_process(first_line_cut(argv));
			ft_valid_number(params[0], argv[i], params);
			solve = ft_solve(params[0], argv[i], params);
			draw(argv[i], solve, params);
			++i;
		}
	}
	return (0);
}
