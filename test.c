#include <stdio.h>
#include <string.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	const unsigned char	*buf1;
	const unsigned char	*buf2;

	buf1 = (const unsigned char *)s1;
	buf2 = (const unsigned char *)s2;
	if (*buf1 != *buf2)
		return (*buf1 - *buf2);
	while (*buf1 && *buf2)
	{
		if (*buf1 != *buf2)
			return (*buf1 - *buf2);
		buf1++;
		buf2++;
	}
	if (*buf1 == '\0' && *buf2 != '\0')
		return (0 - *buf2);
	else if (*buf2 == '\0' && *buf1 != '\0')
		return (*buf1);
	return (0);
}


int main(int argc, char **argv, char **envp)
{
	int i;

	i = 0;
	while(envp[i])
	{
		printf("[%d] %s\n", i, envp[i]);
		i++;
	}
	int a = 0;

	a = ft_strcmp("PWD=/", "PWD");

	printf("%d\n", a);
	printf("%d", '=' * -1);
	
}