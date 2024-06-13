/*
    Copyright (c) 2022 Jian Yu, Chen
    License: MIT License
    file   : test_double.c

    The latest version is avaliable at:
    https://github.com/Zncl2222/c_array_tools
*/


# include <stdio.h>
# include "../src/c_array.h"
# include "utest.h"

UTEST(test_double, c_array_init) {
    c_array_double arr;
    c_array_init(&arr, 0);
    ASSERT_TRUE(arr.capacity == 0);
    ASSERT_TRUE(arr.size == 0);

    c_array_double arr2;
    c_array_init(&arr2, 20);
    ASSERT_TRUE(arr2.capacity == 20);
    ASSERT_TRUE(arr2.size == 20);

    for (int i = 0; i < arr2.size; i++) {
        ASSERT_NEAR(arr2.data[i], 0, 0.01f);
    }

    c_array_free(&arr);
    c_array_free(&arr2);
}

UTEST(test_double, c_array_empty_init) {
    c_array_double arr;
    c_array_empty_init(&arr, 0);
    ASSERT_TRUE(arr.capacity == 0);
    ASSERT_TRUE(arr.size == 0);

    c_array_double arr2;
    c_array_empty_init(&arr2, 20);
    ASSERT_TRUE(arr2.capacity == 20);
    ASSERT_TRUE(arr2.size == 20);

    c_array_free(&arr);
    c_array_free(&arr2);
}

UTEST(test_double, c_array_assign) {
    c_array_double arr;
    c_array_init(&arr, 3);

    c_array_assign(&arr, 2, -99);
    ASSERT_EQ(arr.data[2], -99);

    c_array_assign(&arr, 1, 10);
    ASSERT_EQ(arr.data[1], 10);

    c_array_assign(&arr, 1, 110);
    ASSERT_EQ(arr.data[1], 110);

    c_array_free(&arr);
}

