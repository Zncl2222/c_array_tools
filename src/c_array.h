/*
    Copyright (c) 2022 Jian Yu, Chen
    License: MIT License
    Version: v1.4.2
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
# include <limits.h>

typedef double mean_t;
typedef double std_t;
typedef double var_t;

/* ----------------------------------------------------------------------- */
/*                     Array structure and initialize                      */

# define c_array(T) struct { T* data; size_t size; size_t capacity; }

# define c_array_init(arr, c)                                            \
    do {                                                                 \
        typeof(*((arr)->data)) x;                                        \
        (arr)->size = (c);                                               \
        (arr)->capacity = (c);                                           \
        (arr)->data = calloc((c), sizeof(x));                            \
    } while (0)

# define c_array_empty_init(arr, c)                                      \
    do {                                                                 \
        typeof(*((arr)->data)) x;                                        \
        (arr)->size = (c);                                               \
        (arr)->capacity = (c);                                           \
        (arr)->data = malloc((c) * sizeof(x));                           \
    } while (0)

# define c_array_copy(arr_old, arr_new)                                                                     \
    do {                                                                                                    \
        char* dtype_arr1 = c_array_dtype(arr_old);                                                          \
        char* dtype_arr2 = c_array_dtype(arr_new);                                                          \
        if (dtype_arr1 != dtype_arr2) {                                                                     \
            c_array_error("dtype of two arrays are different");                                             \
        }                                                                                                   \
        (arr_new)->size = (arr_old)->size;                                                                  \
        (arr_new)->capacity = (arr_old)->capacity;                                                          \
        (arr_new)->data = malloc((arr_new)->capacity * sizeof(typeof(*(arr_new)->data)));                   \
        if ((arr_new)->data == NULL) {                                                                      \
            c_array_error("failed to allocate memory in c_array_copy");                                     \
        }                                                                                                   \
        memcpy((arr_new)->data, (arr_old)->data, (arr_new)->capacity * sizeof(typeof(*(arr_new)->data)));   \
    } while (0)

/* c_array_mt.c is necessary for c_array_randnormal & c_array_rand_range */

# define c_array_randnormal(arr, c, rng_state)                          \
    do {                                                                \
        (arr)->size = (c);                                              \
        (arr)->capacity = (c);                                          \
        (arr)->data = malloc(sizeof(typeof(*((arr)->data))) * (c));     \
        for (int i = 0; i < (arr)->size; i++) {                         \
            (arr)->data[i] = random_normal(rng_state);                  \
        }                                                               \
    } while (0)

# define c_array_rand_range(arr, c, rng_function)                       \
    do {                                                                \
        (arr)->size = (c);                                              \
        (arr)->capacity = (c);                                          \
        (arr)->data = malloc(sizeof(typeof(*((arr)->data))) * (c));     \
        for (int i = 0; i < (arr)->size; i++) {                         \
            (arr)->data[i] = rng_function;                              \
        }                                                               \
    } while (0)

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

/* -------------------------------------------------------------------- */
/*                      Array basic operations                          */

# define c_array_capacity(arr) ((arr) ? (arr)->capacity : 0)

# define c_array_size(arr) ((arr) ? (arr)->size : 0)

# define c_array_assign(arr, idx, val)                                   \
    do {                                                                 \
        if ((idx) > (arr)->size) {                                       \
            c_array_error("Index out of range (size)");                  \
        }                                                                \
        (arr)->data[(idx)] = (val);                                      \
    } while (0)

/* -------------------------------------------------------------------- */
/*                  Arrary size and attributes settings                 */

# define c_array_byte(arr) (sizeof((arr)->data[0]))

# define c_array_grow(arr)                                                          \
    do {                                                                            \
        if ((arr)->capacity == 0) {                                                 \
            (arr)->capacity = 1;                                                    \
        }                                                                           \
        (arr)->capacity *= 2;                                                       \
        void* ptr = realloc((arr)->data, (arr)->capacity * c_array_byte((arr)));    \
        if (ptr == NULL) {                                                          \
            c_array_error("Realloc Failed");                                        \
        }                                                                           \
        (arr)->data = ptr;                                                          \
    } while (0)

# define c_array_resize(arr, c)                                             \
    do {                                                                    \
        void* ptr = realloc((arr)->data, (c) * c_array_byte((arr)));        \
        if (ptr == NULL) {                                                  \
            c_array_error("Realloc Failed");                                \
        }                                                                   \
        (arr)->capacity = (c);                                              \
        (arr)->data = ptr;                                                  \
    } while (0)

# define c_array_set_size(arr, l)                                           \
    do {                                                                    \
        if ((l) > (arr)->capacity) {                                        \
            c_array_error("Size should less than or equal to capacity");    \
        }                                                                   \
        for (int i = (arr)->size; i < (arr)->capacity; i++) {               \
            (arr)->data[i] = 0;                                             \
        }                                                                   \
        (arr)->size = (l);                                                  \
    } while (0)

