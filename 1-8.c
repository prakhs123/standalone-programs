#include <stdio.h>

/* count blanks, tabs and newlines in input */
main()
{
	int c, nb, nt, nn;

	nb = nt = nn = 0;	/* number of blanks, tabs and newlines initialized to zero */

	while ((c = getchar()) != EOF)
		if (c == ' ')
			++nb;
		else if (c == '\t')
			++nt;
		else if (c == '\n')
			++nn;
	printf("no. of blanks = %d\nno. of tabs = %d\nno. of newlines = %d\n", nb, nt, nn);
}
