/*
    Copyright (c) 2022 Jian Yu, Chenar
    License: MIT License
*/


# ifndef C_ARRAY_H
# define C_ARRAY_H

# include <stdlib.h>
# include <string.h>

# define MAX(a, b) ((a) < (b) ? (a) : (b))

# define c_array(T) struct { T* data; size_t length; size_t capacity; }

# define c_array_init(arr, l, c)                       \
    do {                                                \
        (arr)->length = (l) < (MAX(l, c)) ? (l) : (c);  \
        (arr)->capacity = (c);                          \
        (arr)->data = malloc(c);                        \
    } while (0)

# define c_array_capacity(arr) ((arr) ? (arr)->capacity : 0)

# define c_array_size(arr) ((arr) ? (arr)->length : 0)

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
