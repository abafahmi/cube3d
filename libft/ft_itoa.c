/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abafahmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:41:41 by abafahmi          #+#    #+#             */
/*   Updated: 2024/11/10 14:38:28 by abafahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nblen(int n)
{
	int	i;

	i = 0;
	if (n < 0 || n == 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

char	*ft_itoa(int n)
{
	unsigned int	nb;
	char			*s;
	int				len;

	len = ft_nblen(n);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	s[len] = '\0';
	nb = ft_abs(n);
	while (len--)
	{
		s[len] = nb % 10 + '0';
		nb = nb / 10;
	}
	if (n < 0)
		s[0] = '-';
	return (s);
}