UTEST(test_double, c_array_copy) {
    c_array_double arr;
    c_array_double arr_copy;
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

UTEST(test_double, c_array_resize) {
    c_array_double arr;
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

UTEST(test_double, c_array_set_size) {
    c_array_double arr;
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

UTEST(test_double, c_array_byte) {
    c_array_double arr;
    c_array_init(&arr, 1);
    c_array_assign(&arr, 0, 15);
    ASSERT_EQ(c_array_byte(&arr), 8);

    c_array_free(&arr);
}

UTEST(test_double, c_array_empty) {
    c_array_double arr;
    c_array_init(&arr, 0);
    ASSERT_EQ(c_array_empty(&arr), 1);

    c_array_resize(&arr, 10);
    ASSERT_EQ(c_array_empty(&arr), 1);

    c_array_set_size(&arr, 10);
    ASSERT_EQ(c_array_empty(&arr), 0);

    c_array_free(&arr);
}

UTEST(test_double, c_array_swap) {
    c_array_double arr;
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

UTEST(test_double, c_array_push_back) {
    c_array_double arr;
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

UTEST (test_double, c_array_print_and_printf) {
    c_array_double arr;
    c_array_init(&arr, 0);

    for (int i = 0; i < 9; i++) {
        c_array_push_back(&arr, 1);
    }
    c_array_print(arr);
    c_array_printf(arr, "%lf");

    c_array_free(&arr);
}

UTEST(test_double, c_array_reverse) {
    c_array_double arr;
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

UTEST(test_double, c_array_pop_back) {
    c_array_double arr;
    c_array_init(&arr, 0);

    c_array_push_back(&arr, 15);
    c_array_push_back(&arr, 20);
    ASSERT_EQ(arr.size, 2);

    c_array_pop_back(&arr);
    ASSERT_EQ(arr.data[1], 0);
    ASSERT_EQ(arr.size, 1);

    c_array_free(&arr);
}

UTEST(test_double, c_array_insert) {
    c_array_double arr;
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

UTEST(test_double, c_array_remove) {
    c_array_double arr;
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

UTEST(test_double, c_array_concat) {
    c_array_double arr;
    c_array_double arr2;

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

UTEST(test_double, c_array_qsort) {
    c_array_double arr;
    c_array_ldouble arr_ld;

    c_array_init(&arr, 0);
    c_array_init(&arr_ld, 0);

    double t_double[] = {9, 4, 245, 1, -9};
    double ans_double[] = {-9, 1, 4, 9, 245};
    long double t_ldouble[] = {9, 4, 245, 1, -9};
    long double ans_ldouble[] = {-9, 1, 4, 9, 245};

    for (int i = 0; i < 5; i++) {
        c_array_push_back(&arr, t_double[i]);
        c_array_push_back(&arr_ld, t_ldouble[i]);
    }

    c_array_qsort(&arr);
    c_array_qsort(&arr_ld);

    for (int i = 0; i < 5; i++) {
        ASSERT_EQ(arr.data[i], ans_double[i]);
        ASSERT_EQ(arr_ld.data[i], ans_ldouble[i]);
    }

    c_array_free(&arr);
    c_array_free(&arr_ld);
}

UTEST(test_double, c_array_msort) {
    c_array_double arr;

    c_array_init(&arr, 0);

    int t_double[] = {9, 4, 245, 1, -9};
    int ans_double[] = {-9, 1, 4, 9, 245};

    for (int i = 0; i < 5; i++) {
        c_array_push_back(&arr, t_double[i]);
    }

    c_array_msort(&arr);

    for (int i = 0; i < 5; i++) {
        ASSERT_EQ(arr.data[i], ans_double[i]);
    }

    c_array_free(&arr);
}

UTEST(test_double, c_array_sum) {
    c_array_double arr;
    c_array_ldouble arr_ld;

    c_array_init(&arr, 0);
    c_array_init(&arr_ld, 0);

    for (int i = 0; i < 9; i++) {
        c_array_push_back(&arr, 1);
        c_array_push_back(&arr_ld, 1);
    }

    double sum_double = c_array_sum(&arr);
    ASSERT_EQ(sum_double, 9);

    long double sum_ldouble = c_array_sum(&arr_ld);
    ASSERT_EQ(sum_ldouble, 9);

    c_array_free(&arr);
    c_array_free(&arr_ld);
}

UTEST(test_double, c_array_min_max) {
    c_array_double arr;
    c_array_ldouble arr_ld;

    c_array_init(&arr, 0);
    c_array_init(&arr_ld, 0);

    double test_arr[] = {3.2, 7.1, 1, 9.6, 2.5, 8.44, 6};
    for (int i = 0; i < 7; i++) {
        c_array_push_back(&arr, test_arr[i]);
        c_array_push_back(&arr_ld, (long double)test_arr[i]);
    }

    double max_double = c_array_max(&arr);
    double min_double = c_array_min(&arr);
    long double max_ldouble = c_array_max(&arr_ld);
    long double min_ldouble = c_array_min(&arr_ld);
    ASSERT_NEAR(max_double, 9.6, 0.01f);
    ASSERT_NEAR(min_double, 1, 0.01f);
    ASSERT_NEAR(max_ldouble, 9.6, 0.01f);
    ASSERT_NEAR(min_ldouble, 1, 0.01f);

    c_array_push_back(&arr, -5999.11);
    c_array_push_back(&arr_ld, -5999.11);
    max_double = c_array_max(&arr);
    min_double = c_array_min(&arr);
    max_ldouble = c_array_max(&arr_ld);
    min_ldouble = c_array_min(&arr_ld);
    ASSERT_NEAR(max_double, 9.6, 0.01f);
    ASSERT_NEAR(min_double, -5999.11, 0.01f);
    ASSERT_NEAR(max_ldouble, 9.6, 0.01f);
    ASSERT_NEAR(min_ldouble, -5999.11, 0.01f);

    c_array_free(&arr);
    c_array_free(&arr_ld);
}

UTEST(test_double, c_array_min_max_2) {
    c_array_double arr;
    c_array_ldouble arr_ld;

    c_array_init(&arr, 0);
    c_array_init(&arr_ld, 0);

    double test_arr[] = {3.2, 7.1, 1, 9.6, 2.5, 8.44, 69778.1};
    for (int i = 0; i < 7; i++) {
        c_array_push_back(&arr, test_arr[i]);
        c_array_push_back(&arr_ld, (long double)test_arr[i]);
    }

    double max_double = c_array_max(&arr);
    double min_double = c_array_min(&arr);
    long double max_ldouble = c_array_max(&arr_ld);
    long double min_ldouble = c_array_min(&arr_ld);
    ASSERT_NEAR(max_double, 69778.1, 0.01f);
    ASSERT_NEAR(min_double, 1, 0.01f);
    ASSERT_NEAR(max_ldouble, 69778.1, 0.01f);
    ASSERT_NEAR(min_ldouble, 1, 0.01f);

    c_array_push_back(&arr, -5999.11);
    c_array_push_back(&arr_ld, -5999.11);
    max_double = c_array_max(&arr);
    min_double = c_array_min(&arr);
    max_ldouble = c_array_max(&arr_ld);
    min_ldouble = c_array_min(&arr_ld);
    ASSERT_NEAR(max_double, 69778.1, 0.01f);
    ASSERT_NEAR(min_double, -5999.11, 0.01f);
    ASSERT_NEAR(max_ldouble, 69778.1, 0.01f);
    ASSERT_NEAR(min_ldouble, -5999.11, 0.01f);

    c_array_free(&arr);
    c_array_free(&arr_ld);
}


UTEST(test_double, c_array_min_max_process) {
    c_array_double arr;
    c_array_ldouble arr_ld;
    c_array_init(&arr, 0);
    c_array_init(&arr_ld, 0);
    double test_arr[] = {3.5, 7.6, 1.4, 9.5, 2.5, 8.5, 60.112};
    for (int i = 0; i < 7; i++) {
        c_array_push_back(&arr, test_arr[i]);
        c_array_push_back(&arr_ld, test_arr[i]);
    }
    double* maxmin_double = c_array_maxmin(&arr);
    long double* maxmin_ldouble = c_array_maxmin(&arr_ld);
    ASSERT_NEAR(maxmin_double[1], 60.112, 0.01f);
    ASSERT_NEAR(maxmin_double[0], 1.4, 0.01f);
    ASSERT_NEAR(maxmin_ldouble[1], 60.112, 0.01f);
    ASSERT_NEAR(maxmin_ldouble[0], 1.4, 0.01f);

    c_array_push_back(&arr, 4);

    ASSERT_NEAR(maxmin_double[1], 60.112, 0.01f);
    ASSERT_NEAR(maxmin_double[0], 1.4, 0.01f);
    ASSERT_NEAR(maxmin_ldouble[1], 60.112, 0.01f);
    ASSERT_NEAR(maxmin_ldouble[0], 1.4, 0.01f);

    c_array_free(&arr);
    c_array_free(&arr_ld);
    free(maxmin_double);
    free(maxmin_ldouble);
}


UTEST(test_double, c_array_statistic_original_func) {
    c_array_double arr;
    c_array_ldouble arr_ld;

    c_array_init(&arr, 0);
    c_array_init(&arr_ld, 0);

    for (int i = 1; i < 6; i++) {
        c_array_push_back(&arr, i);
        c_array_push_back(&arr_ld, i);
    }

    double sum_double = c_array_sum_double(arr.data, arr.size);
    long double sum_ldouble = c_array_sum_long_double(arr_ld.data, arr_ld.size);

    mean_t mean_double = c_array_mean_double(arr.data, arr.size, sum_double);
    long double mean_ldouble = c_array_mean_long_double(arr_ld.data, arr_ld.size, sum_ldouble);

    var_t var_double = c_array_var_double(arr.data, arr.size, sum_double);
    long double var_ldouble = c_array_var_long_double(arr_ld.data, arr_ld.size, sum_ldouble);

    std_t std_double = c_array_std_double(arr.data, arr.size, sum_double);
    long double std_ldouble = c_array_std_long_double(arr_ld.data, arr_ld.size, sum_ldouble);

    c_array_free(&arr);
    c_array_free(&arr_ld);
}

UTEST(test_double, c_array_mean) {
    c_array_double arr;
    c_array_ldouble arr_ld;

    c_array_init(&arr, 0);
    c_array_init(&arr_ld, 0);

    for (int i = 0; i < 5; i++) {
        c_array_push_back(&arr, i);
        c_array_push_back(&arr_ld, i);
    }

    mean_t mean_double = c_array_mean(&arr);
    long double mean_ldouble = c_array_mean(&arr_ld);

    ASSERT_NEAR(mean_double, 2, 0.01f);
    ASSERT_NEAR(mean_ldouble, 2, 0.01f);

    c_array_free(&arr);
    c_array_free(&arr_ld);
}

UTEST(test_double, c_array_var_std) {
    c_array_double arr;
    c_array_ldouble arr_ld;

    c_array_init(&arr, 0);
    c_array_init(&arr_ld, 0);

    for (int i = 1; i < 6; i++) {
        c_array_push_back(&arr, i);
        c_array_push_back(&arr_ld, i);
    }

    var_t var_double = c_array_var(&arr);
    long double var_ldouble = c_array_var(&arr_ld);

    ASSERT_NEAR(var_double, 2, 0.01f);
    ASSERT_NEAR(var_ldouble, 2, 0.01f);

    std_t std_double = c_array_std(&arr);
    long double std_ldouble = c_array_std(&arr_ld);

    ASSERT_NEAR(std_double, 1.414213562, 0.01f);
    ASSERT_NEAR(std_ldouble, 1.414213562, 0.01f);

    c_array_free(&arr);
    c_array_free(&arr_ld);
}

UTEST(test_double, c_array_search) {
    c_array_double arr;
    c_array_ldouble arr_ld;

    c_array_init(&arr, 0);
    c_array_init(&arr_ld, 0);

    for (int i = 0; i < 6; i++) {
        c_array_push_back(&arr, i * 2.5);
        c_array_push_back(&arr_ld, i * 4.5);
    }

    int* search_d = c_array_search(&arr, 7.5);
    int* search_ld = c_array_search(&arr_ld, 22.5);
    int* search_fail = c_array_search(&arr, 99957);

    ASSERT_EQ(search_d[0], 3);
    ASSERT_EQ(search_ld[0], 5);
    ASSERT_EQ(search_fail[0], -1);
    free(search_d);
    free(search_ld);
    free(search_fail);

    c_array_free(&arr);
    c_array_free(&arr_ld);
}

UTEST(test_double, c_matrix_init) {
    c_matrix_double mat;
    c_matrix_init(&mat, 10, 6);
    ASSERT_EQ(mat.rows, 10);
    ASSERT_EQ(mat.cols, 6);

    c_matrix_double mat2;
    c_matrix_init(&mat2, 1000, 6000);
    ASSERT_EQ(mat2.rows, 1000);
    ASSERT_EQ(mat2.cols, 6000);

    c_matrix_double d_mat;
    c_matrix_init(&d_mat, 1000, 600);
    ASSERT_EQ(d_mat.rows, 1000);
    ASSERT_EQ(d_mat.cols, 600);

    c_matrix_double f_mat;
    c_matrix_init(&f_mat, 1512, 2231);
    ASSERT_EQ(f_mat.rows, 1512);
    ASSERT_EQ(f_mat.cols, 2231);

    c_matrix_free(&mat);
    c_matrix_free(&mat2);
    c_matrix_free(&d_mat);
    c_matrix_free(&f_mat);
}

UTEST(test_double, c_matrix_copy) {
    c_matrix_double mat1;
    c_matrix_double mat2;
    c_matrix_ldouble mat_l1;
    c_matrix_ldouble mat_l2;
    c_matrix_init(&mat1, 5, 10);
    c_matrix_init(&mat_l1, 5, 10);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            mat1.data[i][j] = i + 0.5 * j;
            mat_l1.data[i][j] = i + 0.545 * j;
        }
    }
    c_matrix_copy(&mat1, &mat2);
    c_matrix_copy(&mat_l1, &mat_l2);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            ASSERT_NEAR(mat1.data[i][j], mat2.data[i][j], 0.01f);
            ASSERT_NEAR(mat_l1.data[i][j], mat_l2.data[i][j], 0.01f);
        }
    }

    c_matrix_free(&mat1);
    c_matrix_free(&mat2);
    c_matrix_free(&mat_l1);
    c_matrix_free(&mat_l2);
}

UTEST(test_double, c_matrix_mean) {
    c_matrix_double mat;
    c_matrix_ldouble mat_l;

    c_matrix_init(&mat, 5, 2);
    c_matrix_init(&mat_l, 5, 2);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 2; j++) {
            mat.data[i][j] = 222;
            mat_l.data[i][j] = 111;
        }
    }

    mean_t mean_double = c_matrix_mean(&mat);
    ASSERT_NEAR(mean_double, 222, 0.01f);
    mean_t mean_ldouble = c_matrix_mean(&mat_l);
    ASSERT_NEAR(mean_ldouble, 111, 0.01f);

    c_matrix_free(&mat);
    c_matrix_free(&mat_l);
}

UTEST(test_double, c_array_matrix_form) {
    c_array_double arr;
    c_array_ldouble arr_l;
    c_array_init(&arr, 10);
    c_array_init(&arr_l, 10);

    for (int i = 0; i < arr.size; i++) {
        arr.data[i] = i;
        arr_l.data[i] = i;
    }
    c_matrix_double mat = c_array_matrix_form(&arr, 2);
    c_matrix_ldouble mat_l = c_array_matrix_form(&arr_l, 2);
    ASSERT_EQ(mat.rows, 2);
    ASSERT_EQ(mat.cols, 5);
    ASSERT_EQ(mat_l.rows, 2);
    ASSERT_EQ(mat_l.cols, 5);
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            ASSERT_NEAR(mat.data[i][j], i * mat.cols + j, 0.01f);
            ASSERT_NEAR(mat_l.data[i][j], i * mat.cols + j, 0.01f);
        }
    }

    c_matrix_free(&mat);
    c_matrix_free(&mat_l);
    c_array_free(&arr);
    c_array_free(&arr_l);
}

UTEST(test_double, c_matrix_flatten) {
    c_matrix_double mat;
    c_matrix_ldouble mat_l;
    c_matrix_init(&mat, 10, 6);
    c_matrix_init(&mat_l, 10, 6);
    ASSERT_EQ(mat.rows, 10);
    ASSERT_EQ(mat.cols, 6);

    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            mat.data[i][j] = i * mat.cols + j;
            mat_l.data[i][j] = i * mat.cols + j;
        }
    }
    c_array_double arr = c_matrix_flatten(&mat);
    c_array_ldouble arr_l = c_matrix_flatten(&mat_l);
    for (int i = 0; i < mat.rows * mat.cols; i++) {
        ASSERT_NEAR(arr.data[i], i, 0.01f);
        ASSERT_NEAR(arr_l.data[i], i, 0.01f);
    }

    c_matrix_free(&mat);
    c_matrix_free(&mat_l);
    c_array_free(&arr);
    c_array_free(&arr_l);
}

