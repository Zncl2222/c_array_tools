/*
    Copyright (c) 2022 Jian Yu, Chen
    License: MIT License
    file   : test.c

    The latest version is avaliable at:
    https://github.com/Zncl2222/c_array_tools
*/


# include <stdio.h>
# include "../src/c_array.h"
# include "utest.h"

UTEST(test, c_array_init) {
    c_array_int arr;
    c_array_init(&arr, 0);
    ASSERT_TRUE(arr.capacity == 0);
    ASSERT_TRUE(arr.size == 0);

    c_array_int arr2;
    c_array_init(&arr2, 20);
    ASSERT_TRUE(arr2.capacity == 20);
    ASSERT_TRUE(arr2.size == 20);

    for (int i = 0; i < arr2.size; i++) {
        ASSERT_EQ(arr2.data[i], 0);
    }

    c_array_free(&arr);
    c_array_free(&arr2);
}

UTEST(test, c_array_empty_init) {
    c_array_int arr;
    c_array_empty_init(&arr, 0);
    ASSERT_TRUE(arr.capacity == 0);
    ASSERT_TRUE(arr.size == 0);

    c_array_int arr2;
    c_array_empty_init(&arr2, 20);
    ASSERT_TRUE(arr2.capacity == 20);
    ASSERT_TRUE(arr2.size == 20);

    c_array_free(&arr);
    c_array_free(&arr2);
}

UTEST(test, c_array_assign) {
    c_array_int arr;
    c_array_init(&arr, 3);

    c_array_assign(&arr, 2, -99);
    ASSERT_EQ(arr.data[2], -99);

    c_array_assign(&arr, 1, 10);
    ASSERT_EQ(arr.data[1], 10);

    c_array_assign(&arr, 1, 110);
    ASSERT_EQ(arr.data[1], 110);

    c_array_free(&arr);
}

UTEST(test, c_array_copy) {
    c_array_int arr;
    c_array_int arr_copy;
    c_array_init(&arr, 0);

    for (int i = 0; i < 5; i++) {
        c_array_push_back(&arr, i);
    }

    c_array_copy(&arr, &arr_copy);
    ASSERT_EQ(arr_copy.capacity, 8);
    ASSERT_EQ(arr_copy.size, 5);

    for (int i = 0; i < 5; i++) {
        ASSERT_EQ(arr.data[i], arr_copy.data[i]);
    }

    c_array_free(&arr);
    c_array_free(&arr_copy);
}

UTEST(test, c_array_resize) {
    c_array_int arr;
    c_array_init(&arr, 3);
    ASSERT_EQ(arr.capacity, 3);
    ASSERT_EQ(arr.size, 3);

    c_array_resize(&arr, 15);
    ASSERT_EQ(arr.capacity, 15);
    ASSERT_EQ(arr.size, 3);

    c_array_resize(&arr, 2);
    ASSERT_EQ(arr.capacity, 2);

    c_array_free(&arr);
}

UTEST(test, c_array_set_size) {
    c_array_int arr;
    c_array_init(&arr, 30);
    ASSERT_EQ(arr.capacity, 30);
    ASSERT_EQ(arr.size, 30);

    c_array_set_size(&arr, 22);
    ASSERT_EQ(arr.capacity, 30);
    ASSERT_EQ(arr.size, 22);

    c_array_resize(&arr, 90);
    c_array_set_size(&arr, 70);
    ASSERT_EQ(arr.capacity, 90);
    ASSERT_EQ(arr.size, 70);

    c_array_set_size(&arr, 90);
    ASSERT_EQ(arr.capacity, 90);
    ASSERT_EQ(arr.size, 90);

    c_array_free(&arr);
}

UTEST(test, c_array_byte) {
    c_array_int arr;
    c_array_init(&arr, 1);
    c_array_assign(&arr, 0, 15);
    ASSERT_EQ(c_array_byte(&arr), 4);

    c_array_free(&arr);
}

UTEST(test, c_array_empty) {
    c_array_int arr;
    c_array_init(&arr, 0);
    ASSERT_EQ(c_array_empty(&arr), 1);

    c_array_resize(&arr, 10);
    ASSERT_EQ(c_array_empty(&arr), 1);

    c_array_set_size(&arr, 10);
    ASSERT_EQ(c_array_empty(&arr), 0);

    c_array_free(&arr);
}

