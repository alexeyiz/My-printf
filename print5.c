/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichariss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 12:27:29 by ichariss          #+#    #+#             */
/*   Updated: 2021/01/16 13:46:04 by ichariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_itoa(intmax_t n)
{
	char		*stroka;
	int			i;

	i = ft_intlen(n);
	if (!(stroka = ft_calloc((i + 1), sizeof(char))))
		return (NULL);
	stroka[i] = '\0';
	while (i)
	{
		if (n < 0)
		{
			stroka[--i] = -(n % 10) + 48;
			n = n / 10;
			n = -n;
		}
		else
		{
			stroka[--i] = n % 10 + 48;
			n = n / 10;
		}
	}
	return (stroka);
}

int		ft_atoi(char *stroka, int *i)
{
	int		n;

	n = 0;
	while (stroka[*i] >= '0' && stroka[*i] <= '9')
	{
		n = n * 10 + stroka[*i] - 48;
		(*i)++;
	}
	(*i)--;
	return (n);
}

char	*ft_strdup_string(char *s, t_flag *flag)
{
	char	*stroka;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s);
	if (flag->tochnost && flag->tochnost_len < len)
		len = flag->tochnost_len;
	if (!(stroka = ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	while (i < len)
	{
		stroka[i] = s[i];
		i++;
	}
	stroka[i] = '\0';
	return (stroka);
}

void	work_tochnost(t_flag *flag)
{
	flag->tochnost = 1;
	flag->tochnost_parsing = 1;
	flag->tochnost_len = 0;
}

void	null_flags(t_flag *flag)
{
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
}
