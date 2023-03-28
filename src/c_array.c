/*
    Copyright (c) 2022 Jian Yu, Chen
    License: MIT License
    Version: v1.3.2
    file   : c_array.c

    The latest version is avaliable at:
    https://github.com/Zncl2222/c_array_tools
*/

# include "c_array.h"

/*            This is an implementation of c_array extension            */
// -----------------------------------------------------------------------
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

// -----------------------------------------------------------------------
/*                     Array standard deviation                         */

var_t c_array_var_short(short* arr, int size, mean_t mean) {
    c_array_var_process(arr, size, mean)
    return (var / size);
}

var_t c_array_var_ushort(unsigned short* arr, int size, mean_t mean) {
    c_array_var_process(arr, size, mean)
    return (var / size);
}

var_t c_array_var_int(int* arr, int size, mean_t mean) {
    c_array_var_process(arr, size, mean)
    return (var / size);
}

var_t c_array_var_uint(unsigned int* arr, int size, mean_t mean) {
    c_array_var_process(arr, size, mean)
    return (var / size);
}

var_t c_array_var_long(long* arr, int size, mean_t mean) {
    c_array_var_process(arr, size, mean)
    return (var / size);
}

var_t c_array_var_ulong(unsigned long* arr, int size, mean_t mean) {
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

var_t c_array_var_long_double(long double* arr, int size, mean_t mean) {
    c_array_var_process(arr, size, mean)
    return (var / size);
}

std_t c_array_std_short(short* arr, int size, mean_t mean) {
    c_array_var_process(arr, size, mean)
    return sqrt(var / size);
}

std_t c_array_std_ushort(unsigned short* arr, int size, mean_t mean) {
    c_array_var_process(arr, size, mean)
    return sqrt(var / size);
}

std_t c_array_std_int(int* arr, int size, mean_t mean) {
    c_array_var_process(arr, size, mean)
    return sqrt(var / size);
}

std_t c_array_std_uint(unsigned int* arr, int size, mean_t mean) {
    c_array_var_process(arr, size, mean)
    return sqrt(var / size);
}

std_t c_array_std_long(long* arr, int size, mean_t mean) {
    c_array_var_process(arr, size, mean)
    return sqrt(var / size);
}

std_t c_array_std_ulong(unsigned long* arr, int size, mean_t mean) {
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

std_t c_array_std_long_double(long double* arr, int size, mean_t mean) {
    c_array_var_process(arr, size, mean)
    return sqrt(var / size);
}

// -----------------------------------------------------------------------
/*                          Array mean value                            */

mean_t c_array_mean_short(short* arr, int size, short sum) {
    c_array_mean_process(arr, size, sum)
}

mean_t c_array_mean_ushort(unsigned short* arr, int size, unsigned short sum) {
    c_array_mean_process(arr, size, sum)
}

mean_t c_array_mean_int(int* arr, int size, int sum) {
    c_array_mean_process(arr, size, sum)
}

mean_t c_array_mean_uint(unsigned int* arr, int size, unsigned int sum) {
    c_array_mean_process(arr, size, sum)
}

mean_t c_array_mean_long(long* arr, int size, long sum) {
    c_array_mean_process(arr, size, sum)
}

mean_t c_array_mean_ulong(unsigned long* arr, int size, unsigned long sum) {
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

mean_t c_array_mean_long_double(long double* arr, int size, long double sum) {
    c_array_mean_process(arr, size, sum)
}

// -----------------------------------------------------------------------
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

// -----------------------------------------------------------------------
/*                           Array qsort                                */

int cmpfunc_short(const void* a, const void* b) {
    return ( *(short*)a - *(short*)b );
}

int cmpfunc_ushort(const void* a, const void* b) {
    return ( *(unsigned short*)a - *(unsigned short*)b );
}

int cmpfunc_int(const void* a, const void* b) {
    return ( *(int*)a - *(int*)b );
}

int cmpfunc_uint(const void* a, const void* b) {
    return ( *(unsigned int*)a - *(unsigned int*)b );
}

int cmpfunc_long(const void* a, const void* b) {
    return ( *(long*)a - *(long*)b );
}

int cmpfunc_ulong(const void* a, const void* b) {
    return ( *(unsigned long*)a - *(unsigned long*)b );
}

int cmpfunc_long_long(const void* a, const void* b) {
    return ( *(long long*)a - *(long long*)b );
}

int cmpfunc_float(const void* a, const void* b) {
    float ret = *(float*)a - *(float*)b;
    if(ret > 0){
        return 1;
    } else if (ret < 0) {
        return -1;
    }
    return 0;
}

int cmpfunc_double(const void* a, const void* b) {
    double ret = *(double*)a - *(double*)b;
    if(ret > 0){
        return 1;
    } else if (ret < 0) {
        return -1;
    }
    return 0;
}

int cmpfunc_long_double(const void* a, const void* b) {
    long double ret = *(long double*)a - *(long double*)b;
    if(ret > 0){
        return 1;
    } else if (ret < 0) {
        return -1;
    }
    return 0;
}