UTEST(test, c_array_swap) {
    c_array_int arr;
    c_array_init(&arr, 0);

    c_array_push_back(&arr, 101);
    c_array_push_back(&arr, -20);
    ASSERT_EQ(arr.data[0], 101);
    ASSERT_EQ(arr.data[1], -20);

    c_array_swap(&arr, 0, 1);
    ASSERT_EQ(arr.data[0], -20);
    ASSERT_EQ(arr.data[1], 101);

    c_array_push_back(&arr, 9999);
    c_array_push_back(&arr, -1111);

    c_array_swap(&arr, 0, 3);
    ASSERT_EQ(arr.data[0], -1111);
    ASSERT_EQ(arr.data[3], -20);

    c_array_free(&arr);
}

UTEST(test, c_array_push_back) {
    c_array_int arr;
    c_array_init(&arr, 0);

    c_array_push_back(&arr, 15);
    ASSERT_EQ(arr.capacity, 2);
    ASSERT_EQ(arr.size, 1);

    c_array_push_back(&arr, 29);
    ASSERT_EQ(arr.capacity, 2);
    ASSERT_EQ(arr.size, 2);

    c_array_push_back(&arr, 55);
    ASSERT_EQ(arr.capacity, 4);
    ASSERT_EQ(arr.size, 3);

    c_array_push_back(&arr, 66);
    ASSERT_EQ(arr.capacity, 4);
    ASSERT_EQ(arr.size, 4);

    c_array_push_back(&arr, -5);
    ASSERT_EQ(arr.capacity, 8);
    ASSERT_EQ(arr.size, 5);

    ASSERT_EQ(arr.data[0], 15);
    ASSERT_EQ(arr.data[1], 29);
    ASSERT_EQ(arr.data[2], 55);
    ASSERT_EQ(arr.data[3], 66);
    ASSERT_EQ(arr.data[4], -5);

    c_array_free(&arr);
}

UTEST (test, c_array_print_and_printf) {
    c_array_int arr;
    c_array_init(&arr, 0);

    for (int i = 0; i < 9; i++) {
        c_array_push_back(&arr, 1);
    }
    c_array_print(arr);
    c_array_printf(arr, "%d");

    c_array_free(&arr);
}

UTEST(test, c_array_reverse) {
    c_array_int arr;
    c_array_init(&arr, 0);

    c_array_push_back(&arr, 1);
    c_array_push_back(&arr, 2);
    c_array_push_back(&arr, 3);
    c_array_push_back(&arr, 4);
    c_array_push_back(&arr, 5);
    c_array_push_back(&arr, 6);
    ASSERT_EQ(arr.data[0], 1);
    ASSERT_EQ(arr.data[1], 2);
    ASSERT_EQ(arr.data[2], 3);
    ASSERT_EQ(arr.data[3], 4);
    ASSERT_EQ(arr.data[4], 5);
    ASSERT_EQ(arr.data[5], 6);

    c_array_reverse(&arr);
    ASSERT_EQ(arr.data[0], 6);
    ASSERT_EQ(arr.data[1], 5);
    ASSERT_EQ(arr.data[2], 4);
    ASSERT_EQ(arr.data[3], 3);
    ASSERT_EQ(arr.data[4], 2);
    ASSERT_EQ(arr.data[5], 1);

    c_array_push_back(&arr, 0);
    c_array_reverse(&arr);
    ASSERT_EQ(arr.data[0], 0);
    ASSERT_EQ(arr.data[1], 1);
    ASSERT_EQ(arr.data[2], 2);
    ASSERT_EQ(arr.data[3], 3);
    ASSERT_EQ(arr.data[4], 4);
    ASSERT_EQ(arr.data[5], 5);
    ASSERT_EQ(arr.data[6], 6);

    c_array_free(&arr);
}

UTEST(test, c_array_pop_back) {
    c_array_int arr;
    c_array_init(&arr, 0);

    c_array_push_back(&arr, 15);
    c_array_push_back(&arr, 20);
    ASSERT_EQ(arr.size, 2);

    c_array_pop_back(&arr);
    ASSERT_EQ(arr.data[1], 0);
    ASSERT_EQ(arr.size, 1);

    c_array_free(&arr);
}

