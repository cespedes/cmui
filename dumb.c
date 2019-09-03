#include <stdio.h>

#include "mui.h"

int
dumb_available(void) {
	return 1; /* dumb is always available */
}

int
dumb_run(char *name, int argc, char *argv[]) {
	fprintf(stderr, "Error: command \"%s\" is not implemented in dumb front-end.\n", name);
	return 2;
}

struct front_end frontend_dumb = {
	"dumb",
	10,
	dumb_available,
	dumb_run
};
