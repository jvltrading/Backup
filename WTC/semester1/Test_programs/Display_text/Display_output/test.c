#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int		main(void)
{
	FILE	*fptr;
	char	line[150];

	fptr = fopen("bacon.txt", "r");
	while (fgets(line, 150, fptr) != NULL)
	{
		if (*line != NULL)
			puts(line);
		else
			puts("Dandelions");
	}
	fclose(fptr);
	return (0);
}
