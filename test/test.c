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
    c_array_int arr;
    c_array_init(&arr, 0);
    ASSERT_TRUE(arr.capacity == 0);
    ASSERT_TRUE(arr.size == 0);

    c_array_int arr2;
    c_array_init(&arr2, 20);
    ASSERT_TRUE(arr2.capacity == 20);
    ASSERT_TRUE(arr2.size == 20);

    c_array_float f_arr;
    c_array_init(&f_arr, 0);
    ASSERT_TRUE(f_arr.capacity == 0);
    ASSERT_TRUE(f_arr.size == 0);

    c_array_float f_arr2;
    c_array_init(&f_arr2, 20);
    ASSERT_TRUE(f_arr2.capacity == 20);
    ASSERT_TRUE(f_arr2.size == 20);

    c_array_double d_arr;
    c_array_init(&d_arr, 0);
    ASSERT_TRUE(d_arr.capacity == 0);
    ASSERT_TRUE(d_arr.size == 0);

    c_array_double d_arr2;
    c_array_init(&d_arr2, 20);
    ASSERT_TRUE(d_arr2.capacity == 20);
    ASSERT_TRUE(d_arr2.size == 20);

    c_array_free(&arr);
    c_array_free(&arr2);
    c_array_free(&f_arr);
    c_array_free(&f_arr2);
    c_array_free(&d_arr);
    c_array_free(&d_arr2);
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
    c_array_long_long arr_l;
    c_array_float arr_f;
    c_array_double arr_d;
    c_array_int arr_copy;
    c_array_long_long arr_l_copy;
    c_array_float arr_f_copy;
    c_array_double arr_d_copy;

    c_array_init(&arr, 0);
    c_array_init(&arr_l, 0);
    c_array_init(&arr_f, 0);
    c_array_init(&arr_d, 0);

    for (int i = 0; i < 5; i++) {
        c_array_push_back(&arr, i);
        c_array_push_back(&arr_l, i);
        c_array_push_back(&arr_f, i * 0.4);
        c_array_push_back(&arr_d, i * 0.1);
    }

    c_array_copy(&arr, &arr_copy);
    c_array_copy(&arr_l, &arr_l_copy);
    c_array_copy(&arr_f, &arr_f_copy);
    c_array_copy(&arr_d, &arr_d_copy);
    ASSERT_EQ(arr_copy.capacity, 8);
    ASSERT_EQ(arr_copy.size, 5);
    ASSERT_EQ(arr_l_copy.capacity, 8);
    ASSERT_EQ(arr_l_copy.size, 5);
    ASSERT_EQ(arr_f_copy.capacity, 8);
    ASSERT_EQ(arr_f_copy.size, 5);
    ASSERT_EQ(arr_d_copy.capacity, 8);
    ASSERT_EQ(arr_d_copy.size, 5);

    for (int i = 0; i < 5; i++) {
        ASSERT_EQ(arr.data[i], arr_copy.data[i]);
        ASSERT_EQ(arr_l.data[i], arr_l_copy.data[i]);
        ASSERT_EQ(arr_f.data[i], arr_f_copy.data[i]);
        ASSERT_EQ(arr_d.data[i], arr_d_copy.data[i]);
    }

    c_array_free(&arr);
    c_array_free(&arr_l);
    c_array_free(&arr_f);
    c_array_free(&arr_d);
    c_array_free(&arr_copy);
    c_array_free(&arr_l_copy);
    c_array_free(&arr_f_copy);
    c_array_free(&arr_d_copy);
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

    c_array_float f_arr;
    c_array_init(&f_arr, 1);
    c_array_assign(&f_arr, 0, 15.23);
    ASSERT_EQ(c_array_byte(&f_arr), 4);

    c_array_double d_arr;
    c_array_init(&d_arr, 1);
    c_array_assign(&d_arr, 0, 155.2348);
    ASSERT_EQ(c_array_byte(&d_arr), 8);

    c_array_free(&arr);
    c_array_free(&f_arr);
    c_array_free(&d_arr);
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
    c_array_long_long arr_l;
    c_array_float arr_f;
    c_array_double arr_d;

    c_array_init(&arr, 0);
    c_array_init(&arr_l, 0);
    c_array_init(&arr_f, 0);
    c_array_init(&arr_d, 0);

    for (int i = 0; i < 9; i++) {
        c_array_push_back(&arr, 1);
        c_array_push_back(&arr_l, 199);
        c_array_push_back(&arr_f, 1.5);
        c_array_push_back(&arr_d, 2.5);
    }

    c_array_print(arr);
    c_array_print(arr_l);
    c_array_print(arr_f);
    c_array_print(arr_d);
    c_array_printf(arr, "%d");
    c_array_printf(arr_l, "%lld");
    c_array_printf(arr_f, "%f");
    c_array_printf(arr_d, "%lf");

    c_array_free(&arr);
    c_array_free(&arr_l);
    c_array_free(&arr_f);
    c_array_free(&arr_d);
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
    c_array_long_long arr_l;
    c_array_float arr_f;
    c_array_double arr_d;

    c_array_init(&arr, 0);
    c_array_init(&arr_l, 0);
    c_array_init(&arr_f, 0);
    c_array_init(&arr_d, 0);

    int t_int[] = {9, 4, 245, 1, -9};
    int ans_int[] = {-9, 1, 4, 9, 245};
    long long t_long[] = {9, 2, 33, 9999999999, -123};
    long long ans_long[] = {-123, 2, 9, 33, 9999999999};
    float t_float[] = {2.43, -123.23, 222.9999, 222.999, -1221};
    float ans_float[] = {-1221, -123.23, 2.43, 222.999, 222.9999};
    double t_double[] = {9.99282, 9898889882, -2122.3, -2122.2, 0};
    double ans_double[] = {-2122.3, -2122.2, 0, 9.99282, 9898889882};

    for (int i = 0; i < 5; i++) {
        c_array_push_back(&arr, t_int[i]);
        c_array_push_back(&arr_l, t_long[i]);
        c_array_push_back(&arr_f, t_float[i]);
        c_array_push_back(&arr_d, t_double[i]);
    }

    c_array_qsort(&arr);
    c_array_qsort(&arr_l);
    c_array_qsort(&arr_f);
    c_array_qsort(&arr_d);

    for (int i = 0; i < 5; i++) {
        ASSERT_EQ(arr.data[i], ans_int[i]);
        ASSERT_EQ(arr_l.data[i], ans_long[i]);
        ASSERT_NEAR(arr_f.data[i], ans_float[i], 0.01f);
        ASSERT_NEAR(arr_d.data[i], ans_double[i], 0.01f);
    }

    c_array_free(&arr);
    c_array_free(&arr_l);
    c_array_free(&arr_f);
    c_array_free(&arr_d);
}