UTEST(test, c_array_insert) {
    c_array_int arr;
    c_array_init(&arr, 0);

    c_array_push_back(&arr, 15);
    c_array_push_back(&arr, 29);
    c_array_push_back(&arr, 55);
    c_array_push_back(&arr, 66);
    c_array_push_back(&arr, -5);

    // insert at middle
    c_array_insert(&arr, 1, -25);
    ASSERT_EQ(arr.data[1], -25);
    ASSERT_EQ(arr.data[2], 29);
    ASSERT_EQ(arr.data[3], 55);
    ASSERT_EQ(arr.data[4], 66);
    ASSERT_EQ(arr.data[5], -5);
    ASSERT_EQ(arr.size, 6);

    // insert at head
    c_array_insert(&arr, 0, 99999);
    ASSERT_EQ(arr.data[0], 99999);
    ASSERT_EQ(arr.data[1], 15);
    ASSERT_EQ(arr.data[2], -25);
    ASSERT_EQ(arr.data[3], 29);
    ASSERT_EQ(arr.data[4], 55);
    ASSERT_EQ(arr.data[5], 66);
    ASSERT_EQ(arr.data[6], -5);
    ASSERT_EQ(arr.size, 7);

    // insert at tail
    c_array_insert(&arr, 6, 2151);
    ASSERT_EQ(arr.data[6], 2151);
    ASSERT_EQ(arr.data[7], -5);
    ASSERT_EQ(arr.size, 8);

    c_array_free(&arr);
}

UTEST(test, c_array_remove) {
    c_array_int arr;
    c_array_init(&arr, 0);

    c_array_push_back(&arr, 15);
    c_array_push_back(&arr, 29);
    c_array_push_back(&arr, 55);
    c_array_push_back(&arr, 66);
    c_array_push_back(&arr, -5);
    ASSERT_EQ(arr.data[0], 15);
    ASSERT_EQ(arr.data[1], 29);
    ASSERT_EQ(arr.data[2], 55);
    ASSERT_EQ(arr.data[3], 66);
    ASSERT_EQ(arr.data[4], -5);
    ASSERT_EQ(arr.size, 5);

    c_array_remove(&arr, 1);
    ASSERT_EQ(arr.data[0], 15);
    ASSERT_EQ(arr.data[1], 55);
    ASSERT_EQ(arr.data[2], 66);
    ASSERT_EQ(arr.data[3], -5);
    ASSERT_EQ(arr.size, 4);

    c_array_free(&arr);
}

UTEST(test, c_array_concat) {
    c_array_int arr;
    c_array_int arr2;

    c_array_init(&arr, 0);
    c_array_init(&arr2, 5);

    c_array_push_back(&arr, 10);
    c_array_push_back(&arr, 20);
    ASSERT_EQ(arr.capacity, 2);
    ASSERT_EQ(arr.size, 2);
    ASSERT_EQ(arr2.capacity, 5);
    ASSERT_EQ(arr2.size, 5);
    int ans[7] = {10, 20, 0, 0, 0, 0, 0};

    c_array_concat(&arr, &arr2);
    ASSERT_EQ(arr.capacity, 7);
    ASSERT_EQ(arr.size, 7);
    for (int i = 0; i < arr.size; i++) {
        ASSERT_EQ(arr.data[i], ans[i]);
    }

    c_array_push_back(&arr, 5);
    ASSERT_EQ(arr.capacity, 14);
    ASSERT_EQ(arr.size, 8);

    c_array_concat(&arr, &arr2);
    ASSERT_EQ(arr.capacity, 14);
    ASSERT_EQ(arr.size, 13);
    int ans2[13] = {10, 20, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0};
    for (int i = 0; i < arr.size; i++) {
        ASSERT_EQ(arr.data[i], ans2[i]);
    }

    c_array_free(&arr);
    c_array_free(&arr2);
}

