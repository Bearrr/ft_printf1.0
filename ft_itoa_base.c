/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:43:39 by ireva             #+#    #+#             */
/*   Updated: 2017/09/13 16:56:21 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

int			check_flag(int a, int flag)
{
	if (flag == 0)
		a = a + 39;
	else if (flag == 1)
		a = a + 7;
	return (a);
}

int			int_len(intmax_t nbr, int base)
{
	int i;

	i = 0;
	if (nbr < 0 && base == 10)
		i++;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr = nbr / base;
		i++;
	}
	return (i);
}

char		*ft_itoa_base(intmax_t nbr, int base, int flag)
{
	int		a;
	int		f;
	char	*mass;

	f = int_len(nbr, base);
	mass = (char*)malloc(sizeof(char) * (f + 1));
	mass[f] = '\0';
	if (nbr == 0)
		mass[f - 1] = nbr + '0';
	if (nbr < 0 && base == 10)
		mass[0] = '-';
	while (nbr != 0)
	{
		a = nbr % base;
		if (a < 0)
			a = -a;
		if (a > 9 && flag != 2)
			a = check_flag(a, flag);
		nbr = nbr / base;
		mass[f - 1] = a + '0';
		f--;
	}
	return (mass);
}

int			ft_atoi(const char *str)
{
	int		i;
	int		n;
	int		a;

	i = 0;
	n = 1;
	a = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		n = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		a = (a * 10) + (str[i] - '0') * n;
		i++;
	}
	return (a);
}