/* -------------------------------------------------------------------- */
/*                  Arrary push_back and pop_back                       */

# define c_array_push_back(arr, val)                             \
    do {                                                         \
        if (c_array_capacity((arr)) <= c_array_size((arr))) {    \
            c_array_grow((arr));                                 \
        }                                                        \
        (arr)->data[(arr)->size] = val;                          \
        (arr)->size++;                                           \
    } while (0)

# define c_array_pop_back(arr)                              \
    do {                                                    \
        if ((arr)->size <= 0) {                             \
            c_array_error("Size should greater than 0");    \
        }                                                   \
        (arr)->data[(arr)->size - 1] = 0;                   \
        (arr)->size--;                                      \
    } while (0)

/* -------------------------------------------------------------------- */
/*                      Arrary insert and remove                        */

# define c_array_moveright(arr, idx)                  \
    do {                                              \
        if ((arr)->capacity <= (arr)->size) {         \
            c_array_grow(arr);                        \
        }                                             \
        for (int i = (arr)->size; i > idx; i--) {     \
            (arr)->data[i] = (arr)->data[i - 1];      \
        }                                             \
    } while (0)

# define c_array_moveleft(arr, idx)                         \
    do {                                                    \
        for (int i = idx; i < (arr)->size - 1; i++) {       \
            (arr)->data[i] = (arr)->data[i + 1];            \
        }                                                   \
    } while (0)                                             \

# define c_array_insert(arr, idx, val)                  \
    do {                                                \
        if ((idx) < (arr)->size) {                      \
            c_array_moveright((arr), (idx));            \
            (arr)->data[(idx)] = (val);                 \
            (arr)->size++;                              \
        }                                               \
    } while (0)

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
    } while (0)

/* -------------------------------------------------------------------- */
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
    } while (0)

/* -------------------------------------------------------------------- */
/*                           Array qsort                                */

# define c_array_qsort(arr)                                                                       \
    do {                                                                                          \
        qsort((arr)->data, (arr)->size, sizeof(typeof((*(arr)->data))), c_array_qsort_cmp((arr)));\
    } while (0)

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

/* -------------------------------------------------------------------- */
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
                if (r2 >= (arr)->size) {                                    \
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
    } while (0)

/* -------------------------------------------------------------------- */
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

/* -------------------------------------------------------------------- */
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

mean_t c_array_mean_short(const short* arr, int size, short sum);

mean_t c_array_mean_ushort(const unsigned short* arr, int size, unsigned short sum);

mean_t c_array_mean_int(const int* arr, int size, int sum);

mean_t c_array_mean_uint(const unsigned int* arr, int size, unsigned int sum);

mean_t c_array_mean_long(const long* arr, int size, long sum);

mean_t c_array_mean_ulong(const unsigned long* arr, int size, unsigned long sum);

mean_t c_array_mean_long_long(const long long* arr, int size, long long sum);

mean_t c_array_mean_float(const float* arr, int size, float sum);

mean_t c_array_mean_double(const double* arr, int size, double sum);

mean_t c_array_mean_long_double(const long double* arr, int size, long double sum);

/* -------------------------------------------------------------------- */
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

var_t c_array_var_short(const short* arr, int size, mean_t mean);

var_t c_array_var_ushort(const unsigned short* arr, int size, mean_t mean);

var_t c_array_var_int(const int* arr, int size, mean_t mean);

var_t c_array_var_uint(const unsigned int* arr, int size, mean_t mean);

var_t c_array_var_long(const long* arr, int size, mean_t mean);

var_t c_array_var_ulong(const unsigned long* arr, int size, mean_t mean);

var_t c_array_var_long_long(const long long* arr, int size, mean_t mean);

var_t c_array_var_float(const float* arr, int size, mean_t mean);

var_t c_array_var_double(const double* arr, int size, mean_t mean);

var_t c_array_var_long_double(const long double* arr, int size, mean_t mean);

std_t c_array_std_short(const short* arr, int size, mean_t mean);

std_t c_array_std_ushort(const unsigned short* arr, int size, mean_t mean);

std_t c_array_std_int(const int* arr, int size, mean_t mean);

std_t c_array_std_uint(const unsigned int* arr, int size, mean_t mean);

std_t c_array_std_long(const long* arr, int size, mean_t mean);

std_t c_array_std_ulong(const unsigned long* arr, int size, mean_t mean);

std_t c_array_std_long_long(const long long* arr, int size, mean_t mean);

std_t c_array_std_float(const float* arr, int size, mean_t mean);

std_t c_array_std_double(const double* arr, int size, mean_t mean);

std_t c_array_std_long_double(const long double* arr, int size, mean_t mean);

/* -------------------------------------------------------------------- */
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

