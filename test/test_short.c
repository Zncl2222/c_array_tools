/*
    Copyright (c) 2022 Jian Yu, Chen
    License: MIT License
    Version: v1.3.1
    file   : test.c

    The latest version is avaliable at:
    https://github.com/Zncl2222/c_array_tools
*/


# include <stdio.h>
# include "../src/c_array.h"
# include "utest.h"

UTEST(test, c_array_init) {
    c_array_short arr;
    c_array_init(&arr, 0);
    ASSERT_TRUE(arr.capacity == 0);
    ASSERT_TRUE(arr.size == 0);

    c_array_short arr2;
    c_array_init(&arr2, 20);
    ASSERT_TRUE(arr2.capacity == 20);
    ASSERT_TRUE(arr2.size == 20);

    c_array_free(&arr);
    c_array_free(&arr2);
}


UTEST(test, c_array_assign) {
    c_array_short arr;
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
    c_array_short arr;
    c_array_short arr_copy;

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
    c_array_short arr;
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
    c_array_short arr;
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
    c_array_short arr;
    c_array_init(&arr, 1);
    c_array_assign(&arr, 0, 15);
    ASSERT_EQ(c_array_byte(&arr), 2);

    c_array_free(&arr);
}

UTEST(test, c_array_empty) {
    c_array_short arr;
    c_array_init(&arr, 0);
    ASSERT_EQ(c_array_empty(&arr), 1);

    c_array_resize(&arr, 10);
    ASSERT_EQ(c_array_empty(&arr), 1);

    c_array_set_size(&arr, 10);
    ASSERT_EQ(c_array_empty(&arr), 0);

    c_array_free(&arr);
}

UTEST(test, c_array_swap) {
    c_array_short arr;
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
    c_array_short arr;
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
    c_array_short arr;
    c_array_init(&arr, 0);

    for (int i = 0; i < 9; i++) {
        c_array_push_back(&arr, 1);
    }
    c_array_print(arr);
    c_array_printf(arr, "%hd");

    c_array_free(&arr);
}

UTEST(test, c_array_reverse) {
    c_array_short arr;
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
    c_array_short arr;
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
    c_array_short arr;
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
    c_array_insert(&arr, 0, 9999);
    ASSERT_EQ(arr.data[0], 9999);
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
    c_array_short arr;
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
    c_array_short arr;
    c_array_short arr2;

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
    c_array_short arr;
    c_array_ushort arr_u;

    c_array_init(&arr, 0);
    c_array_init(&arr_u, 0);

    int t_short[] = {9, 4, 245, 1, -9};
    int ans_short[] = {-9, 1, 4, 9, 245};
    int t_ushort[] = {9, 4, 245, 1, 0};
    int ans_ushort[] = {0, 1, 4, 9, 245};

    for (int i = 0; i < 5; i++) {
        c_array_push_back(&arr, t_short[i]);
        c_array_push_back(&arr_u, t_ushort[i]);
    }

    c_array_qsort(&arr);
    c_array_qsort(&arr_u);

    for (int i = 0; i < 5; i++) {
        ASSERT_EQ(arr.data[i], ans_short[i]);
        ASSERT_EQ(arr_u.data[i], ans_ushort[i]);
    }

    c_array_free(&arr);
    c_array_free(&arr_u);
}

UTEST(test, c_array_msort) {
    c_array_short arr;

    c_array_init(&arr, 0);

    int t_short[] = {9, 4, 245, 1, -9};
    int ans_short[] = {-9, 1, 4, 9, 245};

    for (int i = 0; i < 5; i++) {
        c_array_push_back(&arr, t_short[i]);
    }

    c_array_msort(&arr);

    for (int i = 0; i < 5; i++) {
        ASSERT_EQ(arr.data[i], ans_short[i]);
    }

    c_array_free(&arr);
}

UTEST(test, c_array_sum) {
    c_array_short arr;
    c_array_ushort arr_u;

    c_array_init(&arr, 0);
    c_array_init(&arr_u, 0);

    for (int i = 0; i < 9; i++) {
        c_array_push_back(&arr, 1);
        c_array_push_back(&arr_u, 2);
    }

    short sum_short = c_array_sum(&arr);
    ASSERT_EQ(sum_short, 9);
    unsigned short sum_ushort = c_array_sum(&arr_u);
    ASSERT_EQ(sum_ushort, 18);

    c_array_free(&arr);
    c_array_free(&arr_u);
}

