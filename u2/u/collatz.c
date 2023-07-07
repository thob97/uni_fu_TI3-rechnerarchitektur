#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>

#define RED		"\033[31m"
#define DEFAULT "\033[39m"

#define BOLD	"\033[1m"
#define RESET	"\033[0m"

extern uint64_t collatz(uint64_t);

int main(int argc, char* argv[]) {
	if(argc < 2) {
		fputs(BOLD RED "Not enough arguments!\n" RESET, stderr);
		return EXIT_FAILURE;
	}
	
	char* test = NULL;
	uint64_t val = strtoull(argv[1], &test, 10);
	if(*test) {
		fprintf(stderr, BOLD RED "Invalid Argument: %s\n" RESET, argv[1]);
		return EXIT_FAILURE;
	}

	uint64_t res = collatz(val);
	printf("collatz(%"PRIu64") = %"PRIu64"\n", val, res);

	return EXIT_SUCCESS;
}

