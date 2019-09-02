#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mui.h"

extern int cmd_help(int argc, char *argv[]);
extern int cmd_question(int argc, char *argv[]);
extern int cmd_input(int argc, char *argv[]);

struct command commands[] = {
	{
		"question",
		cmd_question,
		"display question dialog",
		"Usage: mui question"
		""
		"Display a question with two possible answers: Yes or No."
		""
		"It returns exit code zero with \"Yes\" and nonzero with \"No\"."
		""

	},
	{
		"input",
		cmd_input,
		"display text input dialog",
		"Usage: mui input"
		""
		"Display a question that require a string as the answer."
		""
		"On exit, the input string will be printed on stdout."
		""

	}
};

int
main(int argc, char *argv[]) {
	int i;
	argc--; argv++;

	if (argc < 1 || !strcmp(argv[0], "help")) {
		return cmd_help(argc-1, argv+1);
	}
	for (i=0; i<sizeof(commands)/sizeof(struct command); i++) {
		if (!strcmp(argv[0], commands[i].name)) {
			return commands[i].run(argc-1, argv+1);
		}
	}
	fprintf(stderr, "mui %s: unknown command\n", argv[0]);
	fprintf(stderr, "Run 'mui help' for usage.\n");
	return 2;
}
