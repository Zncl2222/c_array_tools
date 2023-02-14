![licence](https://img.shields.io/github/license/Zncl2222/c_array_tools)
![size](https://img.shields.io/github/repo-size/Zncl2222/c_array_tools)
![language](https://img.shields.io/badge/-Solutions-blue.svg?style=flat&logo=c%2B%2B)
![language_percent](https://img.shields.io/github/languages/top/Zncl2222/c_array_tools)
[![build](https://github.com/Zncl2222/c_array_tools/actions/workflows/cmake.yml/badge.svg)](https://github.com/Zncl2222/c_array_tools/actions/workflows/cmake.yml)
# c_array_tools
This is a simple dynamic array tools similary to C++ **```std::vector```** implemented by C. It coded by macro to simulate the **```template```** function like in C++ or other languages. Thus user can use array in C more easily without declare the type again and again.

# Installation
It is a single header file library. Just put `src/c_array.h` into your project and import it !

Due to the `typeof` and `_Generic` features in the code, now the project was only tested base on the gcc compiler on windows (mingw) and ubuntu os. (gcc >= 4.9 is required, gcc does not support `_Generic` until version 4.9)


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
    c_array_printf(array, "%d");
    printf("Array size = %zu\n", array.size);
    printf("Array capacity = %zu\n\n", array.capacity);

    // assign value directly or via function.
    // assign by function can help to check if the memory is allocated.
    c_array_assign(&array, 0, 999);
    printf("Use c_array_assign: \n");
    c_array_print(array, "%d");
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
```

----
### `c_array(T)` & `c_array_init(arr, c)`
- params:<br>
`T`: the data type of the array -> (**int, long long, float, double etc..**)<br>
`arr`: c_array structure -> (**c_array**)<br>
`c`: the capacity for init -> (**size_t**)<br>

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
### `c_array_copy(arr1, arr2)`
- params:<br>
`arr1`: c_array structure you want to copy -> (**c_array**)<br>
`arr2`: new c_array structure -> (**c_array**)<br>

Copy an array to the target arry.
```C
int main() {
    c_array(int) arr;
    c_array_init(&arr, 0); // arr[0] ~ arr[9] will be initialized with 0
    c_array_push_back(&arr, 7);
    c_array_push_back(&arr, 8);
    c_array_push_back(&arr, 9);

    c_array(int) arr_new;  // declare arr_new without initialize.
    c_array_copy(&arr, &arr_new); // copy the memory from arr to arr_new
    c_array_print(arr_new, "%d"); // arr_new = [7, 8, 9], size and capacity are also equals to arr

    return 0;
}
```

----
### `c_array_capacity(arr)` & `c_array_size(arr)`
- params:<br>
`arr`: c_array structure -> (**c_array**)<br>

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
### `c_array_assign(arr, idx, val)`
- params:<br>
`arr`: c_array structure -> (**c_array**)<br>
`idx`: index of the array -> (**int**)<br>
`val`: value -> (**int, long long, float, double etc..**)<br>

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
### `c_array_grow`
This macro is for array to grow the capacity while the memory is not enough. <b><font color=#ec733f>User don't have to call it manually</font></b>. If you want to adjust the size or the capacity, please refer to the `c_array_resize` and `c_array_set_size`. Features in c_array_tools will grow the capacity while the memory space is not enough. By default, each growing will **double** the **current capacity**.

----
### `c_array_resize(arr, c)` & `c_array_set_size(arr, size)`
- params:<br>
`arr`: c_array structure -> (**c_array**)<br>
`c`: capacity -> (**size_t**)<br>
`size`: size -> (**size_t**)<br>

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
### `c_array_push_back(arr, val)`
- params:<br>
`arr`: c_array structure -> (**c_array**)<br>
`val`: value -> (**int, long long, float, double etc..**)<br>

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
### `c_array_pop_back(arr)`
- params:<br>
`arr`: c_array structure -> (**c_array**)<br>

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
### `c_array_move_left` & `c_array_move_right`
These are the feature for c_array_insert and c_array_remove.

----
### `c_array_insert(arr, idx, val)`
- params:<br>
`arr`: c_array structure -> (**c_array**)<br>
`idx`: index of the array -> (**int**)<br>
`val`: value -> (**int, long long, float, double etc..**)<br>

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
### `c_array_remove(arr, idx)`
- params:<br>
`arr`: c_array structure -> (**c_array**)<br>
`idx`: index of the array -> (**int**)<br>

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
### `c_array_print(arr)` & `c_array_printf(arr, format)`
- params:<br>
`arr`: c_array structure -> (**c_array**)<br>
`format`: format specifier -> (**char\***)<br>

Print the array with clean style.
```C
int main() {
    c_array(int) arr_print_test;
    c_array(&arr_print_test, 0);
    c_array_push_back(&arr_print_test, 1);
    c_array_push_back(&arr_print_test, 2);
    c_array_push_back(&arr_print_test, 3);
    c_array_printf(arr_print_test, "%d");   // Custom format to print the array
    // Results shows: arr_print_test = [1, 2, 3]

    c_array_print(arr_print_test); // Default format like %d %lld %f %lf. You can add more format in c_array_autoformat macro
    // Results shows: arr_print_test = [1, 2, 3]
    return 0;
}
```

----
### `c_array_empty(arr)`
- params:<br>
`arr`: c_array structure -> (**c_array**)<br>
- return: 0 or 1 -> (**int**)<br>

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
### `c_array_swap(arr, idx1, idx2)`
- params:<br>
`arr`: c_array structure -> (**c_array**)<br>
`idx1`: index 1 -> (**int**)<br>
`idx2`: index 2 -> (**int**)<br>

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
### `c_array_reverse(arr)`
- params:<br>
`arr`: c_array structure -> (**c_array**)<br>

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
### `c_array_free(arr)`
- params:<br>
`arr`: c_array structure -> (**c_array**)<br>

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

----
### `c_array_qsort(arr)` & `c_array_msort(arr)`
- params:<br>
`arr`: c_array structure -> (**c_array**)<br>

Sort the array by the qsort function in <stdlib.h>, or sort the array by the 'merge sort'.
```C
int main() {
    c_array(int) arr;
    c_array(&arr, 0);
    c_array_push_back(&arr, 99);
    c_array_push_back(&arr, -2);
    c_array_push_back(&arr, 2); // arr = [99, -2, 2]
    c_array_qsort(&arr); // arr = [-2, 2, 99]

    c_array_push_back(&arr, -91);
    c_array_push_back(&arr, 1); // arr = [-2, 2, 99, -91, 1]
    c_array_msort(&arr); // arr = [-91, -2, 1, 2, 99]
    return 0;
}
```

----
### `c_array_sum(arr)`
- params:<br>
`arr`: c_array structure -> (**c_array**)<br>
- return: `sum` -> (**int, long long, float, double etc..**)<br>

Get the sum of an array.
```C
int main() {
    c_array(int) arr;
    c_array(&arr, 0);
    c_array_push_back(&arr, 1);
    c_array_push_back(&arr, 2);
    c_array_push_back(&arr, 3);
    int sum = c_array_sum(&arr); // sum = 6
    return 0;
}
```

----
### `c_array_max(arr)` & `c_array_min(arr)`
- params:<br>
`arr`: c_array structure -> (**c_array**)<br>
- return: `min or max` -> (**int, long long, float, double etc..**)<br>

Get min or max value of an array
```C
int main() {
    c_array(int) arr;
    c_array(&arr, 0);
    c_array_push_back(&arr, 1);
    c_array_push_back(&arr, 2);
    c_array_push_back(&arr, 3);
    int max = c_array_max(&arr); // max = 3
    int min = c_array_min(&arr); // min = 1
    return 0;
}
```

----
### `c_array_mean(arr)`
- params:<br>
`arr`: c_array structure -> (**c_array**)<br>
- return: `mean value` -> (**mean_t**)<br>

Get mean value of an array
```C
int main() {
    c_array(int) arr;
    c_array(&arr, 0);
    c_array_push_back(&arr, 1);
    c_array_push_back(&arr, 2);
    c_array_push_back(&arr, 3);
    mean_t mean = c_arry_mean(&arr); // mean = 2
    return 0;
}
```

----
### `c_array_std(arr)` & `c_array_var(arr)`
- params:<br>
`arr`: c_array structure -> (**c_array**)<br>
- return: `standard deviation or variance` -> (**std_t, var_t**)<br>

Get the standard deviation or the variance of an array
```C
int main() {
    c_array(int) arr;
    c_array(&arr, 0);
    c_array_push_back(&arr, 1);
    c_array_push_back(&arr, 2);
    c_array_push_back(&arr, 3);
    std_t std = c_array_std(&arr); // std = 0.8164
    var_t var = c_array_var(&arr); // var =  0.6667
    return 0;
}
```
