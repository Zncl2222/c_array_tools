/*
    Copyright (c) 2022 Jian Yu, Chen
    License: MIT License
*/


# ifndef C_ARRAY_H
# define C_ARRAY_H

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>
# include <assert.h>


// -----------------------------------------------------------------------
/*                     Array structure and initialize                   */

# define c_array(T) struct { T* data; size_t size; size_t capacity; }

# define c_array_init(arr, c)                                       \
    do {                                                            \
        typeof(*((arr)->data)) x;                                   \
        (arr)->size = (c);                                          \
        (arr)->capacity = (c);                                      \
        (arr)->data = calloc((c), sizeof(x));                       \
    } while(0)

// -----------------------------------------------------------------------
/*                      Array basic operations                          */

# define c_array_capacity(arr) ((arr) ? (arr)->capacity : 0)

# define c_array_size(arr) ((arr) ? (arr)->size : 0)

# define c_array_assign(arr, idx, val)                                   \
    do {                                                                 \
        assert(idx < (arr)->size);                                       \
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
        assert(ptr != NULL);                                                        \
        (arr)->data = ptr;                                                          \
    } while(0)

# define c_array_resize(arr, c)                                             \
    do {                                                                    \
        void* ptr = realloc((arr)->data, (c) * c_array_byte((arr)));        \
        assert(ptr != NULL);                                                \
        (arr)->capacity = (c);                                              \
        (arr)->data = ptr;                                                  \
    } while(0)

# define c_array_set_size(arr, l)                                   \
    do {                                                            \
        assert(l <= (arr)->capacity);                               \
        for (int i = (arr)->size; i < (arr)->capacity; i++) {       \
            (arr)->data[i] = 0;                                     \
        }                                                           \
        (arr)->size = (l);                                          \
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

# define c_array_pop_back(arr)              \
    do {                                    \
        assert((arr)->size > 0);            \
        (arr)->data[(arr)->size - 1] = 0;   \
        (arr)->size--;                      \
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

# define c_array_remove(arr, idx)           \
    do {                                    \
        assert((arr)->size > 0);            \
        c_array_moveleft(arr, idx);         \
        (arr)->size--;                      \
    } while(0)

// -----------------------------------------------------------------------
/*                              Array Sum                               */

# define c_array_sum(arr)               \
    _Generic((arr)->data,               \
        int*: c_array_sum_int,          \
        long*: c_array_sum_long,        \
        float*: c_array_sum_float,      \
        double*: c_array_sum_double     \
    )((arr)->data, (arr)->size)

# define c_array_sum_process(arr, size)     \
    typeof(*(arr)) sum = 0;                 \
    for (int i = 0; i < size; i++) {        \
        sum += arr[i];                      \
    }                                       \
    return sum;                             \

int c_array_sum_int(int* arr, int size) {
    c_array_sum_process(arr, size);
}

long c_array_sum_long(long* arr, int size) {
    c_array_sum_process(arr, size);
}

float c_array_sum_float(float* arr, int size) {
    c_array_sum_process(arr, size);
}

double c_array_sum_double(double* arr, int size) {
    c_array_sum_process(arr, size);
}

// -----------------------------------------------------------------------
/*                          Array Min and Max                           */

# define c_array_max(arr)                       \
    _Generic((arr)->data,                       \
        int*: c_array_max_int,                  \
        long long*: c_array_max_long_long,      \
        float*: c_array_max_float,              \
        double*: c_array_max_double             \
    )((arr)->data, (arr)->size)

# define c_array_min(arr)                       \
    _Generic((arr)->data,                       \
        int*: c_array_min_int,                  \
        long long*: c_array_min_long_long,      \
        float*: c_array_min_float,              \
        double*: c_array_min_double             \
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

int c_array_max_int(int* arr, int size) {
    c_array_maxmin_process(arr, size, "max");
}

long long c_array_max_long_long(long long* arr, int size) {
    c_array_maxmin_process(arr, size, "max");
}

float c_array_max_float(float* arr, int size) {
    c_array_maxmin_process(arr, size, "max");
}

double c_array_max_double(double* arr, int size) {
    c_array_maxmin_process(arr, size, "max");
}

int c_array_min_int(int* arr, int size) {
    c_array_maxmin_process(arr, size, "min");
}

long long c_array_min_long_long(long long* arr, int size) {
    c_array_maxmin_process(arr, size, "min");
}

float c_array_min_float(float* arr, int size) {
    c_array_maxmin_process(arr, size, "min");
}

double c_array_min_double(double* arr, int size) {
    c_array_maxmin_process(arr, size, "min");
}

// -----------------------------------------------------------------------
/*                            Arrary utils                              */

# define c_array_print(arr, format)                     \
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

# define c_array_swap(arr, idx1, idx2)                              \
    do {                                                            \
        assert((idx1) < (arr)->size && (idx2) < (arr)->size);       \
        assert((arr)->size >= 2);                                   \
        typeof(*((arr)->data)) x;                                   \
        x = (arr)->data[idx2];                                      \
        (arr)->data[idx2] = (arr)->data[idx1];                      \
        (arr)->data[idx1] = x;                                      \
    } while(0)                                                      \

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

// -----------------------------------------------------------------------
/*                  Matrix structure and initialize                     */

# define c_matrix(T) struct { T** data; size_t rows; size_t cols; }

# define c_matrix_init(mat, r, c)                   \
    do{                                             \
        typeof(**((mat)->data)) m;                  \
        typeof(*((mat)->data)) n;                   \
        (mat)->rows = (r);                          \
        (mat)->cols = (c);                          \
        (mat)->data = malloc(r * sizeof(n));        \
        for (int i = 0; i < (r); i++) {             \
            (mat)->data[i] = malloc(c * sizeof(m)); \
        }\
    } while(0)

// -----------------------------------------------------------------------
/*                       Matrix basic operations                        */

# define c_matrix_rows(mat) ((mat) ? (mat)->rows : 0)

# define c_matrix_cols(mat) ((mat) ? (mat)->cols : 0)

# define c_matrix_assign(mat, row, col, val)    \
    do {                                        \
        assert(row < (mat)->rows);              \
        assert(col < (mat)->cols);              \
        (mat)->data[row][col] = val;            \
    } while(0)

// -----------------------------------------------------------------------
/*                            Matrix utils                               */

# define c_matrix_print(mat, format)                        \
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

# endif
