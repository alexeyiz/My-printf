/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichariss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 12:21:21 by ichariss          #+#    #+#             */
/*   Updated: 2021/01/16 13:40:59 by ichariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_strlen(const char *stroka)
{
	size_t	i;

	i = 0;
	while (stroka[i])
		i++;
	return (i);
}

size_t	convert(char a)
{
	return (a == 'c' || a == 's' || a == 'p' || a == 'd' || a == 'i'
	|| a == 'u' || a == 'x' || a == 'n' || a == 'X' || a == '%');
}

size_t	flags(char a)
{
	return (a == 'c' || a == 's' || a == 'p' || a == 'd' || a == 'i' ||
		a == 'u' || a == 'x' || a == 'n' || a == 'X' || a == '%' ||
		(a >= '0' && a <= '9') || a == '-' || a == ' ' || a == '.' || a == '+'
		|| a == '#' || a == '*' || a == 'l' || a == 'h');
}

void	print_int(va_list args, t_flag *flag)
{
	char	*stroka;
	char	*space;

	flag->nujda = 1;
	flag->n = (intmax_t)va_arg(args, int);
	stroka = ft_itoa(flag->n);
	flag->len = ft_intlen(flag->n);
	stroka = work_stroka(stroka, flag);
	flag->len = ft_strlen(stroka);
	(flag->n < 0) ? flag->len++ : 0;
	(flag->n >= 0) && (flag->plus || flag->space) ? flag->len++ : 0;
	if (flag->n == 0 && flag->tochnost && flag->tochnost_len == 0
		&& !flag->shirina)
	{
		free(stroka);
		return ;
	}
	if (flag->n == 0 && flag->tochnost && flag->tochnost_len == 0)
	{
		free(stroka);
		stroka = ft_strdup(" ");
	}
	space = create_space(flag);
	create_text(stroka, space, flag);
}

void	print_string(va_list args, t_flag *flag)
{
	char *stroka;
	char *space;

	if (flag->tochnost && flag->tochnost_len < 0)
		flag->tochnost_len = -flag->tochnost_len;
	if (!(stroka = va_arg(args, char*)))
		stroka = ft_strdup_string("(null)", flag);
	else
		stroka = ft_strdup_string(stroka, flag);
	flag->len = ft_strlen(stroka);
	space = create_space(flag);
	create_text(stroka, space, flag);
}
