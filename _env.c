#include "shell.h"

char **_copy_env(void);
void free_env(void);
char **_get_env(const char *var);

/**
 * _copy_env - this function that Creates a copy of the environment.
 *
 * Return: If an error occurs - NULL.
 *         O/w - a double pointer to the new copy.
 */

char **_copy_env(void)
{
	char **new_env;
	size_t size;
	int i;

	for (size = 0; environ[size]; size++)
		;

	new_env = malloc(sizeof(char *) * (size + 1));
	if (!new_env)
		return (NULL);

	for (i = 0; environ[i]; i++)
	{
		new_env[i] = malloc(_strlen(environ[i]) + 1);

		if (!new_env[i])
		{
			for (i--; i >= 0; i--)
				free(new_env[i]);
			free(new_env);
			return (NULL);
		}
		_strcpy(new_env[i], environ[i]);
	}
	new_env[i] = NULL;

	return (new_env);
}

/**
 * free_env - this function that Frees the the environment copy.
 */
void free_env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
		free(environ[i]);
	free(environ);
}

/**
 * _get_env - this function that Gets an environmental
 *          variable from the PATH.
 * @var: The name of the environmental variable to get.
 *
 * Return: If the environmental variable does not exist - NULL.
 *         Otherwise - a pointer to the environmental variable.
 */
char **_get_env(const char *var)
{
	int i, len;

	len = _strlen(var);
	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(var, environ[i], len) == 0)
			return (&environ[i]);
	}

	return (NULL);
}