# define c_array_maxmin(arr)                              \
    _Generic((arr)->data,                                 \
        short*: c_array_maxmin_short,                     \
        unsigned short*: c_array_maxmin_ushort,           \
        int*: c_array_maxmin_int,                         \
        unsigned int*: c_array_maxmin_uint,               \
        long*: c_array_maxmin_long,                       \
        unsigned long*: c_array_maxmin_ulong,             \
        long long*: c_array_maxmin_long_long,             \
        float*: c_array_maxmin_float,                     \
        double*: c_array_maxmin_double,                   \
        long double*: c_array_maxmin_long_double          \
    )((arr)->data, (arr)->size)

# define c_array_maxmin_process(arr, n)                                     \
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
    typeof(*(arr))* res = malloc(sizeof(typeof(*(arr))) * 2);               \
    res[0] = min;                                                           \
    res[1] = max;                                                           \
    return res;

# define c_array_max_process(arr, n)                                        \
    typeof(*(arr)) max = -pow(2, (((sizeof(typeof(*(arr)))-  1) * 8)));     \
    for (int i = 0; i < n; i++) {                                           \
        if (max < (arr)[i]) {                                               \
            max = (arr)[i];                                                 \
        }                                                                   \
    }                                                                       \
    return max;

# define c_array_min_process(arr, n)                                        \
    typeof(*(arr)) min = pow(2, (((sizeof(typeof(*(arr)))-  1) * 8))) - 1;  \
    for (int i = 0; i < n; i++) {                                           \
        if (min > (arr)[i]) {                                               \
            min = (arr)[i];                                                 \
        }                                                                   \
    }                                                                       \
    return min;

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

short* c_array_maxmin_short(short* arr, int size);

unsigned short* c_array_maxmin_ushort(unsigned short* arr, int size);

int* c_array_maxmin_int(int* arr, int size);

unsigned int* c_array_maxmin_uint(unsigned int* arr, int size);

long* c_array_maxmin_long(long* arr, int size);

unsigned long* c_array_maxmin_ulong(unsigned long* arr, int size);

long long* c_array_maxmin_long_long(long long* arr, int size);

float* c_array_maxmin_float(float* arr, int size);

double* c_array_maxmin_double(double* arr, int size);

long double* c_array_maxmin_long_double(long double* arr, int size);

/* -------------------------------------------------------------------- */
/*                            Array search                              */

# define c_array_search(arr, target)                      \
    _Generic((arr)->data,                                 \
        short*: c_array_search_short,                     \
        unsigned short*: c_array_search_ushort,           \
        int*: c_array_search_int,                         \
        unsigned int*: c_array_search_uint,               \
        long*: c_array_search_long,                       \
        unsigned long*: c_array_search_ulong,             \
        long long*: c_array_search_long_long,             \
        float*: c_array_search_float,                     \
        double*: c_array_search_double,                   \
        long double*: c_array_search_ldouble              \
    )((arr)->data, (arr)->size, (target))

# define c_array_search_process(arr, size, target)          \
    for (int i = 0; i < (size); i++) {                      \
        if (fabs((arr)[i] - (target)) < 1e-6) {             \
            return i;                                       \
        }                                                   \
    }                                                       \
    return -1;

int c_array_search_short(const short* arr, int size, short target);

int c_array_search_ushort(const unsigned short* arr, int size, unsigned short target);

int c_array_search_int(const int* arr, int size, int target);

int c_array_search_uint(const unsigned int* arr, int size, unsigned int target);

int c_array_search_long(const long* arr, int size, long target);

int c_array_search_long_long(const long long* arr, int size, long long target);

int c_array_search_ulong(const unsigned long* arr, int size, unsigned long target);

int c_array_search_float(const float* arr, int size, float target);

int c_array_search_double(const double* arr, int size, double target);

int c_array_search_ldouble(const long double* arr, int size, long double target);

/* -------------------------------------------------------------------- */
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
        long double*: "long double",        \
        short**: "short",                   \
        unsigned short**: "unsigned short", \
        int**: "int",                       \
        unsigned int**: "unsigned int",     \
        long**: "long",                     \
        unsigned long**: "unsigned long",   \
        long long**: "long long",           \
        float**: "float",                   \
        double**: "double",                 \
        long double**: "long double"        \
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
    } while (0)

