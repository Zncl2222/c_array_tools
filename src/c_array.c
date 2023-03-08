/*
    Copyright (c) 2022 Jian Yu, Chen
    License: MIT License
    Version: v1.3.1
    file   : c_array.c

    The latest version is avaliable at:
    https://github.com/Zncl2222/c_array_tools
*/

# include "c_array.h"

/*            This is an implementation of c_array extension            */
// -----------------------------------------------------------------------
/*                          Array Min and Max                           */

int c_array_max_int(int* arr, int size) {
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

int c_array_min_int(int* arr, int size) {
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

// -----------------------------------------------------------------------
/*                     Array standard deviation                         */

var_t c_array_var_int(int* arr, int size, mean_t mean) {
    c_array_var_process(arr, size, mean)
    return (var / size);
}

var_t c_array_var_long_long(long long* arr, int size, mean_t mean) {
    c_array_var_process(arr, size, mean)
    return (var / size);
}

var_t c_array_var_float(float* arr, int size, mean_t mean) {
    c_array_var_process(arr, size, mean)
    return (var / size);
}

var_t c_array_var_double(double* arr, int size, mean_t mean) {
    c_array_var_process(arr, size, mean)
    return (var / size);
}

std_t c_array_std_int(int* arr, int size, mean_t mean) {
    c_array_var_process(arr, size, mean)
    return sqrt(var / size);
}

std_t c_array_std_long_long(long long* arr, int size, mean_t mean) {
    c_array_var_process(arr, size, mean)
    return sqrt(var / size);
}

std_t c_array_std_float(float* arr, int size, mean_t mean) {
    c_array_var_process(arr, size, mean)
    return sqrt(var / size);
}

std_t c_array_std_double(double* arr, int size, mean_t mean) {
    c_array_var_process(arr, size, mean)
    return sqrt(var / size);
}

// -----------------------------------------------------------------------
/*                          Array mean value                            */

mean_t c_array_mean_int(int* arr, int size, int sum) {
    c_array_mean_process(arr, size, sum)
}

mean_t c_array_mean_long_long(long long* arr, int size, long long sum) {
    c_array_mean_process(arr, size, sum)
}

mean_t c_array_mean_float(float* arr, int size, float sum) {
    c_array_mean_process(arr, size, sum)
}

mean_t c_array_mean_double(double* arr, int size, double sum) {
    c_array_mean_process(arr, size, sum)
}

// -----------------------------------------------------------------------
/*                              Array Sum                               */

int c_array_sum_int(int* arr, int size) {
    c_array_sum_process(arr, size)
}

long long c_array_sum_long(long long* arr, int size) {
    c_array_sum_process(arr, size)
}

float c_array_sum_float(float* arr, int size) {
    c_array_sum_process(arr, size)
}

double c_array_sum_double(double* arr, int size) {
    c_array_sum_process(arr, size)
}

// -----------------------------------------------------------------------
/*                           Array qsort                                */

int cmpfunc_int(const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int cmpfunc_long(const void * a, const void * b) {
   return ( *(long long*)a - *(long long*)b );
}

int cmpfunc_float(const void * a, const void * b) {
    float ret = *(float*)a - *(float*)b;
    if(ret > 0){
        return 1;
    } else if (ret < 0) {
        return -1;
    }
    return 0;
}

int cmpfunc_double(const void * a, const void * b) {
    double ret = *(double*)a - *(double*)b;
    if(ret > 0){
        return 1;
    } else if (ret < 0) {
        return -1;
    }
    return 0;
}
