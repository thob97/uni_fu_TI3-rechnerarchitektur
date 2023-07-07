#include <stdio.h>
#include <stdlib.h>

#define RED		"\033[31m"
#define DEFAULT "\033[39m"

#define BOLD	"\033[1m"
#define RESET	"\033[0m"

extern double formula(double, double, double, double, double, double, double, double);

double check(double a, double b, double c, double d, double e, double f, double g, double h) {
	return (((a+b) * (c-d)) * ((e*8) + (f*4) - (g/2) + (h/4)))/3;
}

int main(int argc, char* argv[]) {
	if(argc < 9) {
		fputs(RED BOLD "Not enough arguments!\n" RESET, stderr);
		return EXIT_FAILURE;	
	}
	
	char* test = NULL;
	double a = strtod(argv[1], &test);
	if(*test) {
		fprintf(stderr, BOLD RED "Invalid Argument: %s\n" RESET, argv[1]);
	}
	
	double b = strtod(argv[2], &test);
	if(*test) {
		fprintf(stderr, BOLD RED "Invalid Argument: %s\n" RESET, argv[2]);
	}
	
	double c = strtod(argv[3], &test);
	if(*test) {
		fprintf(stderr, BOLD RED "Invalid Argument: %s\n" RESET, argv[3]);
	}
	
	double d = strtod(argv[4], &test);
	if(*test) {
		fprintf(stderr, BOLD RED "Invalid Argument: %s\n" RESET, argv[4]);
	}
	
	double e = strtod(argv[5], &test);
	if(*test) {
		fprintf(stderr, BOLD RED "Invalid Argument: %s\n" RESET, argv[5]);
	}
	
	double f = strtod(argv[6], &test);
	if(*test) {
		fprintf(stderr, BOLD RED "Invalid Argument: %s\n" RESET, argv[6]);
	}
	
	double g = strtod(argv[7], &test);
	if(*test) {
		fprintf(stderr, BOLD RED "Invalid Argument: %s\n" RESET, argv[7]);
	}
	
	double h = strtod(argv[8], &test);
	if(*test) {
		fprintf(stderr, BOLD RED "Invalid Argument: %s\n" RESET, argv[8]);
	}

	if(*test) {
		return EXIT_FAILURE;
	}

	double res = formula(a, b, c, d, e, f, g, h);
	double debug = check(a, b, c, d, e, f, g, h);
	printf("Erg:  %lf\n", res);
	printf("Test: %lf\n", debug);

	return EXIT_SUCCESS;
}