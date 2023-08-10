#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*ptr;

	if (!dest && !src)
		return (NULL);
	ptr = dest;
	while (n--)
		*((unsigned char *)ptr++) = *((unsigned char *)src++);
	return (dest);
}