UTEST(test, c_array_msort) {
    c_array_int arr;
    c_array_long_long arr_l;
    c_array_float arr_f;
    c_array_double arr_d;

    c_array_init(&arr, 0);
    c_array_init(&arr_l, 0);
    c_array_init(&arr_f, 0);
    c_array_init(&arr_d, 0);

    int t_int[] = {9, 4, 245, 1, -9};
    int ans_int[] = {-9, 1, 4, 9, 245};
    long long t_long[] = {9, 2, 33, 9999999999, -123};
    long long ans_long[] = {-123, 2, 9, 33, 9999999999};
    float t_float[] = {2.43, -123.23, 222.9999, 222.999, -1221};
    float ans_float[] = {-1221, -123.23, 2.43, 222.999, 222.9999};
    double t_double[] = {9.99282, 9898889882, -2122.3, -2122.2, 0};
    double ans_double[] = {-2122.3, -2122.2, 0, 9.99282, 9898889882};

    for (int i = 0; i < 5; i++) {
        c_array_push_back(&arr, t_int[i]);
        c_array_push_back(&arr_l, t_long[i]);
        c_array_push_back(&arr_f, t_float[i]);
        c_array_push_back(&arr_d, t_double[i]);
    }

    c_array_msort(&arr);
    c_array_msort(&arr_l);
    c_array_msort(&arr_f);
    c_array_msort(&arr_d);

    for (int i = 0; i < 5; i++) {
        ASSERT_EQ(arr.data[i], ans_int[i]);
        ASSERT_EQ(arr_l.data[i], ans_long[i]);
        ASSERT_NEAR(arr_f.data[i], ans_float[i], 0.01f);
        ASSERT_NEAR(arr_d.data[i], ans_double[i], 0.01f);
    }

    c_array_free(&arr);
    c_array_free(&arr_l);
    c_array_free(&arr_f);
    c_array_free(&arr_d);
}

