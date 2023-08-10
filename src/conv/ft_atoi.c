#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		result;
	int		sign;
	size_t	i;

	sign = 1;
	result = 0;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			sign = -1;
	while (ft_isdigit(nptr[i]))
		result = result * 10 + nptr[i++] - '0';
	return (result * sign);
}
