/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:33:42 by ccalabro          #+#    #+#             */
/*   Updated: 2025/01/11 19:35:44 by ccalabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_cpy(char *dst, char *src, int start, int len_word)
{
	int	i;

	i = 0;
	while (i < len_word && src[i])
	{
		dst[i] = src[start + i];
		i++;
	}
	dst[i] = '\0';
}

char	**ft_split_argv(char *str)
{
	char	**output;
	int		n_words;

	n_words = count_words(str);
	if (n_words == 0)
		return (NULL);
	output = matrix_argv(n_words);
	if (output == NULL)
		return (NULL);
	fill_matrix(str, output, n_words);
	return (output);
}
