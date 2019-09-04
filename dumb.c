#include <stdio.h>
#include <string.h>

#include "mui.h"

static int dumb_available(void);
static int dumb_run(char *name, int argc, char *argv[]);
static int dumb_question(void);

static struct front_end frontend_dumb = {
	"dumb",
	10,
	dumb_available,
	dumb_run
};

void __attribute__((constructor)) init_dumb(void) {
	register_frontend(&frontend_dumb);
}

static int
dumb_available(void) {
	return 1; /* dumb is always available */
}

static int
dumb_run(char *name, int argc, char *argv[]) {
	if (!strcmp(name, "question")) {
		return dumb_question();
	} else {
		fprintf(stderr, "Error: command \"%s\" is not implemented in dumb front-end.\n", name);
		return 2;
	}
}

static int
dumb_question(void) {
	while (1) {
		printf("Are you sure you wany yo proceed? [yn] ");
		return 0;
	}
}
