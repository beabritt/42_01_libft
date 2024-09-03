/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:38:39 by becamino          #+#    #+#             */
/*   Updated: 2023/02/09 14:38:42 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include "libft.h"

// Locates the LAST occurrence of c in s.
/*size_t	ft_strlen(const char *s);*/

char	*ft_strrchr(const char *s, int c)
{
	int	x;
	int	slen;

	slen = ft_strlen(s);
	x = slen;
	while (x <= slen && x >= 0)
	{
		if (s[x] == (char)c)
			return ((char *) &s[x]);
		else
			x--;
	}
	return (NULL);
}

/*int	main(void)
{
	char	s [] = "Pepita tiene frio";
	int	c = 110;
    printf("%s \n", ft_strrchr(s, c));
	return (0);
}*/
