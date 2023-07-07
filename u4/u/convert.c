#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <inttypes.h>

#define RED		"\033[31m"
#define DEFAULT "\033[39m"

#define BOLD	"\033[1m"
#define RESET	"\033[0m"

#define STR_LEN	50

extern int64_t strToInt(const char*, uint8_t);
extern size_t intToStr(int64_t, uint8_t, char*, size_t);

int main(int argc, char* argv[]) {
	if(argc < 3) {
		printf(BOLD RED "Not enough arguments!\n" RESET);
		return EXIT_FAILURE;
	}

	char* end = NULL;
	int64_t base = strtoull(argv[2], &end, 10);
	if(*end) {
		printf(BOLD RED "No valid base: %s\n" RESET, argv[2]);
		return EXIT_FAILURE;
	}

	int64_t val = strToInt(argv[1], (uint8_t)base);
	printf("Integer: %"PRId64"_%"PRIu8"\n", val, (uint8_t)base);

	char int_str[STR_LEN];
	size_t len = intToStr(val, (uint8_t)base, int_str, STR_LEN);
	printf("String: %s, Length: %zu\n", int_str, len);

	return EXIT_SUCCESS;
}
