/*
    Copyright (c) 2022 Jian Yu, Chen
    License: MIT License
    Version: v1.3.3
    file   : c_array.c

    The latest version is avaliable at:
    https://github.com/Zncl2222/c_array_tools
*/

# include "c_array.h"

/*            This is an implementation of c_array extension            */
/* -------------------------------------------------------------------- */
/*                          Array Min and Max                           */

short c_array_max_short(short* arr, int size) {
    c_array_maxmin_process(arr, size, "max")
}

unsigned short c_array_max_ushort(unsigned short* arr, int size) {
    c_array_maxmin_process(arr, size, "max")
}

int c_array_max_int(int* arr, int size) {
    c_array_maxmin_process(arr, size, "max")
}

unsigned int c_array_max_uint(unsigned int* arr, int size) {
    c_array_maxmin_process(arr, size, "max")
}

long c_array_max_long(long* arr, int size) {
    c_array_maxmin_process(arr, size, "max")
}

unsigned long c_array_max_ulong(unsigned long* arr, int size) {
    c_array_maxmin_process(arr, size, "max")
}

long long c_array_max_long_long(long long* arr, int size) {
    c_array_maxmin_process(arr, size, "max")
}

float c_array_max_float(float* arr, int size) {
    c_array_maxmin_process(arr, size, "max")
}

double c_array_max_double(double* arr, int size) {
    c_array_maxmin_process(arr, size, "max")
}

long double c_array_max_long_double(long double* arr, int size) {
    c_array_maxmin_process(arr, size, "max")
}

short c_array_min_short(short* arr, int size) {
    c_array_maxmin_process(arr, size, "min")
}

unsigned short c_array_min_ushort(unsigned short* arr, int size) {
    c_array_maxmin_process(arr, size, "min")
}

int c_array_min_int(int* arr, int size) {
    c_array_maxmin_process(arr, size, "min")
}

unsigned int c_array_min_uint(unsigned int* arr, int size) {
    c_array_maxmin_process(arr, size, "min")
}

long c_array_min_long(long* arr, int size) {
    c_array_maxmin_process(arr, size, "min")
}

unsigned long c_array_min_ulong(unsigned long* arr, int size) {
    c_array_maxmin_process(arr, size, "min")
}

long long c_array_min_long_long(long long* arr, int size) {
    c_array_maxmin_process(arr, size, "min")
}

float c_array_min_float(float* arr, int size) {
    c_array_maxmin_process(arr, size, "min")
}

double c_array_min_double(double* arr, int size) {
    c_array_maxmin_process(arr, size, "min")
}

long double c_array_min_long_double(long double* arr, int size) {
    c_array_maxmin_process(arr, size, "min")
}

/* -------------------------------------------------------------------- */
/*                     Array standard deviation                         */

var_t c_array_var_short(const short* arr, int size, mean_t mean) {
    c_array_var_process(arr, size, mean)
    return (var / size);
}

var_t c_array_var_ushort(const unsigned short* arr, int size, mean_t mean) {
    c_array_var_process(arr, size, mean)
    return (var / size);
}

var_t c_array_var_int(const int* arr, int size, mean_t mean) {
    c_array_var_process(arr, size, mean)
    return (var / size);
}

var_t c_array_var_uint(const unsigned int* arr, int size, mean_t mean) {
    c_array_var_process(arr, size, mean)
    return (var / size);
}

var_t c_array_var_long(const long* arr, int size, mean_t mean) {
    c_array_var_process(arr, size, mean)
    return (var / size);
}

var_t c_array_var_ulong(const unsigned long* arr, int size, mean_t mean) {
    c_array_var_process(arr, size, mean)
    return (var / size);
}

var_t c_array_var_long_long(const long long* arr, int size, mean_t mean) {
    c_array_var_process(arr, size, mean)
    return (var / size);
}

var_t c_array_var_float(const float* arr, int size, mean_t mean) {
    c_array_var_process(arr, size, mean)
    return (var / size);
}

var_t c_array_var_double(const double* arr, int size, mean_t mean) {
    c_array_var_process(arr, size, mean)
    return (var / size);
}

var_t c_array_var_long_double(const long double* arr, int size, mean_t mean) {
    c_array_var_process(arr, size, mean)
    return (var / size);
}

std_t c_array_std_short(const short* arr, int size, mean_t mean) {
    c_array_var_process(arr, size, mean)
    return sqrt(var / size);
}

std_t c_array_std_ushort(const unsigned short* arr, int size, mean_t mean) {
    c_array_var_process(arr, size, mean)
    return sqrt(var / size);
}

std_t c_array_std_int(const int* arr, int size, mean_t mean) {
    c_array_var_process(arr, size, mean)
    return sqrt(var / size);
}

std_t c_array_std_uint(const unsigned int* arr, int size, mean_t mean) {
    c_array_var_process(arr, size, mean)
    return sqrt(var / size);
}

std_t c_array_std_long(const long* arr, int size, mean_t mean) {
    c_array_var_process(arr, size, mean)
    return sqrt(var / size);
}

