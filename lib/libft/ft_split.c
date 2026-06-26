/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recan <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:49:04 by recan             #+#    #+#             */
/*   Updated: 2025/10/07 13:49:06 by recan            ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *str, char c)
{
	int	count;
	int	word;

	count = 0;
	word = 0;
	while (*str)
	{
		if (*str != c && word == 0)
		{
			word = 1;
			count++;
		}
		else if (*str == c)
			word = 0;
		str++;
	}
	return (count);
}

static char	*ft_word_dup(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	split = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (NULL);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = ft_word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}

/*int main(void)
{
    char *s1 = "****Ben***annemi***çok*seviyorum!********";
    char set = '*';
    char **res = ft_split(s1, set);
    if (res)
    {
        int i = 0;
        while (res[i])
        {
            printf("%s\n", res[i]);
            free(res[i]);
            i++;
        }
    }
    free(res);
    return (0);
}*/
