/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbard <tbard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 14:28:40 by tbard             #+#    #+#             */
/*   Updated: 2024/08/11 14:50:02 by tbard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_is_uppercase(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int	ft_is_lowercase(char c)
{
	return (c >= 'a' && c <= 'z');
}

int	ft_is_alphanumeric(char c)
{
	int	an;

	an = (c >= '0' && c < '9');
	an = an || (c >= 'A' && c <= 'Z');
	an = an || (c >= 'a' && c <= 'z');
	return (an);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	new_word;

	i = 0;
	new_word = 1;
	while (str[i])
	{
		if (!new_word)
		{
			if (ft_is_uppercase(str[i]))
				str[i] += 32;
			if (!ft_is_alphanumeric(str[i]))
				new_word = 1;
		}
		if (new_word)
		{
			if (ft_is_lowercase(str[i]))
				str[i] -= 32;
			if (ft_is_alphanumeric(str[i]))
				new_word = 0;
		}
		i++;
	}
	return (str);
}

/*int main(int argc, char** argv)
{
	if (argc != 2)
		return (1);
	printf("%s\n", ft_strcapitalize(argv[1]));
	return 0;
}
*/