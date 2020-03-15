#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include "selci.h"

int main (int argc, char **argv)
{
	Selci *selci = create_selci();

	while (lprompt(selci, stdin) != NULL)
	{
		lprint(selci, leval(selci, lreadtop(selci, selci->gin), selci->genv));
		printf("%s\n", selci->gout);
	} 
	release_selci(selci);
	return 0;
}
