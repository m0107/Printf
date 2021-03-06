/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgupta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 20:14:04 by mgupta            #+#    #+#             */
/*   Updated: 2020/02/16 02:02:44 by mgupta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdarg.h>

typedef struct		s_block
{
	int				min_width;
	int				prec_length;
	char			specifier;
	unsigned int	o_flag;
	unsigned int	dash_flag;
	unsigned int	prec_flag;
}					t_block;

void				init_block(t_block *block);
t_block				create_block(char **format, va_list *arg);
void				rectify_neg_star(t_block *block);
int					parse_block(t_block block, va_list *arg);
int					ft_printf(char *format, ...);
int					is_flag(char **format);
void				set_flag(t_block *block, char **format);
int					is_width(char c);
int					set_width(char **format);
void				chk_set_prec(t_block *block, char **format, va_list *arg);
int					c_parser(t_block block, va_list arg);
int					d_parser(t_block block, va_list arg);
int					p_parser(t_block block, va_list arg);
int					per_parser(t_block block);
int					s_parser(t_block block, va_list arg);
int					s_parser_1(char *s, t_block block, int i);
int					u_parser(t_block block, va_list arg);
int					x_parser(t_block block, va_list arg);
int					xx_parser(t_block block, va_list arg);
char				*convert(long long num, int base, t_block block);
void				printspacehelper(t_block block);

#endif
