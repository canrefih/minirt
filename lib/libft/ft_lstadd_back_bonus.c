/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recan <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:07:58 by recan             #+#    #+#             */
/*   Updated: 2025/10/07 12:08:00 by recan            ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

/*int main()
{
    int a = 10, b = 20, c = 30;

    t_list *head = ft_lstnew(&a);
    t_list *node2 = ft_lstnew(&b);
    t_list *node3 = ft_lstnew(&c);

    ft_lstadd_back(&head, node2);
    ft_lstadd_back(&head, node3);

    t_list *temp = head;
    while (temp)
    {
        printf("%d\n", *(int *)temp->content);
        temp = temp->next;
    }
    return 0;
    
    lst           → &head
*lst / lst[0] → head → node1
**lst         → node1 yapısının kendisi
(*lst)->next  → node2
lst[0]->next  → node2
(*lst)->next->content → "B"
}*/
