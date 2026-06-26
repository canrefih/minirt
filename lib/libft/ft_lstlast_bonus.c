/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recan <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:02:30 by recan             #+#    #+#             */
/*   Updated: 2025/10/07 13:02:31 by recan            ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*void ft_lstadd_front(t_list **lst, t_list *new)
{
    if (!lst || !new)
        return;
    new->next = lst[0];
    lst[0] = new;
}

t_list *ft_lstnew(void *content)
{
    t_list *node = malloc(sizeof(t_list));
    if (!node)
        return (NULL);
    node->content = content;
    node->next = NULL;
    return (node);
}

int main()
{
    t_list *head = NULL;
    int a = 10, b = 20, c = 30;

    t_list *node1 = ft_lstnew(&a);
    t_list *node2 = ft_lstnew(&b);
    t_list *node3 = ft_lstnew(&c);

    head = node1;

    ft_lstadd_front(&head, node2);
    ft_lstadd_front(&head, node3);

    t_list *temp = ft_lstlast(head);
    while (temp)
    {
        printf("%d\n", *(int *)temp->content);
        temp = temp->next;
    }
    return 0;
    
    lst->next bitip döngüye girmeyince next=NULL 
    kalıyor ve bu noktada lst'yi return edebiliyoruz.
}*/
