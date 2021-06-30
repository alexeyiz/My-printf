/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichariss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:50:04 by ichariss          #+#    #+#             */
/*   Updated: 2021/01/16 13:14:33 by ichariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	work_flag(char *stroka, va_list args, t_flag *flag)
{
	if (stroka[flag->i] == '*')
	{
		if (flag->tochnost_parsing)
			flag->tochnost_len = va_arg(args, int);
		else
			flag->shirina = va_arg(args, int);
	}
	if (stroka[flag->i] == '0' && !flag->minus && !flag->tochnost_parsing)
		flag->zero = 1;
	if (stroka[flag->i] > '0' && stroka[flag->i] <= '9' &&
			!flag->tochnost_parsing)
		flag->shirina = ft_atoi(stroka, &flag->i);
	if (stroka[flag->i] >= '0' && stroka[flag->i] <= '9' &&
			flag->tochnost_parsing)
		flag->tochnost_len = ft_atoi(stroka, &flag->i);
	flag->tochnost_parsing = 0;
	if (stroka[flag->i] == '-')
	{
		flag->zero = 0;
		flag->minus = 1;
	}
	stroka[flag->i] == '.' ? work_tochnost(flag) : 0;
	stroka[flag->i] == ' ' ? flag->space = 1 : 0;
	stroka[flag->i] == '+' ? flag->plus = 1 : 0;
	stroka[flag->i] == '#' ? flag->sharp = 1 : 0;
}

int		parser2(char *str, va_list args, t_flag *flag)
{
	char	*space;
	char	*stroka;

	while (!convert(str[flag->i]))
	{
		work_flag(str, args, flag);
		if (str[flag->i + 1] == '\0')
			return (0);
		if (!flags(str[flag->i + 1]))
		{
			stroka = create_char(str[flag->i + 1]);
			flag->len = 1;
			flag->minus ? flagprint(flag, stroka, 1) : 0;
			space = create_space(flag);
			flagprint(flag, space, flag->space_len);
			!flag->minus ? flagprint(flag, stroka, 1) : 0;
			free(stroka);
			free(space);
			flag->i++;
			return (0);
		}
		flag->i++;
	}
	return (1);
}

char	*create_char(char c)
{
	char *stroka;

	stroka = ft_calloc(2, sizeof(char));
	stroka[0] = c;
	stroka[1] = '\0';
	return (stroka);
}

void	*ft_calloc(size_t count, size_t size)
{
	return (ft_memalloc(count * size));
}

void	*ft_memalloc(size_t size)
{
	void *a;

	if (!(a = malloc(size)))
		return (NULL);
	ft_memset(a, 0, size);
	return (a);
}
