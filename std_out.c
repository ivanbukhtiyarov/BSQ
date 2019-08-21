/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_out.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 19:18:02 by lfilius           #+#    #+#             */
/*   Updated: 2019/08/21 19:01:16 by lfilius          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsqhead.h"
#include "includehead.h"

void	read_std_out(char *str)
{
	int ret;
	int fl;
	char buf[2];

	fl = open(str, O_WRONLY | O_CREAT);
	if (fl == -1)
		error();
	while ((ret = read(0, buf, 1)))
	{
		buf[ret] = '\0';
		write(fl, &buf, 1);
	}
	close (fl);
}
