/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abafahmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:27:31 by abafahmi          #+#    #+#             */
/*   Updated: 2024/11/03 20:07:20 by abafahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*d;
	size_t	i;

	i = ft_strlen(s);
	d = malloc(i + 1);
	if (d == NULL)
		return (NULL);
	ft_memcpy(d, s, i);
	d[i] = '\0';
	return (d);
}