UTEST(test_double, c_matrix_reshape) {
    c_matrix_double mat;
    c_matrix_ldouble mat_l;
    c_matrix_init(&mat, 10, 6);
    c_matrix_init(&mat_l, 10, 6);
    ASSERT_EQ(mat.rows, 10);
    ASSERT_EQ(mat.cols, 6);
    ASSERT_EQ(mat_l.rows, 10);
    ASSERT_EQ(mat_l.cols, 6);
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            mat.data[i][j] = i * mat.cols + j;
            mat_l.data[i][j] = i * mat.cols + j;
        }
    }
    c_matrix_double mat2 = c_matrix_reshape(&mat, 6, 10);
    c_matrix_ldouble mat2_l = c_matrix_reshape(&mat_l, 6, 10);
    ASSERT_EQ(mat2.rows, 6);
    ASSERT_EQ(mat2.cols, 10);
    ASSERT_EQ(mat2_l.rows, 6);
    ASSERT_EQ(mat2_l.cols, 10);

    c_matrix_free(&mat2);
    c_matrix_free(&mat2_l);
}

UTEST(test_double, c_matrix_sum) {
    c_matrix_double mat;
    c_matrix_ldouble mat_l;

    c_matrix_init(&mat, 5, 2);
    c_matrix_init(&mat_l, 5, 2);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 2; j++) {
            mat.data[i][j] = 0.5 * i + 0.5 * j;
            mat_l.data[i][j] = 0.01;
        }
    }

    double sum_d = c_matrix_sum(&mat);
    ASSERT_NEAR(sum_d, 12.5, 0.01f);
    long double sum_ld = c_matrix_sum(&mat_l);
    ASSERT_NEAR(sum_ld, 0.1, 0.01f);

    c_matrix_free(&mat);
    c_matrix_free(&mat_l);
}