std_t c_array_std_ulong(const unsigned long* arr, int size, mean_t mean) {
    c_array_var_process(arr, size, mean)
    return sqrt(var / size);
}

std_t c_array_std_long_long(const long long* arr, int size, mean_t mean) {
    c_array_var_process(arr, size, mean)
    return sqrt(var / size);
}

std_t c_array_std_float(const float* arr, int size, mean_t mean) {
    c_array_var_process(arr, size, mean)
    return sqrt(var / size);
}

std_t c_array_std_double(const double* arr, int size, mean_t mean) {
    c_array_var_process(arr, size, mean)
    return sqrt(var / size);
}

std_t c_array_std_long_double(const long double* arr, int size, mean_t mean) {
    c_array_var_process(arr, size, mean)
    return sqrt(var / size);
}

/* -------------------------------------------------------------------- */
/*                          Array mean value                            */

mean_t c_array_mean_short(const short* arr, int size, short sum) {
    c_array_mean_process(arr, size, sum)
}

mean_t c_array_mean_ushort(const unsigned short* arr, int size, unsigned short sum) {
    c_array_mean_process(arr, size, sum)
}

mean_t c_array_mean_int(const int* arr, int size, int sum) {
    c_array_mean_process(arr, size, sum)
}

mean_t c_array_mean_uint(const unsigned int* arr, int size, unsigned int sum) {
    c_array_mean_process(arr, size, sum)
}

mean_t c_array_mean_long(const long* arr, int size, long sum) {
    c_array_mean_process(arr, size, sum)
}

mean_t c_array_mean_ulong(const unsigned long* arr, int size, unsigned long sum) {
    c_array_mean_process(arr, size, sum)
}

mean_t c_array_mean_long_long(const long long* arr, int size, long long sum) {
    c_array_mean_process(arr, size, sum)
}

mean_t c_array_mean_float(const float* arr, int size, float sum) {
    c_array_mean_process(arr, size, sum)
}

mean_t c_array_mean_double(const double* arr, int size, double sum) {
    c_array_mean_process(arr, size, sum)
}

mean_t c_array_mean_long_double(const long double* arr, int size, long double sum) {
    c_array_mean_process(arr, size, sum)
}

/* -------------------------------------------------------------------- */
/*                              Array Sum                               */

short c_array_sum_short(short* arr, int size) {
    c_array_sum_process(arr, size)
}

unsigned short c_array_sum_ushort(unsigned short* arr, int size) {
    c_array_sum_process(arr, size)
}

int c_array_sum_int(int* arr, int size) {
    c_array_sum_process(arr, size)
}

unsigned int c_array_sum_uint(unsigned int* arr, int size) {
    c_array_sum_process(arr, size)
}

long c_array_sum_long(long* arr, int size) {
    c_array_sum_process(arr, size)
}

unsigned long c_array_sum_ulong(unsigned long* arr, int size) {
    c_array_sum_process(arr, size)
}

long long c_array_sum_long_long(long long* arr, int size) {
    c_array_sum_process(arr, size)
}

float c_array_sum_float(float* arr, int size) {
    c_array_sum_process(arr, size)
}

double c_array_sum_double(double* arr, int size) {
    c_array_sum_process(arr, size)
}

long double c_array_sum_long_double(long double* arr, int size) {
    c_array_sum_process(arr, size)
}

/* -------------------------------------------------------------------- */
/*                           Array qsort                                */

int cmpfunc_short(const void* a, const void* b) {
    return (*(const short*)a - *(const short*)b);
}

int cmpfunc_ushort(const void* a, const void* b) {
    return (*(const unsigned short*)a - *(const unsigned short*)b);
}

int cmpfunc_int(const void* a, const void* b) {
    return (*(const int*)a - *(const int*)b);
}

int cmpfunc_uint(const void* a, const void* b) {
    return (*(const unsigned int*)a - *(const unsigned int*)b);
}

int cmpfunc_long(const void* a, const void* b) {
    return (*(const long*)a - *(const long*)b);
}

int cmpfunc_ulong(const void* a, const void* b) {
    return (*(const unsigned long*)a - *(const unsigned long*)b);
}

int cmpfunc_long_long(const void* a, const void* b) {
    return (*(const long long*)a - *(const long long*)b);
}

int cmpfunc_float(const void* a, const void* b) {
    float ret = *(const float*)a - *(const float*)b;
    if (ret > 0) {
        return 1;
    } else if (ret < 0) {
        return -1;
    }
    return 0;
}

int cmpfunc_double(const void* a, const void* b) {
    double ret = *(const double*)a - *(const double*)b;
    if (ret > 0) {
        return 1;
    } else if (ret < 0) {
        return -1;
    }
    return 0;
}

int cmpfunc_long_double(const void* a, const void* b) {
    long double ret = *(const long double*)a - *(const long double*)b;
    if (ret > 0) {
        return 1;
    } else if (ret < 0) {
        return -1;
    }
    return 0;
}

/* -------------------------------------------------------------------- */
/*                          Matrix Form                                 */

