#include "monty.h"

/**
 * line_av - Splits a string into words
 * @s: Points to the string
 * @deli: points to the delimeter that separate the words
 *
 * Return: An array of each word of the string on success and NULL on failure
 */

char **line_av(char *s, char *deli)
{
	char **av;
	int i, word_c = 0;

	if (s == NULL || deli == NULL)
		return (NULL);

	word_c = word_count(s, deli);
	if (word_c < 1)
		return (NULL);
	av = malloc(sizeof(char *) * ++word_c);
	if (av == NULL)
	{
		print_err(0, "Error: malloc failed", "");
		freestack(top), _free(s);
		exit(EXIT_FAILURE);
	}

	av[0] = strtok(s, deli);

	for (i = 1; i < word_c; i++)
		av[i] = strtok(NULL, deli);

	return (av);
}

/**
 * word_count - Counts the number of words in a string
 * @s: points to the string
 * @deli: points to the delimeter string
 *
 * Return: the number of words in the string
 */

int word_count(char *s, char *deli)
{
	int count_w = 1;
	int index = 0, count = 0;

	while (s[index])
	{
		if (compare_cs(s[index], deli))
		{
			count_w = 1;
			index++;
			continue;
		}
		if (count_w)
		{
			count++;
			count_w = 0;
		}
		index++;
	}
	return (count);
}

/**
 * compare_cs - checks if a char is the same as any of the chars in a string
 * @c: contains the char
 * @s: points to the string
 *
 * Return: true if the char exist in the string and false if it doesn't
 */

int compare_cs(char c, char *s)
{
	int check = 0;
	int i;

	if (c == '\0' && s == NULL)
		return (0);

	for (i = 0; s[i]; i++)
	{
		if (c == s[i])
			check = 1;
	}
	return (check);
}
