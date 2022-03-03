/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoukou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 01:25:07 by ikoukou           #+#    #+#             */
/*   Updated: 2021/12/22 13:04:32 by ikoukou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	choose_cnvrs(va_list arg, char c, int *len);
void	put_char(char c, int *len);
char	*put_str(char *str, int *len);
void	put_id(int nb, int *len);
void	put_uu(unsigned int nb, int *len);
void	put_x(unsigned long int nb, int *len);
void	put_x_upper(unsigned int nb, int *len);
void	put_p(unsigned long int ptr, int *len);

#endif