UTEST(test, c_array_sum) {
    c_array_int arr;
    c_array_long_long arr_l;
    c_array_float arr_f;
    c_array_double arr_d;

    c_array_init(&arr, 0);
    c_array_init(&arr_l, 0);
    c_array_init(&arr_f, 0);
    c_array_init(&arr_d, 0);

    for (int i = 0; i < 9; i++) {
        c_array_push_back(&arr, 1);
        c_array_push_back(&arr_l, 199);
        c_array_push_back(&arr_f, 1.5);
        c_array_push_back(&arr_d, 2.5);
    }

    int sum_int = c_array_sum(&arr);
    long long sum_long = c_array_sum(&arr_l);
    float sum_float = c_array_sum(&arr_f);
    double sum_double = c_array_sum(&arr_d);
    ASSERT_EQ(sum_int, 9);
    ASSERT_EQ(sum_long, 1791);
    ASSERT_EQ(sum_float, 13.5);
    ASSERT_EQ(sum_double, 22.5);

    c_array_free(&arr);
    c_array_free(&arr_l);
    c_array_free(&arr_f);
    c_array_free(&arr_d);
}

UTEST(test, c_array_min_max) {
    c_array_int arr;
    c_array_long_long arr_l;
    c_array_float arr_f;
    c_array_double arr_d;

    c_array_init(&arr, 0);
    c_array_init(&arr_l, 0);
    c_array_init(&arr_f, 0);
    c_array_init(&arr_d, 0);

    c_array_push_back(&arr, 51);
    c_array_push_back(&arr, 99);
    int max_int = c_array_max(&arr);
    int min_int = c_array_min(&arr);
    ASSERT_EQ(max_int, 99);
    ASSERT_EQ(min_int, 51);

    c_array_push_back(&arr, -59999);
    max_int = c_array_max(&arr);
    min_int = c_array_min(&arr);
    ASSERT_EQ(max_int, 99);
    ASSERT_EQ(min_int, -59999);

    c_array_push_back(&arr_l, 9223372036854775);
    c_array_push_back(&arr_l, -9223372036854775);
    long long max_long_long = c_array_max(&arr_l);
    long long min_long_long = c_array_min(&arr_l);
    ASSERT_EQ(max_long_long , 9223372036854775);
    ASSERT_EQ(min_long_long , -9223372036854775);

    c_array_push_back(&arr_l, -9223372036854775807);
    max_long_long = c_array_max(&arr_l);
    min_long_long = c_array_min(&arr_l);
    ASSERT_EQ(max_long_long , 9223372036854775);
    ASSERT_EQ(min_long_long , -9223372036854775807);

    c_array_push_back(&arr_f, 15.6996445);
    c_array_push_back(&arr_f, -55942.119454332);
    float max_float = c_array_max(&arr_f);
    float min_float = c_array_min(&arr_f);
    ASSERT_NEAR(max_float, 15.6996445, 0.01f);
    ASSERT_NEAR(min_float, -55942.119454332, 0.01f);

    c_array_push_back(&arr_f, 99999.9999);
    max_float = c_array_max(&arr_f);
    min_float = c_array_min(&arr_f);
    ASSERT_NEAR(max_float, 99999.9999, 0.01f);
    ASSERT_NEAR(min_float, -55942.119454332, 0.01f);

    c_array_push_back(&arr_d, 49.9541e300);
    c_array_push_back(&arr_d, -5e307);
    double max_double = c_array_max(&arr_d);
    double min_double = c_array_min(&arr_d);
    ASSERT_EQ(max_double, 49.9541e300);
    ASSERT_EQ(min_double, -5e307);

    c_array_push_back(&arr_d, 9e307);
    max_double = c_array_max(&arr_d);
    min_double = c_array_min(&arr_d);
    ASSERT_EQ(max_double, 9e307);
    ASSERT_EQ(min_double, -5e307);

    c_array_free(&arr);
    c_array_free(&arr_l);
    c_array_free(&arr_f);
    c_array_free(&arr_d);
}

