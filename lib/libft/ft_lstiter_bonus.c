/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recan <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:00:38 by recan             #+#    #+#             */
/*   Updated: 2025/10/07 13:00:38 by recan            ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*void	print_int(void *content)
{
	printf("%d\n", *(int *)content);
}

void increment_int(void *content)
{
	(*(int *)content) += 1;
}

int main()
{
    int a = 10, b = 20, c = 30;

    t_list *node1 = ft_lstnew(&a);
    t_list *node2 = ft_lstnew(&b);
    t_list *node3 = ft_lstnew(&c);

    node1->next = node2;
    node2->next = node3;

    printf("Orijinal değerler:\n");
    ft_lstiter(n1, print_int);

    ft_lstiter(n1, increment_int);

    printf("\n1 artırılmış değerler:\n");
    ft_lstiter(n1, print_int);

    return 0;
    
    f fonksiyonunu tüm nodelara uygulayıp bir sonraki node'a geçiyor.
}*/
