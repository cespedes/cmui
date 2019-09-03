#include <stdio.h>

struct frontend {
	char * name;
	int priority;
	int (*available)(void);
	int (*command)(char * name, int argc, char *argv[]);
}

struct frontend ** frontends = NULL;

void
register_frontend(struct frontend *c) {
	int i;

	for (i=0; frontends && frontends[i]; i++);
	frontends = realloc(frontends, (i+2)*sizeof(struct frontend));
	frontends[i] = c;
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
