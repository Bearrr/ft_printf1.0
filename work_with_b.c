/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 12:31:23 by ireva             #+#    #+#             */
/*   Updated: 2017/09/13 12:33:13 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			type_b(uintmax_t x, t_flags flag)
{
	int		f;
	char	*number;

	f = 0;
	number = NULL;
	if (flag.accuracy == -1 && x == 0)
		return (neg_accuracy(flag, f));
	number = ft_uitoa_base(x, 2, 2);
	f = wr_o_uaccuracy(flag, number, f, 'x');
	f = o_uaccuracy_work(flag, number, 'x') + f;
	f = number_writter(number, f);
	(flag.minus != 0) ? f = o_uwidth_work(flag, number, 'x') + f : 0;
	(number != NULL) ? free(number) : 0;
	return (f);
}

int			use_b_flags(t_flags flag, int f, va_list ap)
{
	if (ft_strcmp(flag.letter, "j") == 0)
		f = ((type_b(va_arg(ap, uintmax_t), flag)) + f);
	else if (ft_strcmp(flag.letter, "z") == 0)
		f = ((type_b(va_arg(ap, size_t), flag) + f));
	else if (ft_strcmp(flag.letter, "ll") == 0)
		f = ((type_b(va_arg(ap, unsigned long long), flag)) + f);
	else if (ft_strcmp(flag.letter, "l") == 0)
		f = ((type_b(va_arg(ap, unsigned long), flag)) + f);
	else if (ft_strcmp(flag.letter, "h") == 0)
		f = (type_b((unsigned short)va_arg(ap, int), flag) + f);
	else if (ft_strcmp(flag.letter, "hh") == 0)
		f = (type_b((unsigned char)va_arg(ap, int), flag) + f);
	else
		f = (type_b(va_arg(ap, unsigned int), flag) + f);
	return (f);
}
