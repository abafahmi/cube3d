/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abafahmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:32:51 by abafahmi          #+#    #+#             */
/*   Updated: 2025/03/29 22:45:39 by abafahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!little)
		return (NULL);
	if (!big && !len)
		return (NULL);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (little[j] == big[i + j] && (i + j) < len)
		{
			j++;
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
/*
int main()
{
    const char *haystack = "Hello, world!";
    const char *needle1 = "world";
    const char *needle2 = "planet";
    const char *needle3 = '\0';
    const char *needle4 = "Hello";
    const char *needle5 = "ld!";
    size_t len = 12;

    // Test cases
    char *result;

    // Case 1: Substring is found within length limit
    result = ft_strnstr(haystack, needle1, len);
    printf("Searching for \"%s\" in \"%s\" with len = %zu: %s\n",
           needle1, haystack, len, result ? result : "Not found");

    // Case 2: Substring is not found
    result = ft_strnstr(haystack, needle2, len);
    printf("Searching for \"%s\" in \"%s\" with len = %zu: %s\n",
           needle2, haystack, len, result ? result : "Not found");

    // Case 3: Empty substring (should return haystack)
    result = ft_strnstr(haystack, needle3, len);
    printf("3 %s\n", result);

    // Case 4: Substring is at the beginning
    result = ft_strnstr(haystack, needle4, len);
    printf("Searching for \"%s\" in \"%s\" with len = %zu: %s\n",
           needle4, haystack, len, result ? result : "Not found");

    // Case 5: Substring is at the end but within length limit
    result = ft_strnstr(haystack, needle5, len);
    printf("Searching for \"%s\" in \"%s\" with len = %zu: %s\n",
           needle5, haystack, len, result ? result : "Not found");

    return 0;
}*/
