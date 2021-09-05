#include "Mylib.h" /* including library*/

void checking_val(int quaniti)
{
    if (quaniti!= 3)
        printf ("You entered the wrong values");
}

bool near_to_0(double val)
{
  return (fabs(val)<eps);
}

void AssertTesting()
{
    double x1 = NAN, x2 = NAN;
    printf("Testing started\n");
    assert(((fabs(solve_ss(1, 2, 1, &x1, &x2)) - 1) < eps));
    assert(fabs(x1 + 1) < eps);
    assert(fabs(solve_ss(1,-5,6,&x1,&x2) - 2) < eps);
    assert(fabs(x1 - 3) < eps);
    assert(fabs(x2 - 2) < eps);
    assert(fabs(solve_ss(0,0,0,&x1,&x2) + 1) < eps);
    printf("Testing finished, all is ok\n\n");
}


void UnitTestForSquare(int numb, int qua, double a, double b, double c, double x1ref, double x2ref)
{
     double x1 = NAN,x2 = NAN;
     int nRoots = solve_ss(a, b, c, &x1, &x2);
     switch (nRoots)
     {
        case 2:

            if (!isEqual(nRoots, qua)||!isEqual(x1, x1ref)||!isEqual(x2, x2ref))

                {
                    printf("Test number %d FAILED:\n nRoots = %d, x1 = %lg, x2 = %lg.\n Expected:\n x1 = %lg, x2 = %lg",numb, qua, x1,x2, x1ref, x2ref);
                }
            break;
        case 1:
            if (!isEqual(nRoots, qua)||!isEqual(x1, x1ref))
                {
                     printf("Test number %d FAILED:\n nRoots = %d, x1 = %lg.\n Expected:\n x1 = %lg ", numb, qua, x1, x1ref);

                }
            break;
        case 0:
            if (!isEqual(nRoots, qua))
            {
               printf("Test number %d FAILED:\n nRoots = %d\n", numb, qua);
            }
            break;
        case -1:
            if (!isEqual(nRoots, qua))
            {
                printf("Test number %d FAILED:\n nRoots=%d\n", numb, qua);
            }
            break;
        default:
            printf("error");
     }
}

int isEqual(double x, double xref)
{
    return (fabs(xref - x) < eps) ? 1 : 0;
}

void RunUnitTest()
{
    printf("Unittest started\n");

                     // You must enter ref solutions in descending order
                     //   numb,    qua,       a,         b,        c,        x1ref,        x2ref
    UnitTestForSquare(       1,      1,       1,         2,        1,           -1,           NAN);
    UnitTestForSquare(       2,      2,       1,        -5,        6,            3,             2);
    UnitTestForSquare(       3,      0,       2,         2,        2,          NAN,           NAN);
    UnitTestForSquare(       4,     -1,       0,         0,        0,          NAN,           NAN);
    UnitTestForSquare(       5,      1,       0,         2,        0,            0,           NAN);

    printf("Unittest finished\n\n");

}

int solve_ss(double coef1, double coef2, double coef3, double* sol1, double* sol2)
{
    assert (sol1 != NULL);
    assert (sol2 != NULL);
    assert(isfinite(coef1));
    assert(isfinite(coef2));
    assert(isfinite(coef1));

    if (near_to_0(coef1))
    {
        if (near_to_0(coef2))
        {
            if (near_to_0(coef3))
                return INF_ROOTS;
            else
                return NO_ROOTS;
        }
        else
            *sol1 = -coef3/coef2;
            return ONE_ROOT;
    }
    else
    {
        if (near_to_0(coef2))
        {
            if (near_to_0(coef3))
            {
              *sol1=0;
              return ONE_ROOT;
            }
            else
            {
                if (coef3 > eps)
                    return NO_ROOTS;
                else
                {
                  *sol1 = sqrt(-coef3);
                  *sol2 = -(*sol1);
                  return TWO_ROOTS;
                }
            }
        }
        else
        {
         double discr = (coef2*coef2 - 4*coef1*coef3);
         double sqdiscr = sqrt(discr);
         if (discr > 0)
         {
             *sol1 = (-coef2 + sqdiscr) / (2*coef1);
             *sol2 = (-coef2 - sqdiscr) / (2*coef1);
             return TWO_ROOTS;
         }
         else if (near_to_0(discr))
         {
            *sol1 = (-coef2 + sqdiscr) / (2*coef1);
            *sol2 = *sol1;
            return ONE_ROOT;
         }
         else if (discr < 0)
            return NO_ROOTS;
         }
    }
    return -2;
}

void printing_solutions (int numb, double x1, double x2)
{
    switch (numb)
    {
        case NO_ROOTS:
            printf("0 solve");
            break;

        case ONE_ROOT:
            printf("1 solve: x = %lg", x1);
            break;

        case TWO_ROOTS:
            printf("2 solves: x1 = %lg, x2=%lg", x1, x2);
            break;

        case INF_ROOTS:
            printf("inf solutions");
            break;

        default:

            break;
    }

 }
