/*
    Copyright (c) 2022 Jian Yu, Chen
    License: MIT License
    Version: v1.3.2
    file   : c_array.h

    The latest version is avaliable at:
    https://github.com/Zncl2222/c_array_tools
*/


# ifndef C_ARRAY_H
# define C_ARRAY_H

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <stdint.h>
# include <string.h>
# include <assert.h>

typedef double mean_t;
typedef double std_t;
typedef double var_t;

// -----------------------------------------------------------------------
/*                     Array structure and initialize                   */

# define c_array(T) struct { T* data; size_t size; size_t capacity; }

# define c_array_init(arr, c)                                            \
    do {                                                                 \
        typeof(*((arr)->data)) x;                                        \
        (arr)->size = (c);                                               \
        (arr)->capacity = (c);                                           \
        (arr)->data = calloc((c), sizeof(x));                            \
    } while(0)

# define c_array_copy(arr1, arr2)                                                                \
    do {                                                                                         \
        char* dtype_arr1 = c_array_dtype(arr1);                                                  \
        char* dtype_arr2 = c_array_dtype(arr2);                                                  \
        if (dtype_arr1 != dtype_arr2) {                                                          \
            c_array_error("dtype of two arrays are different");                                  \
        }                                                                                        \
        (arr2)->size = (arr1)->size;                                                             \
        (arr2)->capacity = (arr1)->capacity;                                                     \
        (arr2)->data = malloc((arr2)->capacity * sizeof(typeof(*(arr2)->data)));                 \
        if((arr2)->data == NULL) {                                                               \
            c_array_error("failed to allocate memory in c_array_copy");                          \
        }                                                                                        \
        memcpy((arr2)->data, (arr1)->data, (arr2)->capacity * sizeof(typeof(*(arr2)->data)));    \
    } while(0)

/* c_array_mt.c is necessary for c_array_randnormal & c_array_rand_range */

# define c_array_randnormal(arr, c, rng_state)                          \
    do {                                                                \
        (arr)->size = (c);                                              \
        (arr)->capacity = (c);                                          \
        (arr)->data = malloc(sizeof(typeof(*((arr)->data))) * (c));     \
        for (int i = 0; i < (arr)->size; i++) {                         \
            (arr)->data[i] = random_normal(rng_state);                  \
        }                                                               \
    } while(0)

# define c_array_rand_range(arr, c, rng_function)                       \
    do {                                                                \
        (arr)->size = (c);                                              \
        (arr)->capacity = (c);                                          \
        (arr)->data = malloc(sizeof(typeof(*((arr)->data))) * (c));     \
        for (int i = 0; i < (arr)->size; i++) {                         \
            (arr)->data[i] = rng_function;                              \
        }                                                               \
    } while(0)

typedef c_array(short) c_array_short;
typedef c_array(unsigned short) c_array_ushort;
typedef c_array(int) c_array_int;
typedef c_array(unsigned int) c_array_uint;
typedef c_array(long) c_array_long;
typedef c_array(unsigned long) c_array_ulong;
typedef c_array(long long) c_array_long_long;
typedef c_array(float) c_array_float;
typedef c_array(double) c_array_double;
typedef c_array(long double) c_array_ldouble;


// -----------------------------------------------------------------------
/*                      Array basic operations                          */

# define c_array_capacity(arr) ((arr) ? (arr)->capacity : 0)

# define c_array_size(arr) ((arr) ? (arr)->size : 0)

# define c_array_assign(arr, idx, val)                                   \
    do {                                                                 \
        if ((idx) > (arr)->size) {                                       \
            c_array_error("Index out of range (size)");                  \
        }                                                                \
        (arr)->data[(idx)] = (val);                                      \
    } while(0)

// -----------------------------------------------------------------------
/*                  Arrary size and attributes settings                 */

# define c_array_byte(arr) (sizeof((arr)->data[0]))

# define c_array_grow(arr)                                                          \
    do {                                                                            \
        if((arr)->capacity == 0) {                                                  \
            (arr)->capacity = 1;                                                    \
        }                                                                           \
        (arr)->capacity *= 2;                                                       \
        void* ptr = realloc((arr)->data, (arr)->capacity * c_array_byte((arr)));    \
        if (ptr == NULL) {                                                          \
            c_array_error("Realloc Failed");                                        \
        }                                                                           \
        (arr)->data = ptr;                                                          \
    } while(0)

