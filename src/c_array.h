/*
    Copyright (c) 2022 Jian Yu, Chen
    License: MIT License
*/


# ifndef C_ARRAY_H
# define C_ARRAY_H

# include <stdlib.h>
# include <string.h>
# include <assert.h>


// -----------------------------------------------------------------------
/*                     Array structure and initialize                   */

# define c_array(T) struct { T* data; size_t length; size_t capacity; }

# define c_array_init(arr, T, c)                                    \
    do {                                                            \
        (arr)->length = (c);                                        \
        (arr)->capacity = (c);                                      \
        (arr)->data = calloc((c), sizeof(T));                       \
    } while(0)

// -----------------------------------------------------------------------
/*                      Array basic operations                          */

# define c_array_capacity(arr) ((arr) ? (arr)->capacity : 0)

# define c_array_length(arr) ((arr) ? (arr)->length : 0)

# define c_array_assign(arr, idx, val)                                   \
    do {                                                                 \
        assert(idx < (arr)->length);                                     \
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

# define c_array_set_length(arr, l)                                 \
    do {                                                            \
        assert(l <= (arr)->capacity);                               \
        for (int i = (arr)->length; i < (arr)->capacity; i++) {     \
            (arr)->data[i] = 0;                                     \
        }                                                           \
        (arr)->length = (l);                                        \
    } while(0)

// -----------------------------------------------------------------------
/*                  Arrary push_back and pop_back                       */

# define c_array_push_back(arr, val)                             \
    do {                                                         \
        if (c_array_capacity((arr)) <= c_array_length((arr))) {  \
            c_array_grow((arr));                                 \
        }                                                        \
        (arr)->data[(arr)->length] = val;                        \
        (arr)->length++;                                         \
    } while(0)

# define c_array_pop_back(arr)              \
    do {                                    \
        assert((arr)->length > 0);          \
        (arr)->data[(arr)->length - 1] = 0; \
        (arr)->length--;                    \
    } while(0)

// -----------------------------------------------------------------------
/*                      Arrary insert and remove                        */

# define c_array_moveright(arr, idx)                  \
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

// -----------------------------------------------------------------------
/*                            Arrary utils                              */

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

# define c_array_empty(arr) ((arr)->length == 0)

# define c_array_swap(arr, idx1, idx2)                              \
    do {                                                            \
        assert((idx1) < (arr)->length && (idx2) < (arr)->length);   \
        assert((arr)->length >= 2);                                 \
        if ((arr)->capacity == (arr)->length) {                     \
            c_array_resize((arr), (arr)->capacity + 1);             \
        }                                                           \
        (arr)->data[(arr)->capacity - 1] = (arr)->data[idx2];       \
        (arr)->data[idx2] = (arr)->data[idx1];                      \
        (arr)->data[idx1] = (arr)->data[(arr)->capacity - 1];       \
    } while(0)                                                      \

# define c_array_reverse(arr)                                                       \
    do {                                                                            \
        if ((arr)->capacity == (arr)->length) {                                     \
            c_array_resize((arr), (arr)->capacity + 1);                             \
        }                                                                           \
        for (int i = 0; i < ((arr)->length / 2); i++) {                             \
            (arr)->data[(arr)->capacity - 1] = (arr)->data[i];                      \
            (arr)->data[i] = (arr)->data[(arr)->length - 1 - i];                    \
            (arr)->data[(arr)->length - 1 - i] = (arr)->data[(arr)->capacity - 1];  \
        }                                                                           \
        (arr)->data[(arr)->capacity - 1] = 0;                                       \
    } while(0)

# define c_array_free(arr) (free((arr)->data))

// -----------------------------------------------------------------------
/*                  Matrix structure and initialize                     */

# define c_matrix(T) struct { T** data; size_t rows; size_t cols; }

# define c_matrix_init(mat, T, r, c)                \
    do{                                             \
        (mat)->rows = (r);                          \
        (mat)->cols = (c);                          \
        (mat)->data = malloc(r * sizeof(T*));       \
        for (int i = 0; i < (r); i++) {             \
            (mat)->data[i] = malloc(c * sizeof(T)); \
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