/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichariss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 12:15:08 by ichariss          #+#    #+#             */
/*   Updated: 2021/01/16 14:40:03 by ichariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t		i;
	char		*stroka;

	stroka = b;
	i = 0;
	while (i < len)
	{
		stroka[i] = c;
		i++;
	}
	return (b);
}

void	parser(char *stroka, va_list args, t_flag *flag)
{
	flag->i++;
	null_flags(flag);
	if (!parser2(stroka, args, flag))
		return ;
	if (flag->shirina < 0)
	{
		flag->minus = 1;
		flag->zero = 0;
		flag->shirina = -flag->shirina;
	}
	if (flag->tochnost_len < 0)
		flag->tochnost = 0;
	flag->tochnost && flag->tochnost_len >= 0 ? flag->zero = 0 : 0;
	flag->convert = stroka[flag->i];
	stroka[flag->i] == 'c' ? print_char(args, flag) : 0;
	stroka[flag->i] == 's' ? print_string(args, flag) : 0;
	stroka[flag->i] == 'p' ? print_pointer(args, flag) : 0;
	stroka[flag->i] == 'd' || stroka[flag->i] == 'i' ?
		print_int(args, flag) : 0;
	stroka[flag->i] == 'u' ? print_u(args, flag) : 0;
	stroka[flag->i] == 'x' || stroka[flag->i] == 'X' ?
		print_hex(args, flag) : 0;
	stroka[flag->i] == '%' ? print_char(args, flag) : 0;
}

void	print_u(va_list args, t_flag *flag)
{
	char	*stroka;
	char	*space;

	flag->nujda = 1;
	flag->u = (uintmax_t)va_arg(args, unsigned int);
	stroka = ft_uitoa(flag->u);
	flag->len = ft_strlen(stroka);
	stroka = work_stroka(stroka, flag);
	flag->len = ft_strlen(stroka);
	if (flag->u == 0 && flag->tochnost && flag->tochnost_len == 0
		&& !flag->shirina)
	{
		free(stroka);
		return ;
	}
	if (flag->u == 0 && flag->tochnost && flag->tochnost_len == 0)
	{
		free(stroka);
		stroka = ft_strdup(" ");
	}
	space = create_space(flag);
	create_text(stroka, space, flag);
}

char	*ft_uitoa(uintmax_t n)
{
	char		*stroka;
	int			i;

	i = ft_uintlen(n);
	if (!(stroka = ft_calloc((i + 1), sizeof(char))))
		return (NULL);
	stroka[i] = '\0';
	while (i)
	{
		stroka[--i] = n % 10 + 48;
		n = n / 10;
	}
	return (stroka);
}

char	*ft_strdup(const char *s1)
{
	char	*stroka;
	int		i;

	i = 0;
	if (!(stroka = (char*)malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (NULL);
	while (s1[i])
	{
		stroka[i] = (char)s1[i];
		i++;
	}
	stroka[i] = '\0';
	return (stroka);
}