# define c_array_resize(arr, c)                                             \
    do {                                                                    \
        void* ptr = realloc((arr)->data, (c) * c_array_byte((arr)));        \
        if (ptr == NULL) {                                                  \
            c_array_error("Realloc Failed");                                \
        }                                                                   \
        (arr)->capacity = (c);                                              \
        (arr)->data = ptr;                                                  \
    } while(0)

# define c_array_set_size(arr, l)                                           \
    do {                                                                    \
        if ((l) > (arr)->capacity) {                                        \
            c_array_error("Size should less than or equal to capacity");    \
        }                                                                   \
        for (int i = (arr)->size; i < (arr)->capacity; i++) {               \
            (arr)->data[i] = 0;                                             \
        }                                                                   \
        (arr)->size = (l);                                                  \
    } while(0)

// -----------------------------------------------------------------------
/*                  Arrary push_back and pop_back                       */

# define c_array_push_back(arr, val)                             \
    do {                                                         \
        if (c_array_capacity((arr)) <= c_array_size((arr))) {    \
            c_array_grow((arr));                                 \
        }                                                        \
        (arr)->data[(arr)->size] = val;                          \
        (arr)->size++;                                           \
    } while(0)

# define c_array_pop_back(arr)                              \
    do {                                                    \
        if ((arr)->size <= 0) {                             \
            c_array_error("Size should greater than 0");    \
        }                                                   \
        (arr)->data[(arr)->size - 1] = 0;                   \
        (arr)->size--;                                      \
    } while(0)

// -----------------------------------------------------------------------
/*                      Arrary insert and remove                        */

# define c_array_moveright(arr, idx)                  \
    do {                                              \
        if ((arr)->capacity <= (arr)->size) {         \
            c_array_grow(arr);                        \
        }                                             \
        for(int i = (arr)->size; i > idx; i--) {      \
            (arr)->data[i] = (arr)->data[i - 1];      \
        }                                             \
    } while(0)

# define c_array_moveleft(arr, idx)                         \
    do {                                                    \
        for(int i = idx; i < (arr)->size - 1; i++) {        \
            (arr)->data[i] = (arr)->data[i + 1];            \
        }                                                   \
    } while(0)                                              \

# define c_array_insert(arr, idx, val)                  \
    do {                                                \
        if ((idx) < (arr)->size) {                      \
            c_array_moveright((arr), (idx));            \
            (arr)->data[(idx)] = (val);                 \
            (arr)->size++;                              \
        }                                               \
    } while(0)

# define c_array_remove(arr, idx)                           \
    do {                                                    \
        if ((arr)-> size <= 0) {                            \
            c_array_error("Size should greater than 0");    \
        }                                                   \
        if ((arr)->size <= idx) {                           \
            c_array_error("Index out of range (size)");     \
        }                                                   \
        c_array_moveleft(arr, idx);                         \
        (arr)->size--;                                      \
    } while(0)

// -----------------------------------------------------------------------
/*                       Arrary concatenation                           */

# define c_array_concat(arr1, arr2)                                                 \
    do {                                                                            \
        if (c_array_dtype((arr1)) != c_array_dtype((arr2))) {                       \
            c_array_error("data type of two arrays should be the same");            \
        }                                                                           \
        size_t new_capacity = (arr1)->capacity + (arr2)->capacity;                  \
        size_t new_size = (arr1)->size + (arr2)->size;                              \
        if ((arr1)->capacity < new_size) {                                          \
            c_array_resize(arr1, new_capacity);                                     \
        }                                                                           \
        for (int i = 0; i < (arr2)->size; i++) {                                    \
            (arr1)->data[i + (arr1)->size] = (arr2)->data[i];                       \
        }                                                                           \
        (arr1)->size = new_size;                                                    \
    } while(0)

// -----------------------------------------------------------------------
/*                           Array qsort                                */

# define c_array_qsort(arr)                                                                       \
    do {                                                                                          \
        qsort((arr)->data, (arr)->size, sizeof(typeof((*(arr)->data))), c_array_qsort_cmp((arr)));\
    } while(0)

