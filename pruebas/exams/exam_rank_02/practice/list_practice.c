#include <stdio.h>
#include <stdlib.h>
typedef struct s_list t_list;

struct s_list
{
    int     data;
    t_list  *next;
};

t_list*  insert(t_list *head, int value)
{
    t_list *new = malloc(sizeof(t_list));
    if (!new) {
        printf("Error: No se pudo asignar memoria\n");
        return head;
    }
    new ->data = value;
    new ->next = head;
    return new;
}

t_list  *sort_list(t_list* lst, int (*cmp)(int, int))
{
    int tmp;

    t_list *actual = lst;

    while (lst ->next)
    {
        if((cmp(lst->data, lst->next->data)) == 0)
        {
            tmp = lst->data;
            lst->data = lst->next->data;
            lst->next->data = tmp;
            lst = actual;
        }
        else
            lst = lst->next;
    }
    lst = actual;
    return (lst); 
}

void print_list(t_list *head)
{
    t_list *actual = head;

    while (actual)
    {
        printf("%d -> ", actual -> data);
        actual = actual->next;
    }
    printf("Null\n");
}


int ascending(int a, int b)
{
    return (a <= b);
}

int main(int argc, char const *argv[])
{
    t_list *list = NULL;
    
    list = insert(list, 10);
    list = insert(list, 30);
    list = insert(list, 9);
    list = insert(list, 21);

    print_list(list);

    list = sort_list(list, ascending);

    print_list(list);
    return 0;
}
