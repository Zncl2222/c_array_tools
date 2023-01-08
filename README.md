![licence](https://img.shields.io/github/license/Zncl2222/c_array_tools)
![size](https://img.shields.io/github/repo-size/Zncl2222/c_array_tools)
![language](https://img.shields.io/github/languages/top/Zncl2222/c_array_tools)
# c_array_tools
This is a simple dynamic array tools similary to C++ **```std::vector```** implemented by C. It coded by macro to simulate the **```template```** function like in C++ or other languages. Thus user can use array in C more easily without declare the type again and again.

# Installation
It is a single header file library. Just put `src/c_array.h` into your project and import it !

# Usuage
Here is an example.c to display how to use this llibrary. You could just use the shell script example.sh (linux) or batch file example.bat to compile and run the program. The example program print out the results for user to understand how it works.

```C
# include <stdio.h>
# include "./src/c_array.h"

int main() {
    printf("\nc_array Example\n\n");

    // Initialize the array. If capacity > 0, then it will initialize with 0 val.
    c_array(int) array;
    c_array_init(&array, int, 0);

    // add element to the back (the idx of back is the current length of array)
    c_array_push_back(&array, 10);
    c_array_push_back(&array, 2222);
    c_array_push_back(&array, -1024);

    // print the array in this style -> arr = [1, 2, 3]
    printf("After push back\n");
    c_array_print(array, "%d");
    printf("Array length = %zu\n", array.length);
    printf("Array capacity = %zu\n\n", array.capacity);

    // assign value directly or via function.
    // assign by function can help to check if the memory is allocated.
    c_array_assign(&array, 0, 999);
    printf("Use c_array_assign: \n");
    c_array_print(array, "%d");
    printf("Assign directly: \n");
    array.data[0] = 111;
    c_array_print(array, "%d");

    // pop the last element in array.
    // That element will be reseted to 0, and - 1 to the array length.
    c_array_pop_back(&array);
    printf("\nAfter pop_back\n");
    c_array_print(array, "%d");
    printf("Array length = %zu\n", array.length);
    printf("Array capacity = %zu\n\n", array.capacity);

    // insert the element at certain idx of the array
    // c_array_insert(array, index, value)
    c_array_insert(&array, 1, 90);
    printf("\nAfter insert\n");
    c_array_print(array, "%d");
    printf("Array length = %zu\n", array.length);
    printf("Array capacity = %zu\n\n", array.capacity);

    // remove the element at certain idx of the array
    // c_array_remove(array, index)
    c_array_remove(&array, 1);
    printf("\nAfter remove\n");
    c_array_print(array, "%d");
    printf("Array length = %zu\n", array.length);
    printf("Array capacity = %zu\n\n", array.capacity);

    // adjust the array capacity
    // should be careful the value was not initialize
    c_array_resize(&array, 20);
    printf("\nAfter resize\n");
    c_array_print(array, "%d");
    printf("Array length = %zu\n", array.length);
    printf("Array capacity = %zu\n\n", array.capacity);

    // adjust the array length
    c_array_set_length(&array, 20);
    printf("\nAfter set length\n");
    c_array_print(array, "%d");
    printf("Array length = %zu\n", array.length);
    printf("Array capacity = %zu\n\n", array.capacity);

    // Remember to free the memory after you don't need it.
    c_array_free(&array);

    return 0;
}
```
