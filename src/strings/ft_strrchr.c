#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*last;

	i = -1;
	last = NULL;
	while (s[++i])
		if (s[i] == c)
			last = (char *)&s[i];
	if (s[i] == c)
		return ((char *)&s[i]);
	return (last);
}
