#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = ft_calloc(2, sizeof(*node));
	if (!node)
		return (NULL);
	node->content = content;
	return (node);
}
