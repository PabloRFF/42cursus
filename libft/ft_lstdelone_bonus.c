/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:30:02 by pablrome          #+#    #+#             */
/*   Updated: 2025/02/03 14:19:23 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/* void del(void *content) {
    free(content);
}

int main() {
    t_list *node = malloc(sizeof(t_list));
    if (!node)
	{
        printf("Malloc fail\n");
        return 1;
    }
    
    int *num = malloc(sizeof(int));
    if (!num)
	{
        printf("Malloc fail\n");
        free(node);
        return 1;
    }
    *num = 42;
    node->content = num;
    node->next = NULL;
    printf("Contenido antes de eliminar: %d\n", *(int *)(node->content));
    ft_lstdelone(node, del);
    printf("Nodo eliminado correctamente\n");

    return 0;
} */
