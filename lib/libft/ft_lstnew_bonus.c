/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recan <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:08:19 by recan             #+#    #+#             */
/*   Updated: 2025/10/07 13:08:20 by recan            ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

/*int main()
{
    int a = 10, b = 20, c = 30;

    t_list *head = ft_lstnew(&a);

    head->next = ft_lstnew(&b);

    head->next->next = ft_lstnew(&c);

    t_list *temp = head;
    while (temp)
    {
        printf("%d\n", *(int *)temp->content);
        temp = temp->next;
    }
    return 0;
    
    ekstra temp kullandık çünkü indeksleyerek onun üzerinden ilerliyoruz, 
eğer head üzerinden ilerleseydik head'i sonra kullanım için kaybetmiş olurduk.
(int *)temp->content → int * tipinde pointer cast ediyoruz, 
çünkü içinde int adresi gönderiyoruz. &a, &b
&a, &b şeklinde gönderdik çünkü void *content şeklinde bir pointer bekliyoruz.
*(int *)temp->content → Bu pointer’ın gösterdiği yerdeki gerçek int değeri.
}*/
