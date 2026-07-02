#include <stdio.h>
#include "counte.h"

int sum(int a, int b) {
    return a + b;
}

int dimun(int a, int b) {
    return a - b;
}

int mult(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b == 0) return 0; 
    return a / b;
}