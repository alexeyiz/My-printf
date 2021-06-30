/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichariss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 12:35:43 by ichariss          #+#    #+#             */
/*   Updated: 2021/01/16 13:50:35 by ichariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_char(va_list args, t_flag *flag)
{
	char *stroka;
	char *space;

	stroka = NULL;
	flag->len = 1;
	flag->convert == 'c' ? stroka = create_char(va_arg(args, int)) : 0;
	flag->convert == '%' ? stroka = create_char('%') : 0;
	space = create_space(flag);
	create_text(stroka, space, flag);
}

void	print_hex(va_list args, t_flag *flag)
{
	char *s;
	char *space;

	s = NULL;
	flag->nujda = 1;
	flag->u = (uintmax_t)va_arg(args, unsigned int);
	flag->convert == 'x' ? s = ft_itoa_base(flag->u, "0123456789abcdef") : 0;
	flag->convert == 'X' ? s = ft_itoa_base(flag->u, "0123456789ABCDEF") : 0;
	flag->len = ft_strlen(s);
	s = work_stroka(s, flag);
	flag->len = ft_strlen(s);
	if (flag->u == 0 && flag->tochnost && flag->tochnost_len == 0
		&& !flag->shirina)
	{
		free(s);
		return ;
	}
	if (flag->u == 0 && flag->tochnost && flag->tochnost_len == 0)
	{
		free(s);
		s = ft_strdup(" ");
	}
	flag->sharp && flag->u ? flag->len += 2 : 0;
	space = create_space(flag);
	create_text(s, space, flag);
}

void	print_pointer(va_list args, t_flag *flag)
{
	char *stroka;
	char *space;

	flag->u = va_arg(args, long unsigned);
	stroka = ft_itoa_base(flag->u, "0123456789abcdef");
	flag->tochnost ? flag->zero = 0 : 0;
	flag->len = ft_strlen(stroka);
	stroka = work_stroka(stroka, flag);
	flag->len = ft_strlen(stroka) + 2;
	if (flag->u == 0 && flag->tochnost && flag->tochnost_len == 0)
	{
		free(stroka);
		stroka = ft_strdup("");
		flag->len -= 1;
	}
	space = create_space(flag);
	create_text(stroka, space, flag);
}

char	*ft_itoa_base(uintmax_t n, char *base)
{
	char	*stroka;
	int		i;
	int		a;

	i = ft_intlen_base(n, base);
	a = ft_strlen(base);
	if (!(stroka = ft_calloc((i + 1), sizeof(char))))
		return (NULL);
	stroka[i] = '\0';
	while (i)
	{
		stroka[--i] = base[n % a];
		n = n / a;
	}
	return (stroka);
}

size_t	ft_intlen_base(uintmax_t n, char *base)
{
	size_t		i;
	uintmax_t	a;

	i = 1;
	a = ft_strlen(base);
	while (n >= a)
	{
		n = n / a;
		i++;
	}
	return (i);
}
