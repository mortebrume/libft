#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_calloc(1, 1));
	substr = ft_calloc(len + 1, 1);
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}
