#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void		*pdest;
	const void	*psrc;

	if (!dest && !src)
		return (NULL);
	if (dest < src)
	{
		pdest = dest;
		while (n--)
			*((unsigned char *)pdest++) = *((unsigned char *)src++);
	}
	else
	{
		pdest = dest + (n - 1);
		psrc = src + (n - 1);
		while (n--)
			*((unsigned char *)pdest--) = *((unsigned char *)psrc--);
	}
	return (dest);
}
