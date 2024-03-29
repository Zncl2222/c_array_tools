# include <stdio.h>
# include "./src/c_array.h"

int main() {
    printf("\nc_array Example\n\n");

    // Initialize the array. If capacity > 0, then it will initialize with 0 val.
    c_array_int array;
    c_array_init(&array, 0);

    // add element to the back (the idx of back is the current size of array)
    c_array_push_back(&array, 10);
    c_array_push_back(&array, 2222);
    c_array_push_back(&array, -1024);

    // print the array in this style -> arr = [1, 2, 3]
    printf("After push back\n");
    c_array_printf(array, "%d");
    printf("Array size = %zu\n", array.size);
    printf("Array capacity = %zu\n\n", array.capacity);

    // assign value directly or via function.
    // assign by function can help to check if the memory is allocated.
    c_array_assign(&array, 0, 999);
    printf("Use c_array_assign: \n");
    c_array_printf(array, "%d");
    printf("Assign directly: \n");
    array.data[0] = 111;
    c_array_printf(array, "%d");

    // pop the last element in array.
    // That element will be reseted to 0, and - 1 to the array size.
    c_array_pop_back(&array);
    printf("\nAfter pop_back\n");
    c_array_printf(array, "%d");
    printf("Array size = %zu\n", array.size);
    printf("Array capacity = %zu\n\n", array.capacity);

    // insert the element at certain idx of the array
    // c_array_insert(array, index, value)
    c_array_insert(&array, 1, 90);
    printf("\nAfter insert\n");
    c_array_printf(array, "%d");
    printf("Array size = %zu\n", array.size);
    printf("Array capacity = %zu\n\n", array.capacity);

    // remove the element at certain idx of the array
    // c_array_remove(array, index)
    c_array_remove(&array, 1);
    printf("\nAfter remove\n");
    c_array_printf(array, "%d");
    printf("Array size = %zu\n", array.size);
    printf("Array capacity = %zu\n\n", array.capacity);

    // adjust the array capacity
    // should be careful the value was not initialize
    c_array_resize(&array, 20);
    printf("\nAfter resize\n");
    c_array_printf(array, "%d");
    printf("Array size = %zu\n", array.size);
    printf("Array capacity = %zu\n\n", array.capacity);

    // adjust the array size
    c_array_set_size(&array, 20);
    printf("\nAfter set size\n");
    c_array_printf(array, "%d");
    printf("Array size = %zu\n", array.size);
    printf("Array capacity = %zu\n\n", array.capacity);

    // Remember to free the memory after you don't need it.
    c_array_free(&array);

    return 0;
}