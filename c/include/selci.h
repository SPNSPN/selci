#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <memory.h>

#define SELCI_BUFMAX 65536
#define SELCI_INITIAL_POOLSIZE 256

#define SELCI_MARK 0x80
#define SELCI_ISALIVE 0x40

#define SELCI_NIL 0x00
#define SELCI_INUM 0x01
#define SELCI_CONS 0x02

typedef uint8_t  Byte;
typedef uint32_t Addr;
typedef uint64_t Full;
typedef int32_t Fixnum;

typedef union Cell_u
{
	Full rax;
	Addr eax[2];
	Byte   a[8];
} Cell;

typedef struct Selci_t
{
	Cell *pool;
	Addr size;
	Addr head;
	Addr nil;
	Addr genv;
	char gin[SELCI_BUFMAX];
	char gout[SELCI_BUFMAX];
} Selci;

Selci * create_selci ();
void release_selci   (Selci *selci);

char * lprompt (Selci *, FILE *);
Addr lread     (Selci *, const char *code);
Addr lreadtop  (Selci *, const char *code);
Addr leval     (Selci *, Addr expr, Addr env);
void lprint    (Selci *, Addr expr);

Addr alloc_cell (Selci *);
void gc (Selci *);

Addr make_nil  (Selci *);
Addr make_inum (Selci *, Fixnum);
Addr make_cons (Selci *, Addr, Addr);

Addr make_genv (Selci *);

