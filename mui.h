struct command {
	char *name;
	int (*run)(int argc, char *argv[]);
	char *usage;
	char *long_usage;
};

extern struct command commands[2];
