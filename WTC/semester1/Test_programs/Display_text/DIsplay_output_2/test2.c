#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

char	*bob(char *s, int n, FILE *stream);

int	main(void)
{
	char	buff[256];

	while (bob (buff, sizeof(buff), stdin))
	{
		printf("line: %s", buff);
	}
	if (ferror(stdin))
	{
		fprintf(stderr, "Oops, error reading stdin\n");
		abort();
	}
	return (0);
}

char	*bob(char *s, int n, FILE *stream)
{
	char	c;
	char	*p;

	p = s;
	while (n > 1)
	{
		if (1 == fread(&c, sizeof(char), 1, stream))
		{
			*p++ = c;
			n--;
			if (c == '\n')
				break;
			continue;
		}
		if (feof(stream) && (p != s))
			break;
		return (0);
	}
	if (n > 0)
		*p = '\0';
	return (s);
}
