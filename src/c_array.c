/*
    Copyright (c) 2022 Jian Yu, Chen
    License: MIT License
    Version: v1.4.2
    file   : c_array.c

    The latest version is avaliable at:
    https://github.com/Zncl2222/c_array_tools
*/

# include "c_array.h"

/*            This is an implementation of c_array extension            */
/* -------------------------------------------------------------------- */
/*                          Array Min and Max                           */

short c_array_max_short(short* arr, int size) {
    c_array_max_process(arr, size)
}

unsigned short c_array_max_ushort(unsigned short* arr, int size) {
    c_array_max_process(arr, size)
}

int c_array_max_int(int* arr, int size) {
    c_array_max_process(arr, size)
}

unsigned int c_array_max_uint(unsigned int* arr, int size) {
    c_array_max_process(arr, size)
}

long c_array_max_long(long* arr, int size) {
    c_array_max_process(arr, size)
}

unsigned long c_array_max_ulong(unsigned long* arr, int size) {
    c_array_max_process(arr, size)
}

long long c_array_max_long_long(long long* arr, int size) {
    c_array_max_process(arr, size)
}

float c_array_max_float(float* arr, int size) {
    c_array_max_process(arr, size)
}

double c_array_max_double(double* arr, int size) {
    c_array_max_process(arr, size)
}

long double c_array_max_long_double(long double* arr, int size) {
    c_array_max_process(arr, size)
}

short c_array_min_short(short* arr, int size) {
    c_array_min_process(arr, size)
}

unsigned short c_array_min_ushort(unsigned short* arr, int size) {
    c_array_min_process(arr, size)
}

int c_array_min_int(int* arr, int size) {
    c_array_min_process(arr, size)
}

unsigned int c_array_min_uint(unsigned int* arr, int size) {
    c_array_min_process(arr, size)
}

long c_array_min_long(long* arr, int size) {
    c_array_min_process(arr, size)
}

unsigned long c_array_min_ulong(unsigned long* arr, int size) {
    c_array_min_process(arr, size)
}

long long c_array_min_long_long(long long* arr, int size) {
    c_array_min_process(arr, size)
}

float c_array_min_float(float* arr, int size) {
    c_array_min_process(arr, size)
}

double c_array_min_double(double* arr, int size) {
    c_array_min_process(arr, size)
}

long double c_array_min_long_double(long double* arr, int size) {
    c_array_min_process(arr, size)
}

/* -------------------------------------------------------------------- */
/*                         Array maxmin process                         */

short* c_array_maxmin_short(short* arr, int size) {
    c_array_maxmin_process(arr, size)
}

unsigned short* c_array_maxmin_ushort(unsigned short* arr, int size) {
    c_array_maxmin_process(arr, size)
}

int* c_array_maxmin_int(int* arr, int size) {
    c_array_maxmin_process(arr, size)
}

unsigned int* c_array_maxmin_uint(unsigned int* arr, int size) {
    c_array_maxmin_process(arr, size)
}

long* c_array_maxmin_long(long* arr, int size) {
    c_array_maxmin_process(arr, size)
}

unsigned long* c_array_maxmin_ulong(unsigned long* arr, int size) {
    c_array_maxmin_process(arr, size)
}

long long* c_array_maxmin_long_long(long long* arr, int size) {
    c_array_maxmin_process(arr, size)
}

float* c_array_maxmin_float(float* arr, int size) {
    c_array_maxmin_process(arr, size)
}

double* c_array_maxmin_double(double* arr, int size) {
    c_array_maxmin_process(arr, size)
}