c_matrix_short c_array_matrix_form_short(const c_array_short* arr, int n_row){
    c_matrix_short mat;
    c_array_matrix_form_init(arr, &mat, n_row);
    c_array_matrix_form_process(&mat, arr);
    return mat;
}

c_matrix_ushort c_array_matrix_form_ushort(const c_array_ushort* arr, int n_row){
    c_matrix_ushort mat;
    c_array_matrix_form_init(arr, &mat, n_row);
    c_array_matrix_form_process(&mat, arr);
    return mat;
}

c_matrix_int c_array_matrix_form_int(const c_array_int* arr, int n_row){
    c_matrix_int mat;
    c_array_matrix_form_init(arr, &mat, n_row);
    return mat;
}

c_matrix_uint c_array_matrix_form_uint(const c_array_uint* arr, int n_row){
    c_matrix_uint mat;
    c_array_matrix_form_init(arr, &mat, n_row);
    c_array_matrix_form_process(&mat, arr);
    return mat;
}

c_matrix_long c_array_matrix_form_long(const c_array_long* arr, int n_row){
    c_matrix_long mat;
    c_array_matrix_form_init(arr, &mat, n_row);
    c_array_matrix_form_process(&mat, arr);
    return mat;
}

c_matrix_long_long c_array_matrix_form_long_long(const c_array_long_long* arr, int n_row){
    c_matrix_long_long mat;
    c_array_matrix_form_init(arr, &mat, n_row);
    c_array_matrix_form_process(&mat, arr);
    return mat;
}

c_matrix_ulong c_array_matrix_form_ulong(const c_array_ulong* arr, int n_row){
    c_matrix_ulong mat;
    c_array_matrix_form_init(arr, &mat, n_row);
    c_array_matrix_form_process(&mat, arr);
    return mat;
}

c_matrix_float c_array_matrix_form_float(const c_array_float* arr, int n_row){
    c_matrix_float mat;
    c_array_matrix_form_init(arr, &mat, n_row);
    c_array_matrix_form_process(&mat, arr);
    return mat;
}

c_matrix_double c_array_matrix_form_double(const c_array_double* arr, int n_row){
    c_matrix_double mat;
    c_array_matrix_form_init(arr, &mat, n_row);
    c_array_matrix_form_process(&mat, arr);
    return mat;
}

c_matrix_ldouble c_array_matrix_form_ldouble(const c_array_ldouble* arr, int n_row){
    c_matrix_ldouble mat;
    c_array_matrix_form_init(arr, &mat, n_row);
    c_array_matrix_form_process(&mat, arr);
    return mat;
}

/* -------------------------------------------------------------------- */
/*                         Matrix Flatten                               */

c_array_short c_matrix_flatten_short(const c_matrix_short* mat) {
    c_array_short arr;
    c_matrix_flatten_init(mat, &arr);
    c_matrix_flatten_process(mat, &arr);
    return arr;
}

c_array_ushort c_matrix_flatten_ushort(const c_matrix_ushort* mat) {
    c_array_ushort arr;
    c_matrix_flatten_init(mat, &arr);
    c_matrix_flatten_process(mat, &arr);
    return arr;
}

c_array_int c_matrix_flatten_int(const c_matrix_int* mat) {
    c_array_int arr;
    c_matrix_flatten_init(mat, &arr);
    c_matrix_flatten_process(mat, &arr);
    return arr;
}

c_array_uint c_matrix_flatten_uint(const c_matrix_uint* mat) {
    c_array_uint arr;
    c_matrix_flatten_init(mat, &arr);
    c_matrix_flatten_process(mat, &arr);
    return arr;
}

c_array_long c_matrix_flatten_long(const c_matrix_long* mat) {
    c_array_long arr;
    c_matrix_flatten_init(mat, &arr);
    c_matrix_flatten_process(mat, &arr);
    return arr;
}

c_array_long_long c_matrix_flatten_long_long(const c_matrix_long_long* mat) {
    c_array_long_long arr;
    c_matrix_flatten_init(mat, &arr);
    c_matrix_flatten_process(mat, &arr);
    return arr;
}

c_array_ulong c_matrix_flatten_ulong(const c_matrix_ulong* mat) {
    c_array_ulong arr;
    c_matrix_flatten_init(mat, &arr);
    c_matrix_flatten_process(mat, &arr);
    return arr;
}

c_array_float c_matrix_flatten_float(const c_matrix_float* mat) {
    c_array_float arr;
    c_matrix_flatten_init(mat, &arr);
    c_matrix_flatten_process(mat, &arr);
    return arr;
}

c_array_double c_matrix_flatten_double(const c_matrix_double* mat) {
    c_array_double arr;
    c_matrix_flatten_init(mat, &arr);
    c_matrix_flatten_process(mat, &arr);
    return arr;
}

c_array_ldouble c_matrix_flatten_ldouble(const c_matrix_ldouble* mat) {
    c_array_ldouble arr;
    c_matrix_flatten_init(mat, &arr);
    c_matrix_flatten_process(mat, &arr);
    return arr;
}
