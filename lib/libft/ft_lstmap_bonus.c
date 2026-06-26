/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recan <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:04:08 by recan             #+#    #+#             */
/*   Updated: 2025/10/07 13:04:09 by recan            ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;

	if (!lst || !f)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_node, (*del));
			free(new_list);
			new_list = new_node;
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

/*void *ft_duplicate_int(void *content)
{
    int *new_int = malloc(sizeof(int));
    if (!new_int)
        return NULL;
    *new_int = (*(int *)content) * 2; // örnek işlem: her değeri 2 ile çarp
    return (new_int);
}

void ft_del_int(void *content)
{
    free(content);
}

void ft_print_list(t_list *lst)
{
    while (lst)
    {
        printf("%d\n", *(int *)lst->content);
        lst = lst->next;
    }
}

t_list *ft_lstnew(void *content)
{
    t_list *node = malloc(sizeof(t_list));
    if (!node)
        return NULL;
    node->content = content;
    node->next = NULL;
    return node;
}

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *temp;

    if (!lst || !new)
        return;
    if (!*lst)
    {
        *lst = new;
        return;
    }
    temp = *lst;
    while (temp->next)
        temp = temp->next;
    temp->next = new;
}

void ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list *temp;
    if (!lst || !del)
        return;
    while (*lst)
    {
        temp = (*lst)->next;
        del((*lst)->content);
        free(*lst);
        *lst = temp;
    }
    *lst = NULL;
}

int main(void)
{
    int *a = malloc(sizeof(int));
    int *b = malloc(sizeof(int));
    int *c = malloc(sizeof(int));
    *a = 1; *b = 2; *c = 3;

    t_list *node1 = ft_lstnew(a);
    t_list *node2 = ft_lstnew(b);
    t_list *node3 = ft_lstnew(c);
    node1->next = node2;
    node2->next = node3;

    t_list *new_list = ft_lstmap(node1, ft_duplicate_int, ft_del_int);

    printf("Orijinal liste:\n");
    ft_print_list(node1);
    printf("\nYeni (f uygulanmış) liste:\n");
    ft_print_list(new_list);

    ft_lstclear(&node1, ft_del_int);
    ft_lstclear(&new_list, ft_del_int);
    return 0;
}*/
