#include "betterctypes.h"
#include <stdio.h>

int main(void) {
    {
        /* all three are of type char* */
        ptr(char) a, b, c;
        printf("%zu %zu %zu\n", sizeof(a), sizeof(b), sizeof(c));
    }
    {
        /* a is of type char*, b & c are of type char */
        char* a, b, c;
        printf("%zu %zu %zu\n", sizeof(a), sizeof(b), sizeof(c));
    }
}
