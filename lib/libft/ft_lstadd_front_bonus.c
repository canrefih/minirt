/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recan <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:11:01 by recan             #+#    #+#             */
/*   Updated: 2025/10/07 12:11:01 by recan            ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = lst[0];
	lst[0] = new;
}

/*int main()
{
    t_list *head = NULL;
    int a = 10, b = 20, c = 30;

    t_list *node1 = ft_lstnew(&a);
    t_list *node2 = ft_lstnew(&b);
    t_list *node3 = ft_lstnew(&c);

    head = node1;

    ft_lstadd_front(&head, node2);
    ft_lstadd_front(&head, node3);

    t_list *temp = head;
    while (temp)
    {
        printf("%d\n", *(int *)temp->content);
        temp = temp->next;
    }
    return 0;
    
    t_list	*ft_lstnew_(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
    
lstadd_frontda newin nextini ilk düğüme bağladık, 
ilk düğümü de new düğümünü yaptık.
mainde düğümleri oluşturduk ve lstadd fonksiyonu ile birbirlerine bağladık.
}*/
