# include <stdio.h>
# include "../src/c_array.h"
# include "utest.h"

UTEST(test, c_array_init) {
    c_array(int) arr;
    c_array_init(&arr, int, 0);
    ASSERT_TRUE(arr.capacity == 0);
    ASSERT_TRUE(arr.length == 0);

    c_array(int) arr2;
    c_array_init(&arr2, int, 20);
    ASSERT_TRUE(arr2.capacity == 20);
    ASSERT_TRUE(arr2.length == 20);

    c_array(float) f_arr;
    c_array_init(&f_arr, float, 0);
    ASSERT_TRUE(f_arr.capacity == 0);
    ASSERT_TRUE(f_arr.length == 0);

    c_array(float) f_arr2;
    c_array_init(&f_arr2, float, 20);
    ASSERT_TRUE(f_arr2.capacity == 20);
    ASSERT_TRUE(f_arr2.length == 20);

    c_array(double) d_arr;
    c_array_init(&d_arr, double, 0);
    ASSERT_TRUE(d_arr.capacity == 0);
    ASSERT_TRUE(d_arr.length == 0);

    c_array(double) d_arr2;
    c_array_init(&d_arr2, double, 20);
    ASSERT_TRUE(d_arr2.capacity == 20);
    ASSERT_TRUE(d_arr2.length == 20);

    c_array_free(&arr);
    c_array_free(&arr2);
    c_array_free(&f_arr);
    c_array_free(&f_arr2);
    c_array_free(&d_arr);
    c_array_free(&d_arr2);
}

UTEST(test, c_array_assign) {
    c_array(int) arr;
    c_array_init(&arr, int, 3);

    c_array_assign(&arr, 2, -99);
    ASSERT_EQ(arr.data[2], -99);

    c_array_assign(&arr, 1, 10);
    ASSERT_EQ(arr.data[1], 10);

    c_array_assign(&arr, 1, 110);
    ASSERT_EQ(arr.data[1], 110);

    c_array_free(&arr);
}

UTEST(test, c_array_resize) {
    c_array(int) arr;
    c_array_init(&arr, int, 3);
    ASSERT_EQ(arr.capacity, 3);
    ASSERT_EQ(arr.length, 3);

    c_array_resize(&arr, 15);
    ASSERT_EQ(arr.capacity, 15);
    ASSERT_EQ(arr.length, 3);

    c_array_resize(&arr, 2);
    ASSERT_EQ(arr.capacity, 2);

    c_array_free(&arr);
}

UTEST(test, c_array_set_length) {
    c_array(int) arr;
    c_array_init(&arr, int, 30);
    ASSERT_EQ(arr.capacity, 30);
    ASSERT_EQ(arr.length, 30);

    c_array_set_length(&arr, 22);
    ASSERT_EQ(arr.capacity, 30);
    ASSERT_EQ(arr.length, 22);

    c_array_resize(&arr, 90);
    c_array_set_length(&arr, 70);
    ASSERT_EQ(arr.capacity, 90);
    ASSERT_EQ(arr.length, 70);

    c_array_set_length(&arr, 90);
    ASSERT_EQ(arr.capacity, 90);
    ASSERT_EQ(arr.length, 90);

    c_array_free(&arr);
}

UTEST(test, c_array_byte) {
    c_array(int) arr;
    c_array_init(&arr, int, 1);
    c_array_assign(&arr, 0, 15);
    ASSERT_EQ(c_array_byte(&arr), 4);

    c_array(float) f_arr;
    c_array_init(&f_arr, float, 1);
    c_array_assign(&f_arr, 0, 15.23);
    ASSERT_EQ(c_array_byte(&f_arr), 4);

    c_array(double) d_arr;
    c_array_init(&d_arr, double, 1);
    c_array_assign(&d_arr, 0, 155.2348);
    ASSERT_EQ(c_array_byte(&d_arr), 8);

    c_array_free(&arr);
    c_array_free(&f_arr);
    c_array_free(&d_arr);
}

UTEST(test, c_array_empty) {
    c_array(int) arr;
    c_array_init(&arr, int, 0);
    ASSERT_EQ(c_array_empty(&arr), 1);

    c_array_resize(&arr, 10);
    ASSERT_EQ(c_array_empty(&arr), 1);

    c_array_set_length(&arr, 10);
    ASSERT_EQ(c_array_empty(&arr), 0);

    c_array_free(&arr);
}

