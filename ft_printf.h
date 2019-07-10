/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 19:25:42 by rpizpot           #+#    #+#             */
/*   Updated: 2019/07/05 19:25:44 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FT_PRINTF_H
#define FT_PRINTF_FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
# define BUFF_SIZE 10000

typedef struct s_list
{
	va_list ap;
	size_t i;
	char type;
	char *typical_type;
	char *size;
	char p_size[3];
	char *flag;
	const char *copy;
	char minus;
	char plus;
	char space;
	char lattice;
	char zero;
	unsigned int width;
	int precision;
}				t_list;

typedef struct s_buf
{
	char *buf;
	int len;
	size_t i;
	size_t for_space;
	char sign;
}				t_buf;

union
{
	double                  fl;
	long long               x;
}                           u_f;

union
{
	long double             ld;
	unsigned long long      x[2];
}                           u_q;

char            *ft_strnew_zero(size_t size);
char            *ft_strnew_one(size_t size);
void            ft_zero(void *s, size_t len);
void            ft_one(void *s, size_t len);
char            *ft_strrjoin(char *a, char *b);
char            *ft_long_sum(char *a, char *b);
char            *ft_long_composition(char *a, char *b);
char            *ft_long_pow(long long n);
char            *ft_long_sum_dot(char *a, char *b);
char            *ft_long_composition_dot(char *a, char *b);
char            *ft_long_division(char *a);
char            *ft_long_pow_minus(long long n);
char			*ft_long_double(t_list *print);
int             get_before_dot_float(char *c);
int             get_after_dot_float(char *c);
t_list			*inicialization(t_list *print, t_buf **buf);
t_list			*parser(t_list *print, t_buf *for_buf);
t_list 			*reinicialization(t_list *print, t_buf **buf);
t_list 			*parser_flag(t_list *print);
t_list 			*ft_atoi_width(t_list *print);
t_list 			*ft_atoi_precision(t_list *print);
t_list 			*parser_size(t_list *print);
t_list 			*parser_type(t_list *print);
t_buf			*buffer(t_list *print, t_buf *for_buf, char *str);
//t_buf			*filling_buf(t_list *print, t_buf *for_buf, char **str);
//t_buf 			*filling_buf_str(t_buf *for_buf, char *str);
t_buf 			*filling_buf_byspace(t_list *print, t_buf *for_buf);
t_buf 			*filling_buf_2(t_list *print, t_buf *for_buf, char **str);
t_buf			*filling_buf_start(t_list *print, t_buf *for_buf, int len);
void			what_print(t_list *print, t_buf *for_buf);
//void			ft_printf_c(t_list *print);
void			print_w_flag(char c, int i);
int				ft_printf(const char *format, ...);
void			ft_printf_s(char *str);
void			ft_atoi_base(long int nbr, int base);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strnew(size_t size);
char			*ft_until_per(t_list **print);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strdup(const char *str);
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_printf_p(long int pointer);
void			*ft_memalloc(size_t size);
size_t			ft_strlen(const char *s);
void			ft_strdel(char **as);
char			*ft_float(t_list *print);
char			*ft_int(t_list *print);
char			*ft_unsigned_int(t_list *print);
char			*ft_octal(t_list *print);
char			*ft_hex(t_list *print);
size_t			count_numbers(uintmax_t n, int k);
void			ft_one(void *s, size_t len);
void			ft_zero(void *s, size_t len);
void			ft_bzero(void *s, size_t len);
void			print_percent(t_list *print, t_buf *for_buf);

#endif
