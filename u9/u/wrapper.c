#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <time.h>

#define RED		"\033[31m"
#define DEFAULT "\033[39m"

#define BOLD	"\033[1m"
#define RESET	"\033[0m"

#define BOUND	100

extern void sort(uint64_t len, int64_t a[len]);

static inline void printArray(int64_t* to_show, uint64_t len) {
	for(uint64_t i=0; i<len; i++) {
		if(i == 0) { // erstes Element
			printf("Array: %"PRId64", ", to_show[i]);
		} else if(i == (len-1)) { // letztes Element
			printf("%"PRId64"\n", to_show[i]);
		} else {
			printf("%"PRId64", ", to_show[i]);
		}
	}
}

int main(int argc, char* argv[]){
	if(argc < 2) {
		fprintf(stderr, RED BOLD "Not enough arguments!\n" RESET);
		printf("Usage: ./sort <len>\n");
		return EXIT_FAILURE;
	}
	
	char* end = NULL;
	uint64_t len = strtoull(argv[1], &end, 10);
	if(*end) {
		fprintf(stderr, RED BOLD "Invalid argument: %s\n" RESET, argv[1]);
		printf("Please insert only digits.\n");
		return EXIT_FAILURE;
	}
	
	if(len < 2) {
		fprintf(stderr, RED BOLD "Length to small!\n" RESET);
		printf("Length has to be at least 2.\n");
		return EXIT_FAILURE;
	}
	
	srand(time(NULL));	
	int64_t to_sort[len];
	for(uint64_t i=0; i<len; i++) {
		to_sort[i] = rand() % BOUND;
		// int8_t neg = rand() % 2;
		// if(neg) {
		// 	to_sort[i] = to_sort[i] * -1;
		// }
	}
	
	printArray(to_sort, len);
	sort(len, to_sort);
	printArray(to_sort, len);
	
	return EXIT_SUCCESS;
}

