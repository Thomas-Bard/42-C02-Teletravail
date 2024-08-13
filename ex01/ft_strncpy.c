/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbard <tbard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 14:00:40 by tbard             #+#    #+#             */
/*   Updated: 2024/08/13 12:58:03 by tbard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int	i;
	int	extend_zero;

	i = 0;
	extend_zero = 0;
	while (i < n)
	{
		if (src[i] && !extend_zero)
			dest[i] = src[i];
		else
		{
			extend_zero = 1;
			dest[i] = 0;
		}
		i++;
	}
	return (dest);
}