UTEST(test, c_array_min_max) {
    c_array_short arr;
    c_array_ushort arr_u;

    c_array_init(&arr, 0);
    c_array_init(&arr_u, 0);

    c_array_push_back(&arr, 51);
    c_array_push_back(&arr, 99);
    c_array_push_back(&arr_u, 511);
    c_array_push_back(&arr_u, 991);
    short max_short = c_array_max(&arr);
    short min_short = c_array_min(&arr);
    ASSERT_EQ(max_short, 99);
    ASSERT_EQ(min_short, 51);

    unsigned short max_ushort = c_array_max(&arr_u);
    unsigned short min_ushort = c_array_min(&arr_u);
    ASSERT_EQ(max_ushort, 991);
    ASSERT_EQ(min_ushort, 255);

    c_array_push_back(&arr, -599);
    max_short = c_array_max(&arr);
    min_short = c_array_min(&arr);
    ASSERT_EQ(max_short, 99);
    ASSERT_EQ(min_short, -599);

    c_array_free(&arr);
    c_array_free(&arr_u);
}

UTEST(test, c_array_statistic_original_func) {
    c_array_short arr;
    c_array_ushort arr_u;

    c_array_init(&arr, 0);
    c_array_init(&arr_u, 0);

    for (int i = 1; i < 6; i++) {
        c_array_push_back(&arr, i);
        c_array_push_back(&arr_u, i);
    }

    int sum_short = c_array_sum_short(arr.data, arr.size);

    mean_t mean_short = c_array_mean_short(arr.data, arr.size, sum_short);
    mean_t mean_ushort = c_array_mean_ushort(arr_u.data, arr_u.size, sum_short);

    var_t var_short = c_array_var_short(arr.data, arr.size, sum_short);
    var_t var_ushort = c_array_var_ushort(arr_u.data, arr_u.size, sum_short);

    std_t std_short = c_array_std_short(arr.data, arr.size, sum_short);
    std_t std_ushort = c_array_std_ushort(arr_u.data, arr_u.size, sum_short);

    c_array_free(&arr);
    c_array_free(&arr_u);
}

UTEST(test, c_array_mean) {
    c_array_short arr;
    c_array_ushort arr_u;

    c_array_init(&arr, 0);
    c_array_init(&arr_u, 0);

    for (int i = 0; i < 5; i++) {
        c_array_push_back(&arr, i);
        c_array_push_back(&arr_u, i);
    }

    mean_t mean_short = c_array_mean(&arr);
    mean_t mean_ushort = c_array_mean(&arr_u);

    ASSERT_NEAR(mean_short, 2, 0.01f);
    ASSERT_NEAR(mean_ushort, 2, 0.01f);

    c_array_free(&arr);
    c_array_free(&arr_u);
}

UTEST(test, c_array_var_std) {
    c_array_short arr;
    c_array_ushort arr_u;

    c_array_init(&arr, 0);
    c_array_init(&arr_u, 0);
    for (int i = 1; i < 6; i++) {
        c_array_push_back(&arr, i);
        c_array_push_back(&arr_u, i);
    }

    var_t var_short = c_array_var(&arr);
    var_t var_ushort = c_array_var(&arr_u);

    ASSERT_NEAR(var_short, 2, 0.01f);
    ASSERT_NEAR(var_ushort, 2, 0.01f);

    std_t std_short = c_array_std(&arr);
    std_t std_ushort = c_array_std(&arr_u);

    ASSERT_NEAR(std_short, 1.414213562, 0.01f);
    ASSERT_NEAR(std_ushort, 1.414213562, 0.01f);

    c_array_free(&arr);
    c_array_free(&arr_u);
}

UTEST(test, c_matrix_init) {
    c_matrix_short mat;
    c_matrix_init(&mat, 10, 6);
    ASSERT_EQ(mat.rows, 10);
    ASSERT_EQ(mat.cols, 6);

    c_matrix_short mat2;
    c_matrix_init(&mat2, 1000, 6000);
    ASSERT_EQ(mat2.rows, 1000);
    ASSERT_EQ(mat2.cols, 6000);

    c_matrix_double d_mat;
    c_matrix_init(&d_mat, 10000, 6000);
    ASSERT_EQ(d_mat.rows, 10000);
    ASSERT_EQ(d_mat.cols, 6000);

    c_matrix_short f_mat;
    c_matrix_init(&f_mat, 15112, 22131);
    ASSERT_EQ(f_mat.rows, 15112);
    ASSERT_EQ(f_mat.cols, 22131);

    c_matrix_free(&mat);
    c_matrix_free(&mat2);
    c_matrix_free(&d_mat);
    c_matrix_free(&f_mat);
}

UTEST (test, c_matrix_print_and_printf) {
    c_matrix_short mat;

    c_matrix_init(&mat, 5, 1);

    for (int i = 0; i < 5; i++) {
        mat.data[i][0] = 10;
    }

    c_matrix_print(mat);
    c_matrix_printf(mat, "%hd");

    c_matrix_free(&mat);
}

UTEST_MAIN();
