#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>
#include <time.h>

#define RED		"\033[31m"
#define DEFAULT "\033[39m"

#define BOLD	"\033[1m"
#define RESET	"\033[0m"

extern int64_t fold(int64_t (*func)(int64_t, int64_t), uint64_t len, int64_t a[len], uint8_t dir);
extern void zipWith(int64_t (*func)(int64_t, int64_t), uint64_t len, int64_t a[len], int64_t b[len], int64_t c[len]);

int64_t add(int64_t a, int64_t b) {
	return a+b;
}

int64_t sub(int64_t a, int64_t b) {
	return a-b;
}

int64_t mul(int64_t a, int64_t b) {
	return a*b;
}

int64_t own_div(int64_t a, int64_t b) {
	return a/b;
}

// 1. Param Länge der Arrays
// 2. Param Operation
int main(int argc, char* argv[]) {
	if(argc < 3) {
		fprintf(stderr, BOLD RED "Not enough arguments!\n" RESET);
		printf("Usage: ./hofs <len> <op>\n");
		return EXIT_FAILURE;
	}

	char* end = NULL;
	size_t len = strtoull(argv[1], &end, 10);
	if(*end) {
		fprintf(stderr, BOLD RED "Invalid argument: \"%s\"!\n" RESET, argv[1]);
		printf("Only Digits are allowed!\n");
		return EXIT_FAILURE;
	}

	if(argv[2][1] || (argv[2][0] != '+' && argv[2][0] != '-' && argv[2][0] != '/' && argv[2][0] != '*')) {
		fprintf(stderr, RED BOLD "Invalid Argument: \"%s\"!\n" RESET, argv[2]);
		printf("Please insert only \"+\", \"-\", \"\\*\", \"/\" as operation.\n");
		return EXIT_FAILURE;
	}

	srand(time(NULL));

	int64_t a[len], b[len], c[len];
	for(size_t i=0; i<len; i++) {
		a[i] = rand() % 100;
		b[i] = rand() % 100;
		c[i] = rand() % 100;
	}
	uint8_t dir = rand() % 2;

	int64_t (*func)(int64_t, int64_t);
	if(argv[2][0] == '+') {
		func = add;
	} else if(argv[2][0] == '-') {
		func = sub;
	} else if(argv[2][0] == '*') {
		func = mul;
	} else {
		func = own_div;
	}

	int64_t res = fold(func, len, a, dir);
	// Ausgabe fold
	if(dir) {
		printf("fold-rtl:\n");
		for(size_t i=0; i<len; i++) {
			if(i == len-1) {
				printf("%"PRId64, a[i]);
			} else {
				printf("%"PRId64"%c", a[i], argv[2][0]);
			}
			if(i < len -2) {
				printf("(");
			}
		}
		for(size_t i=2; i<len; i++) {
			printf(")");
		}
	} else {
		printf("fold-ltr:\n");
		for(size_t i=2; i<len; i++) {
			printf("(");
		}
		for(size_t i=0; i<len; i++) {
			printf("%"PRId64, a[i]);
			if(i < len-1) {
				if(i > 0) {
					printf(")");
				}
				printf("%c", argv[2][0]);
			}
		}
	}
	printf("=%"PRId64"\n\nzipWith:\n", res);

	zipWith(func, len, a, b, c);
	// Ausgabe zipWith
	for(size_t i=0; i<len; i++) {
		printf("%"PRId64"%c%"PRId64"=%"PRId64"\n", a[i], argv[2][0], b[i], c[i]);
	}

	return EXIT_SUCCESS;
}
