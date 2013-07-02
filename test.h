#undef NDEBUG
#ifndef __test_h__
#define __test_h__

#include <stdio.h>
#include <stdlib.h>
#include "debug.h"

// mu_test_suite(): marks the beginning of a minuet test suite.
#define mu_test_suite() char *message = NULL

// mu_assert(test, message): performs a test and prints the specified message with log_err(M, ...) if it fails
#define mu_assert(test, message) if (!(test)) { log_err(message); return message; }

// mu_run_test(test): runs the specified function as a minuet test within this suite
#define mu_run_test(test) debug("[minuet] running test %s", #test); message = test(); tests_run++; if (message) return message;

// mu_run_test_suite(suite): runs the specified function as a full minuet test suite (use by itself)
#define mu_run_test_suite(suite) int main(int argc, char *argv[]) {\
    argc = 1; \
    debug("[minuet] running suite %s", argv[0]);\
	printf("[minuet] running %s\n", argv[0]);\
        char *result = suite();\
        if (result != 0) {\
            printf("[minuet] %s failed with message: %s\n", argv[0], result);\
        }\
        else {\
            printf("[minuet] %s passed all tests.\n", argv[0]);\
        }\
    printf("[minuet] ran %d tests.\n", tests_run);\
        exit(result != 0);\
}

int tests_run;

#endif
