![licence](https://img.shields.io/github/license/Zncl2222/c_array_tools)
![size](https://img.shields.io/github/repo-size/Zncl2222/c_array_tools)
![language](https://img.shields.io/badge/-Solutions-blue.svg?style=flat&logo=c%2B%2B)
![language_percent](https://img.shields.io/github/languages/top/Zncl2222/c_array_tools)
![cmake](https://img.shields.io/github/actions/workflow/status/Zncl2222/c_array_tools/cmake.yml?logo=cmake&logoColor=red&label=CMake)
[![build](https://github.com/Zncl2222/c_array_tools/actions/workflows/codeql.yml/badge.svg)](https://github.com/Zncl2222/c_array_tools/actions/workflows/codeql.yml)

[![Quality Gate Status](https://sonarcloud.io/api/project_badges/measure?project=Zncl2222_c_array_tools&metric=alert_status)](https://sonarcloud.io/summary/new_code?id=Zncl2222_c_array_tools)
[![Reliability Rating](https://sonarcloud.io/api/project_badges/measure?project=Zncl2222_c_array_tools&metric=reliability_rating)](https://sonarcloud.io/summary/new_code?id=Zncl2222_c_array_tools)
[![Security Rating](https://sonarcloud.io/api/project_badges/measure?project=Zncl2222_c_array_tools&metric=security_rating)](https://sonarcloud.io/summary/new_code?id=Zncl2222_c_array_tools)
[![Maintainability Rating](https://sonarcloud.io/api/project_badges/measure?project=Zncl2222_c_array_tools&metric=sqale_rating)](https://sonarcloud.io/summary/new_code?id=Zncl2222_c_array_tools)


# c_array_tools
This is a simple dynamic array tool, similar to C++'s **```std::vector```**, implemented in C. It is coded using macros to simulate **```template-like```** functions found in languages like C++. This allows users to work with arrays in C more easily, without the need to repeatedly declare the data type.

# Installation
It's a single-header library. For most basic dynamic array functionality, you only need to include `src/c_array.h` in your project. If you want to use extended features such as statistical calculations and the `mt19937 random number generator`, you should also link either `src/c_array.c` or `src/c_array_mt.c` when compiling your code. (All the functions are declared in `src/c_array.h`, so you can call any of them by including the header file `src/c_array.h` in your source code.)

For example, if you have a program like main.c:


### main.c

```C
# include "c_array.h"

int main() {
    c_array_int array;
    mt19937_state state;
    mt19937_init(&state, 1314);

    // This funciton is implemented in c_array_mt.c
    c_array_rand_range(&array, 10, mt19937_get_int32_range(&state, -5, 20));

     // This funciton is implemented in c_array.c
    int sum = c_array_sum(&array);

    c_array_free(&array);
}
```

compile with gcc (remember to add -lm to link math.h in linux os)
```bash
gcc main.c c_array_mt.c c_array.c -lm -o main.out
```

Because of the `typeof` and `_Generic` features in the code, the project has been tested exclusively with the GCC compiler on both Windows (MinGW) and Ubuntu operating systems. (A minimum version of GCC 4.9 is required, as `_Generic` support was introduced starting from version 4.9.)


<div align='center'>

| Compiler                      | Windows            | Ubuntu             | Mac                 |
| ----------------------------- | :----------------: | :----------------: | ------------------  |
| GNU Compiler Collection (gcc) | -                  | :white_check_mark: | Not  yet tested     |
| x86_64 mingw series (gcc)     | :white_check_mark: | -                  | Not  yet tested     |
| Visual Studio Build Tools     | :x:                | :x:                | Not  yet tested     |

</div>

### Extension in c_array.c
- [c_array_sum](#c_array_sumarr)
- [c_array_mean](#c_array_meanarr)
- [c_array_std](#c_array_stdarr--c_array_vararr)
- [c_array_var](#c_array_stdarr--c_array_vararr)
- [c_array_max](#c_array_maxarr--c_array_minarr)
- [c_array_min](#c_array_maxarr--c_array_minarr)
- [c_array_qsort](#c_array_qsortarr--c_array_msortarr)
- [c_matrix_flatten](#c_matrix_flattenmat)
- [c_matrix_reshape](#c_matrix_reshapemat-row-col)
- [c_matrix_sum](#c_matrix_summat)
- [c_matrix_mean](#c_matrix_meanmat)
- [c_matrix_max](#c_matrix_maxmat)
- [c_matrix_min](#c_matrix_minmat)
- [c_matrix_var](#c_matrix_varmat)
- [c_matrix_std](#c_matrix_stdmat)
- [c_array_search](#c_array_searcharr-target)

### Extension in c_array_mt.c
- [mt19937_init](#void-mt19937_initmt19937_state-state-unsigned-int-seed)
- [mt19937_generate](#unsigned-long-mt19937_generatemt19937_state-state)
- [mt19937_get_int32_range](#int-mt19937_get_int32_rangemt19937_state-state-int-m-int-n)
- [mt19937_get_float](#float-mt19937_get_floatmt19937_state-state)
- [mt19937_get_float_range](#float-mt19937_get_float_rangemt19937_state-state-float-m-float-n)
- [mt19937_get_double](#double-mt19937_get_doublemt19937_state-state)
- [mt19937_get_double_range](#double-mt19937_get_double_rangemt19937_state-state-double-m-double-n)
- [random_normal](#double-random_normalmt19937_state-state)
- [c_array_randnormal](#c_array_randnormalarr-c-rng_state)
- [c_array_rand_range](#c_array_rand_rangearr-c-rng_function)

# Usuage
Here is an example in `example.c` that demonstrates how to use this library. You can simply use the shell script `example.sh (for Linux)` or the batch file `example.bat` to compile and run the program. The example program prints out results to help users understand how it works.

### Example
```C
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

Create the array with given datatype by `c_array(datatype) arr;`. You should initialize it before use. `arr.size` is the logical size of the array and `arr.capacity` is the whole space for the container. However it is better to use `c_array_int`, `c_array_float`, `c_array_doulbe` which was defined by `typdef`. You can also define your own type like `typedef c_array_long c_array(long);`.

Initialize the array with the given size & capacity by `c_array_init(&arr, size)`.
```C
int main() {
    c_array(int) arr;  // You can use this method to declare array, but it can't be used in other function which need to declare the dtype.
    c_array_int array; // This is the dtype of c_array(int). You can use this in any function which need to declare dtype like void foo(c_array_int array, int num);
    c_array_init(&arr, 10); // arr[0] ~ arr[9] will be initialized with 0
    c_array_free(&arr); // free memory
    return 0;
}
```

----
### `c_array_empty_init(arr, c)`
- params:<br>
`T`: the data type of the array -> (**int, long long, float, double etc..**)<br>
`arr`: c_array structure -> (**c_array**)<br>
`c`: the capacity for init -> (**size_t**)<br>

Allocate memory of the array with the given size & capacity (No initialize value).
```C
int main() {
    c_array(int) arr;  // You can use this method to declare array, but it can't be used in other function which need to declare the dtype.
    c_array_int array; // This is the dtype of c_array(int). You can use this in any function which need to declare dtype like void foo(c_array_int array, int num);
    c_array_init(&arr, 10); // arr[0] ~ arr[9] will be initialized with 0
    c_array_free(&arr); // free memory
    return 0;
}
```

----
### `c_array_copy(arr_old, arr_new)`
- params:<br>
`arr_old`: c_array structure you want to copy -> (**c_array**)<br>
`arr_new`: new c_array structure -> (**c_array**)<br>

Copy an array to the target arry.
```C
int main() {
    c_array_int arr;
    c_array_init(&arr, 0); // arr[0] ~ arr[9] will be initialized with 0
    c_array_push_back(&arr, 7);
    c_array_push_back(&arr, 8);
    c_array_push_back(&arr, 9);

    c_array_int arr_new;  // declare arr_new without initialize.
    c_array_copy(&arr, &arr_new); // copy the memory from arr to arr_new
    c_array_print(arr_new, "%d"); // arr_new = [7, 8, 9], size and capacity are also equals to arr
    c_array_free(&arr); // free memory

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
    c_array_int arr;
    c_array_init(&arr, 10);
    // Get size and capacity by macro
    int size = c_array_size(&arr); // equals to 10
    int capacity = c_array_capacity(&arr); // equals to 10

    // Get these attributes by struct
    size = arr.size;
    capacity = arr.capacity;
    c_array_free(&arr);
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
    c_array_int arr;
    c_array_init(&arr, 10);
    c_array_assign(&arr, 0, 150); // arr.data[0] now is 150
    c_array_assign(&arr, 11, 150); // program abort due to the size of array is only 10.

    // Assign value in struct directly
    arr.data[0] = -150; // warning: this method didn't check if the memory is allocated.
    c_array_free(&arr); // free memory
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
    c_array_int arr;
    c_array_init(&arr, 0); // capacity and size are both 0 now
    c_array_resize(&arr, 10); // capacity become 10 and size remain 0.
    c_array_set_size(&arr, 8); // capacity is 10 and size is 8 (element will initialize with 0)
    c_array_free(&arr); // free memory
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
    c_array_int arr;
    c_array(&arr, 0);
    c_array_push_back(&arr, 1); // capacity and size is 1 now
    c_array_push_back(&arr, 2); // capacity and size is 2 now
    c_array_push_back(&arr, 3); // capacity is 4 and size is 3 now
    c_array_free(&arr); // free memory
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
    c_array_int arr;
    c_array(&arr, 0);
    c_array_push_back(&arr, 1);
    c_array_push_back(&arr, 2);
    c_array_push_back(&arr, 3); // arr = [1, 2, 3]
    c_array_pop_back(&arr);     // arr = [1, 2]
    c_array_free(&arr); // free memory
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
    c_array_int arr;
    c_array(&arr, 0);
    c_array_push_back(&arr, 1);
    c_array_push_back(&arr, 2);
    c_array_push_back(&arr, 3);  // arr = [1, 2, 3]
    c_array_insert(&arr, 1, 99); // arr = [1, 99, 2, 3]
    c_array_free(&arr); // free memory
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
    c_array_int arr;
    c_array(&arr, 0);
    c_array_push_back(&arr, 1);
    c_array_push_back(&arr, 2);
    c_array_push_back(&arr, 3); // arr = [1, 2, 3]
    c_array_remove(&arr, 1);    // arr = [1, 3]
    c_array_free(&arr); // free memory
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
    c_array_int arr_print_test;
    c_array(&arr_print_test, 0);
    c_array_push_back(&arr_print_test, 1);
    c_array_push_back(&arr_print_test, 2);
    c_array_push_back(&arr_print_test, 3);
    c_array_printf(arr_print_test, "%d");   // Custom format to print the array
    // Results shows: arr_print_test = [1, 2, 3]

    c_array_print(arr_print_test); // Default format like %d %lld %f %lf. You can add more format in c_array_autoformat macro
    // Results shows: arr_print_test = [1, 2, 3]

    c_array_free(&arr); // free memory
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
    c_array_int arr;
    c_array(&arr, 0);
    int e = c_array_empty(&arr); // e = 1
    c_array_free(&arr); // free memory
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
    c_array_int arr;
    c_array(&arr, 0);
    c_array_push_back(&arr, 1);
    c_array_push_back(&arr, 2);
    c_array_push_back(&arr, 3); // arr = [1, 2, 3]
    c_array_swap(&arr, 0, 1);   // arr = [2, 1, 3]
    c_array_free(&arr); // free memory
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
    c_array_int arr;
    c_array(&arr, 0);
    c_array_push_back(&arr, 1);
    c_array_push_back(&arr, 2);
    c_array_push_back(&arr, 3); // arr = [1, 2, 3]
    c_array_reverse(&arr);      // arr = [3, 2, 1]
    c_array_free(&arr); // free memory
    return 0;
}
```

----
### `c_array_concat(arr1, arr2)`
- params:<br>
`arr1`: c_array structure (result will concat at this array) -> (**c_array**)<br>
`arr2`: c_array structure -> (**c_array**)<br>

Concat two arrays.
```C
int main() {
    c_array_int arr;
    c_array_int arr2;
    c_array(&arr, 0);
    c_array(&arr2, 0);
    c_array_push_back(&arr, 1);
    c_array_push_back(&arr, 2);
    c_array_push_back(&arr2, 9);
    c_array_push_back(&arr2, -45);

    c_array_concat(&arr1, &arr2); // arr1 = [1, 2, 9, -45], arr2 = [9, -45]

    c_array_free(&arr); // free memory
    c_array_free(&arr2); // free memory
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
    c_array_int arr;
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
    c_array_int arr;
    c_array(&arr, 0);
    c_array_push_back(&arr, 99);
    c_array_push_back(&arr, -2);
    c_array_push_back(&arr, 2); // arr = [99, -2, 2]
    c_array_qsort(&arr); // arr = [-2, 2, 99]

    c_array_push_back(&arr, -91);
    c_array_push_back(&arr, 1); // arr = [-2, 2, 99, -91, 1]
    c_array_msort(&arr); // arr = [-91, -2, 1, 2, 99]
    c_array_free(&arr); // free memory
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
    c_array_int arr;
    c_array(&arr, 0);
    c_array_push_back(&arr, 1);
    c_array_push_back(&arr, 2);
    c_array_push_back(&arr, 3);
    int sum = c_array_sum(&arr); // sum = 6
    c_array_free(&arr); // free memory
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
    c_array_int arr;
    c_array(&arr, 0);
    c_array_push_back(&arr, 1);
    c_array_push_back(&arr, 2);
    c_array_push_back(&arr, 3);
    int max = c_array_max(&arr); // max = 3
    int min = c_array_min(&arr); // min = 1
    c_array_free(&arr); // free memory
    return 0;
}
```

----
### `c_array_maxmin(arr)`
- params:<br>
`arr`: c_array structure -> (**c_array**)<br>
- return: `pointer contain min and max (arr[0] = min, arr[1] = max)` -> (**int*, long long*, float*, double* etc..**)<br>

Get min or max value of an array
```C
int main() {
    c_array_int arr;
    c_array(&arr, 0);
    c_array_push_back(&arr, 1);
    c_array_push_back(&arr, 2);
    c_array_push_back(&arr, 3);
    int* max_min = c_array_maxmin(&arr); // max_min[0] = 1, max_min[1] = 3
    c_array_free(&arr); // free memory
    free(max_min)
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
    c_array_int arr;
    c_array(&arr, 0);
    c_array_push_back(&arr, 1);
    c_array_push_back(&arr, 2);
    c_array_push_back(&arr, 3);
    mean_t mean = c_arry_mean(&arr); // mean = 2
    c_array_free(&arr); // free memory
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
    c_array_int arr;
    c_array(&arr, 0);
    c_array_push_back(&arr, 1);
    c_array_push_back(&arr, 2);
    c_array_push_back(&arr, 3);
    std_t std = c_array_std(&arr); // std = 0.8164
    var_t var = c_array_var(&arr); // var =  0.6667
    c_array_free(&arr); // free memory
    return 0;
}
```

----
### `void mt19937_init(mt19937_state* state, unsigned int seed)`
- params:<br>
`state`: state of random seed generator -> (**mt19937_state***)<br>
`seed`: random seed number -> (**unsigned int**)<br>
- return: `void` -> (**void**)<br>

Create the random seed generator with the given random seed.
```C
int main() {
    mt19937_state state;
    mt19937_init(&state, 12345);
    return 0;
}
```

----
### `unsigned long mt19937_generate(mt19937_state* state)`
- params:<br>
`state`: state of random seed generator -> (**mt19937_state***)<br>
- return: `random value` -> (**unsigned long**)<br>

Get the long or integer type random value between 0 ~ 4294967296.
```C
int main() {
    mt19937_state state;
    mt19937_init(&state, 12345);
    long num = mt19937_generate(&state);
    return 0;
}
```

----
### `float mt19937_get_float(mt19937_state* state)`
- params:<br>
`state`: state of random seed generator -> (**mt19937_state***)<br>
- return: `random value` -> (**float**)<br>

Get the float type random value between 0 ~ 1.
```C
int main() {
    mt19937_state state;
    mt19937_init(&state, 12345);
    float num = mt19937_get_float(&state);
    return 0;
}
```

----
### `double mt19937_get_double(mt19937_state* state)`
- params:<br>
`state`: state of random seed generator -> (**mt19937_state***)<br>
- return: `random value` -> (**double**)<br>

Get the double type random value between 0 ~ 1.
```C
int main() {
    mt19937_state state;
    mt19937_init(&state, 12345);
    double num = mt19937_get_double(&state);
    return 0;
}
```

----
### `int mt19937_get_int32_range(mt19937_state* state, int m, int n)`
- params:<br>
`state`: state of random seed generator -> (**mt19937_state***)<br>
`m`: min value -> (**int**)<br>
`n`: max value -> (**int**)<br>
- return: `random value` -> (**int**)<br>

Get the random value between given min and max.
```C
int main() {
    mt19937_state state;
    mt19937_init(&state, 12345);
    int num = mt19937_get_int32_range(&state, -10, 20); // -10 <= num <= 20
    return 0;
}
```

----
### `float mt19937_get_float_range(mt19937_state* state, float m, float n)`
- params:<br>
`state`: state of random seed generator -> (**mt19937_state***)<br>
`m`: min value -> (**float**)<br>
`n`: max value -> (**float**)<br>
- return: `random value` -> (**float**)<br>

Get the random value between given min and max.
```C
int main() {
    mt19937_state state;
    mt19937_init(&state, 12345);
    float num = mt19937_get_float_range(&state, -5.65, 20.11); // -5.65 <= num < 20.11
    return 0;
}
```

----
### `double mt19937_get_double_range(mt19937_state* state, double m, double n)`
- params:<br>
`state`: state of random seed generator -> (**mt19937_state***)<br>
`m`: min value -> (**double**)<br>
`n`: max value -> (**double**)<br>
- return: `random value` -> (**double**)<br>

Get the random value between given min and max.
```C
int main() {
    mt19937_state state;
    mt19937_init(&state, 12345);
    double num = mt19937_get_double_range(&state, -5.65, 20.11); // -5.65 <= num < 20.11
    return 0;
}
```

----
### `double random_normal(mt19937_state* state)`
- params:<br>
`state`: state of random seed generator -> (**mt19937_state***)<br>
- return: `random value` -> (**double**)<br>

Draw the random value from standard normal distribution.
```C
int main() {
    mt19937_state state;
    mt19937_init(&state, 12345);
    double num = random_normal(&state);
    return 0;
}
```

----
### `c_array_randnormal(arr, c, rng_state)`
- params:<br>
`arr`: c_array structure -> (**c_array**)<br>
`c`: capacity and size for init -> (**int**)<br>
`rng_state`: state of random seed generator -> (**mt19937_state***)<br>

Initialize the c_array with the random value from standard normal distribution.
```C
int main() {
    mt19937_state state;
    mt19937_init(&state, 12345);
    c_array_double array;
    c_array_randnormal(&array, 10, &state);
    c_array_free(&array); // free memory
    return 0;
}
```

----
### `c_array_rand_range(arr, c, rng_function)`
- params:<br>
`arr`: c_array structure -> (**c_array**)<br>
`c`: capacity and size for init -> (**int**)<br>
`rng_function`: rng_function -> (**rng_function**)<br>

Initialize the c_array with the random value from given random function
```C
int main() {
    mt19937_state state;
    mt19937_init(&state, 12345);
    c_array_double array;
    double num = random_normal(&state);
    c_array_rand_range(&arr, c, mt19937_get_int32_range(&state, -5, 20));
    c_array_free(&array); // free memory
    return 0;
}
```

----
### `c_array_search(arr, target)`
- params:<br>
`arr`: c_array structure -> (**c_array**)<br>
`target`: target you want to search -> (**int, long long, float, double etc..**)<br>
- return: `An heap array of the target` -> (**int pointer**)<br>

Initialize the c_array with the random value from given random function
```C
int main() {
    c_array_int array;
    c_array_init(&array, 0);
    for (int i = 0; i < 5; i++) {
        array.data[i] = i * 2;
    }
    int* indices = c_array_search(&array, 8); // idx[0] = 4;
    c_array_free(&array); // free memory
    free(indices);
    return 0;
}
```

----
### `c_matrix_init(mat, rows, cols)`
- params:<br>
`mat`: c_matrix structure -> (**c_matrix**)<br>
`rows`: number of rows -> (**int**)<br>
`cols`: number of cols -> (**int**)<br>

Initialize c_matrix with given rows and cols.
```C
int main() {
    c_matrix_int mat;
    c_matrix_init(&mat, 2, 2); // matrix will init with value = 0
    c_matrix_free(&mat); // free memory
    return 0;
}
```

----
### `c_matrix_copy(mat_old, mat_new)`
- params:<br>
`mat_old`: c_matrix structure to be copied -> (**c_matrix**)<br>
`mat_new`: The new clone of c_matrix structure -> (**c_matrix**)<br>

Copy memory of mat_old to mat_new.
```C
int main() {
    c_matrix_int mat;
    c_matrix_int mat_new;
    c_matrix_init(&mat, 4, 5);
    c_matrix_copy(&mat, &mat_new); // mat_new row = 4, mat_new col = 5
    c_matrix_free(&mat); // free memory
    c_matrix_free(&mat_new);
    return 0;
}
```

----
### `c_matrix_empty_init(mat, rows, cols)`
- params:<br>
`mat`: c_matrix structure -> (**c_matrix**)<br>
`rows`: number of rows -> (**int**)<br>
`cols`: number of cols -> (**int**)<br>

Allocate memory of the matrix with given rows and cols (No initialize value).
```C
int main() {
    c_matrix_int mat;
    c_matrix_empty_init(&mat, 2, 2);
    c_matrix_free(&mat); // free memory
    return 0;
}
```

----
### `c_matrix_randnormal(mat, r, c, rng_state)`
- params:<br>
`mat`: c_matrix structure -> (**c_matrix**)<br>
`r`: number of rows -> (**int**)<br>
`c`: number of cols -> (**int**)<br>
`rng_state`: state of random seed generator -> (**mt19937_state***)<br>

Initialize c_matrix with random value draw from noraml distribution.
```C
int main() {
    c_matrix_double mat;
    mt19937_state rng;
    unsigned int seed = 12345;
    mt19937_init(&rng, seed);
    c_matrix_randnormal(&mat, 10, 10, &rng);
    c_matrix_free(&mat); // free memory
    return 0;
}
```

----
### `c_matrix_rand_range(mat, r, c, rng_function)`
- params:<br>
`mat`: c_matrix structure -> (**c_matrix**)<br>
`r`: number of rows -> (**int**)<br>
`c`: number of cols -> (**int**)<br>
`rng_state`: state of random seed generator -> (**mt19937_state***)<br>

Initialize the c_matrix with the random value from given random function.
```C
int main() {
    c_matrix_int mat;
    mt19937_state rng;
    unsigned int seed = 12345;
    mt19937_init(&rng, seed);
    c_matrix_rand_range(&mat, r, c, mt19937_get_int32_range(&state, -5, 20));
    c_matrix_free(&mat); // free memory
    return 0;
}
```

----
### `c_matrix_assign(mat, rows, cols, val)`
- params:<br>
`mat`: c_matrix structure -> (**c_matrix**)<br>
`rows`: number of rows -> (**int**)<br>
`cols`: number of cols -> (**int**)<br>
`val`: value -> (**int, long long, float, double etc..**)<br>

Assign given value at given row and col.
```C
int main() {
    c_matrix_int mat;
    c_matrix_init(&mat, 2, 2);
    c_matrix_assign(&mat, 2, 2, 10);
    c_matrix_free(&mat); // free memory
    return 0;
}
```

----
### `c_matrix_print(mat)` & `c_matrix_printf(mat, format)`
- params:<br>
`mat`: c_matrix structure -> (**c_matrix**)<br>
`format`: format specifier -> (**char\***)<br>

Print matirx with clean style.
```C
int main() {
    c_matrix_int mat;
    c_matrix_init(&mat, 2, 2);
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            mat.data[i][j] = i + j;
        }
    }

    c_matrix_print(mat);
    c_matrix_printf(mat, "%d");

    c_array_free(&arr); // free memory
    return 0;
}
```

----
### `c_matrix_free(mat)`
- params:<br>
`mat`: c_matrix structure -> (**c_matrix**)<br>

Free memory
```C
int main() {
    c_matrix_int mat;
    c_matrix_init(&mat, 2, 2);
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            mat.data[i][j] = i + j;
        }
    }
    c_matrix_free(&mat); // free memory
    return 0;
}
```

----
### `c_array_matrix_form(arr, n_row)`
- params:<br>
`arr`: c_matrix structure -> (**c_array**)<br>
`n_row`: number of rows -> (**int**)<br>
- return: `c_matrix` -> (**c_matrix**)<br>

Reshape array to matrix with given row numbers.
```C
int main() {
    c_array_int arr;
    c_matrix_init(&mat, 20);
    for (int i = 0; i < arr.size; i++) {
        arr.data[i] = i;
    }
    c_matrix_int mat = c_array_matrix_form(&arr, 4); // mat.rows = 4, mat.cols = 5
    c_array_free(&arr);
    c_matrix_free(&mat); // free memory
    return 0;
}
```

----
### `c_matrix_flatten(mat)`
- params:<br>
`mat`: c_matrix structure -> (**c_matrix**)<br>
- return: `c_array` -> (**c_array**)<br>

Flatten c_matrix and return c_array
```C
int main() {
    c_matrix_int mat;
    c_matrix_init(&mat, 2, 2);
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            mat.data[i][j] = i + j;
        }
    }
    c_array_int arr = c_matrix_flatten(&mat);
    c_matrix_free(&mat); // free memory
    return 0;
}
```

----
### `c_matrix_reshape(mat, row, col)`
- params:<br>
`mat`: c_matrix structure -> (**c_matrix**)<br>
`row`: row number -> (**int**)<br>
`col`: col number -> (**int**)<br>
- return: `c_matrix` -> (**c_matrix**)<br>

Reshape c_matrix.
```C
int main() {
    c_matrix_int mat;
    c_matrix_init(&mat, 2, 2);
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            mat.data[i][j] = i + j;
        }
    }
    c_array_int arr = c_matrix_reshape(&mat, 4, 1);
    c_matrix_free(&mat); // free memory
    return 0;
}
```

----
### `c_matrix_sum(mat)`
- params:<br>
`mat`: c_matrix structure -> (**c_matrix**)<br>
- return: `sum` -> (**int, long long, float, double etc..**)<br>

Calculate the sum of the matrix.
```C
int main() {
    c_matrix_int mat;
    c_matrix_init(&mat, 2, 2);
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            mat.data[i][j] = 5;
        }
    }
    int sum_i = c_matrix_sum(&mat); // sum i = 20
    c_matrix_free(&mat); // free memory
    return 0;
}
```

----
### `c_matrix_mean(mat)`
- params:<br>
`mat`: c_matrix structure -> (**c_matrix**)<br>
- return: `mean` -> (**mean_t**)<br>

Calculate the mean value of the matrix.
```C
int main() {
    c_matrix_int mat;
    c_matrix_init(&mat, 2, 2);
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            mat.data[i][j] = 5;
        }
    }
    mean_t mean = c_matrix_mean(&mat); // mean = 5
    c_matrix_free(&mat); // free memory
    return 0;
}
```

----
### `c_matrix_max(mat) and c_matrix_min(mat)`
- params:<br>
`mat`: c_matrix structure -> (**c_matrix**)<br>
- return: `max or min` -> (**int, long long, float, double etc..**)<br>

Get the max or min of the matrix.
```C
int main() {
    c_matrix_int mat;
    c_matrix_init(&mat, 2, 2);
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            mat.data[i][j] = i + j;
        }
    }
    int max = c_matrix_max(&mat); // mean = 2
    int min = c_matrix_min(&mat); // min = 0
    c_matrix_free(&mat); // free memory
    return 0;
}
```


----
### `c_matrix_var(mat) and c_matrix_std(mat)`
- params:<br>
`mat`: c_matrix structure -> (**c_matrix**)<br>
- return: `std or var` -> (**std_t, var_t**)<br>

Calculate the variance or the standard deviation of the matrix.
```C
int main() {
    c_matrix_int mat;
    c_matrix_init(&mat, 3, 3);
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            mat.data[i][j] = i + j;
        }
    }
    var_t var = c_matrix_var(&mat); // var = 1.3333333
    std_t std = c_matrix_std(&mat); // std = 1.154701
    c_matrix_free(&mat); // free memory
    return 0;
}
```