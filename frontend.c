#include <stdio.h>
#include <stdlib.h>

#include "mui.h"

struct front_end ** frontends = NULL;

int
order_frontends(const void *a, const void *b) {
	struct front_end **f1, **f2;

	f1 = (struct front_end **)a;
	f2 = (struct front_end **)b;
	return (*f1)->priority - (*f2)->priority;
}

void
register_frontend(struct front_end *c) {
	int i;

	for (i=0; frontends && frontends[i]; i++);
	frontends = realloc(frontends, (i+2)*sizeof(struct front_end *));
	frontends[i] = c;
	qsort(frontends, i+1, sizeof(*frontends), order_frontends);
	frontends[i+1] = NULL;
}

int
run(char * name, int argc, char *argv[]) {
	int i;

	for (i=0; frontends && frontends[i]; i++) {
		if (frontends[i]->available()) {
			return frontends[i]->run(name, argc, argv);
		}
	}
	fprintf(stderr, "Error: no front-ends are available\n");
	return 2;
}

int
run_question(int argc, char *argv[]) {
	printf("This is a question\n");
	return 0;
}

int
run_input(int argc, char *argv[]) {
	printf("This is an input\n");
	return 0;
}
