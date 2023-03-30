/*
    Copyright (c) 2022 Jian Yu, Chen
    License: MIT License
    file   : test_mt.c

    The latest version is avaliable at:
    https://github.com/Zncl2222/c_array_tools
*/


# include <stdio.h>
# include "../src/c_array.h"
# include "utest.h"


UTEST(test, mt19937_generate) {
    mt19937_state state1;
    mt19937_state state2;
    unsigned int seed = 12345;
    mt19937_init(&state1, seed);
    mt19937_init(&state2, seed);

    for (int i = 0; i < 10; i++) {
        unsigned long num1 = mt19937_generate(&state1);
        unsigned long num2 = mt19937_generate(&state2);
        ASSERT_EQ(num1, num2);
    }

    unsigned int prev;
    unsigned long num1 = mt19937_generate(&state1);

    for (int i = 0; i < 10; i++) {
        prev = num1;
        num1 = mt19937_generate(&state1);
        ASSERT_NE(prev, num1);
    }
}

UTEST(test, mt19937_get_int32_range) {
    mt19937_state state;
    unsigned int seed = 12345;
    mt19937_init(&state, seed);

    for (int i = 0; i < 1000; i++) {
        int num1 = mt19937_get_int32_range(&state, -10, 0);
        ASSERT_TRUE((num1 <= 0 & num1 >= -10));
    }

    for (int i = 0; i < 1000; i++) {
        int num1 = mt19937_get_int32_range(&state, -10, 20);
        ASSERT_TRUE((num1 <= 20 & num1 >= -10));
    }

    for (int i = 0; i < 1000; i++) {
        int num1 = mt19937_get_int32_range(&state, 10, 20);
        ASSERT_TRUE((num1 <= 20 & num1 >= 10));
    }
}

UTEST(test, mt19937_get_float) {
    mt19937_state state;
    unsigned int seed = 12345;
    mt19937_init(&state, seed);

    for (int i = 0; i < 1000; i++) {
        float num1 = mt19937_get_float(&state);
        ASSERT_TRUE((num1 < 1 & num1 >= 0));
    }

    for (int i = 0; i < 1000; i++) {
        float num1 = mt19937_get_float_range(&state, -2.56, 0);
        ASSERT_TRUE((num1 < 0 & num1 >= -2.56));
    }

    for (int i = 0; i < 1000; i++) {
        float num1 = mt19937_get_float_range(&state, -2.56, 2.56);
        ASSERT_TRUE((num1 < 2.56 & num1 >= -2.56));
    }

    for (int i = 0; i < 1000; i++) {
        float num1 = mt19937_get_float_range(&state, 9.15, 9999);
        ASSERT_TRUE((num1 < 9999 & num1 >= 9.15));
    }
}

UTEST(test, mt19937_get_double) {
    mt19937_state state;
    unsigned int seed = 12345;
    mt19937_init(&state, seed);

    for (int i = 0; i < 1000; i++) {
        double num1 = mt19937_get_double(&state);
        ASSERT_TRUE((num1 < 1 & num1 >= 0));
    }

    for (int i = 0; i < 1000; i++) {
        double num1 = mt19937_get_double_range(&state, -2.56, 0);
        ASSERT_TRUE((num1 < 0 & num1 >= -2.56));
    }

    for (int i = 0; i < 1000; i++) {
        double num1 = mt19937_get_double_range(&state, -2.56, 2.56);
        ASSERT_TRUE((num1 < 2.56 & num1 >= -2.56));
    }

    for (int i = 0; i < 1000; i++) {
        double num1 = mt19937_get_double_range(&state, 9.15, 9999);
        ASSERT_TRUE((num1 < 9999 & num1 >= 9.15));
    }
}

UTEST(test, random_normal) {
    mt19937_state state;
    unsigned int seed = 12345;
    mt19937_init(&state, seed);
    for (int i = 0; i < 1000; i++) {
        double num = random_normal(&state);
        ASSERT_TRUE((num < 6 & num >= -6));
    }
}

UTEST(test, c_array_randnormal) {
    mt19937_state state;
    unsigned int seed = 12345;
    mt19937_init(&state, seed);

    c_array_double array;
    c_array_randnormal(&array, 10000, &state);
    ASSERT_EQ(array.size, 10000);
    ASSERT_EQ(array.capacity, 10000);
    for (int i = 0; i < 10000; i++) {
        ASSERT_TRUE((array.data[i] < 6 & array.data[i] >= -6));
    }
    ASSERT_NEAR(c_array_mean(&array), 0, 0.01f);
    ASSERT_NEAR(c_array_std(&array), 1, 0.01f);
    c_array_free(&array);
}

UTEST(test, c_array_random_range) {
    mt19937_state state;
    unsigned int seed = 12345;
    mt19937_init(&state, seed);

    c_array_double array_d;
    c_array_rand_range(&array_d, 5000, mt19937_get_double_range(&state, 2.65, 5.5));
    ASSERT_EQ(array_d.size, 5000);
    ASSERT_EQ(array_d.capacity, 5000);
    for (int i = 0; i < 5000; i++) {
        ASSERT_TRUE((array_d.data[i] < 5.5 & array_d.data[i] >= 2.65));
    }
    ASSERT_NEAR(c_array_mean(&array_d), (5.5 + 2.65) / 2, 0.01f);

    c_array_float array_f;
    c_array_rand_range(&array_f, 2000, mt19937_get_float_range(&state, -5.99, 5.5));
    ASSERT_EQ(array_f.size, 2000);
    ASSERT_EQ(array_f.capacity, 2000);
    for (int i = 0; i < 2000; i++) {
        ASSERT_TRUE((array_f.data[i] < 5.5 & array_f.data[i] >= -5.99));
    }
    ASSERT_NEAR(c_array_mean(&array_f), (5.5 - 5.99) / 2, 0.01f);

    c_array_int array;
    c_array_rand_range(&array, 10000, mt19937_get_double_range(&state, -5, 5));
    ASSERT_EQ(array.size, 10000);
    ASSERT_EQ(array.capacity, 10000);
    for (int i = 0; i < 10000; i++) {
        ASSERT_TRUE((array.data[i] < 5 & array.data[i] >= -5));
    }
    ASSERT_NEAR(c_array_mean(&array), 0, 0.01f);

    c_array_free(&array);
    c_array_free(&array_d);
    c_array_free(&array_f);
}

UTEST_MAIN();
