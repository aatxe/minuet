#ifndef __debug_h__
#define __debug_h__

#include <stdio.h>
#include <errno.h>
#include <string.h>

// debug(M, ...): logs a specific message with debugging information prefixed with (DD) except when NDEBUG is defined.
#ifdef NDEBUG
#define debug(M, ...)
#else
#define debug(M, ...) fprintf(stderr, "(DD) %s:%d: " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#endif

// clean_errno(): gets a safe, readable version of errno
#define clean_errno() (errno == 0 ? "none" : strerror(errno))

// log_err(M, ...): logs a specific message with helpful debugging information prefixed with (EE)
#define log_err(M, ...) fprintf(stderr, "(EE) (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

// log_warn(M, ...): logs a specific message with helpful debugging information prefixed with (WW)
#define log_warn(M, ...) fprintf(stderr, "(WW) (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

// log_info(M, ...): logs a specific message prefixed with (II)
#define log_info(M, ...) fprintf(stderr, "(II) (%s:%d) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)

// log(M, ...): shorthand for log_info(M, ...)
#define log(M, ...) log_info(M, ##__VA_ARGS__);

// check(A, M, ...): logs a message with log_err(M, ...) and jumps to the label error if a condition is not met.
#define check(A, M, ...) if(!(A)) { log_err(M, ##__VA_ARGS__); errno=0; goto error; }

// check_user(A, M, ...): logs a message with fprintf(M, ...) and jumps to the label error if a condition is not met.
#define check_user(A, M, ...) if(!(A)) { fprintf(stderr, M, ##__VA_ARGS__); errno=0; goto error; }

// check_debug(A, M, ...): logs a message with debug(M, ...) and jumps to the label error if a condition is not met.
#define check_debug(A, M, ...) if(!(A)) { debug(M, ##__VA_ARGS__); errno=0; goto error; }

// sentinel(M, ...): logs a message with log_err and jumps to the label error
#define sentinel(M, ...)  { log_err(M, ##__VA_ARGS__); errno=0; goto error; }

// check_mem(A): uses check(A, "Out of memory.\n") to check if a pointer was properly allocated.
#define check_mem(A) check((A), "Out of memory.\n")

#endif