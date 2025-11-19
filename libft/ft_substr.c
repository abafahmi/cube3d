/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abafahmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:23:40 by abafahmi          #+#    #+#             */
/*   Updated: 2024/11/08 20:14:22 by abafahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*arr;
	size_t	slen;
	size_t	f;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	f = 0;
	if (start < slen)
		f = slen - start;
	if (f > len)
		f = len;
	arr = (char *)malloc(sizeof(char) * (f + 1));
	if (!arr)
		return (NULL);
	ft_strlcpy(arr, s + start, f + 1);
	return (arr);
}
/*
int	main()
{
	char s[] = "NULL";
	int i = 10;
	size_t len = 5;
	char *n = ft_substr(s, i, len);
	printf("%s\n", n);
}*/