# define c_array_printf(arr, format)                    \
    do {                                                \
        printf(#arr);                                   \
        printf(" = [");                                 \
        for (int i = 0; i < (arr).size; i++) {          \
            if (i < (arr).size - 1) {                   \
                printf((format), arr.data[i]);          \
                printf(", ");                           \
            } else {                                    \
                printf((format), arr.data[i]);          \
            }                                           \
        }                                               \
        printf("]\n");                                  \
    } while (0)

# define c_array_empty(arr) ((arr)->size == 0)

# define c_array_swap(arr, idx1, idx2)                                              \
    do {                                                                            \
        if ((idx1) >= (arr)->size || (idx2) >= (arr)->size) {                       \
            c_array_error("Index out of range (size)");                             \
        }                                                                           \
        typeof(*((arr)->data)) x;                                                   \
        x = (arr)->data[idx2];                                                      \
        (arr)->data[idx2] = (arr)->data[idx1];                                      \
        (arr)->data[idx1] = x;                                                      \
    } while (0)                                                                     \

# define c_array_reverse(arr)                                                       \
    do {                                                                            \
        typeof(*((arr)->data)) x;                                                   \
        for (int i = 0; i < ((arr)->size / 2); i++) {                               \
            x = (arr)->data[i];                                                     \
            (arr)->data[i] = (arr)->data[(arr)->size - 1 - i];                      \
            (arr)->data[(arr)->size - 1 - i] = x;                                   \
        }                                                                           \
    } while (0)

# define c_array_free(arr) (free((arr)->data))

# define c_array_error(msg)                           \
    do {                                              \
        fprintf(stderr, "Error in %s:%d: %s\n",       \
                __FILE__, __LINE__, (msg));           \
        exit(EXIT_FAILURE);                           \
    } while (0)

/* -------------------------------------------------------------------- */
/*                  Matrix structure and initialize                     */

# define c_matrix(T) struct { T** data; size_t rows; size_t cols; }

# define c_matrix_init(mat, r, c)                                           \
    do{                                                                     \
        typeof(**((mat)->data)) m;                                          \
        typeof(*((mat)->data)) n;                                           \
        (mat)->rows = (r);                                                  \
        (mat)->cols = (c);                                                  \
        (mat)->data = calloc((r), sizeof(n));                               \
        if ((mat)->data == NULL) {                                          \
            c_array_error(                                                  \
                "Failed to allocate memory for matrix data (row)");         \
        }                                                                   \
        for (int i = 0; i < (r); i++) {                                     \
            (mat)->data[i] = calloc((c), sizeof(m));                        \
            if ((mat)->data[i] == NULL) {                                   \
                c_array_error(                                              \
                    "Failed to allocate memory for matrix data (col)");     \
            }                                                               \
        }                                                                   \
    } while (0)

# define c_matrix_empty_init(mat, r, c)                                     \
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
    } while (0)

# define c_matrix_copy(mat_old, mat_new)                                                            \
    do {                                                                                            \
        char* dtype_mat1 = c_array_dtype(mat_old);                                                  \
        char* dtype_mat2 = c_array_dtype(mat_new);                                                  \
        if (dtype_mat1 != dtype_mat2) {                                                             \
            c_array_error("dtype of two arrays are different");                                     \
        }                                                                                           \
        (mat_new)->rows = (mat_old)->rows;                                                          \
        (mat_new)->cols = (mat_old)->cols;                                                          \
        (mat_new)->data = malloc((mat_old)->rows * sizeof(typeof(*(mat_old)->data)));               \
        if ((mat_new)->data == NULL) {                                                              \
            c_array_error("failed to allocate memory in c_matrix_copy");                            \
        }                                                                                           \
        for (int i = 0; i < (mat_old)->rows; i++) {                                                 \
            (mat_new)->data[i] = malloc((mat_old)->cols * sizeof(typeof(*(mat_old)->data[i])));     \
            memcpy(                                                                                 \
                (mat_new)->data[i],                                                                 \
                (mat_old)->data[i],                                                                 \
                (mat_new)->cols * sizeof(typeof(*(mat_new)->data[i]))                               \
            );                                                                                      \
        }                                                                                           \
    } while (0)

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

/* c_array_mt.c is necessary for c_array_randnormal & c_array_rand_range */

# define c_matrix_randnormal(mat, r, c, rng_state)                            \
    do {                                                                      \
        (mat)->rows = (r);                                                    \
        (mat)->cols = (c);                                                    \
        (mat)->data = malloc(sizeof(typeof(*((mat)->data))) * (r));           \
        for (int i = 0; i < (r); i++) {                                       \
            (mat)->data[i] = malloc(sizeof(typeof(*(mat)->data[i])) * (c));   \
            for (int j = 0; j < (c); j++) {                                   \
                (mat)->data[i][j] = random_normal(rng_state);                 \
            }                                                                 \
        }                                                                     \
    } while (0)

# define c_matrix_rand_range(mat, r, c, rng_function)                         \
    do {                                                                      \
        (mat)->rows = (r);                                                    \
        (mat)->cols = (c);                                                    \
        (mat)->data = malloc(sizeof(typeof(*((mat)->data))) * (r));           \
        for (int i = 0; i < (r); i++) {                                       \
            (mat)->data[i] = malloc(sizeof(typeof(*(mat)->data[i])) * (c));   \
            for (int j = 0; j < (c); j++) {                                   \
                (mat)->data[i][j] = rng_function;                             \
            }                                                                 \
        }                                                                     \
    } while (0)

/* -------------------------------------------------------------------- */
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
    } while (0)

/* -------------------------------------------------------------------- */
/*                          Matrix Form                                 */

