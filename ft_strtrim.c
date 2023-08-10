#include "libft.h"

static int	ft_inset(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
		if (set[i++] == c)
			return (1);
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*trimmed;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (ft_inset(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	if (start == end + 1)
		return (ft_calloc(1, 1));
	while (ft_inset(s1[end], set))
		end--;
	trimmed = ft_substr(s1, start, (end - start + 1));
	return (trimmed);
}