# define c_array_qsort_cmp(arr)                         \
    _Generic((arr)->data,                               \
        short*: cmpfunc_short,                          \
        unsigned short*: cmpfunc_ushort,                \
        int*: cmpfunc_int,                              \
        unsigned int*: cmpfunc_uint,                    \
        long*: cmpfunc_long,                            \
        unsigned long*: cmpfunc_ulong,                  \
        long long*: cmpfunc_long_long,                  \
        float*: cmpfunc_float,                          \
        double*: cmpfunc_double,                        \
        long double*: cmpfunc_long_double               \
    )

int cmpfunc_short(const void* a, const void* b);

int cmpfunc_ushort(const void* a, const void* b);

int cmpfunc_int(const void* a, const void* b);

int cmpfunc_uint(const void* a, const void* b);

int cmpfunc_long(const void* a, const void* b);

int cmpfunc_ulong(const void* a, const void* b);

int cmpfunc_long_long(const void* a, const void* b);

int cmpfunc_float(const void* a, const void* b);

int cmpfunc_double(const void* a, const void* b);

int cmpfunc_long_double(const void* a, const void* b);

// -----------------------------------------------------------------------
/*                           Array msort                                */

# define c_array_msort(arr)                                                 \
    do {                                                                    \
        int i, j, k, l1, r1, l2, r2;                                        \
        int curr_size;                                                      \
        typeof(*(arr)->data) temp[(arr)->size];                             \
        for (curr_size = 1; curr_size < (arr)->size; curr_size *= 2) {      \
            l1 = 0;                                                         \
            k = 0;                                                          \
            while (l1 + curr_size < (arr)->size) {                          \
                r1 = l1 + curr_size - 1;                                    \
                l2 = r1 + 1;                                                \
                r2 = l2 + curr_size - 1;                                    \
                if(r2 >= (arr)->size) {                                     \
                    r2 = (arr)->size - 1;                                   \
                }                                                           \
                i = l1;                                                     \
                j = l2;                                                     \
                while (i <= r1 && j <= r2) {                                \
                    if ((arr)->data[i] <= (arr)->data[j]) {                 \
                        temp[k++] = (arr)->data[i++];                       \
                    } else {                                                \
                        temp[k++] = (arr)->data[j++];                       \
                    }                                                       \
                }                                                           \
                while (i <= r1) {                                           \
                    temp[k++] = (arr)->data[i++];                           \
                }                                                           \
                while (j <= r2) {                                           \
                    temp[k++] = (arr)->data[j++];                           \
                }                                                           \
                l1 = r2 + 1;                                                \
            }                                                               \
            for (i = l1; k < (arr)->size; i++) {                            \
                temp[k++] = (arr)->data[i];                                 \
            }                                                               \
            for (i = 0; i < (arr)->size; i++) {                             \
                (arr)->data[i] = temp[i];                                   \
            }                                                               \
        }                                                                   \
    } while(0)

// -----------------------------------------------------------------------
/*                              Array Sum                               */

# define c_array_sum(arr)                       \
    _Generic((arr)->data,                       \
        short*: c_array_sum_short,              \
        unsigned short*: c_array_sum_ushort,    \
        int*: c_array_sum_int,                  \
        unsigned int*: c_array_sum_uint,        \
        long*: c_array_sum_long,                \
        unsigned long*: c_array_sum_ulong,      \
        long long*: c_array_sum_long_long,      \
        float*: c_array_sum_float,              \
        double*: c_array_sum_double,            \
        long double*: c_array_sum_long_double   \
    )((arr)->data, (arr)->size)

# define c_array_sum_process(arr, size)     \
    typeof(*(arr)) sum = 0;                 \
    for (int i = 0; i < size; i++) {        \
        sum += arr[i];                      \
    }                                       \
    return sum;                             \

short c_array_sum_short(short* arr, int size);

unsigned short c_array_sum_ushort(unsigned short* arr, int size);

int c_array_sum_int(int* arr, int size);

unsigned int c_array_sum_uint(unsigned int* arr, int size);

long c_array_sum_long(long* arr, int size);

unsigned long c_array_sum_ulong(unsigned long* arr, int size);

long long c_array_sum_long_long(long long* arr, int size);

float c_array_sum_float(float* arr, int size);

double c_array_sum_double(double* arr, int size);

long double c_array_sum_long_double(long double* arr, int size);

