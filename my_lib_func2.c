/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_lib_func2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 16:03:30 by ireva             #+#    #+#             */
/*   Updated: 2017/09/13 16:19:37 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*ss1;
	unsigned char	*ss2;
	int				i;

	i = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while (ss1[i] && ss2[i])
	{
		if (ss1[i] != ss2[i])
			return (ss1[i] - ss2[i]);
		i++;
	}
	if (ss1[i] != ss2[i])
		return (ss1[i] - ss2[i]);
	return (0);
}

char				*ft_strchr(const char *s, int c)
{
	if ((char)c == '\0')
		return ((char*)(s + ft_strlen(s)));
	while (*s)
	{
		if (*s == (char)c)
			return ((char*)s);
		s++;
	}
	return (NULL);
}

void				ft_putchar(char c)
{
	write(1, &c, 1);
}

char				*ft_strnew(size_t size)
{
	int				i;
	char			*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	while (size != 0)
	{
		str[i] = '\0';
		i++;
		size--;
	}
	str[i] = '\0';
	return (str);
}

int					ft_atoi(const char *str)
{
	int				i;
	int				n;
	int				a;

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
