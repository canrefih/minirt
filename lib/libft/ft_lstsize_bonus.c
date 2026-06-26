/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recan <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:09:43 by recan             #+#    #+#             */
/*   Updated: 2025/10/07 13:09:44 by recan            ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

/*t_list *ft_lstnew(void *content)
{
    t_list *node = malloc(sizeof(t_list));
    if (!node)
        return (NULL);
    node->content = content;
    node->next = NULL;
    return (node);
}

void ft_lstadd_front(t_list **lst, t_list *new)
{
    if (!lst || !new)
        return;
    new->next = lst[0];
    lst[0] = new;
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

    printf("%d", ft_lstsize(head));
    return 0;
    
    ft_lstsize fonksiyonunda lst ilk liste olarak gönderiliyor yani head.
sonrasında next next diye düğümler arasında ilerleyip count hesaplayabiliyoruz.
}*/
