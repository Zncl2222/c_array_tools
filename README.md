![licence](https://img.shields.io/github/license/Zncl2222/c_array_tools)
![size](https://img.shields.io/github/repo-size/Zncl2222/c_array_tools)
![language](https://img.shields.io/badge/C-Solutions-blue.svg?style=flat&logo=c%2B%2B)
![language_percent](https://img.shields.io/github/languages/top/Zncl2222/c_array_tools)
[![build](https://github.com/Zncl2222/c_array_tools/actions/workflows/cmake.yml/badge.svg)](https://github.com/Zncl2222/c_array_tools/actions/workflows/cmake.yml)
# c_array_tools
This is a simple dynamic array tools similary to C++ **```std::vector```** implemented by C. It coded by macro to simulate the **```template```** function like in C++ or other languages. Thus user can use array in C more easily without declare the type again and again.

# Installation
It is a single header file library. Just put `src/c_array.h` into your project and import it !

Due to the `typeof` feature in the code, now the project was only tested base on the gcc compiler on windows (mingw) and ubuntu os.

<div align='center'>

| Compiler                      | Windows            | Ubuntu             | Mac                 |
| ----------------------------- | ------------------ | ------------------ | ------------------  |
| GNU Compiler Collection (gcc) | :x:                | :white_check_mark: | Not  yet tested     |
| x86_64 mingw series (gcc)     | :white_check_mark: | :x:                | Not  yet tested     |
| Visual Studio Build Tools     | :x:                | :x:                | Not  yet tested     |

</div>

# Usuage
Here is an example.c to display how to use this llibrary. You could just use the shell script example.sh (linux) or batch file example.bat to compile and run the program. The example program print out the results for user to understand how it works.

### Example
```C
# include <stdio.h>
# include "./src/c_array.h"

int main() {
    printf("\nc_array Example\n\n");

    // Initialize the array. If capacity > 0, then it will initialize with 0 val.
    c_array(int) array;
    c_array_init(&array, 0);

    // add element to the back (the idx of back is the current size of array)
    c_array_push_back(&array, 10);
    c_array_push_back(&array, 2222);
    c_array_push_back(&array, -1024);

    // print the array in this style -> arr = [1, 2, 3]
    printf("After push back\n");
    c_array_print(array, "%d");
    printf("Array size = %zu\n", array.size);
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
    // That element will be reseted to 0, and - 1 to the array size.
    c_array_pop_back(&array);
    printf("\nAfter pop_back\n");
    c_array_print(array, "%d");
    printf("Array size = %zu\n", array.size);
    printf("Array capacity = %zu\n\n", array.capacity);

    // insert the element at certain idx of the array
    // c_array_insert(array, index, value)
    c_array_insert(&array, 1, 90);
    printf("\nAfter insert\n");
    c_array_print(array, "%d");
    printf("Array size = %zu\n", array.size);
    printf("Array capacity = %zu\n\n", array.capacity);

    // remove the element at certain idx of the array
    // c_array_remove(array, index)
    c_array_remove(&array, 1);
    printf("\nAfter remove\n");
    c_array_print(array, "%d");
    printf("Array size = %zu\n", array.size);
    printf("Array capacity = %zu\n\n", array.capacity);

    // adjust the array capacity
    // should be careful the value was not initialize
    c_array_resize(&array, 20);
    printf("\nAfter resize\n");
    c_array_print(array, "%d");
    printf("Array size = %zu\n", array.size);
    printf("Array capacity = %zu\n\n", array.capacity);

    // adjust the array size
    c_array_set_size(&array, 20);
    printf("\nAfter set size\n");
    c_array_print(array, "%d");
    printf("Array size = %zu\n", array.size);
    printf("Array capacity = %zu\n\n", array.capacity);

    // Remember to free the memory after you don't need it.
    c_array_free(&array);

    return 0;
}
```

----
### c_array and c_array_init
Create the array with given datatype by `c_array(datatype) arr;`. You should initialize it before use. `arr.size` is the logical size of the array and `arr.capacity` is the whole space for the container.

Initialize the array with the given size & capacity by `c_array_init(&arr, size)`.
```C
int main() {
    c_array(int) arr;
    c_array_init(&arr, 10); // arr[0] ~ arr[9] will be initialized with 0
    return 0;
}
```

----
### c_array_capacity & c_array_size
Get array capacity and size.
```C
int main() {
    c_array(int) arr;
    c_array_init(&arr, 10);
    // Get size and capacity by macro
    int size = c_array_size(&arr); // equals to 10
    int capacity = c_array_capacity(&arr); // equals to 10

    // Get these attributes by struct
    size = arr.size;
    capacity = arr.capacity;
    return 0;
}
```

----
### c_array_assign
Assign the value at given location. This funciton will help to check if the memory is allocated before assigning the value. If memory is not allocated, then the program will abort with error.
```C
int main() {
    c_array(int) arr;
    c_array_init(&arr, 10);
    c_array_assign(&arr, 0, 150); // arr.data[0] now is 150
    c_array_assign(&arr, 11, 150); // program abort due to the size of array is only 10.

    // Assign value in struct directly
    arr.data[0] = -150; // warning: this method didn't check if the memory is allocated.
    return 0;
}
```

----
### c_array_grow
This macro is for array to grow the capacity while the memory is not enough. <b><font color=#ec733f>User don't have to call it manually</font></b>. If you want to adjust the size or the capacity, please refer to the `c_array_resize` and `c_array_set_size`. Features in c_array_tools will grow the capacity while the memory space is not enough. By default, each growing will **double** the **current capacity**.

----
### c_array_resize & c_array_set_size
Resize the capacity to given value.
```c
int main() {
    c_array(int) arr;
    c_array_init(&arr, 0); // capacity and size are both 0 now
    c_array_resize(&arr, 10); // capacity become 10 and size remain 0.
    c_array_set_size(&arr, 8); // capacity is 10 and size is 8 (element will initialize with 0)
    return 0;
}
```

----
### c_array_push_back
Push the element at the end of the array (depend on arr.size). If the capacity is not enough, this funciton will call `c_array_grow` to enlarge the capacity automatically. Notice if you need to push_back frequently, please use `c_array_resize` to set enough capacity to avoid the realloc of memory.
```C
int main() {
    c_array(int) arr;
    c_array(&arr, 0);
    c_array_push_back(&arr, 1); // capacity and size is 1 now
    c_array_push_back(&arr, 2); // capacity and size is 2 now
    c_array_push_back(&arr, 3); // capacity is 4 and size is 3 now
    return 0;
}
```

----
### c_array_pop_back
Remove the last element of the array (depend on arr.size).
```C
int main() {
    c_array(int) arr;
    c_array(&arr, 0);
    c_array_push_back(&arr, 1);
    c_array_push_back(&arr, 2);
    c_array_push_back(&arr, 3); // arr = [1, 2, 3]
    c_array_pop_back(&arr);     // arr = [1, 2]
    return 0;
}
```

----
### c_array_move_left & c_array_move_right
These are the feature for c_array_insert and c_array_remove.

----
### c_array_insert(arr, idx, val)
Insert the element at given index.
```C
int main() {
    c_array(int) arr;
    c_array(&arr, 0);
    c_array_push_back(&arr, 1);
    c_array_push_back(&arr, 2);
    c_array_push_back(&arr, 3);  // arr = [1, 2, 3]
    c_array_insert(&arr, 1, 99); // arr = [1, 99, 2, 3]
    return 0;
}
```

----
### c_array_remove(arr, idx)
Remove the elemnt at given index.
```C
int main() {
    c_array(int) arr;
    c_array(&arr, 0);
    c_array_push_back(&arr, 1);
    c_array_push_back(&arr, 2);
    c_array_push_back(&arr, 3); // arr = [1, 2, 3]
    c_array_remove(&arr, 1);    // arr = [1, 3]
    return 0;
}
```

----
### c_array_print
Print the array with clean style.
```C
int main() {
    c_array(int) arr_print_test;
    c_array(&arr_print_test, 0);
    c_array_push_back(&arr_print_test, 1);
    c_array_push_back(&arr_print_test, 2);
    c_array_push_back(&arr_print_test, 3);
    c_array_print(arr_print_test, "%d");   // Don't need to pass the address of arr
    // Results shows: arr_print_test = [1, 2, 3]
    return 0;
}
```

----
### c_array_empty
Check if array is empty, if yes return 1 else 0
```C
int main() {
    c_array(int) arr;
    c_array(&arr, 0);
    int e = c_array_empty(&arr); // e = 1
    return 0;
}
```

----
### c_array_swap
Swap the data in array
```C
int main() {
    c_array(int) arr;
    c_array(&arr, 0);
    c_array_push_back(&arr, 1);
    c_array_push_back(&arr, 2);
    c_array_push_back(&arr, 3); // arr = [1, 2, 3]
    c_array_swap(&arr, 0, 1);   // arr = [2, 1, 3]
    return 0;
}
```

----
### c_array_reverse
Reverse the array
```C
int main() {
    c_array(int) arr;
    c_array(&arr, 0);
    c_array_push_back(&arr, 1);
    c_array_push_back(&arr, 2);
    c_array_push_back(&arr, 3); // arr = [1, 2, 3]
    c_array_reverse(&arr);      // arr = [3, 2, 1]
    return 0;
}
```

----
### c_array_free
Free the memory allocated from heap.
```C
int main() {
    c_array(int) arr;
    c_array(&arr, 0);
    c_array_push_back(&arr, 1);
    c_array_free(&arr);
    return 0;
}
```
