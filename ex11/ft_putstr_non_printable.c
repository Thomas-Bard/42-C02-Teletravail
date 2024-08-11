/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbard <tbard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:07:21 by tbard             #+#    #+#             */
/*   Updated: 2024/08/11 15:49:53 by tbard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_c_to_hex(char c, char *buffer, int ptr)
{
	static const char	hex_digits[16] = "0123456789abcdef";

	if (ptr >= 3)
		return ;
	ft_c_to_hex(c / 0x10, buffer, ptr + 1);
	buffer[ptr - (ptr == 2) + (ptr == 1)] = hex_digits[c % 0x10];
}

int	ft_is_printable(char c)
{
	return (c >= 32 && c <= 126);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	hex_buffer[4];

	i = 0;
	hex_buffer[0] = '\\';
	hex_buffer[3] = 0;
	while (str[i])
	{
		if (ft_is_printable(str[i]))
			write(1, &str[i++], 1);
		else
		{
			ft_c_to_hex(str[i++], hex_buffer, 1);
			ft_putstr(hex_buffer);
		}
	}
}
/*
int	main(void)
{
	ft_putstr_non_printable("Coucou\ntu vas bien ?");
	return (0);
}
*/