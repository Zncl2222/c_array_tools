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

UTEST_MAIN();
