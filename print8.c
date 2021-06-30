/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print8.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichariss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 13:05:39 by ichariss          #+#    #+#             */
/*   Updated: 2021/01/16 14:33:30 by ichariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*work_stroka(char *stroka, t_flag *flag)
{
	char	*a;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!flag->tochnost)
		return (stroka);
	if (flag->tochnost_len < flag->len)
		return (stroka);
	if (!(a = ft_calloc(flag->tochnost_len + flag->len + 1, sizeof(char))))
		return (NULL);
	while (i < flag->tochnost_len - flag->len)
	{
		a[i] = '0';
		i++;
	}
	while (stroka[j])
	{
		a[i + j] = stroka[j];
		j++;
	}
	a[i + j] = '\0';
	free(stroka);
	return (a);
}

size_t	ft_uintlen(uintmax_t n)
{
	size_t		len;

	len = 1;
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}
