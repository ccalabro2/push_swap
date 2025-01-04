//modificare
void	ft_cpy(char *dst, char *src, int start, int len)
{
	int	i;

	i = 0;
	while (i < len && src[i])
	{
		dst[i] = src[start + i];
		i++;
	}
	dst[i] = '\0';
}

//modificare
char	**ft_split_modified_for_argv(char *str)
{
	char	**output;
	int		n_words;

	n_words = count_words(str);
	if (n_words == 0)
		return (NULL);
	output = create_matrix_like_real_argv(n_words);
	if (output == NULL)
		return (NULL);
	fill_matrix(str, output, n_words);
	return (output);
}
