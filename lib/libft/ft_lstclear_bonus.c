/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recan <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:56:42 by recan             #+#    #+#             */
/*   Updated: 2025/10/07 12:56:43 by recan            ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}

/*int main()
{
    int *a = malloc(sizeof(int));
    int *b = malloc(sizeof(int));
    int *c = malloc(sizeof(int));
    *a = 10; *b = 20; *c = 30;

    t_list *node1 = ft_lstnew(a);
    t_list *node2 = ft_lstnew(b);
    t_list *node3 = ft_lstnew(c);

    node1->next = node2;
    node2->next = node3;

    t_list *head = node1;
    ft_lstclear(&head, delete_content);

    if (head == NULL)
        printf("Liste başarıyla temizlendi!\n");

    return 0;
    
        delone bir node silerken clear baştan sona hepsini temizliyor.
    önce bir sonrakinin adresini kaybetmemek için tempe atıyor
    sonra mevcut node'u siliyor ve free ediyor.
    sonra mevcut node'u bir sonrakine eşitleyip geçiyor.
    en sonda da mevcut node'u null'a eşitleyip bırakıyor
}*/
