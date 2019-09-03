struct command {
	char *name;
	char *usage;
	char *long_usage;
};

struct front_end {
	char *name;
	int priority;
	int (*available)(void);
	int (*run)(char * name, int argc, char *argv[]);
};

extern struct command **commands;

extern void register_frontend(struct front_end * f);

extern int run(char * name, int argc, char *argv[]);

extern int help(int argc, char *argv[]);

extern struct front_end frontend_dumb;