UTEST(test, c_array_push_back) {
    c_array(int) arr;
    c_array_init(&arr, int, 0);

    c_array_push_back(&arr, 15);
    ASSERT_EQ(arr.capacity, 2);
    ASSERT_EQ(arr.length, 1);

    c_array_push_back(&arr, 29);
    ASSERT_EQ(arr.capacity, 2);
    ASSERT_EQ(arr.length, 2);

    c_array_push_back(&arr, 55);
    ASSERT_EQ(arr.capacity, 4);
    ASSERT_EQ(arr.length, 3);

    c_array_push_back(&arr, 66);
    ASSERT_EQ(arr.capacity, 4);
    ASSERT_EQ(arr.length, 4);

    c_array_push_back(&arr, -5);
    ASSERT_EQ(arr.capacity, 8);
    ASSERT_EQ(arr.length, 5);

    ASSERT_EQ(arr.data[0], 15);
    ASSERT_EQ(arr.data[1], 29);
    ASSERT_EQ(arr.data[2], 55);
    ASSERT_EQ(arr.data[3], 66);
    ASSERT_EQ(arr.data[4], -5);

    c_array_free(&arr);
}

UTEST(test, c_array_reverse) {
    c_array(int) arr;
    c_array_init(&arr, int, 0);

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
    c_array(int) arr;
    c_array_init(&arr, int, 0);

    c_array_push_back(&arr, 15);
    c_array_push_back(&arr, 20);
    ASSERT_EQ(arr.length, 2);

    c_array_pop_back(&arr);
    ASSERT_EQ(arr.data[1], 0);
    ASSERT_EQ(arr.length, 1);

    c_array_free(&arr);
}

UTEST(test, c_array_insert) {
    c_array(int) arr;
    c_array_init(&arr, int, 0);

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
    ASSERT_EQ(arr.length, 6);

    // insert at head
    c_array_insert(&arr, 0, 99999);
    ASSERT_EQ(arr.data[0], 99999);
    ASSERT_EQ(arr.data[1], 15);
    ASSERT_EQ(arr.data[2], -25);
    ASSERT_EQ(arr.data[3], 29);
    ASSERT_EQ(arr.data[4], 55);
    ASSERT_EQ(arr.data[5], 66);
    ASSERT_EQ(arr.data[6], -5);
    ASSERT_EQ(arr.length, 7);

    // insert at tail
    c_array_insert(&arr, 6, 2151);
    ASSERT_EQ(arr.data[6], 2151);
    ASSERT_EQ(arr.data[7], -5);
    ASSERT_EQ(arr.length, 8);

    c_array_free(&arr);
}

UTEST(test, c_array_remove) {
    c_array(int) arr;
    c_array_init(&arr, int, 0);

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
    ASSERT_EQ(arr.length, 5);

    c_array_remove(&arr, 1);
    ASSERT_EQ(arr.data[0], 15);
    ASSERT_EQ(arr.data[1], 55);
    ASSERT_EQ(arr.data[2], 66);
    ASSERT_EQ(arr.data[3], -5);
    ASSERT_EQ(arr.length, 4);

    c_array_free(&arr);
}

UTEST(test, c_matrix_init) {
    c_matrix(int) mat;
    c_matrix_init(&mat, int, 10, 6);
    ASSERT_EQ(mat.rows, 10);
    ASSERT_EQ(mat.cols, 6);

    c_matrix(int) mat2;
    c_matrix_init(&mat2, int, 1000, 6000);
    ASSERT_EQ(mat2.rows, 1000);
    ASSERT_EQ(mat2.cols, 6000);

    c_matrix(double) d_mat;
    c_matrix_init(&d_mat, double, 10000, 6000);
    ASSERT_EQ(d_mat.rows, 10000);
    ASSERT_EQ(d_mat.cols, 6000);

    c_matrix(float) f_mat;
    c_matrix_init(&f_mat, float, 15112, 22131);
    ASSERT_EQ(f_mat.rows, 15112);
    ASSERT_EQ(f_mat.cols, 22131);

    c_matrix_free(&mat);
    c_matrix_free(&mat2);
    c_matrix_free(&d_mat);
    c_matrix_free(&f_mat);
}

UTEST_MAIN();
