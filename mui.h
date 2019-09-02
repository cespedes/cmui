struct command {
	char *name;
	int (*run)(int argc, char *argv[]);
	char *usage;
	char *long_usage;
};

struct front_end {
	char *name;
	int priority;
	int (*available)(void);
	int (*question)(void);
	char *(*input)(void);
};

extern struct command **commands;

extern void register_frontend(struct front_end * f);

extern int run_help(int argc, char *argv[]);
extern int run_question(int argc, char *argv[]);
extern int run_input(int argc, char *argv[]);
