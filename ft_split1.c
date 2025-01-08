#include "push_swap.h"

int count_words(char *s)
{
    int len_word;
    int i;

    len_word = 0;
    i = 0;
    while (s[i])
    {
        while (s[i] == ' ' && s[i])
            i++;
        if (s[i] != ' '  && s[i])
        {
            len_word++;
            while (s[i] != ' ' && s[i])
                i++;
        }
    }
    return (len_word);
}

char **matrix_argv(int n)
{
    char    **matrix;
    int     program_name;
    program_name = 1;

matrix = (char **)malloc((n + program_name + 1) * sizeof(char *));
    if (matrix == NULL)
        return (NULL);
    return (matrix);
}

char	*element_matrix_argv(char *src)
{
	int			start;
	char		*output;
	static int	i;
	int			len_word;

	len_word = 0;
	if (src[i] != '\0')
	{
		while (src[i] == ' ' && src[i])
			i++;
		while (src[i] != ' ' && src[i])
		{
			len_word++;
			i++;
		}
	}
	output = (char *)malloc((len_word + 1) * sizeof(char));
	if (output == NULL)
		return (NULL);
	output[len_word] = '\0';
	start = i - len_word;
	ft_cpy(output, src, start, len_word);
	return (output);
}

//mdificare
void	free_elements_matrix_argv(char **matrix, int i)
{
	int	j;

	j = 0;
	while (j <= i)
	{
		free(matrix[j]);
		j++;
	}
	free(matrix);
	matrix = NULL;
}


void    fill_matrix(char *src, char **matrix, int n_words)
{
	int	i;

	matrix[0] = NULL;
	i = 1;
	while (i <= n_words)
	{
		matrix[i] = element_matrix_argv(src);
		if (matrix[i] == NULL)
		{
			free_elements_matrix_argv(matrix, i);
			matrix = NULL;
			return ;
		}
		i++;
	}
	matrix[i] = NULL;
}