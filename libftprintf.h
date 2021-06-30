/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichariss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:24:37 by ichariss          #+#    #+#             */
/*   Updated: 2021/01/16 14:34:23 by ichariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

typedef struct	s_flag
{
	char		buffer[BUFFER_SIZE + 1];
	int			buffer_i;
	int			itog;
	int			shirina;
	int			tochnost;
	int			tochnost_len;
	int			tochnost_parsing;
	int			convert;
	int			minus;
	int			zero;
	int			plus;
	int			space;
	int			sharp;
	int			len;
	int			space_len;
	int			nujda;
	uintmax_t	u;
	intmax_t	n;
	int			i;
}				t_flag;

int				ft_printf(const char *stroka, ...);
void			flag_init(t_flag *flag);
void			ft_printf1(t_flag *flag, char *stroka);
void			flagprint(t_flag *flag, char *stroka, int len);
void			print(t_flag *flag);
void			*ft_memalloc(size_t size);
void			*ft_calloc(size_t count, size_t size);
char			*create_char(char c);
int				parser2(char *str, va_list args, t_flag *flag);
void			work_flag(char *stroka, va_list args, t_flag *flag);
char			*ft_strdup(const char *s1);
char			*ft_uitoa(uintmax_t n);
void			print_u(va_list args, t_flag *flag);
void			parser(char *stroka, va_list args, t_flag *flag);
void			*ft_memset(void *b, int c, size_t len);
void			print_string(va_list args, t_flag *flag);
void			print_int(va_list args, t_flag *flag);
size_t			flags(char a);
size_t			ft_uintlen(uintmax_t n);
size_t			convert(char a);
size_t			ft_strlen(const char *stroka);
void			null_flags(t_flag *flag);
void			work_tochnost(t_flag *flag);
char			*ft_strdup_string(char *s, t_flag *flag);
int				ft_atoi(char *stroka, int *i);
char			*ft_itoa(intmax_t n);
size_t			ft_intlen_base(uintmax_t n, char *base);
char			*ft_itoa_base(uintmax_t n, char *base);
void			print_pointer(va_list args, t_flag *flag);
void			print_hex(va_list args, t_flag *flag);
void			print_char(va_list args, t_flag *flag);
char			*create_space(t_flag *flag);
void			create_text(char *stroka, char *space, t_flag *flag);
void			iksik(t_flag *flag);
void			znaki(t_flag *flag);
int				ft_intlen(intmax_t a);
char			*work_stroka(char *stroka, t_flag *flag);

#endif