UTEST(test_double, c_matrix_max_min) {
    c_matrix_double mat;
    c_matrix_ldouble mat_l;

    c_matrix_init(&mat, 2, 2);
    c_matrix_init(&mat_l, 2, 2);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            mat.data[i][j] = 0.2 * i +  0.2 * j;
            mat_l.data[i][j] = 3.545 + i;
        }
    }

    double max = c_matrix_max(&mat);
    double min = c_matrix_min(&mat);
    double max_l = c_matrix_max(&mat_l);
    double min_l = c_matrix_min(&mat_l);
    ASSERT_NEAR(max, 0.4, 0.01f);
    ASSERT_NEAR(min, 0, 0.01f);
    ASSERT_NEAR(max_l, 4.545, 0.01f);
    ASSERT_NEAR(min_l, 3.545, 0.01f);

    c_matrix_free(&mat);
    c_matrix_free(&mat_l);
}

UTEST(test_double, c_matrix_var_std) {
    c_matrix_double mat;
    c_matrix_ldouble mat_l;

    c_matrix_init(&mat, 3, 3);
    c_matrix_init(&mat_l, 3, 3);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mat.data[i][j] = 0.5 * i + 12.212 * j;
            mat_l.data[i][j] = 2147483648.99225 * i + 55564798542384.512 * j;
        }
    }

    var_t var_double = c_matrix_var(&mat);
    var_t var_ldouble = c_matrix_var(&mat_l);
    ASSERT_NEAR(var_double, 99.588628, 0.01f);
    ASSERT_NEAR(var_ldouble, 2058297894444975095399055360.000000, 0.01f);

    std_t std_double = c_matrix_std(&mat);
    std_t std_ldouble = c_matrix_std(&mat_l);
    ASSERT_NEAR(std_double, 9.979410, 0.01f);
    ASSERT_NEAR(std_ldouble, 45368468063678.046875, 0.01f);

    c_matrix_free(&mat);
    c_matrix_free(&mat_l);
}

UTEST (test_double, c_matrix_print_and_printf) {
    c_matrix_double mat;

    c_matrix_init(&mat, 5, 1);

    for (int i = 0; i < 5; i++) {
        mat.data[i][0] = 10;
    }

    c_matrix_print(mat);
    c_matrix_printf(mat, "%lf");

    c_matrix_free(&mat);
}

UTEST_MAIN();
