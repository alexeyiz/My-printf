/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichariss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 12:48:11 by ichariss          #+#    #+#             */
/*   Updated: 2021/01/16 14:06:06 by ichariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_intlen(intmax_t a)
{
	int		i;

	i = 0;
	if (!a)
		i++;
	while (a)
	{
		a = a / 10;
		i++;
	}
	return (i);
}

void	znaki(t_flag *flag)
{
	if (flag->n < 0)
	{
		flag->len--;
		flagprint(flag, "-", 1);
	}
	else if (flag->plus && (flag->n >= 0))
	{
		flag->len--;
		flagprint(flag, "+", 1);
	}
	else if (flag->space && !flag->plus && (flag->n >= 0))
	{
		flag->len--;
		flagprint(flag, " ", 1);
	}
}

void	iksik(t_flag *flag)
{
	if (flag->convert == 'x')
	{
		flagprint(flag, "0x", 2);
		flag->len -= 2;
	}
	if (flag->convert == 'X')
	{
		flagprint(flag, "0X", 2);
		flag->len -= 2;
	}
}

void	create_text(char *stroka, char *space, t_flag *flag)
{
	(flag->nujda && flag->zero) ? znaki(flag) : 0;
	if (flag->zero && flag->convert == 'p')
	{
		flagprint(flag, "0x", 2);
		flag->len -= 2;
	}
	if (flag->sharp && flag->u && flag->zero && flag->tochnost_len < flag->len)
		iksik(flag);
	if (space && !flag->minus)
		flagprint(flag, space, flag->space_len);
	if (!flag->zero && flag->convert == 'p')
	{
		flagprint(flag, "0x", 2);
		flag->len -= 2;
	}
	if (flag->sharp && flag->u && !flag->zero && flag->tochnost_len < flag->len)
		iksik(flag);
	if (flag->nujda && !flag->zero)
		znaki(flag);
	flagprint(flag, stroka, flag->len);
	if (space && flag->minus)
		flagprint(flag, space, flag->space_len);
	free(stroka);
	free(space);
}

char	*create_space(t_flag *flag)
{
	char	*stroka;
	int		i;

	i = 0;
	if (flag->shirina < flag->len)
		return (NULL);
	if (!(stroka = ft_calloc((flag->shirina - flag->len + 1), sizeof(char))))
		return (NULL);
	if (flag->tochnost && flag->tochnost_len > flag->len)
		flag->zero = 0;
	while (i < flag->shirina - flag->len)
	{
		if (flag->zero)
			stroka[i] = '0';
		else
			stroka[i] = ' ';
		i++;
	}
	flag->space_len = i;
	stroka[i] = '\0';
	return (stroka);
}
