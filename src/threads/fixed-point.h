#ifndef FIXED_POINT_H
#define FIXED_POINT_H

#include <stdint.h>

/* 17.14 fixed point representation */
#define F (1 << 14)
typedef int fixed_point;

/* Convert n to fixed point: n * f. */
static fixed_point itof(int n) {
    return n * F;
}

/* Convert x to integer (rounding toward zero): x / f. */
static int ftoi(fixed_point x) {
    return x / F;
}

/* Convert x to integer (rounding to nearest): (x + f / 2) / f if x >= 0, (x - f / 2) / f if x <= 0. */
static int ftoi_round(fixed_point x) {
    return (x >= 0) ? (x + F / 2) / F : (x - F / 2) / F;
}

/* Add x and y: x + y. */
static fixed_point add(fixed_point x, fixed_point y) {
    return x + y;
}

/* Subtract y from x: x - y. */
static fixed_point sub(fixed_point x, fixed_point y) {
    return x - y;
}

/* Add x and n: x + n * f. */
static fixed_point add_int(fixed_point x, int n) {
    return x + n * F;
}

/* Subtract n from x: x - n * f. */
static fixed_point sub_int(fixed_point x, int n) {
    return x - n * F;
}

/* Multiply x by y: ((int64_t) x) * y / f. */
static fixed_point mul(fixed_point x, fixed_point y) {
    return ((int64_t) x) * y / F;
}

/* Multiply x by n: x * n. */
static fixed_point mul_int(fixed_point x, int n) {
    return x * n;
}

/* Divide x by y: ((int64_t) x) * f / y. */
static fixed_point div(fixed_point x, fixed_point y) {
    return ((int64_t) x) * F / y;
}

/* Divide x by n: x / n. */
static fixed_point div_int(fixed_point x, int n) {
    return x / n;
}

#endif 