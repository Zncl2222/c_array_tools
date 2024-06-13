/*
    Copyright (c) 2022 Jian Yu, Chen
    License: MIT License
    file   : test_long.c

    The latest version is avaliable at:
    https://github.com/Zncl2222/c_array_tools
*/


# include <stdio.h>
# include "../src/c_array.h"
# include "utest.h"

UTEST(test_long, c_array_init) {
    c_array_long arr;
    c_array_init(&arr, 0);
    ASSERT_TRUE(arr.capacity == 0);
    ASSERT_TRUE(arr.size == 0);

    c_array_long arr2;
    c_array_init(&arr2, 20);
    ASSERT_TRUE(arr2.capacity == 20);
    ASSERT_TRUE(arr2.size == 20);

    for (int i = 0; i < arr2.size; i++) {
        ASSERT_EQ(arr2.data[i], 0);
    }

    c_array_free(&arr);
    c_array_free(&arr2);
}

UTEST(test_long, c_array_empty_init) {
    c_array_long arr;
    c_array_empty_init(&arr, 0);
    ASSERT_TRUE(arr.capacity == 0);
    ASSERT_TRUE(arr.size == 0);

    c_array_long arr2;
    c_array_empty_init(&arr2, 20);
    ASSERT_TRUE(arr2.capacity == 20);
    ASSERT_TRUE(arr2.size == 20);

    c_array_free(&arr);
    c_array_free(&arr2);
}

UTEST(test_long, c_array_assign) {
    c_array_long arr;
    c_array_init(&arr, 3);

    c_array_assign(&arr, 2, -99);
    ASSERT_EQ(arr.data[2], -99);

    c_array_assign(&arr, 1, 10);
    ASSERT_EQ(arr.data[1], 10);

    c_array_assign(&arr, 1, 110);
    ASSERT_EQ(arr.data[1], 110);

    c_array_free(&arr);
}

