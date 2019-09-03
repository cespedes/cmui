#include <stdio.h>
#include <string.h>

#include "mui.h"

int
help(int argc, char *argv[]) {
	int i;
	FILE *output = stdout;

	if (argc < 0) {
		output = stderr;
	}
	if (argc < 1) {
		fprintf(output,
			"Mui is a tool to display graphical dialog boxes.\n"
			"\n"
			"Usage:\n"
			"\n"
			"\tmui <command> [arguments]\n"
			"\n"
			"The commands are:\n"
			"\n");
		for (i=0; commands[i]; i++) {
			fprintf(output, "\t%-10s %s\n", commands[i]->name, commands[i]->usage);
		}
		fprintf(output, "\nUse \"mui help <command>\" for more information about a command.\n\n");
		return (argc < 0) ? 2 : 0;
	}
	for (i=0; commands[i]; i++) {
		if (!strcmp(argv[0], commands[i]->name)) {
			printf("%s\n", commands[i]->long_usage);
			return 0;
		}
	}
	fprintf(stderr, "mui help %s: unknown help topic. Run 'mui help'.\n", argv[0]);
	return 2;
}
