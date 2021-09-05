#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED

/*including library*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

/*declaration of functions*/

//  ----------------------------------
//!  @note This function is checking intered values
//!
//!  @param [in] quaniti - counter of correctly entered values
//!
//!  @return nothing
//------------------------------------

void checking_val (int quaniti);

//  ----------------------------------
//!  @note fuction for testing solver
//!
//!  @param numb - number of test
//!  @param qua - expected number of solves
//!  @param a - coefficient at x^2
//!  @param b - coefficient at x
//!  @param c - coefficient at free-member
//!  @param x1ref -  1st expected solve
//!  @param x2ref -  2nd expected solve
//!
//!  @return nothing
//  ----------------------------------

void unit_test_for_square (int numb, int qua, double a, double b, double c, double x1ref, double x2ref);

//  ----------------------------------
//!  @note fuction that run unittest
//!
//!  @param no param
//!
//!  @return nothing
//  ----------------------------------

void run_unit_test ();

//  ----------------------------------
//!  @note fuction that compares values
//!
//!  @param x - the variable, that compared to
//!  @param xref - the variable that is compared to
//!
//!  @return function returns 1 if variables are equale to each other
//!  @return function returns 0 if variables aren't equale to each other
//!
//  ----------------------------------

int is_Equal (double x, double xref);

//  ----------------------------------
//!  @note Function, that solves the equal
//!
//!  @param [in] coef1 - coefficient at x^2
//!  @param [in] coef2 - coefficient at x
//!  @param [in] coef3 - coefficient at free-member
//!  @param [out] *sol1 - the pointer for the first solutoin
//!  @param [out] *sol1 - the pointer for the first solution
//!
//!  @return This program returns INF_ROOTS if equation has infinit number of solutions
//!  @return This program returns NO_ROOTS if equation has no solutions
//!  @return This program returns ONE_ROOT if equation has only one solution
//!  @return This program returns TWO_ROOTS  if equation has two solutions
//!  @return This program returns  -2 if smth went wrong :)
//!
//  ----------------------------------

int solve_ss (double coef1, double coef2, double coef3, double* sol1, double* sol2);

//  ----------------------------------
//!  @note Assert testing for program
//!
//!  @param no param
//!
//!  @return nothing
//!
//  ----------------------------------

void assert_testing ();

//  ----------------------------------
//!  @note this function is processing of returned data and printing solutions
//!
//!  @param [in] numb - number of solutions
//!  @param [in] sol1 - first solution of ss
//!  @param [in] sol2 - second solution of ss
//!
//!  @return nothing
//  ----------------------------------

void printing_solutions (int numb, double sol1, double sol2);

//!  adding constant

const double eps = 1e-7;

//!  changing names of the number of solutions

enum Constants
{
    NO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2,
    INF_ROOTS = -1,
};


#endif //MYLIB_H_INCLUDED
