/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbard <tbard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:07:21 by tbard             #+#    #+#             */
/*   Updated: 2024/08/13 14:06:32 by tbard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_normalized_hex(unsigned long long n, int size, int ptr)
{
	static const char	hex_digits[16] = "0123456789abcdef";
	char				c;

	if (ptr >= size)
		return ;
	ft_print_normalized_hex(n / 0x10, size, ptr + 1);
	c = hex_digits[n % 0x10];
	write(1, &c, 1);
}

int	ft_is_printable(char c)
{
	return (c >= 32 && c <= 126);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_is_printable(str[i]))
			write(1, &str[i], 1);
		else
		{
			write(1, "\\", 1);
			ft_print_normalized_hex(str[i], 2, 0);
		}
		i++;
	}
}

int	main(void)
{
	ft_putstr_non_printable("Coucou\ntu vas bien ?");
	return (0);
}
