#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mui.h"


struct command cmd_question = {
	"question",
	run_question,
	"display question dialog",
	"Usage: mui question"
	""
	"Display a question with two possible answers: Yes or No."
	""
	"It returns exit code zero with \"Yes\" and nonzero with \"No\"."
	""
};

struct command cmd_input = {
	"input",
	run_input,
	"display text input dialog",
	"Usage: mui input"
	""
	"Display a question that require a string as the answer."
	""
	"On exit, the input string will be printed on stdout."
	""
};

/* NULL-terminated list of pointers to commands: */
struct command **commands = NULL;

void
register_command(struct command *c) {
	int i;
	if (commands==NULL) {
		commands = realloc(commands, 2*sizeof(struct command));
		i=0;
	} else {
		for (i=0; commands[i]; i++);
		commands = realloc(commands, (i+2)*sizeof(struct command));
	}
	commands[i] = c;
}

void
register_all_commands(void) {
	register_command(&cmd_question);
	register_command(&cmd_input);
}

int
main(int argc, char *argv[]) {
	int i;
	argc--; argv++;

	register_all_commands();
	if (argc < 1 || !strcmp(argv[0], "help")) {
		return run_help(argc-1, argv+1);
	}
	for (i=0; commands[i]; i++) {
		if (!strcmp(argv[0], commands[i]->name)) {
			return commands[i]->run(argc-1, argv+1);
		}
	}
	fprintf(stderr, "mui %s: unknown command\n", argv[0]);
	fprintf(stderr, "Run 'mui help' for usage.\n");
	return 2;
}
