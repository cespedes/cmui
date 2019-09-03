#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mui.h"


struct command cmd_question = {
	"question",
	"display question dialog",
	"Usage: mui question\n"
	"\n"
	"Display a question with two possible answers: Yes or No.\n"
	"\n"
	"It returns exit code zero with \"Yes\" and nonzero with \"No\".\n"
};

struct command cmd_input = {
	"input",
	"display text input dialog",
	"Usage: mui input\n"
	"\n"
	"Display a question that require a string as the answer.\n"
	"\n"
	"On exit, the input string will be printed on stdout.\n"
};

/* NULL-terminated list of pointers to commands: */
struct command **commands = NULL;

void
register_command(struct command *c) {
	int i;

	for (i=0; commands && commands[i]; i++);
	commands = realloc(commands, (i+2)*sizeof(struct command));
	commands[i] = c;
	commands[i+1] = NULL;
}

void
register_all_commands(void) {
	register_command(&cmd_question);
	register_command(&cmd_input);
}

void
register_all_frontends(void) {
	register_frontend(&frontend_dumb);
	/* register_frontend(&frontend_dumb); */
}

int
main(int argc, char *argv[]) {
	int i;
	argc--; argv++;

	register_all_commands();
	register_all_frontends();
	if (argc < 1 || !strcmp(argv[0], "help")) {
		return help(argc-1, argv+1);
	}
	for (i=0; commands && commands[i]; i++) {
		if (!strcmp(argv[0], commands[i]->name)) {
			return run(argv[0], argc-1, argv+1);
		}
	}
	fprintf(stderr, "mui %s: unknown command\n", argv[0]);
	fprintf(stderr, "Run 'mui help' for usage.\n");
	return 2;
}
