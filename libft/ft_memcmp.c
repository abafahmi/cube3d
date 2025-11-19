/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abafahmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:52:15 by abafahmi          #+#    #+#             */
/*   Updated: 2024/11/10 14:31:40 by abafahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
/*int	main()
{
	char str1[] = "abcdef";
	char str2[] = "";
	size_t n = 6;
	int result = ft_memcmp(str1, str2, n);
	printf("Comparison result for identical strings: %d\n", result);

	char str3[] = "abcdef";
	char str4[] = "abcxef";
	result = ft_memcmp(str3, str4, n);
	printf("Comparison result for differing strings: %d\n", result);

	char str5[] = "abcdzz";
	char str6[] = "abcdef";
	result = ft_memcmp(str5, str6, n);
	printf("Comparison result for partially matching strings: %d\n", result);

	result = ft_memcmp(str5, str6, 3);
	printf("Comparison result for first 3 characters: %d\n", result);

	return 0;
}*/