UTEST(test, c_array_qsort) {
    c_array_int arr;
    c_array_uint arr_u;

    c_array_init(&arr, 0);
    c_array_init(&arr_u, 0);

    int t_int[] = {9, 4, 245, 1, -9};
    int ans_int[] = {-9, 1, 4, 9, 245};
    unsigned int t_uint[] = {9, 4, 245, 1, -9};
    unsigned int ans_uint[] = {-9, 1, 4, 9, 245};

    for (int i = 0; i < 5; i++) {
        c_array_push_back(&arr, t_int[i]);
        c_array_push_back(&arr_u, t_uint[i]);
    }

    c_array_qsort(&arr);
    c_array_qsort(&arr_u);

    for (int i = 0; i < 5; i++) {
        ASSERT_EQ(arr.data[i], ans_int[i]);
        ASSERT_EQ(arr_u.data[i], ans_uint[i]);
    }

    c_array_free(&arr);
    c_array_free(&arr_u);
}

UTEST(test, c_array_msort) {
    c_array_int arr;

    c_array_init(&arr, 0);

    int t_int[] = {9, 4, 245, 1, -9};
    int ans_int[] = {-9, 1, 4, 9, 245};

    for (int i = 0; i < 5; i++) {
        c_array_push_back(&arr, t_int[i]);
    }

    c_array_msort(&arr);

    for (int i = 0; i < 5; i++) {
        ASSERT_EQ(arr.data[i], ans_int[i]);
    }

    c_array_free(&arr);
}

UTEST(test, c_array_sum) {
    c_array_int arr;
    c_array_uint arr_u;

    c_array_init(&arr, 0);
    c_array_init(&arr_u, 0);

    for (int i = 0; i < 9; i++) {
        c_array_push_back(&arr, 1);
        c_array_push_back(&arr_u, 1);
    }

    int sum_int = c_array_sum(&arr);
    ASSERT_EQ(sum_int, 9);
    unsigned int sum_uint = c_array_sum(&arr);
    ASSERT_EQ(sum_uint, 9);

    c_array_free(&arr);
    c_array_free(&arr_u);
}

UTEST(test, c_array_min_max) {
    c_array_int arr;
    c_array_uint arr_u;

    c_array_init(&arr, 0);
    c_array_init(&arr_u, 0);

    int test_arr[] = {3, 7, 1, 9, 2, 8, 6};
    for (int i = 0; i < 7; i++) {
        c_array_push_back(&arr, test_arr[i]);
        c_array_push_back(&arr_u, (unsigned int)test_arr[i]);
    }
    int max_int = c_array_max(&arr);
    int min_int = c_array_min(&arr);
    unsigned int max_uint = c_array_max(&arr_u);
    unsigned int min_uint = c_array_min(&arr_u);
    ASSERT_EQ(max_int, 9);
    ASSERT_EQ(min_int, 1);
    ASSERT_EQ(max_uint, 9);
    ASSERT_EQ(min_uint, 1);

    c_array_push_back(&arr, 4);
    c_array_push_back(&arr_u, 4);
    ASSERT_EQ(max_int, 9);
    ASSERT_EQ(min_int, 1);
    ASSERT_EQ(max_uint, 9);
    ASSERT_EQ(min_uint, 1);

    c_array_free(&arr);
    c_array_free(&arr_u);
}

UTEST(test, c_array_min_max_2) {
    c_array_int arr;
    c_array_uint arr_u;

    c_array_init(&arr, 0);
    c_array_init(&arr_u, 0);

    int test_arr[] = {3, 7, 1, 9, 2, 8, 60};
    for (int i = 0; i < 7; i++) {
        c_array_push_back(&arr, test_arr[i]);
        c_array_push_back(&arr_u, (unsigned int)test_arr[i]);
    }
    int max_int = c_array_max(&arr);
    int min_int = c_array_min(&arr);
    unsigned int max_uint = c_array_max(&arr_u);
    unsigned int min_uint = c_array_min(&arr_u);
    ASSERT_EQ(max_int, 60);
    ASSERT_EQ(min_int, 1);
    ASSERT_EQ(max_uint, 60);
    ASSERT_EQ(min_uint, 1);

    c_array_push_back(&arr, 4);
    c_array_push_back(&arr_u, 4);
    ASSERT_EQ(max_int, 60);
    ASSERT_EQ(min_int, 1);
    ASSERT_EQ(max_uint, 60);
    ASSERT_EQ(min_uint, 1);

    c_array_free(&arr);
    c_array_free(&arr_u);
}