# define c_array_matrix_form(arr, n_row)                       \
    _Generic((arr)->data,                                      \
        short*: c_array_matrix_form_short,                     \
        unsigned short*: c_array_matrix_form_ushort,           \
        int*: c_array_matrix_form_int,                         \
        unsigned int*: c_array_matrix_form_uint,               \
        long*: c_array_matrix_form_long,                       \
        unsigned long*: c_array_matrix_form_ulong,             \
        long long*: c_array_matrix_form_long_long,             \
        float*: c_array_matrix_form_float,                     \
        double*: c_array_matrix_form_double,                   \
        long double*: c_array_matrix_form_ldouble              \
    )((arr), (n_row))

# define c_array_matrix_form_init(arr, mat, n_row)                      \
    do {                                                                \
        if ((arr)->size % (n_row) != 0) {                               \
            c_array_error("Size / n_row be divided with no remain");    \
        }                                                               \
        c_matrix_init((mat), (n_row), (arr)->size / (n_row));           \
    } while (0)

# define c_array_matrix_form_process(mat, arr)                          \
    do {                                                                \
        for (int i = 0; i < (mat)->rows; i++) {                         \
            for (int j = 0; j < (mat)->cols; j++) {                     \
                (mat)->data[i][j] = (arr)->data[i * (mat)->cols + j];   \
            }                                                           \
        }                                                               \
    } while (0)

c_matrix_short c_array_matrix_form_short(const c_array_short* arr, int n_row);

c_matrix_ushort c_array_matrix_form_ushort(const c_array_ushort* arr, int n_row);

c_matrix_int c_array_matrix_form_int(const c_array_int* arr, int n_row);

c_matrix_uint c_array_matrix_form_uint(const c_array_uint* arr, int n_row);

c_matrix_long c_array_matrix_form_long(const c_array_long* arr, int n_row);

c_matrix_long_long c_array_matrix_form_long_long(const c_array_long_long* arr, int n_row);

c_matrix_ulong c_array_matrix_form_ulong(const c_array_ulong* arr, int n_row);

c_matrix_float c_array_matrix_form_float(const c_array_float* arr, int n_row);

c_matrix_double c_array_matrix_form_double(const c_array_double* arr, int n_row);

c_matrix_ldouble c_array_matrix_form_ldouble(const c_array_ldouble* arr, int n_row);

/* -------------------------------------------------------------------- */
/*                          Matrix Flatten                              */

# define c_matrix_flatten(mat)                      \
    _Generic((mat)->data,                           \
        short**: c_matrix_flatten_short,            \
        unsigned short**: c_matrix_flatten_ushort,  \
        int**: c_matrix_flatten_int,                \
        unsigned int**: c_matrix_flatten_uint,      \
        long**: c_matrix_flatten_long,              \
        unsigned long**: c_matrix_flatten_ulong,    \
        long long**: c_matrix_flatten_long_long,    \
        float**: c_matrix_flatten_float,            \
        double**: c_matrix_flatten_double,          \
        long double**: c_matrix_flatten_ldouble     \
    )((mat))

# define c_matrix_flatten_init(mat, arr)                    \
    do {                                                    \
        if ((mat)->rows * (mat)->cols >= INT_MAX) {         \
            c_array_error("Size(int) overflow");            \
        }                                                   \
        int arr_size = (mat)->rows * (mat)->cols;           \
        c_array_init(arr, arr_size);                        \
    } while (0)

# define c_matrix_flatten_process(mat, arr)                             \
    do {                                                                \
        for (int i = 0; i < (mat)->rows; i++) {                         \
            for (int j = 0; j < (mat)->cols; j++) {                     \
                (arr)->data[i * (mat)->cols + j] = (mat)->data[i][j];   \
            }                                                           \
        }                                                               \
    } while (0)

c_array_short c_matrix_flatten_short(const c_matrix_short* mat);

c_array_ushort c_matrix_flatten_ushort(const c_matrix_ushort* mat);

c_array_int c_matrix_flatten_int(const c_matrix_int* mat);

c_array_uint c_matrix_flatten_uint(const c_matrix_uint* mat);

c_array_long c_matrix_flatten_long(const c_matrix_long* mat);

c_array_long_long c_matrix_flatten_long_long(const c_matrix_long_long* mat);

c_array_ulong c_matrix_flatten_ulong(const c_matrix_ulong* mat);

c_array_float c_matrix_flatten_float(const c_matrix_float* mat);

c_array_double c_matrix_flatten_double(const c_matrix_double* mat);

c_array_ldouble c_matrix_flatten_ldouble(const c_matrix_ldouble* mat);

/* -------------------------------------------------------------------- */
/*                          Matrix Reshape                              */
# define c_matrix_reshape(mat, row, col)            \
    _Generic((mat)->data,                           \
        short**: c_matrix_reshape_short,            \
        unsigned short**: c_matrix_reshape_ushort,  \
        int**: c_matrix_reshape_int,                \
        unsigned int**: c_matrix_reshape_uint,      \
        long**: c_matrix_reshape_long,              \
        unsigned long**: c_matrix_reshape_ulong,    \
        long long**: c_matrix_reshape_long_long,    \
        float**: c_matrix_reshape_float,            \
        double**: c_matrix_reshape_double,          \
        long double**: c_matrix_reshape_ldouble     \
    )((mat), (row), (col))

