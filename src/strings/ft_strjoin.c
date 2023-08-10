#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*join;
	size_t	length;

	if (!s1 || !s2)
		return (NULL);
	length = ft_strlen(s1) + ft_strlen(s2) + 1;
	join = ft_calloc(length, 1);
	if (!join)
		return (NULL);
	ft_strlcat(join, s1, length);
	ft_strlcat(join, s2, length);
	return (join);
}
