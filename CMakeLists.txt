cmake_minimum_required(VERSION 3.13)
project(rpizpot_2 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(rpizpot_2
		buf_right_alignment.c
		buffer.c
		count_numbers.c
		ft_atoi_precision.c
		ft_atoi_width.c
		ft_float.c
		ft_hex.c
		ft_int.c
		ft_long_composition.c
		ft_long_composition_dot.c
		ft_long_division.c
		ft_long_double.c
		ft_long_pow.c
		ft_long_pow_minus.c
		ft_long_sum.c
		ft_long_sum_dot.c
		ft_memalloc.c
		ft_octal.c
		ft_printf.c
		ft_printf.h
		ft_printf_f.c
		ft_strcmp.c
		ft_strdel.c
		ft_strdup.c
		ft_strjoin.c
		ft_strlen.c
		ft_strnew.c
		ft_strnew_one.c
		ft_strnew_zero.c
		ft_strrjoin.c
		ft_strcpy.c
		until_per.c
		ft_unsigned_int.c
		get_after_dot_float.c
		get_before_dot_float.c
		inicialization.c
		main.c
		parser.c
		parser_flag.c
		parser_size.c
		parser_type.c
		print_w_flag.c
		reinicialization.c
		ft_itoa.c
		ft_type_e.c
		ft_size.c
		ft_remake_str.c
		ft_count_until.c
		ft_make_precision.c
		ft_type_e_l.c
		ft_minus_str.c
		what_print.c ft_one.c ft_zero.c until_per.c ft_bzero.c print_percent.c ft_color_print.c)