UTEST(test_long, c_array_copy) {
    c_array_long arr;
    c_array_long arr_copy;
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

UTEST(test_long, c_array_resize) {
    c_array_long arr;
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

UTEST(test_long, c_array_set_size) {
    c_array_long arr;
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

UTEST(test_long, c_array_byte) {
    c_array_long arr;
    c_array_init(&arr, 1);
    c_array_assign(&arr, 0, 15);
#ifdef _WIN32
        ASSERT_EQ(c_array_byte(&arr), 4);
#elif __linux__
        ASSERT_EQ(c_array_byte(&arr), 8);
#endif
    c_array_free(&arr);
}

UTEST(test_long, c_array_empty) {
    c_array_long arr;
    c_array_init(&arr, 0);
    ASSERT_EQ(c_array_empty(&arr), 1);

    c_array_resize(&arr, 10);
    ASSERT_EQ(c_array_empty(&arr), 1);

    c_array_set_size(&arr, 10);
    ASSERT_EQ(c_array_empty(&arr), 0);

    c_array_free(&arr);
}

UTEST(test_long, c_array_swap) {
    c_array_long arr;
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

UTEST(test_long, c_array_push_back) {
    c_array_long arr;
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

UTEST (test_long, c_array_print_and_printf) {
    c_array_long arr;
    c_array_init(&arr, 0);

    for (int i = 0; i < 9; i++) {
        c_array_push_back(&arr, 1);
    }
    c_array_print(arr);
    c_array_printf(arr, "%ld");

    c_array_free(&arr);
}

UTEST(test_long, c_array_reverse) {
    c_array_long arr;
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

UTEST(test_long, c_array_pop_back) {
    c_array_long arr;
    c_array_init(&arr, 0);

    c_array_push_back(&arr, 15);
    c_array_push_back(&arr, 20);
    ASSERT_EQ(arr.size, 2);

    c_array_pop_back(&arr);
    ASSERT_EQ(arr.data[1], 0);
    ASSERT_EQ(arr.size, 1);

    c_array_free(&arr);
}

UTEST(test_long, c_array_insert) {
    c_array_long arr;
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

UTEST(test_long, c_array_remove) {
    c_array_long arr;
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

UTEST(test_long, c_array_concat) {
    c_array_long arr;
    c_array_long arr2;

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

UTEST(test_long, c_array_qsort) {
    c_array_long arr;
    c_array_long_long arr_ll;
    c_array_ulong arr_ul;

    c_array_init(&arr, 0);
    c_array_init(&arr_ll, 0);
    c_array_init(&arr_ul, 0);

    int t_long[] = {9, 4, 245, 1, -9};
    int ans_long[] = {-9, 1, 4, 9, 245};
    int t_long_long[] = {9, 4, 245, 1, -9};
    int ans_long_long[] = {-9, 1, 4, 9, 245};
    int t_ulong[] = {9, 4, 245, 1, -9};
    int ans_ulong[] = {-9, 1, 4, 9, 245};

    for (int i = 0; i < 5; i++) {
        c_array_push_back(&arr, t_long[i]);
        c_array_push_back(&arr_ll, t_long_long[i]);
        c_array_push_back(&arr_ul, t_ulong[i]);
    }

    c_array_qsort(&arr);
    c_array_qsort(&arr_ll);
    c_array_qsort(&arr_ul);

    for (int i = 0; i < 5; i++) {
        ASSERT_EQ(arr.data[i], ans_long[i]);
        ASSERT_EQ(arr_ll.data[i], ans_long_long[i]);
        ASSERT_EQ(arr_ul.data[i], ans_ulong[i]);
    }

    c_array_free(&arr);
    c_array_free(&arr_ll);
    c_array_free(&arr_ul);
}

UTEST(test_long, c_array_msort) {
    c_array_long arr;

    c_array_init(&arr, 0);

    int t_long[] = {9, 4, 245, 1, -9};
    int ans_long[] = {-9, 1, 4, 9, 245};

    for (int i = 0; i < 5; i++) {
        c_array_push_back(&arr, t_long[i]);
    }

    c_array_msort(&arr);

    for (int i = 0; i < 5; i++) {
        ASSERT_EQ(arr.data[i], ans_long[i]);
    }

    c_array_free(&arr);
}

UTEST(test_long, c_array_sum) {
    c_array_long arr;
    c_array_long_long arr_ll;
    c_array_ulong arr_ul;

    c_array_init(&arr, 0);
    c_array_init(&arr_ll, 0);
    c_array_init(&arr_ul, 0);

    for (int i = 0; i < 9; i++) {
        c_array_push_back(&arr, 1);
        c_array_push_back(&arr_ll, 1);
        c_array_push_back(&arr_ul, 1);
    }

    long sum_long = c_array_sum(&arr);
    ASSERT_EQ(sum_long, 9);
    long long sum_long_long = c_array_sum(&arr_ll);
    ASSERT_EQ(sum_long_long, 9);
    unsigned long sum_ulong = c_array_sum(&arr_ul);
    ASSERT_EQ(sum_ulong, 9);

    c_array_free(&arr);
    c_array_free(&arr_ll);
    c_array_free(&arr_ul);
}

UTEST(test_long, c_array_min_max) {
    c_array_long arr;
    c_array_long_long arr_ll;
    c_array_ulong arr_ul;

    c_array_init(&arr, 0);
    c_array_init(&arr_ll, 0);
    c_array_init(&arr_ul, 0);

    long test_arr[] = {3, 7, 1, 9, 2, 8, 6};
    for (int i = 0; i < 7; i++) {
        c_array_push_back(&arr, test_arr[i]);
        c_array_push_back(&arr_ll, (long long)test_arr[i]);
        c_array_push_back(&arr_ul, (unsigned long)test_arr[i]);
    }
    long max_long = c_array_max(&arr);
    long min_long = c_array_min(&arr);
    long long max_long_long = c_array_max(&arr_ll);
    long long min_long_long = c_array_min(&arr_ll);
    unsigned long max_ulong = c_array_max(&arr_ul);
    unsigned long min_ulong = c_array_min(&arr_ul);
    ASSERT_EQ(max_long, 9);
    ASSERT_EQ(min_long, 1);
    ASSERT_EQ(max_long_long, 9);
    ASSERT_EQ(min_long_long, 1);
    ASSERT_EQ(max_ulong, 9);
    ASSERT_EQ(min_ulong, 1);

    c_array_push_back(&arr, 4);
    c_array_push_back(&arr_ll, 4);
    c_array_push_back(&arr_ul, 4);
    max_long = c_array_max(&arr);
    min_long = c_array_min(&arr);
    max_long_long = c_array_max(&arr_ll);
    min_long_long = c_array_min(&arr_ll);
    max_ulong = c_array_max(&arr_ul);
    min_ulong = c_array_min(&arr_ul);
    ASSERT_EQ(max_long, 9);
    ASSERT_EQ(min_long, 1);
    ASSERT_EQ(max_long_long, 9);
    ASSERT_EQ(min_long_long, 1);
    ASSERT_EQ(max_ulong, 9);
    ASSERT_EQ(min_ulong, 1);

    c_array_free(&arr);
    c_array_free(&arr_ll);
    c_array_free(&arr_ul);
}

UTEST(test_long, c_array_min_max_2) {
    c_array_long arr;
    c_array_long_long arr_ll;
    c_array_ulong arr_ul;

    c_array_init(&arr, 0);
    c_array_init(&arr_ll, 0);
    c_array_init(&arr_ul, 0);

    long test_arr[] = {3, 7, 1, 9, 2, 8, 678945};
    for (int i = 0; i < 7; i++) {
        c_array_push_back(&arr, test_arr[i]);
        c_array_push_back(&arr_ll, (long long)test_arr[i]);
        c_array_push_back(&arr_ul, (unsigned long)test_arr[i]);
    }
    long max_long = c_array_max(&arr);
    long min_long = c_array_min(&arr);
    long long max_long_long = c_array_max(&arr_ll);
    long long min_long_long = c_array_min(&arr_ll);
    unsigned long max_ulong = c_array_max(&arr_ul);
    unsigned long min_ulong = c_array_min(&arr_ul);
    ASSERT_EQ(max_long, 678945);
    ASSERT_EQ(min_long, 1);
    ASSERT_EQ(max_long_long, 678945);
    ASSERT_EQ(min_long_long, 1);
    ASSERT_EQ(max_ulong, 678945);
    ASSERT_EQ(min_ulong, 1);

    c_array_push_back(&arr, 4);
    c_array_push_back(&arr_ll, 4);
    c_array_push_back(&arr_ul, 4);
    max_long = c_array_max(&arr);
    min_long = c_array_min(&arr);
    max_long_long = c_array_max(&arr_ll);
    min_long_long = c_array_min(&arr_ll);
    max_ulong = c_array_max(&arr_ul);
    min_ulong = c_array_min(&arr_ul);
    ASSERT_EQ(max_long, 678945);
    ASSERT_EQ(min_long, 1);
    ASSERT_EQ(max_long_long, 678945);
    ASSERT_EQ(min_long_long, 1);
    ASSERT_EQ(max_ulong, 678945);
    ASSERT_EQ(min_ulong, 1);

    c_array_free(&arr);
    c_array_free(&arr_ll);
    c_array_free(&arr_ul);
}

UTEST(test_long, c_array_min_max_process) {
    c_array_long arr;
    c_array_long_long arr_ll;
    c_array_ulong arr_ul;

    c_array_init(&arr, 0);
    c_array_init(&arr_ll, 0);
    c_array_init(&arr_ul, 0);

    long test_arr[] = {3, 7, 1, 9, 2, 8, 60};
    for (int i = 0; i < 7; i++) {
        c_array_push_back(&arr, test_arr[i]);
        c_array_push_back(&arr_ll, (long long)test_arr[i]);
        c_array_push_back(&arr_ul, (unsigned long)test_arr[i]);
    }
    long* maxmin_long = c_array_maxmin(&arr);
    long long* maxmin_long_long = c_array_maxmin(&arr_ll);
    unsigned long* maxmin_ulong = c_array_maxmin(&arr_ul);
    ASSERT_EQ(maxmin_long[1], 60);
    ASSERT_EQ(maxmin_long[0], 1);
    ASSERT_EQ(maxmin_long_long[1], 60);
    ASSERT_EQ(maxmin_long_long[0], 1);
    ASSERT_EQ(maxmin_ulong[1], 60);
    ASSERT_EQ(maxmin_ulong[0], 1);

    c_array_push_back(&arr, 4);
    c_array_push_back(&arr_ll, 4);
    c_array_push_back(&arr_ul, 4);
    ASSERT_EQ(maxmin_long[1], 60);
    ASSERT_EQ(maxmin_long[0], 1);
    ASSERT_EQ(maxmin_ulong[1], 60);
    ASSERT_EQ(maxmin_ulong[0], 1);

    c_array_free(&arr);
    c_array_free(&arr_ll);
    c_array_free(&arr_ul);
    free(maxmin_long);
    free(maxmin_long_long);
    free(maxmin_ulong);
}

UTEST(test_long, c_array_statistic_original_func) {
    c_array_long arr;
    c_array_long_long arr_ll;
    c_array_ulong arr_ul;

    c_array_init(&arr, 0);
    c_array_init(&arr_ll, 0);
    c_array_init(&arr_ul, 0);

    for (int i = 1; i < 6; i++) {
        c_array_push_back(&arr, i);
        c_array_push_back(&arr_ll, i);
        c_array_push_back(&arr_ul, i);
    }

    long sum_long = c_array_sum_long(arr.data, arr.size);
    long long sum_long_long = c_array_sum_long_long(arr.data, arr.size);
    unsigned long sum_ulong = c_array_sum_ulong(arr.data, arr.size);

    mean_t mean_long = c_array_mean_long(arr.data, arr.size, sum_long);
    mean_t mean_long_long = c_array_mean_long_long(arr_ll.data, arr_ll.size, sum_long);
    mean_t mean_ulong = c_array_mean_ulong(arr_ul.data, arr_ul.size, sum_long);

    var_t var_long = c_array_var_long(arr.data, arr.size, sum_long);
    var_t var_long_long = c_array_var_long_long(arr_ll.data, arr_ll.size, sum_long);
    var_t var_ulong = c_array_var_ulong(arr_ul.data, arr_ul.size, sum_long);

    std_t std_long = c_array_std_long(arr.data, arr.size, sum_long);
    std_t std_long_long = c_array_std_long_long(arr_ll.data, arr_ll.size, sum_long);
    std_t std_ulong = c_array_std_ulong(arr_ul.data, arr_ul.size, sum_long);

    c_array_free(&arr);
    c_array_free(&arr_ll);
    c_array_free(&arr_ul);
}

UTEST(test_long, c_array_mean) {
    c_array_long arr;
    c_array_long_long arr_ll;
    c_array_ulong arr_ul;

    c_array_init(&arr, 0);
    c_array_init(&arr_ll, 0);
    c_array_init(&arr_ul, 0);

    for (int i = 0; i < 5; i++) {
        c_array_push_back(&arr, i);
        c_array_push_back(&arr_ll, i);
        c_array_push_back(&arr_ul, i);
    }

    mean_t mean_long = c_array_mean(&arr);
    mean_t mean_long_long = c_array_mean(&arr_ll);
    mean_t mean_ulong = c_array_mean(&arr_ul);

    ASSERT_NEAR(mean_long, 2, 0.01f);
    ASSERT_NEAR(mean_long_long, 2, 0.01f);
    ASSERT_NEAR(mean_ulong, 2, 0.01f);

    c_array_free(&arr);
    c_array_free(&arr_ll);
    c_array_free(&arr_ul);
}

UTEST(test_long, c_array_var_std) {
    c_array_long arr;
    c_array_long_long arr_ll;
    c_array_ulong arr_ul;

    c_array_init(&arr, 0);
    c_array_init(&arr_ll, 0);
    c_array_init(&arr_ul, 0);

    for (int i = 1; i < 6; i++) {
        c_array_push_back(&arr, i);
        c_array_push_back(&arr_ll, i);
        c_array_push_back(&arr_ul, i);
    }

    var_t var_long = c_array_var(&arr);
    var_t var_long_long = c_array_var(&arr_ll);
    var_t var_ulong = c_array_var(&arr_ul);

    ASSERT_NEAR(var_long, 2, 0.01f);
    ASSERT_NEAR(var_long_long, 2, 0.01f);
    ASSERT_NEAR(var_ulong, 2, 0.01f);

    std_t std_long = c_array_std(&arr);
    std_t std_long_long = c_array_std(&arr_ll);
    std_t std_ulong = c_array_std(&arr_ul);

    ASSERT_NEAR(std_long, 1.414213562, 0.01f);
    ASSERT_NEAR(std_long_long, 1.414213562, 0.01f);
    ASSERT_NEAR(std_ulong, 1.414213562, 0.01f);

    c_array_free(&arr);
    c_array_free(&arr_ll);
    c_array_free(&arr_ul);
}

UTEST(test_long, c_array_search) {
    c_array_long arr;
    c_array_ulong arr_u;
    c_array_long_long arr_ll;

    c_array_init(&arr, 0);
    c_array_init(&arr_u, 0);
    c_array_init(&arr_ll, 0);

    for (int i = 0; i < 6; i++) {
        c_array_push_back(&arr, i * 2);
        c_array_push_back(&arr_u, i * 2);
        c_array_push_back(&arr_ll, i * 3);
    }

    int* search_l = c_array_search(&arr, 6);
    int* search_ul = c_array_search(&arr_u, 6);
    int* search_ll = c_array_search(&arr_ll, 9);
    int* search_fail = c_array_search(&arr, 99957);

    ASSERT_EQ(search_l[0], 3);
    ASSERT_EQ(search_ul[0], 3);
    ASSERT_EQ(search_ll[0], 3);
    ASSERT_EQ(search_fail[0], -1);
    free(search_l);
    free(search_ul);
    free(search_ll);
    free(search_fail);

    c_array_free(&arr);
    c_array_free(&arr_u);
    c_array_free(&arr_ll);
}

UTEST(test_long, c_matrix_init) {
    c_matrix_long mat;
    c_matrix_init(&mat, 10, 6);
    ASSERT_EQ(mat.rows, 10);
    ASSERT_EQ(mat.cols, 6);

    c_matrix_long mat2;
    c_matrix_init(&mat2, 1000, 6000);
    ASSERT_EQ(mat2.rows, 1000);
    ASSERT_EQ(mat2.cols, 6000);

    c_matrix_double d_mat;
    c_matrix_init(&d_mat, 1000, 600);
    ASSERT_EQ(d_mat.rows, 1000);
    ASSERT_EQ(d_mat.cols, 600);

    c_matrix_long f_mat;
    c_matrix_init(&f_mat, 1512, 2231);
    ASSERT_EQ(f_mat.rows, 1512);
    ASSERT_EQ(f_mat.cols, 2231);

    c_matrix_free(&mat);
    c_matrix_free(&mat2);
    c_matrix_free(&d_mat);
    c_matrix_free(&f_mat);
}

UTEST(test_long, c_matrix_copy) {
    c_matrix_long mat1;
    c_matrix_long mat2;
    c_matrix_long_long mat_ll1;
    c_matrix_long_long mat_ll2;
    c_matrix_ulong mat_u1;
    c_matrix_ulong mat_u2;
    c_matrix_init(&mat1, 5, 10);
    c_matrix_init(&mat_ll1, 5, 10);
    c_matrix_init(&mat_u1, 5, 10);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            mat1.data[i][j] = i + j;
            mat_ll1.data[i][j] = i + j;
            mat_u1.data[i][j] = i + j;
        }
    }
    c_matrix_copy(&mat1, &mat2);
    c_matrix_copy(&mat_ll1, &mat_ll2);
    c_matrix_copy(&mat_u1, &mat_u2);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            ASSERT_EQ(mat1.data[i][j], mat2.data[i][j]);
            ASSERT_EQ(mat_ll1.data[i][j], mat_ll2.data[i][j]);
            ASSERT_EQ(mat_u1.data[i][j], mat_u2.data[i][j]);
        }
    }

    c_matrix_free(&mat1);
    c_matrix_free(&mat2);
    c_matrix_free(&mat_ll1);
    c_matrix_free(&mat_ll2);
    c_matrix_free(&mat_u1);
    c_matrix_free(&mat_u2);
}

UTEST(test_long, c_array_matrix_form) {
    c_array_long arr;
    c_array_long_long arr_ll;
    c_array_ulong arr_ul;
    c_array_init(&arr, 10);
    c_array_init(&arr_ll, 10);
    c_array_init(&arr_ul, 10);

    for (int i = 0; i < arr.size; i++) {
        arr.data[i] = i;
        arr_ll.data[i] = i;
        arr_ul.data[i] = i;
    }
    c_matrix_long mat = c_array_matrix_form(&arr, 2);
    c_matrix_long_long mat_ll = c_array_matrix_form(&arr_ll, 2);
    c_matrix_ulong mat_ul = c_array_matrix_form(&arr_ul, 2);
    ASSERT_EQ(mat.rows, 2);
    ASSERT_EQ(mat.cols, 5);
    ASSERT_EQ(mat_ll.rows, 2);
    ASSERT_EQ(mat_ll.cols, 5);
    ASSERT_EQ(mat_ul.rows, 2);
    ASSERT_EQ(mat_ul.cols, 5);
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            ASSERT_EQ(mat.data[i][j], i * mat.cols + j);
            ASSERT_EQ(mat_ll.data[i][j], i * mat.cols + j);
            ASSERT_EQ(mat_ul.data[i][j], i * mat.cols + j);
        }
    }

    c_matrix_free(&mat);
    c_matrix_free(&mat_ll);
    c_matrix_free(&mat_ul);
    c_array_free(&arr);
    c_array_free(&arr_ll);
    c_array_free(&arr_ul);
}

UTEST(test_long, c_matrix_flatten) {
    c_matrix_long mat;
    c_matrix_long_long mat_ll;
    c_matrix_ulong mat_ul;
    c_matrix_init(&mat, 10, 6);
    c_matrix_init(&mat_ll, 10, 6);
    c_matrix_init(&mat_ul, 10, 6);
    ASSERT_EQ(mat.rows, 10);
    ASSERT_EQ(mat.cols, 6);

    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            mat.data[i][j] = i * mat.cols + j;
            mat_ll.data[i][j] = i * mat.cols + j;
            mat_ul.data[i][j] = i * mat.cols + j;
        }
    }
    c_array_long arr = c_matrix_flatten(&mat);
    c_array_long_long arr_ll = c_matrix_flatten(&mat_ll);
    c_array_ulong arr_ul = c_matrix_flatten(&mat_ul);
    for (int i = 0; i < mat.rows * mat.cols; i++) {
        ASSERT_EQ(arr.data[i], i);
        ASSERT_EQ(arr_ll.data[i], i);
        ASSERT_EQ(arr_ul.data[i], i);
    }

    c_matrix_free(&mat);
    c_matrix_free(&mat_ll);
    c_matrix_free(&mat_ul);
    c_array_free(&arr);
    c_array_free(&arr_ll);
    c_array_free(&arr_ul);
}

UTEST(test_long, c_matrix_reshape) {
    c_matrix_long mat;
    c_matrix_long_long mat_ll;
    c_matrix_ulong mat_u;
    c_matrix_init(&mat, 10, 6);
    c_matrix_init(&mat_ll, 10, 6);
    c_matrix_init(&mat_u, 10, 6);
    ASSERT_EQ(mat.rows, 10);
    ASSERT_EQ(mat.cols, 6);
    ASSERT_EQ(mat_ll.rows, 10);
    ASSERT_EQ(mat_ll.cols, 6);
    ASSERT_EQ(mat_u.rows, 10);
    ASSERT_EQ(mat_u.cols, 6);
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            mat.data[i][j] = i * mat.cols + j;
            mat_ll.data[i][j] = i * mat.cols + j;
            mat_u.data[i][j] = i * mat.cols + j;
        }
    }
    c_matrix_long mat2 = c_matrix_reshape(&mat, 6, 10);
    c_matrix_long_long mat2_ll = c_matrix_reshape(&mat_ll, 6, 10);
    c_matrix_ulong mat2_u = c_matrix_reshape(&mat_u, 6, 10);
    ASSERT_EQ(mat2.rows, 6);
    ASSERT_EQ(mat2.cols, 10);
    ASSERT_EQ(mat2_u.rows, 6);
    ASSERT_EQ(mat2_u.cols, 10);
    ASSERT_EQ(mat2_ll.rows, 6);
    ASSERT_EQ(mat2_ll.cols, 10);

    c_matrix_free(&mat2);
    c_matrix_free(&mat2_ll);
    c_matrix_free(&mat2_u);
}