// -----------------------------------------------------------------------
/*                          Array mean value                            */

# define c_array_mean(arr)                              \
    _Generic((arr)->data,                               \
        short*: c_array_mean_short,                     \
        unsigned short*: c_array_mean_ushort,           \
        int*: c_array_mean_int,                         \
        unsigned int*: c_array_mean_uint,               \
        long*: c_array_mean_long,                       \
        unsigned long*: c_array_mean_ulong,             \
        long long*: c_array_mean_long_long,             \
        float*: c_array_mean_float,                     \
        double*: c_array_mean_double,                   \
        long double*: c_array_mean_long_double          \
    )((arr)->data, (arr)->size, c_array_sum((arr)))

# define c_array_mean_process(arr, size, sum)   \
    mean_t mean = (mean_t)(sum) / (size);       \
    return mean;

mean_t c_array_mean_short(short* arr, int size, short sum);

mean_t c_array_mean_ushort(unsigned short* arr, int size, unsigned short sum);

mean_t c_array_mean_int(int* arr, int size, int sum);

mean_t c_array_mean_uint(unsigned int* arr, int size, unsigned int sum);

mean_t c_array_mean_long(long* arr, int size, long sum);

mean_t c_array_mean_ulong(unsigned long* arr, int size, unsigned long sum);

mean_t c_array_mean_long_long(long long* arr, int size, long long sum);

mean_t c_array_mean_float(float* arr, int size, float sum);

mean_t c_array_mean_double(double* arr, int size, double sum);

mean_t c_array_mean_long_double(long double* arr, int size, long double sum);

// -----------------------------------------------------------------------
/*                     Array standard deviation                         */

# define c_array_std(arr)                              \
    _Generic((arr)->data,                              \
        short*: c_array_std_short,                     \
        unsigned short*: c_array_std_ushort,           \
        int*: c_array_std_int,                         \
        unsigned int*: c_array_std_uint,               \
        long*: c_array_std_long,                       \
        unsigned long*: c_array_std_ulong,             \
        long long*: c_array_std_long_long,             \
        float*: c_array_std_float,                     \
        double*: c_array_std_double,                   \
        long double*: c_array_std_long_double          \
    )((arr)->data, (arr)->size, c_array_mean((arr)))

# define c_array_var(arr)                              \
    _Generic((arr)->data,                              \
        short*: c_array_var_short,                     \
        unsigned short*: c_array_var_ushort,           \
        int*: c_array_var_int,                         \
        unsigned int*: c_array_var_uint,               \
        long*: c_array_var_long,                       \
        unsigned long*: c_array_var_ulong,             \
        long long*: c_array_var_long_long,             \
        float*: c_array_var_float,                     \
        double*: c_array_var_double,                   \
        long double*: c_array_var_long_double          \
    )((arr)->data, (arr)->size, c_array_mean((arr)))

# define c_array_var_process(arr, size, mean)  \
    var_t var = 0;                             \
    for (int i = 0; i < (size); i++) {         \
        var += pow((arr)[i] - (mean), 2);      \
    }                                          \

var_t c_array_var_short(short* arr, int size, mean_t mean);

var_t c_array_var_ushort(unsigned short* arr, int size, mean_t mean);

var_t c_array_var_int(int* arr, int size, mean_t mean);

var_t c_array_var_uint(unsigned int* arr, int size, mean_t mean);

var_t c_array_var_long(long* arr, int size, mean_t mean);

var_t c_array_var_ulong(unsigned long* arr, int size, mean_t mean);

var_t c_array_var_long_long(long long* arr, int size, mean_t mean);

var_t c_array_var_float(float* arr, int size, mean_t mean);

var_t c_array_var_double(double* arr, int size, mean_t mean);

var_t c_array_var_long_double(long double* arr, int size, mean_t mean);

std_t c_array_std_short(short* arr, int size, mean_t mean);

std_t c_array_std_ushort(unsigned short* arr, int size, mean_t mean);

std_t c_array_std_int(int* arr, int size, mean_t mean);

std_t c_array_std_uint(unsigned int* arr, int size, mean_t mean);

std_t c_array_std_long(long* arr, int size, mean_t mean);

std_t c_array_std_ulong(unsigned long* arr, int size, mean_t mean);

