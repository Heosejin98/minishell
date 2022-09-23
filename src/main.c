

#include "../include/minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	char			*str;

    (void)envp;
	if (!argc && !argv)
		return (0);
	while (1)
	{
		str = readline("minishell$> ");
        if(str == NULL)
            return (1);
	}
}