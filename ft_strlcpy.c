#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	srclen;

	srclen = ft_strlen(src);
	if (srclen + 1 < n)
		ft_memcpy(dest, src, srclen + 1);
	else if (n != 0)
	{
		ft_memcpy(dest, src, n - 1);
		dest[n - 1] = '\0';
	}
	return (srclen);
}
