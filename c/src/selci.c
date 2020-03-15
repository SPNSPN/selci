#include "selci.h"

Selci * create_selci ()
{
	Selci *selci = (Selci *)malloc(sizeof(Selci));
	selci->pool = (Cell *)malloc(sizeof(Cell) * SELCI_INITIAL_POOLSIZE);
	selci->size = SELCI_INITIAL_POOLSIZE;
	selci->head = 0;
	selci->nil = make_nil(selci);
	selci->genv = make_genv(selci);
	// TODO
	return selci;
}

void release_selci (Selci *selci)
{
	// TODO
	free(selci->pool);
	free(selci);
}

char * lprompt (Selci *selci, FILE *fp)
{
	printf("selci> ");
	return fgets(selci->gin, SELCI_BUFMAX, fp);
}

Addr lread (Selci *selci, const char *code)
{
	// TODO
	return selci->nil;
}

Addr lreadtop (Selci *selci, const char *code)
{
	// TODO
	return selci->nil;
}

Addr leval (Selci *selci, Addr expr, Addr env)
{
	// TODO
	return expr;
}

void lprint (Selci *selci, Addr expr)
{
	// TODO
	sprintf(selci->gout, "NIL");
}

Addr alloc_cell (Selci *selci)
{
	Addr newcell = selci->head;
	selci->pool[newcell].a[7] &= SELCI_ISALIVE;
	for (; selci->pool[selci->head].a[7] & SELCI_ISALIVE; ++(selci->head))
	{
		if (selci->head >= selci->size)
		{
			size_t newsize = sizeof(Cell) * selci->size * 2;
			Cell *newpool = (Cell *)malloc(newsize);
			if (NULL == newpool) { fprintf(stderr, "cannot allocate cell."); exit(-1); }
			memcpy(newpool, selci->pool, selci->size);
			free(selci->pool);
			selci->pool = newpool;
			break;
		}
	}
	return newcell;
}

void gc (Selci *selci)
{
	// TODO
}

Addr make_nil (Selci *selci)
{
	Addr newcell = alloc_cell(selci);
	selci->pool[newcell].a[7] |= SELCI_NIL;
	return newcell;
}

Addr make_inum (Selci *selci, Fixnum n)
{
	Addr newcell = alloc_cell(selci);
	selci->pool[newcell].a[7] |= SELCI_INUM;
	// TODO
	return newcell;
}

Addr make_cons (Selci *selci, Addr a, Addr d)
{
	Addr newcell = alloc_cell(selci);
	selci->pool[newcell].a[7] |= SELCI_CONS;
	// TODO
	return newcell;
}

Addr make_genv (Selci *selci)
{
	// TODO regist nil, t, subr, spfm
	return make_cons(selci, selci->nil, selci->nil);
}

