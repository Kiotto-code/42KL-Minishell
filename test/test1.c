# include <stdio.h>
# include <string.h>
# include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;

	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

int main()
{
	char *str1 = strdup("qqqqqdasdadsasdadsdasdasdasdaqqqqqqqq");
	char *str2 = strdup("asddfasjhdfs,h");
	// char str3[4] = "dumb";

	ft_memcpy(str2, str1, sizeof(char *));
	printf("%s\n", str2);
	str1 = "chibaiasdsxgfchvjbkafdsfdsgafdsgdfbsdb";
	// ft_memcpy(str1, "chibai", sizeof(char *));
	printf("%s\n", str1);
	// str1[3] = 'a';
}