# define c_matrix_reshape_init(mat_old, mat_new, row, col)                              \
    do {                                                                                \
        int matsize = (mat_old)->rows * (mat_old)->cols;                                \
        if (matsize != (row) * (col)                                                    \
            || ((mat_old)->rows == (row) && (mat_old)->cols == (col))) {                \
            c_array_error("Matrix can't reshape to the target shape.\n");               \
        }                                                                               \
        c_matrix_init((mat_new), (row), (col));                                         \
    } while (0)

# define c_matrix_reshape_process(mat_old, mat_new, row, col)               \
    do {                                                                    \
        for (int i = 0; i < (row) * (col); i++) {                           \
            (mat_new)->data[i / (col)][i % (col)] =                         \
                (mat_old)->data[i / (mat_old)->cols][i % (mat_old)->cols];  \
        }                                                                   \
        c_matrix_free(mat_old);                                             \
    } while (0)

c_matrix_short c_matrix_reshape_short(c_matrix_short* mat, int row, int col);

c_matrix_ushort c_matrix_reshape_ushort(c_matrix_ushort* mat, int row, int col);

c_matrix_int c_matrix_reshape_int(c_matrix_int* mat, int row, int col);

c_matrix_uint c_matrix_reshape_uint(c_matrix_uint* mat, int row, int col);

c_matrix_long c_matrix_reshape_long(c_matrix_long* mat, int row, int col);

c_matrix_long_long c_matrix_reshape_long_long(c_matrix_long_long* mat, int row, int col);

c_matrix_ulong c_matrix_reshape_ulong(c_matrix_ulong* mat, int row, int col);

c_matrix_float c_matrix_reshape_float(c_matrix_float* mat, int row, int col);

c_matrix_double c_matrix_reshape_double(c_matrix_double* mat, int row, int col);

c_matrix_ldouble c_matrix_reshape_ldouble(c_matrix_ldouble* mat, int row, int col);

/* -------------------------------------------------------------------- */
/*                            Matrix sum                                */

# define c_matrix_sum(mat)                       \
    _Generic((mat)->data,                       \
        short**: c_matrix_sum_short,              \
        unsigned short**: c_matrix_sum_ushort,    \
        int**: c_matrix_sum_int,                  \
        unsigned int**: c_matrix_sum_uint,        \
        long**: c_matrix_sum_long,                \
        unsigned long**: c_matrix_sum_ulong,      \
        long long**: c_matrix_sum_long_long,      \
        float**: c_matrix_sum_float,              \
        double**: c_matrix_sum_double,            \
        long double**: c_matrix_sum_long_double   \
    )((mat)->data, (mat)->rows, (mat)->cols)

# define c_matrix_sum_process(mat, rows, cols)  \
   typeof(**(mat)) sum = 0;                     \
    for (int i = 0; i < (rows); i++) {          \
        for (int j = 0; j < (cols); j++) {      \
            sum += (mat)[i][j];                 \
        }                                       \
    }                                           \
    return sum;                                 \

short c_matrix_sum_short(short** mat, int rows, int cols);

unsigned short c_matrix_sum_ushort(unsigned short** mat, int rows, int cols);

int c_matrix_sum_int(int** mat, int rows, int cols);

unsigned int c_matrix_sum_uint(unsigned int** mat, int rows, int cols);

long c_matrix_sum_long(long** mat, int rows, int cols);

unsigned long c_matrix_sum_ulong(unsigned long** mat, int rows, int cols);

long long c_matrix_sum_long_long(long long** mat, int rows, int cols);

float c_matrix_sum_float(float** mat, int rows, int cols);

double c_matrix_sum_double(double** mat, int rows, int cols);

long double c_matrix_sum_long_double(long double** mat, int rows, int cols);

/* -------------------------------------------------------------------- */
/*                            Matrix mean                               */

# define c_matrix_mean(mat)                       \
    _Generic((mat)->data,                       \
        short**: c_matrix_mean_short,              \
        unsigned short**: c_matrix_mean_ushort,    \
        int**: c_matrix_mean_int,                  \
        unsigned int**: c_matrix_mean_uint,        \
        long**: c_matrix_mean_long,                \
        unsigned long**: c_matrix_mean_ulong,      \
        long long**: c_matrix_mean_long_long,      \
        float**: c_matrix_mean_float,              \
        double**: c_matrix_mean_double,            \
        long double**: c_matrix_mean_long_double   \
    )((mat)->data, (mat)->rows, (mat)->cols, c_matrix_sum((mat)))

# define c_matrix_mean_process(mat, rows, cols, sum)    \
    mean_t mean = (mean_t)(sum) / ((rows) * (cols));    \
    return mean;                                        \

mean_t c_matrix_mean_short(const short** mat, int rows, int cols, short sum);

mean_t c_matrix_mean_ushort(const unsigned short** mat, int rows, int cols, unsigned short sum);

mean_t c_matrix_mean_int(const int** mat, int rows, int cols, int sum);

