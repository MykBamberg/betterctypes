#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "betterctypes.h"

arrptr(int32_t, 5) get_arr(void) {
    /* cannot be stack allocated */
    static arr(int32_t, 5) example = {1, 2, 3, 4, 5};
    return &example;
}

arrptr(int32_t, 5) get_arr_malloc(void) {
    arrptr(int32_t, 5) example = malloc(sizeof(arr(int32_t, 5)));

    for (size_t i = 0; i < 5; i++) {
        /* access needs to dereference the pointer to the array */
        (*example)[i] = (i + 1) * (i + 1);
    }

    return example;
}

int main(void) {
    arrptr(int32_t, 5) numbers = get_arr();
    arrptr(int32_t, 5) numbers_squared = get_arr_malloc();

    for (size_t i = 0; i < 5; i++) {
        printf("%d² = %d\n", (*numbers)[i], (*numbers_squared)[i]);
    }

    free(numbers_squared);
}
