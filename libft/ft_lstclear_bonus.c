/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:30:08 by pablrome          #+#    #+#             */
/*   Updated: 2025/02/03 17:38:18 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*next;

	if (!lst || !del)
		return ;
	current = *lst;
	while (!current)
	{
		next = current->next;
		del(current);
		free(current);
		current = next;
	}
	*lst = NULL;
}

/* void	del_string(void *content)
{
	free(content);
}
int main()
{
    t_list *list = NULL;
    t_list *node1, *node2, *node3;

    node1 = ft_lstnew(strdup("Hola"));
    node2 = ft_lstnew(strdup("Mundo"));
    node3 = ft_lstnew(strdup("Lista"));

    list = node1;
    node1->next = node2;
    node2->next = node3;

    printf("Lista antes de ft_lstclear:\n");
    t_list *temp = list;
    while (temp != NULL)
    {
        printf("%s -> ", (char *)temp->content);
        temp = temp->next;
    }
    printf("NULL\n");

    ft_lstclear(&list, del_string);

    printf("Lista después de ft_lstclear:\n");
    if (list == NULL)
        printf("La lista está vacía (NULL)\n");
	else
		printf("La lista no fue liberada correctamente!!\n");
    return 0;
} */