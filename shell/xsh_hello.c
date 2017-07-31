/* xsh_hello.c - xsh_hello */

#include <xinu.h>
#include <string.h>
#include <stdio.h>

/*------------------------------------------------------------------------
 * xsh_hello - obtain an input <string> and print within a simple statement
 *------------------------------------------------------------------------
 */

shellcmd xsh_hello(int nargs, char *args[]) {

	char *str;

	/* Output info for '--help' argument */

	if (nargs == 2 && strncmp(args[1], "--help", 7) == 0) {
		printf("Usage: %s\n\n", args[0]);
		printf("Description:\n");
		printf("\tPrint a simple statement with hello cmd\n");
		printf("Options:\n");
		printf("\thello...\t with one argument\n");
		printf("\t--help\t display this help and exit\n");
		return 0;
	}

	/* Check argument count */

	if (nargs > 2) {
		fprintf(stderr, "%s: too many arguments\n", args[0]);
		fprintf(stderr, "Try '%s --help' for more information\n",
			args[0]);
		return 1;
	}

	if (nargs == 2) {
		str = args[1];
		printf("Hello %s, Welcome to the world of Xinu!!\n", str);
		return 0;
	}

	if (nargs < 2) {
		fprintf(stderr, "%s: too few arguments\n", args[0]);
		fprintf(stderr, "Try '%s --help' for more information\n",
			args[0]);
		return 1;
	}

	fprintf(stderr, "%s: too few arguments\n", args[0]);
	fprintf(stderr, "Try '%s --help' for more information\n",
		args[0]);
	return 1;
}