#include <stdlib.h>
#include <stdio.h>

void	builtint_echo(char **argv, char **env);

int	main(void)
{
	char *argv[3];
	char *env[1];

	env[0] = NULL;
	argv[0] = "echo";
	argv[1] = "hola";
	argv[2] = NULL;
	builtint_echo(argv, env);
}

void	builtint_echo(char **argv, char **env)
{
	int i;

	i = 1;
	while (argv[i] != NULL)
	{
		printf("%s ", argv[i]);
		i++;
	}
	printf("\n");
}