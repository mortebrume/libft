#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (!nmemb || !size)
		return (malloc(0));
	ptr = malloc(nmemb * size);
	if (! ptr)
		return (NULL);
	return (ft_bzero(ptr, nmemb * size));
}