UTEST(test, c_array_min_max_process) {
    c_array_int arr;
    c_array_uint arr_u;

    c_array_init(&arr, 0);
    c_array_init(&arr_u, 0);

    int test_arr[] = {3, 7, 1, 9, 2, 8, 60};
    for (int i = 0; i < 7; i++) {
        c_array_push_back(&arr, test_arr[i]);
        c_array_push_back(&arr_u, (unsigned int)test_arr[i]);
    }
    int* maxmin_int = c_array_maxmin(&arr);
    unsigned int* maxmin_uint = c_array_maxmin(&arr_u);
    ASSERT_EQ(maxmin_int[1], 60);
    ASSERT_EQ(maxmin_int[0], 1);
    ASSERT_EQ(maxmin_uint[1], 60);
    ASSERT_EQ(maxmin_uint[0], 1);

    c_array_push_back(&arr, 4);
    c_array_push_back(&arr_u, 4);
    ASSERT_EQ(maxmin_int[1], 60);
    ASSERT_EQ(maxmin_int[0], 1);
    ASSERT_EQ(maxmin_uint[1], 60);
    ASSERT_EQ(maxmin_uint[0], 1);

    c_array_free(&arr);
    c_array_free(&arr_u);
    free(maxmin_int);
    free(maxmin_uint);
}

UTEST(test, c_array_statistic_original_func) {
    c_array_int arr;
    c_array_uint arr_u;

    c_array_init(&arr, 0);
    c_array_init(&arr_u, 0);

    for (int i = 1; i < 6; i++) {
        c_array_push_back(&arr, i);
        c_array_push_back(&arr_u, i);
    }

    int sum_int = c_array_sum_int(arr.data, arr.size);
    unsigned int sum_uint = c_array_sum_uint(arr_u.data, arr_u.size);

    mean_t mean_int = c_array_mean_int(arr.data, arr.size, sum_int);
    mean_t mean_uint = c_array_mean_uint(arr_u.data, arr_u.size, sum_int);

    var_t var_int = c_array_var_int(arr.data, arr.size, sum_int);
    var_t var_uint = c_array_var_uint(arr_u.data, arr_u.size, sum_int);

    std_t std_int = c_array_std_int(arr.data, arr.size, sum_int);
    std_t std_uint = c_array_std_uint(arr_u.data, arr_u.size, sum_int);

    c_array_free(&arr);
    c_array_free(&arr_u);
}

UTEST(test, c_array_mean) {
    c_array_int arr;
    c_array_uint arr_u;

    c_array_init(&arr, 0);
    c_array_init(&arr_u, 0);

    for (int i = 0; i < 5; i++) {
        c_array_push_back(&arr, i);
        c_array_push_back(&arr_u, i);
    }

    mean_t mean_int = c_array_mean(&arr);
    mean_t mean_uint = c_array_mean(&arr_u);

    ASSERT_NEAR(mean_int, 2, 0.01f);
    ASSERT_NEAR(mean_uint, 2, 0.01f);

    c_array_free(&arr);
    c_array_free(&arr_u);
}

UTEST(test, c_array_var_std) {
    c_array_int arr;
    c_array_uint arr_u;

    c_array_init(&arr, 0);
    c_array_init(&arr_u, 0);

    for (int i = 1; i < 6; i++) {
        c_array_push_back(&arr, i);
        c_array_push_back(&arr_u, i);
    }

    var_t var_int = c_array_var(&arr);
    var_t var_uint = c_array_var(&arr_u);

    ASSERT_NEAR(var_int, 2, 0.01f);
    ASSERT_NEAR(var_uint, 2, 0.01f);

    std_t std_int = c_array_std(&arr);
    std_t std_uint = c_array_std(&arr_u);

    ASSERT_NEAR(std_int, 1.414213562, 0.01f);
    ASSERT_NEAR(std_uint, 1.414213562, 0.01f);

    c_array_free(&arr);
    c_array_free(&arr_u);
}

