/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recan <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:59:12 by recan             #+#    #+#             */
/*   Updated: 2025/10/07 12:59:13 by recan            ###   ####lausanne.ch   */
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

/*int main()
{
    int *num = malloc(sizeof(int));
    int *num2 = malloc(sizeof(int));
    *num = 42;
    *num2 = 442;

    t_list *node = ft_lstnew(num);
    t_list *node2 = ft_lstnew(num2);

    ft_lstdelone(node2, ft_delete_content);
    t_list *temp = node;
    while (temp)
    {
        printf("%d\n", *(int *)temp->content);
        temp = temp->next;
    }
    return 0;
    
        del(lst->content); düğümün içeriğini siler
    free(lst); ardından düğümün kendisini siler
}*/
