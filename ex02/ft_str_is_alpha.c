/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbard <tbard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 14:00:31 by tbard             #+#    #+#             */
/*   Updated: 2024/08/13 12:57:40 by tbard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;
	int	condition;

	i = 0;
	condition = 0;
	while (str[i])
	{
		condition = (str[i] >= 'A' && str[i] <= 'Z');
		condition = condition || (str[i] >= 'a' && str[i] <= 'z');
		if (!condition)
			return (0);
		i++;
	}
	return (1);
}
/*
int main(void)
{
	if (ft_str_is_alpha("HelloThere"))
		__builtin_printf("Yes\n");
	else
		__builtin_printf("No\n");
	return (0);
}
*/