UTEST(test, c_array_search) {
    c_array_int arr;
    c_array_uint arr_u;

    c_array_init(&arr, 0);
    c_array_init(&arr_u, 0);

    for (int i = 0; i < 6; i++) {
        c_array_push_back(&arr, i * 2);
        c_array_push_back(&arr_u, i * 2);
    }

    int search_int = c_array_search(&arr, 6);
    int search_uint = c_array_search(&arr_u, 6);
    int search_fail = c_array_search(&arr, 99957);

    ASSERT_EQ(search_int, 3);
    ASSERT_EQ(search_uint, 3);
    ASSERT_EQ(search_fail, -1);

    c_array_free(&arr);
    c_array_free(&arr_u);
}

UTEST(test, c_matrix_init) {
    c_matrix_int mat;
    c_matrix_init(&mat, 10, 6);
    ASSERT_EQ(mat.rows, 10);
    ASSERT_EQ(mat.cols, 6);

    c_matrix_free(&mat);
}

UTEST(test, c_matrix_copy) {
    c_matrix_int mat1;
    c_matrix_int mat2;
    c_matrix_uint mat_u1;
    c_matrix_uint mat_u2;
    c_matrix_init(&mat1, 5, 10);
    c_matrix_init(&mat_u1, 5, 10);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            mat1.data[i][j] = i + j;
            mat_u1.data[i][j] = i + j;
        }
    }
    c_matrix_copy(&mat1, &mat2);
    c_matrix_copy(&mat_u1, &mat_u2);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            ASSERT_EQ(mat1.data[i][j], mat2.data[i][j]);
            ASSERT_EQ(mat_u1.data[i][j], mat_u2.data[i][j]);
        }
    }

    c_matrix_free(&mat1);
    c_matrix_free(&mat2);
    c_matrix_free(&mat_u1);
    c_matrix_free(&mat_u2);
}

UTEST(test, c_array_matrix_form) {
    c_array_int arr;
    c_array_uint arr_l;
    c_array_init(&arr, 10);
    c_array_init(&arr_l, 10);

    for (int i = 0; i < arr.size; i++) {
        arr.data[i] = i;
        arr_l.data[i] = i;
    }
    c_matrix_int mat = c_array_matrix_form(&arr, 2);
    c_matrix_uint mat_l = c_array_matrix_form(&arr_l, 2);
    ASSERT_EQ(mat.rows, 2);
    ASSERT_EQ(mat.cols, 5);
    ASSERT_EQ(mat_l.rows, 2);
    ASSERT_EQ(mat_l.cols, 5);
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            ASSERT_EQ(mat.data[i][j], i * mat.cols + j);
            ASSERT_EQ(mat_l.data[i][j], i * mat.cols + j);
        }
    }

    c_matrix_free(&mat);
    c_matrix_free(&mat_l);
    c_array_free(&arr);
    c_array_free(&arr_l);
}

UTEST(test, c_matrix_flatten) {
    c_matrix_int mat;
    c_matrix_uint mat_u;
    c_matrix_init(&mat, 10, 6);
    c_matrix_init(&mat_u, 10, 6);
    ASSERT_EQ(mat.rows, 10);
    ASSERT_EQ(mat.cols, 6);
    ASSERT_EQ(mat_u.rows, 10);
    ASSERT_EQ(mat_u.cols, 6);
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            mat.data[i][j] = i * mat.cols + j;
            mat_u.data[i][j] = i * mat.cols + j;
        }
    }
    c_array_int arr = c_matrix_flatten(&mat);
    c_array_uint arr_u = c_matrix_flatten(&mat_u);
    for (int i = 0; i < mat.rows * mat.cols; i++) {
        ASSERT_EQ(arr.data[i], i);
        ASSERT_EQ(arr_u.data[i], i);
    }

    c_matrix_free(&mat);
    c_matrix_free(&mat_u);
    c_array_free(&arr);
    c_array_free(&arr_u);
}

