/*
    Copyright (c) 2022 Jian Yu, Chen
    License: MIT License
*/


# ifndef C_ARRAY_H
# define C_ARRAY_H

# include <stdlib.h>
# include <string.h>
# include <assert.h>


# define c_array(T) struct { T* data; size_t length; size_t capacity; }

# define c_array_init(arr, T, c)                                    \
    do {                                                            \
        (arr)->length = (c);                                        \
        (arr)->capacity = (c);                                      \
        (arr)->data = calloc(0, c * sizeof(T));                     \
    } while(0)

# define c_array_capacity(arr) ((arr) ? (arr)->capacity : 0)

# define c_array_length(arr) ((arr) ? (arr)->length : 0)

# define c_array_assign(arr, idx, val)                                   \
    do {                                                                 \
        assert(idx < (arr)->capacity);                                   \
        (arr)->data[(idx)] = (val);                                      \
        (arr)->length = (idx) < (arr)->length ? (arr)->length : (idx);   \
    } while(0)

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

# define c_array_set_length(arr, l)     \
    assert(l <= (arr)->capacity); (arr)->length = (l)

# define c_array_push_back(arr, val)                             \
    do {                                                         \
        if (c_array_capacity((arr)) <= c_array_length((arr))) {  \
            c_array_grow((arr));                                 \
        }                                                        \
        (arr)->data[(arr)->length] = val;                        \
        (arr)->length++;                                         \
    } while(0)

# define c_array_moveright(arr, idx) \
    do {                                              \
        if ((arr)->capacity <= (arr)->length) {       \
            c_array_grow(arr);                        \
        }                                             \
        for(int i = (arr)->length; i > idx; i--) {    \
            (arr)->data[i] = (arr)->data[i - 1];      \
        }                                             \
    } while(0)

# define c_array_moveleft(arr, idx)                         \
    do {                                                    \
        for(int i = idx; i < (arr)->length - 1; i++) {      \
            (arr)->data[i] = (arr)->data[i + 1];            \
        }                                                   \
    } while(0)                                              \

# define c_array_insert(arr, idx, val)                  \
    do {                                                \
        if ((idx) < (arr)->length) {                    \
            c_array_moveright((arr), (idx));            \
            (arr)->data[(idx)] = (val);                 \
            (arr)->length++;                            \
        }                                               \
    } while(0)

# define c_array_remove(arr, idx)           \
    do {                                    \
        assert((arr)->length > 0);          \
        c_array_moveleft(arr, idx);         \
        (arr)->length--;                    \
    } while(0)

# define c_array_pop_back(arr)              \
    do {                                    \
        assert((arr)->length > 0);          \
        (arr)->data[(arr)->length - 1] = 0; \
        (arr)->length--;                    \
    } while(0)

# define c_array_print(arr, format)                     \
    do {                                                \
        printf(#arr);                                   \
        printf(" = [");                                 \
        for(int i = 0; i < (arr).length; i++) {         \
            if (i < (arr).length - 1) {                 \
                printf((format), arr.data[i]);          \
                printf(", ");                           \
            } else {                                    \
                printf((format), arr.data[i]);          \
            }                                           \
        }                                               \
        printf("]\n");                                  \
    } while(0)

# define c_array_free(arr) (free((arr)->data))

# define c_matrix(T) struct { T** data; size_t rows; size_t cols; }

# define c_matrix_rows(mat) ((mat) ? (mat)->rows : 0)

# define c_matrix_cols(mat) ((mat) ? (mat)->cols : 0)

# define c_matrix_init(mat, T, r, c)                \
    do{                                             \
        (mat)->rows = (r);                          \
        (mat)->cols = (c);                          \
        (mat)->data = malloc(r * sizeof(T*));       \
        for (int i = 0; i < (r); i++) {             \
            (mat)->data[i] = malloc(c * sizeof(T)); \
        }\
    } while(0)

# define c_matrix_free(mat)                         \
    do{                                             \
        for (int i = 0; i < (mat)->rows; i++) {     \
            free((mat)->data[i]);                   \
        }                                           \
        free((mat)->data);                          \
    } while(0)

# endif