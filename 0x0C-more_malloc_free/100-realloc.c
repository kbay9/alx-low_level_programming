#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size) {
    if (ptr == NULL) {
        return malloc(new_size);
    }

    if (new_size == 0) {
        free(ptr);
        return NULL;
    }

    void *new_ptr = malloc(new_size);
    if (new_ptr == NULL) {
        return NULL; // Memory allocation failed
    }

    // Copy the contents from the old memory block to the new block
    unsigned int copy_size = (old_size < new_size) ? old_size : new_size;
    memcpy(new_ptr, ptr, copy_size);

    // Free the old memory block
    free(ptr);

    return new_ptr;
}

int main() {
    int *arr = malloc(5 * sizeof(int)); // Allocate memory for 5 integers
    for (int i = 0; i < 5; i++) {
        arr[i] = i * i;
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Reallocate memory for 10 integers
    arr = _realloc(arr, 5 * sizeof(int), 10 * sizeof(int));
    for (int i = 5; i < 10; i++) {
        arr[i] = i * i;
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Deallocate the memory
    free(arr);

    return 0;
}
