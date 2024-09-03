/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:07:03 by becamino          #+#    #+#             */
/*   Updated: 2023/02/27 16:07:05 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include "libft.h"

/*	 Reserves a strings array using malloc, splitting string s in substrings
		using c character as an delimiter. Array must end with a NULL. */

static int	ft_search(const char *s, char c, int x)
{
	while (s[x] != '\0' && s[x] != c)
		x++;
	return (x);
}

static size_t	ft_wcounter(char const *s, char c)
{
	size_t	x;
	size_t	cont;

	x = 0;
	cont = 0;
	if (s[x] != c && s[x] != '\0')
	{
		cont++;
		x++;
	}
	while (s[x] != '\0')
	{
		if (s[x] != c && s[x - 1] == c)
		cont++;
	x++;
	}
	return (cont);
}

static void	*ft_free(char **arr, size_t a)
{
	while (!arr[a])
	{
		free(arr[a]);
		a--;
	}
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int			x;
	size_t		y;
	size_t		a;
	char		**arr;

	if (!s)
		return (NULL);
	arr = ft_calloc(ft_wcounter(s, c) + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	x = 0;
	a = 0;
	while (a < ft_wcounter(s, c))
	{
		while (s[x] != '\0' && s[x] == c)
			x++;
		y = x;
		x = ft_search(s, c, x);
		arr[a] = ft_substr(s, y, x - y);
		if (!arr[a])
			return (ft_free(arr, a));
		a++;
	}
	return (arr);
}

/*int	main(void)
{
	//char	s[14] = "Que puto frio";
	char	c;
	char	**array;

	c ='z';
	array = ft_split("", c);
	printf("%s \n", array[0]);
	printf("%s \n", array[1]);
	printf("%s \n", array[2]);
	free (array);
	return (0);
}
*/