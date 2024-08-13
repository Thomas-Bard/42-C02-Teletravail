/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbard <tbard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 14:00:50 by tbard             #+#    #+#             */
/*   Updated: 2024/08/13 12:41:03 by tbard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(src);
	while (i <= size)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
