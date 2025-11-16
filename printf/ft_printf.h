/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:55:37 by yourlogin         #+#    #+#             */
/*   Updated: 2025/10/20 14:00:12 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define HEX_LOW "0123456789abcdef"
# define HEX_UPP "0123456789ABCDEF"

# include <unistd.h>
# include <stdarg.h>

int	ft_printf_char(char c);
int	ft_printf_str(char *str);
int	ft_printf_nbr(int n);
int	ft_printf_dec(unsigned int n);
int	ft_printf_hexa(unsigned int n, char tmp, int *count);
int	ft_printf_ptr(void *content);
int	ft_printf(const char *format, ...);

#endif