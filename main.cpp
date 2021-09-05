/*#ifdef LEHA
#define LEHA_ZASRANETZ
#endif*/

#include "Mylib.h"
//#include LEHA_ZASRANETZ
#include "func.cpp"

//main function

int main ()
{

    printf ("This programm solves square equations\n (c) Kutuzov Viktor, 2021\n\n");

    // Testing my prog

    assert_testing ();
    run_unit_test ();

    printf ("input your coefficient\nEnter through the space without any signs\n");

    //val declaration

    double a = NAN;
    double b = NAN;
    double c = NAN;

    //checking the entered values

    int check = scanf ("%lg %lg %lg", &a, &b, &c);
    checking_val (check);

    //val declaration

    double x1 = NAN;
    double x2 = NAN;

    int nRoots = solve_ss ( a, b, c, &x1, &x2);

    printing_solutions (nRoots, x1, x2);

    return 0;
}
