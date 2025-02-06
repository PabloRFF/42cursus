/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:52:31 by pablrome          #+#    #+#             */
/*   Updated: 2025/02/04 14:11:09 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}

 void	del_string(void *content)
{
	free(content);
}
int main()
{
	t_list *node1, *node2, *node_add;
	t_list *list = NULL;

	node1 = ft_lstnew(ft_strdup("Hola"));
	node2 = ft_lstnew(ft_strdup("Mundo"));
	node_add = ft_lstnew(ft_strdup("Principio"));

	list = node1;
	node1->next = node2;
	printf("Lista antes de añadir el nodo:\n");
    t_list *temp = list;
    while (temp != NULL)
    {
        printf("%s -> ", (char *)temp->content);
        temp = temp->next;
    }
    printf("NULL\n");
	
	ft_lstadd_front(&list, node_add);
	printf("Lista despues de añadir el nodo:\n");
    temp = list;
    while (temp != NULL)
    {
        printf("%s -> ", (char *)temp->content);
        temp = temp->next;
    }
    printf("NULL\n");
	ft_lstclear(&list, del_string);
    if (list == NULL)
        printf("La lista ha sido liberada correctamente.\n");
	return 0;
}