mean_t c_matrix_mean_uint(const unsigned int** mat, int rows, int cols, unsigned int sum);

mean_t c_matrix_mean_long(const long** mat, int rows, int cols, long sum);

mean_t c_matrix_mean_ulong(const unsigned long** mat, int rows, int cols, unsigned long sum);

mean_t c_matrix_mean_long_long(const long long** mat, int rows, int cols, long long sum);

mean_t c_matrix_mean_float(const float** mat, int rows, int cols, float sum);

mean_t c_matrix_mean_double(const double** mat, int rows, int cols, double sum);

mean_t c_matrix_mean_long_double(const long double** mat, int rows, int cols, long double sum);

/* -------------------------------------------------------------------- */
/*                          Array Min and Max                           */

# define c_matrix_max(mat)                               \
    _Generic((mat)->data,                                \
        short**: c_matrix_max_short,                     \
        unsigned short**: c_matrix_max_ushort,           \
        int**: c_matrix_max_int,                         \
        unsigned int**: c_matrix_max_uint,               \
        long**: c_matrix_max_long,                       \
        unsigned long**: c_matrix_max_ulong,             \
        long long**: c_matrix_max_long_long,             \
        float**: c_matrix_max_float,                     \
        double**: c_matrix_max_double,                   \
        long double**: c_matrix_max_long_double          \
    )((mat)->data, (mat)->rows, (mat)->cols)

# define c_matrix_min(mat)                               \
    _Generic((mat)->data,                                \
        short**: c_matrix_min_short,                     \
        unsigned short**: c_matrix_min_ushort,           \
        int**: c_matrix_min_int,                         \
        unsigned int**: c_matrix_min_uint,               \
        long**: c_matrix_min_long,                       \
        unsigned long**: c_matrix_min_ulong,             \
        long long**: c_matrix_min_long_long,             \
        float**: c_matrix_min_float,                     \
        double**: c_matrix_min_double,                   \
        long double**: c_matrix_min_long_double          \
    )((mat)->data, (mat)->rows, (mat)->cols)

# define c_matrix_max_process(mat, r, c)                                    \
    typeof(**(mat)) max = -pow(2, (((sizeof(typeof(**(mat)))-  1) * 8)));   \
    for (int i = 0; i < (r); i++) {                                         \
        for (int j = 0; j < (c); j++) {                                     \
            if (max < (mat)[i][j]) {                                        \
                max = (mat)[i][j];                                          \
            }                                                               \
        }                                                                   \
    }                                                                       \
    return max;

# define c_matrix_min_process(mat, r, c)                                    \
    typeof(**(mat)) min = pow(2, (((sizeof(typeof(**(mat)))-  1) * 8))) - 1;\
    for (int i = 0; i < (r); i++) {                                         \
        for (int j = 0; j < (c); j++) {                                     \
            if (min > (mat)[i][j]) {                                        \
                min = (mat)[i][j];                                          \
            }                                                               \
        }                                                                   \
    }                                                                       \
    return min;

short c_matrix_max_short(short** mat, int r, int c);

unsigned short c_matrix_max_ushort(unsigned short** mat, int r, int c);

int c_matrix_max_int(int** mat, int r, int c);

unsigned int c_matrix_max_uint(unsigned int** mat, int r, int c);

long c_matrix_max_long(long** mat, int r, int c);

unsigned long c_matrix_max_ulong(unsigned long** mat, int r, int c);

long long c_matrix_max_long_long(long long** mat, int r, int c);

float c_matrix_max_float(float** mat, int r, int c);

double c_matrix_max_double(double** mat, int r, int c);

long double c_matrix_max_long_double(long double** mat, int r, int c);

short c_matrix_min_short(short** mat, int r, int c);

unsigned short c_matrix_min_ushort(unsigned short** mat, int r, int c);

int c_matrix_min_int(int** mat, int r, int c);

unsigned int c_matrix_min_uint(unsigned int** mat, int r, int c);

long c_matrix_min_long(long** mat, int r, int c);

unsigned long c_matrix_min_ulong(unsigned long** mat, int r, int c);

long long c_matrix_min_long_long(long long** mat, int r, int c);

float c_matrix_min_float(float** mat, int r, int c);

double c_matrix_min_double(double** mat, int r, int c);

long double c_matrix_min_long_double(long double** mat, int r, int c);

/* -------------------------------------------------------------------- */
/*                     Matrix standard deviation                        */

# define c_matrix_std(mat)                                          \
    _Generic((mat)->data,                                           \
        short**: c_matrix_std_short,                                \
        unsigned short**: c_matrix_std_ushort,                      \
        int**: c_matrix_std_int,                                    \
        unsigned int**: c_matrix_std_uint,                          \
        long**: c_matrix_std_long,                                  \
        unsigned long**: c_matrix_std_ulong,                        \
        long long**: c_matrix_std_long_long,                        \
        float**: c_matrix_std_float,                                \
        double**: c_matrix_std_double,                              \
        long double**: c_matrix_std_long_double                     \
    )((mat)->data, (mat)->rows, (mat)->cols, c_matrix_mean((mat)))