UTEST(test, c_array_statistic_original_func) {
    c_array_int arr;
    c_array_long_long arr_l;
    c_array_float arr_f;
    c_array_double arr_d;

    c_array_init(&arr, 0);
    c_array_init(&arr_l, 0);
    c_array_init(&arr_f, 0);
    c_array_init(&arr_d, 0);

    for (int i = 1; i < 6; i++) {
        c_array_push_back(&arr, i);
        c_array_push_back(&arr_l, i);
        c_array_push_back(&arr_f, i * 0.4);
        c_array_push_back(&arr_d, i * 0.3);
    }

    int sum_int = c_array_sum_int(arr.data, arr.size);
    long long sum_long = c_array_sum_long(arr_l.data, arr_l.size);
    float sum_float = c_array_sum_float(arr_f.data, arr_f.size);
    double sum_double = c_array_sum_double(arr_d.data, arr_d.size);

    mean_t mean_int = c_array_mean_int(arr.data, arr.size, sum_int);
    mean_t mean_long = c_array_mean_long_long(arr_l.data, arr_l.size, sum_long);
    mean_t mean_float = c_array_mean_float(arr_f.data, arr_f.size, sum_float);
    mean_t mean_double = c_array_mean_double(arr_d.data, arr_d.size, sum_double);

    var_t var_int = c_array_var_int(arr.data, arr.size, sum_int);
    var_t var_long = c_array_var_long_long(arr_l.data, arr_l.size, sum_long);
    var_t var_float = c_array_var_float(arr_f.data, arr_f.size, sum_float);
    var_t var_double = c_array_var_double(arr_d.data, arr_d.size, sum_double);

    std_t std_int = c_array_std_int(arr.data, arr.size, sum_int);
    std_t std_long = c_array_std_long_long(arr_l.data, arr_l.size, sum_long);
    std_t std_float = c_array_std_float(arr_f.data, arr_f.size, sum_float);
    std_t std_double = c_array_std_double(arr_d.data, arr_d.size, sum_double);

    c_array_free(&arr);
    c_array_free(&arr_l);
    c_array_free(&arr_f);
    c_array_free(&arr_d);
}

UTEST(test, c_array_mean) {
    c_array_int arr;
    c_array_long_long arr_l;
    c_array_float arr_f;
    c_array_double arr_d;

    c_array_init(&arr, 0);
    c_array_init(&arr_l, 0);
    c_array_init(&arr_f, 0);
    c_array_init(&arr_d, 0);

    for (int i = 0; i < 5; i++) {
        c_array_push_back(&arr, i);
        c_array_push_back(&arr_l, i);
        c_array_push_back(&arr_f, i * 0.4);
        c_array_push_back(&arr_d, i * 0.1);
    }

    mean_t mean_int = c_array_mean(&arr);
    mean_t mean_long = c_array_mean(&arr_l);
    mean_t mean_float = c_array_mean(&arr_f);
    mean_t mean_double = c_array_mean(&arr_d);

    ASSERT_NEAR(mean_int, 2, 0.01f);
    ASSERT_NEAR(mean_long, 2, 0.01f);
    ASSERT_NEAR(mean_float, 0.8, 0.01f);
    ASSERT_NEAR(mean_double, 0.2, 0.01f);

    c_array_free(&arr);
    c_array_free(&arr_l);
    c_array_free(&arr_f);
    c_array_free(&arr_d);
}

