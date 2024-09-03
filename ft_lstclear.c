/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:25:30 by becamino          #+#    #+#             */
/*   Updated: 2023/07/25 12:28:12 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Deletes and free the node 'lst' and consecutives,
//using 'del' and free. The pointer to the list must be NULL.

/*void	ft_del(void *p)
{
	p = (void *)0;
}*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;

	if (!*lst || !del)
		return ;
	aux = *lst;
	while (aux != NULL)
	{
		aux = aux->next;
		ft_lstdelone(*lst, (del));
		*lst = aux;
	}
}
/*int main(void)
{

}*/