UTEST(test_long, c_matrix_sum) {
    c_matrix_long mat;
    c_matrix_long_long mat_ll;
    c_matrix_ulong mat_u;

    c_matrix_init(&mat, 5, 2);
    c_matrix_init(&mat_ll, 5, 2);
    c_matrix_init(&mat_u, 5, 2);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 2; j++) {
            mat.data[i][j] = i + j;
            mat_u.data[i][j] = 1;
            mat_ll.data[i][j] = 2;
        }
    }

    long sum_long = c_matrix_sum(&mat);
    ASSERT_EQ(sum_long, 25);
    unsigned long sum_ulong = c_matrix_sum(&mat_u);
    ASSERT_EQ(sum_ulong, 10);
    long long sum_long_long = c_matrix_sum(&mat_ll);
    ASSERT_EQ(sum_long_long, 20);

    c_matrix_free(&mat);
    c_matrix_free(&mat_u);
    c_matrix_free(&mat_ll);
}

UTEST(test_long, c_matrix_mean) {
    c_matrix_long mat;
    c_matrix_ulong mat_u;
    c_matrix_long_long mat_ll;

    c_matrix_init(&mat, 5, 2);
    c_matrix_init(&mat_u, 5, 2);
    c_matrix_init(&mat_ll, 5, 2);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 2; j++) {
            mat.data[i][j] = 2;
            mat_u.data[i][j] = 1;
            mat_ll.data[i][j] = 1024;
        }
    }

    mean_t mean_long = c_matrix_mean(&mat);
    ASSERT_NEAR(mean_long, 2, 0.01f);
    mean_t mean_ulong = c_matrix_mean(&mat_u);
    ASSERT_NEAR(mean_ulong, 1, 0.01f);
    mean_t mean_long_long = c_matrix_mean(&mat_ll);
    ASSERT_NEAR(mean_long_long, 1024, 0.01f);

    c_matrix_free(&mat);
    c_matrix_free(&mat_u);
    c_matrix_free(&mat_ll);
}

