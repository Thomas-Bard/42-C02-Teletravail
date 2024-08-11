/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbard <tbard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:56:10 by tbard             #+#    #+#             */
/*   Updated: 2024/08/11 17:03:18 by tbard            ###   ########.fr       */
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

void	ft_print_buffer(char *buffer, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		if (buffer[i] >= 32 && buffer[i] <= 126)
			write(1, &buffer[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_print_line(void *addr, int remaining_size)
{
	int	j;

	ft_print_normalized_hex((unsigned long long)addr, 16, 0);
	write(1, ": ", 2);
	j = 0;
	while (j < remaining_size && j < 16)
	{
		write(1, " ", j > 0 && !(j % 2));
		ft_print_normalized_hex(((unsigned char *)(addr))[j], 2, 0);
		j++;
	}
	while (j++ < 16)
	{
		write(1, "  ", 2);
		write(1, " ", !(j % 2));
	}
	if (16 <= remaining_size)
		remaining_size = 16;
	write(1, " ", !(remaining_size % 2));
	ft_print_buffer((char *)addr, remaining_size);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		ft_print_line((unsigned char *)addr + i, size - i);
		i += 16;
	}
	return (addr);
}
/*
int main(void)
{
    unsigned char data[48] = {
        0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
        0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10,
        0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18,
        0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 0x20,
        0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28,
        0x29, 0x2A, 0x2B, 0x2C
    };
	ft_print_memory(data, 48);
}
*/