std_t c_array_std_long_long(long long* arr, int size, mean_t mean);

std_t c_array_std_float(float* arr, int size, mean_t mean);

std_t c_array_std_double(double* arr, int size, mean_t mean);

std_t c_array_std_long_double(long double* arr, int size, mean_t mean);

// -----------------------------------------------------------------------
/*                          Array Min and Max                           */

# define c_array_max(arr)                              \
    _Generic((arr)->data,                              \
        short*: c_array_max_short,                     \
        unsigned short*: c_array_max_ushort,           \
        int*: c_array_max_int,                         \
        unsigned int*: c_array_max_uint,               \
        long*: c_array_max_long,                       \
        unsigned long*: c_array_max_ulong,             \
        long long*: c_array_max_long_long,             \
        float*: c_array_max_float,                     \
        double*: c_array_max_double,                   \
        long double*: c_array_max_long_double          \
    )((arr)->data, (arr)->size)

# define c_array_min(arr)                              \
    _Generic((arr)->data,                              \
        short*: c_array_min_short,                     \
        unsigned short*: c_array_min_ushort,           \
        int*: c_array_min_int,                         \
        unsigned int*: c_array_min_uint,               \
        long*: c_array_min_long,                       \
        unsigned long*: c_array_min_ulong,             \
        long long*: c_array_min_long_long,             \
        float*: c_array_min_float,                     \
        double*: c_array_min_double,                   \
        long double*: c_array_min_long_double          \
    )((arr)->data, (arr)->size)

# define c_array_maxmin_process(arr, n, mode)                               \
    int odd = (n) & 1;                                                      \
    typeof(*(arr)) max = -pow(2, (((sizeof(typeof(*(arr)))-  1) * 8)));     \
    typeof(*(arr)) min = pow(2, (((sizeof(typeof(*(arr)))-  1) * 8))) - 1;  \
    if (odd) {                                                              \
        (n)--;                                                              \
    }                                                                       \
    typeof(*(arr)) minimum = arr[0];                                        \
    typeof(*(arr)) maximum = arr[0];                                        \
    for (int i = 0; i < n; i = i + 2) {                                     \
        if (arr[i] > arr[i + 1]) {                                          \
            minimum = arr[i + 1],                                           \
            maximum = arr[i];                                               \
        } else {                                                            \
            minimum = arr[i],                                               \
            maximum = arr[i + 1];                                           \
        }                                                                   \
        if (maximum > max) {                                                \
            max = maximum;                                                  \
        }                                                                   \
        if (minimum < min) {                                                \
            min = minimum;                                                  \
        }                                                                   \
    }                                                                       \
    if (odd) {                                                              \
        if (arr[n] > max) {                                                 \
            max = arr[n];                                                   \
        }                                                                   \
        if (arr[n] < min) {                                                 \
            min = arr[n];                                                   \
        }                                                                   \
    }                                                                       \
    if (mode == "max") {                                                    \
        return max;                                                         \
    } else {                                                                \
        return min;                                                         \
    }                                                                       \

short c_array_max_short(short* arr, int size);

unsigned short c_array_max_ushort(unsigned short* arr, int size);

int c_array_max_int(int* arr, int size);

unsigned int c_array_max_uint(unsigned int* arr, int size);

long c_array_max_long(long* arr, int size);

unsigned long c_array_max_ulong(unsigned long* arr, int size);

long long c_array_max_long_long(long long* arr, int size);

float c_array_max_float(float* arr, int size);

double c_array_max_double(double* arr, int size);

long double c_array_max_long_double(long double* arr, int size);

short c_array_min_short(short* arr, int size);

unsigned short c_array_min_ushort(unsigned short* arr, int size);

int c_array_min_int(int* arr, int size);

unsigned int c_array_min_uint(unsigned int* arr, int size);

long c_array_min_long(long* arr, int size);

unsigned long c_array_min_ulong(unsigned long* arr, int size);

long long c_array_min_long_long(long long* arr, int size);

float c_array_min_float(float* arr, int size);

double c_array_min_double(double* arr, int size);

long double c_array_min_long_double(long double* arr, int size);

// -----------------------------------------------------------------------
/*                            Arrary utils                              */