UTEST(test_long, c_matrix_max_min) {
    c_matrix_long mat;
    c_matrix_ulong mat_ul;
    c_matrix_long_long mat_ll;

    c_matrix_init(&mat, 2, 2);
    c_matrix_init(&mat_ul, 2, 2);
    c_matrix_init(&mat_ll, 2, 2);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            mat.data[i][j] = i + j;
            mat_ul.data[i][j] = i + j;
            mat_ll.data[i][j] = 2 + j;
        }
    }

    long max = c_matrix_max(&mat);
    unsigned long max_ul = c_matrix_max(&mat_ul);
    long min = c_matrix_min(&mat);
    unsigned long min_ul = c_matrix_min(&mat_ul);
    long long min_ll = c_matrix_min(&mat_ll);
    long long max_ll = c_matrix_max(&mat_ll);
    ASSERT_EQ(max, 2);
    ASSERT_EQ(max_ul, 2);
    ASSERT_EQ(min, 0);
    ASSERT_EQ(min_ul, 0);
    ASSERT_EQ(max_ll, 3);
    ASSERT_EQ(min_ll, 2);

    c_matrix_free(&mat);
    c_matrix_free(&mat_ul);
    c_matrix_free(&mat_ll);
}

UTEST(test_long, c_matrix_var_std) {
    c_matrix_long mat;
    c_matrix_long_long mat_ll;
    c_matrix_ulong mat_ul;

    c_matrix_init(&mat, 3, 3);
    c_matrix_init(&mat_ul, 3, 3);
    c_matrix_init(&mat_ll, 3, 3);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int val = i + j;
            mat.data[i][j] = val;
            mat_ul.data[i][j] = val;
            mat_ll.data[i][j] = 12456 * i + val;
        }
    }

    var_t var_long = c_matrix_var(&mat);
    var_t var_ulong = c_matrix_var(&mat_ul);
    var_t var_long_long = c_matrix_var(&mat_ll);

    ASSERT_NEAR(var_long, 1.3333333, 0.01f);
    ASSERT_NEAR(var_ulong, 1.333333, 0.01f);
    ASSERT_NEAR(var_long_long, 103451233.3333333, 0.01f);

    std_t std_long = c_matrix_std(&mat);
    std_t std_ulong = c_matrix_std(&mat_ul);
    std_t std_long_long = c_matrix_std(&mat_ll);
    ASSERT_NEAR(std_long, 1.154701, 0.01f);
    ASSERT_NEAR(std_ulong, 1.154701, 0.01f);
    ASSERT_NEAR(std_long_long, 10171.097941, 0.01f);

    c_matrix_free(&mat);
    c_matrix_free(&mat_ul);
    c_matrix_free(&mat_ll);
}

UTEST (test_long, c_matrix_print_and_printf) {
    c_matrix_long mat;

    c_matrix_init(&mat, 5, 1);

    for (int i = 0; i < 5; i++) {
        mat.data[i][0] = 10;
    }

    c_matrix_print(mat);
    c_matrix_printf(mat, "%ld");

    c_matrix_free(&mat);
}

UTEST_MAIN();
