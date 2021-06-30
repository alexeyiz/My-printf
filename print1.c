/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichariss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:44:07 by ichariss          #+#    #+#             */
/*   Updated: 2021/01/16 14:14:44 by ichariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print(t_flag *flag)
{
	write(1, flag->buffer, flag->buffer_i);
	flag->buffer_i = 0;
}

void	flagprint(t_flag *flag, char *stroka, int len)
{
	int		i;

	i = 0;
	flag->itog += len;
	while (i < len)
	{
		flag->buffer[flag->buffer_i] = stroka[i];
		flag->buffer_i++;
		if (flag->buffer_i == BUFFER_SIZE)
			print(flag);
		i++;
	}
}

void	ft_printf1(t_flag *flag, char *stroka)
{
	int		len;

	len = 0;
	while (stroka[flag->i] && stroka[flag->i] != '%')
	{
		flag->buffer[flag->buffer_i] = stroka[flag->i];
		flag->buffer_i++;
		len++;
		if (flag->buffer_i == BUFFER_SIZE)
			print(flag);
		flag->i++;
	}
	flag->itog += len;
	flag->i--;
}

void	flag_init(t_flag *flag)
{
	flag->buffer_i = 0;
	flag->itog = 0;
	flag->shirina = 0;
	flag->tochnost = 0;
	flag->tochnost_len = 0;
	flag->tochnost_parsing = 0;
	flag->convert = 0;
	flag->minus = 0;
	flag->zero = 0;
	flag->plus = 0;
	flag->space = 0;
	flag->sharp = 0;
	flag->len = 0;
	flag->space_len = 0;
	flag->nujda = 0;
	flag->u = 0;
	flag->n = 0;
	flag->i = 0;
}

int		ft_printf(const char *stroka, ...)
{
	t_flag	flag;
	va_list	args;

	flag_init(&flag);
	va_start(args, stroka);
	while (stroka[flag.i])
	{
		if (stroka[flag.i] == '%')
		{
			if (stroka[flag.i + 1] == '\0')
				break ;
			if (flags(stroka[flag.i + 1]))
				parser((char*)stroka, args, &flag);
		}
		else
			ft_printf1(&flag, (char*)stroka);
		flag.i++;
	}
	va_end(args);
	print(&flag);
	return (flag.itog);
}
