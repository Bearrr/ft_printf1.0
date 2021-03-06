/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:07:13 by ireva             #+#    #+#             */
/*   Updated: 2017/03/10 16:04:17 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			check_type(char *format, int x)
{
	int		i;

	i = 0;
	while (x > i)
	{
		if (ft_strchr("sSpdDioOuUxXcCb", format[i]))
			return (1);
		i++;
	}
	i = 0;
	while (x > i)
	{
		if (!ft_strchr("hljz", format[i]) && format[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int			check_format(char *format)
{
	int		i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			return (0);
		i++;
	}
	return (1);
}

int			check_percent(char *format)
{
	int		j;
	int		i;

	i = 0;
	if (format[i + 1] == '\0')
		return (1);
	j = 1;
	i++;
	while (ft_strchr("#0-+ .", format[i]) || ft_strchr("hljz", format[i])
		|| (format[i] >= 48 && format[i] <= 57))
	{
		if (format[i + 1] == '\0')
			break ;
		i++;
		j++;
	}
	if (ft_strchr("sSpdDioOuUxXcCb", format[i]))
		j++;
	return (j);
}

void		check_zero(char *format, t_flags *flag)
{
	int		i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '0')
		{
			if ((format[i - 1] >= 48 && format[i - 1] <= 57)
				|| format[i - 1] == '.')
				flag->zero = 0;
			else
			{
				flag->zero = 1;
				break ;
			}
		}
		i++;
	}
}