UTEST(test, c_array_var_std) {
    c_array_int arr;
    c_array_long_long arr_l;
    c_array_float arr_f;
    c_array_double arr_d;

    c_array_init(&arr, 0);
    c_array_init(&arr_l, 0);
    c_array_init(&arr_f, 0);
    c_array_init(&arr_d, 0);

    for (int i = 1; i < 6; i++) {
        c_array_push_back(&arr, i);
        c_array_push_back(&arr_l, i);
        c_array_push_back(&arr_f, i * 0.4);
        c_array_push_back(&arr_d, i * 0.3);
    }

    var_t var_int = c_array_var(&arr);
    var_t var_long = c_array_var(&arr_l);
    var_t var_float = c_array_var(&arr_f);
    var_t var_double = c_array_var(&arr_d);

    ASSERT_NEAR(var_int, 2, 0.01f);
    ASSERT_NEAR(var_long, 2, 0.01f);
    ASSERT_NEAR(var_float, 0.32, 0.01f);
    ASSERT_NEAR(var_double, 0.18, 0.01f);

    std_t std_int = c_array_std(&arr);
    std_t std_long = c_array_std(&arr_l);
    std_t std_float = c_array_std(&arr_f);
    std_t std_double = c_array_std(&arr_d);

    ASSERT_NEAR(std_int, 1.414213562, 0.01f);
    ASSERT_NEAR(std_long, 1.414213562, 0.01f);
    ASSERT_NEAR(std_float, 0.5656854249, 0.01f);
    ASSERT_NEAR(std_double, 0.4242640687, 0.01f);

    c_array_free(&arr);
    c_array_free(&arr_l);
    c_array_free(&arr_f);
    c_array_free(&arr_d);
}

UTEST(test, c_matrix_init) {
    c_matrix_int mat;
    c_matrix_init(&mat, 10, 6);
    ASSERT_EQ(mat.rows, 10);
    ASSERT_EQ(mat.cols, 6);

    c_matrix_int mat2;
    c_matrix_init(&mat2, 1000, 6000);
    ASSERT_EQ(mat2.rows, 1000);
    ASSERT_EQ(mat2.cols, 6000);

    c_matrix_double d_mat;
    c_matrix_init(&d_mat, 10000, 6000);
    ASSERT_EQ(d_mat.rows, 10000);
    ASSERT_EQ(d_mat.cols, 6000);

    c_matrix_float f_mat;
    c_matrix_init(&f_mat, 15112, 22131);
    ASSERT_EQ(f_mat.rows, 15112);
    ASSERT_EQ(f_mat.cols, 22131);

    c_matrix_free(&mat);
    c_matrix_free(&mat2);
    c_matrix_free(&d_mat);
    c_matrix_free(&f_mat);
}

UTEST (test, c_matrix_print_and_printf) {
    c_matrix_int mat;
    c_matrix_long_long mat_l;
    c_matrix_float mat_f;
    c_matrix_double mat_d;

    c_matrix_init(&mat, 5, 1);
    c_matrix_init(&mat_l, 5, 2);
    c_matrix_init(&mat_f, 5, 3);
    c_matrix_init(&mat_d, 5, 4);

    for (int i = 0; i < 5; i++) {
        mat.data[i][0] = 10;

        for (int j = 0; j < 2; j++) {
            mat_l.data[i][j] = i + j;
        }
        for (int j = 0; j < 3; j++) {
            mat_f.data[i][j] = i + 0.5 * j;
        }
        for (int j = 0; j < 4; j++) {
            mat_d.data[i][j] = i + 0.65 * j;
        }
    }

    c_matrix_print(mat);
    c_matrix_print(mat_l);
    c_matrix_print(mat_f);
    c_matrix_print(mat_d);
    c_matrix_printf(mat, "%d");
    c_matrix_printf(mat_l, "%lld");
    c_matrix_printf(mat_f, "%f");
    c_matrix_printf(mat_d, "%lf");

    c_matrix_free(&mat);
    c_matrix_free(&mat_l);
    c_matrix_free(&mat_f);
    c_matrix_free(&mat_d);
}

UTEST_MAIN();