UTEST(test, c_matrix_reshape) {
    c_matrix_int mat;
    c_matrix_uint mat_u;
    c_matrix_init(&mat, 10, 6);
    c_matrix_init(&mat_u, 10, 6);
    ASSERT_EQ(mat.rows, 10);
    ASSERT_EQ(mat.cols, 6);
    ASSERT_EQ(mat_u.rows, 10);
    ASSERT_EQ(mat_u.cols, 6);
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            mat.data[i][j] = i * mat.cols + j;
            mat_u.data[i][j] = i * mat.cols + j;
        }
    }
    c_matrix_int mat2 = c_matrix_reshape(&mat, 6, 10);
    c_matrix_uint mat2_u = c_matrix_reshape(&mat_u, 6, 10);
    ASSERT_EQ(mat2.rows, 6);
    ASSERT_EQ(mat2.cols, 10);
    ASSERT_EQ(mat2_u.rows, 6);
    ASSERT_EQ(mat2_u.cols, 10);

    c_matrix_free(&mat2);
    c_matrix_free(&mat2_u);
}

UTEST(test, c_matrix_sum) {
    c_matrix_int mat;
    c_matrix_uint mat_u;

    c_matrix_init(&mat, 5, 2);
    c_matrix_init(&mat_u, 5, 2);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 2; j++) {
            mat.data[i][j] = i + j;
            mat_u.data[i][j] = 1;
        }
    }

    int sum_int = c_matrix_sum(&mat);
    ASSERT_EQ(sum_int, 25);
    unsigned int sum_uint = c_matrix_sum(&mat_u);
    ASSERT_EQ(sum_uint, 10);

    c_matrix_free(&mat);
    c_matrix_free(&mat_u);
}

UTEST(test, c_matrix_mean) {
    c_matrix_int mat;
    c_matrix_uint mat_u;

    c_matrix_init(&mat, 5, 2);
    c_matrix_init(&mat_u, 5, 2);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 2; j++) {
            mat.data[i][j] = 2;
            mat_u.data[i][j] = 1;
        }
    }

    mean_t mean_int = c_matrix_mean(&mat);
    ASSERT_NEAR(mean_int, 2, 0.01f);
    mean_t mean_uint = c_matrix_mean(&mat_u);
    ASSERT_NEAR(mean_uint, 1, 0.01f);

    c_matrix_free(&mat);
    c_matrix_free(&mat_u);
}

UTEST(test, c_matrix_max_min) {
    c_matrix_int mat;
    c_matrix_uint mat_u;

    c_matrix_init(&mat, 2, 2);
    c_matrix_init(&mat_u, 2, 2);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            mat.data[i][j] = i + j;
            mat_u.data[i][j] = i + j;
        }
    }

    int max = c_matrix_max(&mat);
    int max_u = c_matrix_max(&mat_u);
    int min = c_matrix_min(&mat);
    int min_u = c_matrix_min(&mat_u);
    ASSERT_EQ(max, 2);
    ASSERT_EQ(max_u, 2);
    ASSERT_EQ(min, 0);
    ASSERT_EQ(min_u, 0);

    c_matrix_free(&mat);
    c_matrix_free(&mat_u);
}

UTEST(test, c_matrix_var_std) {
    c_matrix_int mat;
    c_matrix_uint mat_u;

    c_matrix_init(&mat, 3, 3);
    c_matrix_init(&mat_u, 3, 3);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int val = i + j;
            mat.data[i][j] = val;
            mat_u.data[i][j] = val;
        }
    }

    var_t var_int = c_matrix_var(&mat);
    var_t var_uint = c_matrix_var(&mat_u);

    ASSERT_NEAR(var_int, 1.3333333, 0.01f);
    ASSERT_NEAR(var_uint, 1.333333, 0.01f);

    std_t std_int = c_matrix_std(&mat);
    std_t std_uint = c_matrix_std(&mat_u);
    ASSERT_NEAR(std_int, 1.154701, 0.01f);
    ASSERT_NEAR(std_uint, 1.154701, 0.01f);

    c_matrix_free(&mat);
    c_matrix_free(&mat_u);
}

UTEST (test, c_matrix_print_and_printf) {
    c_matrix_int mat;

    c_matrix_init(&mat, 5, 1);

    for (int i = 0; i < 5; i++) {
        mat.data[i][0] = 10;
    }

    c_matrix_print(mat);
    c_matrix_printf(mat, "%d");

    c_matrix_free(&mat);
}

UTEST_MAIN();
