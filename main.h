#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

//선언부
int print_f();

//from recommand
int print_R();

//for func

//for code
#define NMAX 10000000
double stddev(double* values, int n);
double mean(double* values, int n);
double* generate(int n);
void printHistogram(double* values, int n);