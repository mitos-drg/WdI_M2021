/**
 * Debugging utilities for cstd library
 */

#include <stdio.h>

#define ASSERT(x) if(!(x)) {fprintf(stderr, "Assertion failed at %s:%d %s", __FILE__, __LINE__, __FUNCTION__); exit(1);}else{}