long double* c_array_maxmin_long_double(long double* arr, int size) {
    c_array_maxmin_process(arr, size)
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
/*                           Array search                               */

int c_array_search_short(const short* arr, int size, short target) {
    c_array_search_process(arr, size, target)
}

int c_array_search_ushort(const unsigned short* arr, int size, unsigned short target){
    c_array_search_process(arr, size, target)
}

int c_array_search_int(const int* arr, int size, int target){
    c_array_search_process(arr, size, target)
}

int c_array_search_uint(const unsigned int* arr, int size, unsigned int target){
    c_array_search_process(arr, size, target)
}

int c_array_search_long(const long* arr, int size, long target){
    c_array_search_process(arr, size, target)
}

int c_array_search_long_long(const long long* arr, int size, long long target){
    c_array_search_process(arr, size, target)
}

int c_array_search_ulong(const unsigned long* arr, int size, unsigned long target){
    c_array_search_process(arr, size, target)
}

int c_array_search_float(const float* arr, int size, float target){
    c_array_search_process(arr, size, target)
}

int c_array_search_double(const double* arr, int size, double target){
    c_array_search_process(arr, size, target)
}

int c_array_search_ldouble(const long double* arr, int size, long double target){
    c_array_search_process(arr, size, target)
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
    c_array_matrix_form_process(&mat, arr);
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

/* -------------------------------------------------------------------- */
/*                          Matrix Reshape                              */

c_matrix_short c_matrix_reshape_short(c_matrix_short* mat, int n_row, int n_col){
    c_matrix_short mat_new;
    c_matrix_reshape_init(mat, &mat_new, n_row, n_col);
    c_matrix_reshape_process(mat, &mat_new, n_row, n_col);
    return mat_new;
}

c_matrix_ushort c_matrix_reshape_ushort(c_matrix_ushort* mat, int n_row, int n_col){
    c_matrix_ushort mat_new;
    c_matrix_reshape_init(mat, &mat_new, n_row, n_col);
    c_matrix_reshape_process(mat, &mat_new, n_row, n_col);
    return mat_new;
}

c_matrix_int c_matrix_reshape_int(c_matrix_int* mat, int n_row, int n_col){
    c_matrix_int mat_new;
    c_matrix_reshape_init(mat, &mat_new, n_row, n_col);
    c_matrix_reshape_process(mat, &mat_new, n_row, n_col);
    return mat_new;
}

c_matrix_uint c_matrix_reshape_uint(c_matrix_uint* mat, int n_row, int n_col){
    c_matrix_uint mat_new;
    c_matrix_reshape_init(mat, &mat_new, n_row, n_col);
    c_matrix_reshape_process(mat, &mat_new, n_row, n_col);
    return mat_new;
}

c_matrix_long c_matrix_reshape_long(c_matrix_long* mat, int n_row, int n_col){
    c_matrix_long mat_new;
    c_matrix_reshape_init(mat, &mat_new, n_row, n_col);
    c_matrix_reshape_process(mat, &mat_new, n_row, n_col);
    return mat_new;
}

c_matrix_long_long c_matrix_reshape_long_long(c_matrix_long_long* mat, int n_row, int n_col){
    c_matrix_long_long mat_new;
    c_matrix_reshape_init(mat, &mat_new, n_row, n_col);
    c_matrix_reshape_process(mat, &mat_new, n_row, n_col);
    return mat_new;
}

c_matrix_ulong c_matrix_reshape_ulong(c_matrix_ulong* mat, int n_row, int n_col){
    c_matrix_ulong mat_new;
    c_matrix_reshape_init(mat, &mat_new, n_row, n_col);
    c_matrix_reshape_process(mat, &mat_new, n_row, n_col);
    return mat_new;
}

c_matrix_float c_matrix_reshape_float(c_matrix_float* mat, int n_row, int n_col){
    c_matrix_float mat_new;
    c_matrix_reshape_init(mat, &mat_new, n_row, n_col);
    c_matrix_reshape_process(mat, &mat_new, n_row, n_col);
    return mat_new;
}

c_matrix_double c_matrix_reshape_double(c_matrix_double* mat, int n_row, int n_col){
    c_matrix_double mat_new;
    c_matrix_reshape_init(mat, &mat_new, n_row, n_col);
    c_matrix_reshape_process(mat, &mat_new, n_row, n_col);
    return mat_new;
}

c_matrix_ldouble c_matrix_reshape_ldouble(c_matrix_ldouble* mat, int n_row, int n_col){
    c_matrix_ldouble mat_new;
    c_matrix_reshape_init(mat, &mat_new, n_row, n_col);
    c_matrix_reshape_process(mat, &mat_new, n_row, n_col);
    return mat_new;
}

/* -------------------------------------------------------------------- */
/*                            Matrix sum                                */

short c_matrix_sum_short(short** mat, int rows, int cols) {
    c_matrix_sum_process(mat, rows, cols)
}

unsigned short c_matrix_sum_ushort(unsigned short** mat, int rows, int cols) {
    c_matrix_sum_process(mat, rows, cols)
}

int c_matrix_sum_int(int** mat, int rows, int cols) {
    c_matrix_sum_process(mat, rows, cols)
}

unsigned int c_matrix_sum_uint(unsigned int** mat, int rows, int cols) {
    c_matrix_sum_process(mat, rows, cols)
}

long c_matrix_sum_long(long** mat, int rows, int cols) {
    c_matrix_sum_process(mat, rows, cols)
}

unsigned long c_matrix_sum_ulong(unsigned long** mat, int rows, int cols) {
    c_matrix_sum_process(mat, rows, cols)
}

long long c_matrix_sum_long_long(long long** mat, int rows, int cols) {
    c_matrix_sum_process(mat, rows, cols)
}

float c_matrix_sum_float(float** mat, int rows, int cols) {
    c_matrix_sum_process(mat, rows, cols)
}

double c_matrix_sum_double(double** mat, int rows, int cols) {
    c_matrix_sum_process(mat, rows, cols)
}

long double c_matrix_sum_long_double(long double** mat, int rows, int cols) {
    c_matrix_sum_process(mat, rows, cols)
}

/* -------------------------------------------------------------------- */
/*                          matrix mean value                            */

mean_t c_matrix_mean_short(const short** mat, int rows, int cols, short sum) {
    c_matrix_mean_process(mat, rows, cols, sum)
}

mean_t c_matrix_mean_ushort(const unsigned short** mat, int rows, int cols, unsigned short sum) {
    c_matrix_mean_process(mat, rows, cols, sum)
}

mean_t c_matrix_mean_int(const int** mat, int rows, int cols, int sum) {
    c_matrix_mean_process(mat, rows, cols, sum)
}

mean_t c_matrix_mean_uint(const unsigned int** mat, int rows, int cols, unsigned int sum) {
    c_matrix_mean_process(mat, rows, cols, sum)
}

mean_t c_matrix_mean_long(const long** mat, int rows, int cols, long sum) {
    c_matrix_mean_process(mat, rows, cols, sum)
}

mean_t c_matrix_mean_ulong(const unsigned long** mat, int rows, int cols, unsigned long sum) {
    c_matrix_mean_process(mat, rows, cols, sum)
}

mean_t c_matrix_mean_long_long(const long long** mat, int rows, int cols, long long sum) {
    c_matrix_mean_process(mat, rows, cols, sum)
}

mean_t c_matrix_mean_float(const float** mat, int rows, int cols, float sum) {
    c_matrix_mean_process(mat, rows, cols, sum)
}

mean_t c_matrix_mean_double(const double** mat, int rows, int cols, double sum) {
    c_matrix_mean_process(mat, rows, cols, sum)
}

mean_t c_matrix_mean_long_double(const long double** mat, int rows, int cols, long double sum) {
    c_matrix_mean_process(mat, rows, cols, sum)
}

/* -------------------------------------------------------------------- */
/*                          Matrix Min and Max                           */

short c_matrix_max_short(short** mat, int r, int c) {
    c_matrix_max_process(mat, r, c)
}

unsigned short c_matrix_max_ushort(unsigned short** mat, int r, int c) {
    c_matrix_max_process(mat, r, c)
}

int c_matrix_max_int(int** mat, int r, int c) {
    c_matrix_max_process(mat, r, c)
}

unsigned int c_matrix_max_uint(unsigned int** mat, int r, int c) {
    c_matrix_max_process(mat, r, c)
}

long c_matrix_max_long(long** mat, int r, int c) {
    c_matrix_max_process(mat, r, c)
}

unsigned long c_matrix_max_ulong(unsigned long** mat, int r, int c) {
    c_matrix_max_process(mat, r, c)
}

long long c_matrix_max_long_long(long long** mat, int r, int c) {
    c_matrix_max_process(mat, r, c)
}

float c_matrix_max_float(float** mat, int r, int c) {
    c_matrix_max_process(mat, r, c)
}

double c_matrix_max_double(double** mat, int r, int c) {
    c_matrix_max_process(mat, r, c)
}

long double c_matrix_max_long_double(long double** mat, int r, int c) {
    c_matrix_max_process(mat, r, c)
}

short c_matrix_min_short(short** mat, int r, int c) {
    c_matrix_min_process(mat, r, c)
}

unsigned short c_matrix_min_ushort(unsigned short** mat, int r, int c) {
    c_matrix_min_process(mat, r, c)
}

int c_matrix_min_int(int** mat, int r, int c) {
    c_matrix_min_process(mat, r, c)
}

unsigned int c_matrix_min_uint(unsigned int** mat, int r, int c) {
    c_matrix_min_process(mat, r, c)
}

long c_matrix_min_long(long** mat, int r, int c) {
    c_matrix_min_process(mat, r, c)
}

unsigned long c_matrix_min_ulong(unsigned long** mat, int r, int c) {
    c_matrix_min_process(mat, r, c)
}

long long c_matrix_min_long_long(long long** mat, int r, int c) {
    c_matrix_min_process(mat, r, c)
}

float c_matrix_min_float(float** mat, int r, int c) {
    c_matrix_min_process(mat, r, c)
}

double c_matrix_min_double(double** mat, int r, int c) {
    c_matrix_min_process(mat, r, c)
}

long double c_matrix_min_long_double(long double** mat, int r, int c) {
    c_matrix_min_process(mat, r, c)
}

/* -------------------------------------------------------------------- */
/*                     Matrix standard deviation                        */

var_t c_matrix_var_short(const short** mat, int row, int col, mean_t mean) {
    c_matrix_var_process(mat, row, col, mean)
    return (var / (row * col));
}

var_t c_matrix_var_ushort(const unsigned short** mat, int row, int col, mean_t mean) {
    c_matrix_var_process(mat, row, col, mean)
    return (var / (row * col));
}

var_t c_matrix_var_int(const int** mat, int row, int col, mean_t mean) {
    c_matrix_var_process(mat, row, col, mean)
    return (var / (row * col));
}

var_t c_matrix_var_uint(const unsigned int** mat, int row, int col, mean_t mean) {
    c_matrix_var_process(mat, row, col, mean)
    return (var / (row * col));
}

var_t c_matrix_var_long(const long** mat, int row, int col, mean_t mean) {
    c_matrix_var_process(mat, row, col, mean)
    return (var / (row * col));
}

var_t c_matrix_var_ulong(const unsigned long** mat, int row, int col, mean_t mean) {
    c_matrix_var_process(mat, row, col, mean)
    return (var / (row * col));
}

var_t c_matrix_var_long_long(const long long** mat, int row, int col, mean_t mean) {
    c_matrix_var_process(mat, row, col, mean)
    return (var / (row * col));
}

var_t c_matrix_var_float(const float** mat, int row, int col, mean_t mean) {
    c_matrix_var_process(mat, row, col, mean)
    return (var / (row * col));
}

var_t c_matrix_var_double(const double** mat, int row, int col, mean_t mean) {
    c_matrix_var_process(mat, row, col, mean)
    return (var / (row * col));
}

var_t c_matrix_var_long_double(const long double** mat, int row, int col, mean_t mean) {
    c_matrix_var_process(mat, row, col, mean)
    return (var / (row * col));
}

std_t c_matrix_std_short(const short** mat, int row, int col, mean_t mean) {
    c_matrix_var_process(mat, row, col, mean)
    return sqrt(var / (row * col));
}

std_t c_matrix_std_ushort(const unsigned short** mat, int row, int col, mean_t mean) {
    c_matrix_var_process(mat, row, col, mean)
    return sqrt(var / (row * col));
}

std_t c_matrix_std_int(const int** mat, int row, int col, mean_t mean) {
    c_matrix_var_process(mat, row, col, mean)
    return sqrt(var / (row * col));
}

std_t c_matrix_std_uint(const unsigned int** mat, int row, int col, mean_t mean) {
    c_matrix_var_process(mat, row, col, mean)
    return sqrt(var / (row * col));
}

std_t c_matrix_std_long(const long** mat, int row, int col, mean_t mean) {
    c_matrix_var_process(mat, row, col, mean)
    return sqrt(var / (row * col));
}

std_t c_matrix_std_ulong(const unsigned long** mat, int row, int col, mean_t mean) {
    c_matrix_var_process(mat, row, col, mean)
    return sqrt(var / (row * col));
}

std_t c_matrix_std_long_long(const long long** mat, int row, int col, mean_t mean) {
    c_matrix_var_process(mat, row, col, mean)
    return sqrt(var / (row * col));
}

std_t c_matrix_std_float(const float** mat, int row, int col, mean_t mean) {
    c_matrix_var_process(mat, row, col, mean)
    return sqrt(var / (row * col));
}

std_t c_matrix_std_double(const double** mat, int row, int col, mean_t mean) {
    c_matrix_var_process(mat, row, col, mean)
    return sqrt(var / (row * col));
}

std_t c_matrix_std_long_double(const long double** mat, int row, int col, mean_t mean) {
    c_matrix_var_process(mat, row, col, mean)
    return sqrt(var / (row * col));
}