# define c_array_autoformat(arr)    \
    _Generic((arr).data,            \
        short*: "%hd",              \
        unsigned short*: "%hu",     \
        int*: "%d",                 \
        unsigned int*: "%u",        \
        long*: "%ld",               \
        unsigned long: "%lu",       \
        long long*: "%lld",         \
        float*: "%f",               \
        double*: "%lf",             \
        long double*: "%Lf",        \
        short**: "%hd",             \
        unsigned short**: "%hu",    \
        int**: "%d",                \
        unsigned int**: "%u",       \
        long**: "%ld",              \
        unsigned long**: "%lu",     \
        long long**: "%lld",        \
        float**: "%f",              \
        double**: "%lf",            \
        long double**: "%Lf"        \
    )

# define c_array_dtype(arr)                 \
    _Generic((arr)->data,                   \
        short*: "short",                    \
        unsigned short*: "unsigned short",  \
        int*: "int",                        \
        unsigned int*: "unsigned int",      \
        long*: "long",                      \
        unsigned long*: "unsigned long",    \
        long long*: "long long",            \
        float*: "float",                    \
        double*: "double",                  \
        long double*: "long double"         \
    )

# define c_array_print(arr)                                         \
    do {                                                            \
        printf(#arr);                                               \
        printf(" = [");                                             \
        for (int i = 0; i < (arr).size; i++) {                      \
            if (i < (arr).size - 1) {                               \
                printf(c_array_autoformat((arr)), (arr).data[i]);   \
                printf(", ");                                       \
            } else {                                                \
                printf(c_array_autoformat((arr)), (arr).data[i]);   \
            }                                                       \
        }                                                           \
        printf("]\n");                                              \
    } while(0)

# define c_array_printf(arr, format)                    \
    do {                                                \
        printf(#arr);                                   \
        printf(" = [");                                 \
        for(int i = 0; i < (arr).size; i++) {           \
            if (i < (arr).size - 1) {                   \
                printf((format), arr.data[i]);          \
                printf(", ");                           \
            } else {                                    \
                printf((format), arr.data[i]);          \
            }                                           \
        }                                               \
        printf("]\n");                                  \
    } while(0)

# define c_array_empty(arr) ((arr)->size == 0)

# define c_array_swap(arr, idx1, idx2)                                              \
    do {                                                                            \
        if((idx1) >= (arr)->size || (idx2) >= (arr)->size) {                        \
            c_array_error("Index out of range (size)");                             \
        }                                                                           \
        typeof(*((arr)->data)) x;                                                   \
        x = (arr)->data[idx2];                                                      \
        (arr)->data[idx2] = (arr)->data[idx1];                                      \
        (arr)->data[idx1] = x;                                                      \
    } while(0)                                                                      \

# define c_array_reverse(arr)                                                       \
    do {                                                                            \
        typeof(*((arr)->data)) x;                                                   \
        for (int i = 0; i < ((arr)->size / 2); i++) {                               \
            x = (arr)->data[i];                                                     \
            (arr)->data[i] = (arr)->data[(arr)->size - 1 - i];                      \
            (arr)->data[(arr)->size - 1 - i] = x;                                   \
        }                                                                           \
    } while(0)

# define c_array_free(arr) (free((arr)->data))

# define c_array_error(msg)                           \
    do {                                              \
        fprintf(stderr, "Error in %s:%d: %s\n",       \
                __FILE__, __LINE__, (msg));           \
        exit(EXIT_FAILURE);                           \
    } while(0)

// -----------------------------------------------------------------------
/*                  Matrix structure and initialize                     */

# define c_matrix(T) struct { T** data; size_t rows; size_t cols; }

# define c_matrix_init(mat, r, c)                                           \
    do{                                                                     \
        typeof(**((mat)->data)) m;                                          \
        typeof(*((mat)->data)) n;                                           \
        (mat)->rows = (r);                                                  \
        (mat)->cols = (c);                                                  \
        (mat)->data = malloc(r * sizeof(n));                                \
        if ((mat)->data == NULL) {                                          \
            c_array_error(                                                  \
                "Failed to allocate memory for matrix data (row)");         \
        }                                                                   \
        for (int i = 0; i < (r); i++) {                                     \
            (mat)->data[i] = malloc(c * sizeof(m));                         \
            if ((mat)->data[i] == NULL) {                                   \
                c_array_error(                                              \
                    "Failed to allocate memory for matrix data (col)");     \
            }                                                               \
        }                                                                   \
    } while(0)

typedef c_matrix(short) c_matrix_short;
typedef c_matrix(unsigned short) c_matrix_ushort;
typedef c_matrix(int) c_matrix_int;
typedef c_matrix(unsigned int) c_matrix_uint;
typedef c_matrix(long) c_matrix_long;
typedef c_matrix(unsigned long) c_matrix_ulong;
typedef c_matrix(long long) c_matrix_long_long;
typedef c_matrix(float) c_matrix_float;
typedef c_matrix(double) c_matrix_double;
typedef c_matrix(long double) c_matrix_ldouble;

// -----------------------------------------------------------------------
/*                       Matrix basic operations                        */

# define c_matrix_rows(mat) ((mat) ? (mat)->rows : 0)

# define c_matrix_cols(mat) ((mat) ? (mat)->cols : 0)

# define c_matrix_assign(mat, row, col, val)                \
    do {                                                    \
        if ((row) > (mat)->rows) {                          \
            c_array_error("Index out of range (row)");      \
        }                                                   \
        if ((col) > (mat)->cols) {                          \
            c_array_error("Index out of range(col)");       \
        }                                                   \
        (mat)->data[row][col] = val;                        \
    } while(0)

// -----------------------------------------------------------------------
/*                            Matrix utils                               */

# define c_matrix_print(mat)                                                \
    do {                                                                    \
        printf(#mat);                                                       \
        printf(" =\n   [ ");                                                \
        for (int i = 0; i < (mat).rows; i++) {                              \
            if (i != 0)                                                     \
                printf("     ");                                            \
            printf("[ ");                                                   \
            for(int j = 0; j < (mat).cols; j++) {                           \
                if (j < (mat).cols) {                                       \
                    printf(c_array_autoformat((mat)), (mat).data[i][j]);    \
                    printf(", ");                                           \
                } else {                                                    \
                    printf(c_array_autoformat((mat)), (mat).data[i][j]);    \
                }                                                           \
            }                                                               \
            printf("]");                                                    \
            if (i < (mat).rows - 1){                                        \
                printf("\n");                                               \
            }                                                               \
        }                                                                   \
        printf(" ]\n");                                                     \
    } while(0)

# define c_matrix_printf(mat, format)                       \
    do {                                                    \
        printf(#mat);                                       \
        printf(" =\n   [ ");                                \
        for (int i = 0; i < (mat).rows; i++) {              \
            if (i != 0)                                     \
                printf("     ");                            \
            printf("[ ");                                   \
            for(int j = 0; j < (mat).cols; j++) {           \
                if (j < (mat).cols) {                       \
                    printf((format), (mat).data[i][j]);     \
                    printf(", ");                           \
                } else {                                    \
                    printf((format), (mat).data[i][j]);     \
                }                                           \
            }                                               \
            printf("]");                                    \
            if (i < (mat).rows - 1){                        \
                printf("\n");                               \
            }                                               \
        }                                                   \
        printf(" ]\n");                                     \
    } while(0)

# define c_matrix_free(mat)                         \
    do {                                            \
        for (int i = 0; i < (mat)->rows; i++) {     \
            free((mat)->data[i]);                   \
        }                                           \
        free((mat)->data);                          \
    } while(0)

// -----------------------------------------------------------------------
/*                       Random number generator                        */

/*  mt19937 license is declared in c_array_mt.c  */
# ifndef M_PI
# define M_PI 3.1415926
# endif

# define MT_N 624
# define MT_M 397
# define MT_MATRIX_A 0x9908b0df
# define MT_UPPER_MASK 0x80000000
# define MT_LOWER_MASK 0x7fffffff

typedef struct {
    unsigned int state[MT_N];
    int index;
} mt19937_state;

void mt19937_init(mt19937_state* state, unsigned int seed);

unsigned long mt19937_generate(mt19937_state* state);

float mt19937_get_float(mt19937_state* state);

float mt19937_get_float_range(mt19937_state* state, float m, float n);

double mt19937_get_double(mt19937_state* state);

double mt19937_get_double_range(mt19937_state* state, double m, double n);

int mt19937_get_int32_range(mt19937_state* state, int m, int n);

double random_normal(mt19937_state* state);

# endif