# define c_matrix_var(mat)                                          \
    _Generic((mat)->data,                                           \
        short**: c_matrix_var_short,                                \
        unsigned short**: c_matrix_var_ushort,                      \
        int**: c_matrix_var_int,                                    \
        unsigned int**: c_matrix_var_uint,                          \
        long**: c_matrix_var_long,                                  \
        unsigned long**: c_matrix_var_ulong,                        \
        long long**: c_matrix_var_long_long,                        \
        float**: c_matrix_var_float,                                \
        double**: c_matrix_var_double,                              \
        long double**: c_matrix_var_long_double                     \
    )((mat)->data, (mat)->rows, (mat)->cols, c_matrix_mean((mat)))

# define c_matrix_var_process(mat, row, col, mean)  \
    var_t var = 0;                                  \
    for (int i = 0; i < (row); i++) {               \
        for (int j = 0; j < (col); j++) {           \
            var += pow((mat)[i][j] - (mean), 2);    \
        }                                           \
    }                                               \

var_t c_matrix_var_short(const short** mat, int row, int col, mean_t mean);

var_t c_matrix_var_ushort(const unsigned short** mat, int row, int col, mean_t mean);

var_t c_matrix_var_int(const int** mat, int row, int col, mean_t mean);

var_t c_matrix_var_uint(const unsigned int** mat, int row, int col, mean_t mean);

var_t c_matrix_var_long(const long** mat, int row, int col, mean_t mean);

var_t c_matrix_var_ulong(const unsigned long** mat, int row, int col, mean_t mean);

var_t c_matrix_var_long_long(const long long** mat, int row, int col, mean_t mean);

var_t c_matrix_var_float(const float** mat, int row, int col, mean_t mean);

var_t c_matrix_var_double(const double** mat, int row, int col, mean_t mean);

var_t c_matrix_var_long_double(const long double** mat, int row, int col, mean_t mean);

std_t c_matrix_std_short(const short** mat, int row, int col, mean_t mean);

std_t c_matrix_std_ushort(const unsigned short** mat, int row, int col, mean_t mean);

std_t c_matrix_std_int(const int** mat, int row, int col, mean_t mean);

std_t c_matrix_std_uint(const unsigned int** mat, int row, int col, mean_t mean);

std_t c_matrix_std_long(const long** mat, int row, int col, mean_t mean);

std_t c_matrix_std_ulong(const unsigned long** mat, int row, int col, mean_t mean);

std_t c_matrix_std_long_long(const long long** mat, int row, int col, mean_t mean);

std_t c_matrix_std_float(const float** mat, int row, int col, mean_t mean);

std_t c_matrix_std_double(const double** mat, int row, int col, mean_t mean);

std_t c_matrix_std_long_double(const long double** mat, int row, int col, mean_t mean);

/* -------------------------------------------------------------------- */
/*                            Matrix utils                              */

# define c_matrix_print(mat)                                                \
    do {                                                                    \
        printf(#mat);                                                       \
        printf(" =\n   [ ");                                                \
        for (int i = 0; i < (mat).rows; i++) {                              \
            if (i != 0)                                                     \
                printf("     ");                                            \
            printf("[ ");                                                   \
            for (int j = 0; j < (mat).cols; j++) {                          \
                if (j < (mat).cols) {                                       \
                    printf(c_array_autoformat((mat)), (mat).data[i][j]);    \
                    printf(", ");                                           \
                } else {                                                    \
                    printf(c_array_autoformat((mat)), (mat).data[i][j]);    \
                }                                                           \
            }                                                               \
            printf("]");                                                    \
            if (i < (mat).rows - 1) {                                       \
                printf("\n");                                               \
            }                                                               \
        }                                                                   \
        printf(" ]\n");                                                     \
    } while (0)

# define c_matrix_printf(mat, format)                       \
    do {                                                    \
        printf(#mat);                                       \
        printf(" =\n   [ ");                                \
        for (int i = 0; i < (mat).rows; i++) {              \
            if (i != 0)                                     \
                printf("     ");                            \
            printf("[ ");                                   \
            for (int j = 0; j < (mat).cols; j++) {          \
                if (j < (mat).cols) {                       \
                    printf((format), (mat).data[i][j]);     \
                    printf(", ");                           \
                } else {                                    \
                    printf((format), (mat).data[i][j]);     \
                }                                           \
            }                                               \
            printf("]");                                    \
            if (i < (mat).rows - 1) {                       \
                printf("\n");                               \
            }                                               \
        }                                                   \
        printf(" ]\n");                                     \
    } while (0)

# define c_matrix_free(mat)                         \
    do {                                            \
        for (int i = 0; i < (mat)->rows; i++) {     \
            free((mat)->data[i]);                   \
        }                                           \
        free((mat)->data);                          \
    } while (0)

/* -------------------------------------------------------------------- */
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
