/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abafahmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:53:03 by abafahmi          #+#    #+#             */
/*   Updated: 2025/04/05 12:56:54 by abafahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*d;
	char	*s;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	d = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!d)
		return (NULL);
	s = d;
	while (*s1)
		*d++ = *s1++;
	while (*s2)
		*d++ = *s2++;
	*d = '\0';
	return (s);
}
