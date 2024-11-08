#include <stdint.h>
#include <time.h>
#include <stdio.h>

#include "betterctypes.h"

enum parity {
    EVEN,
    ODD,
};

/* parameter of function pointer type */
/* with void return ⮧ and ⮦ const char* parameter */
static void f1(fn(void, const char*) output) {
    output("unix time second even");
}

static void f2(fn(void, const char*) output) {
    output("unix time second odd");
}

/* function pointer lookup table */
/*                            infer array size ⮧ by leaving out length */
static const arr(fn(void, fn(void, const char*))) function_lut = {
/* void return value ⮥    ⮤ fn-pointer parameter to outer fn-pointer */
    [EVEN] = f1,
    [ODD] = f2,
};

static void print_line(const char* str) {
    printf("%s\n", str);
}

int main(void) {
    const enum parity current_time_parity = time(NULL) & 1 ? ODD : EVEN;

    const fn(void, fn(void, const char*)) function = function_lut[current_time_parity];

    function(print_line);
}
