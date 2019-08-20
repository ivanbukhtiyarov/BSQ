/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlaurenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 15:51:19 by qlaurenc          #+#    #+#             */
/*   Updated: 2019/08/06 14:55:22 by qlaurenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsqhead.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n')
	{
		i++;
	}
	return (i + 1);
}
int	ft_atoi(char *str)
{
	int i;
	int nb;
	int sgn;

	i = 0;
	nb = 0;
	sgn = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
			str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sgn = -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	nb *= sgn;
	return (nb);
}
