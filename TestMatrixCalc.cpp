#define BOOST_TEST_MODULE mytests
#include <boost/test/included/unit_test.hpp>
#include "MatrCalc.h"

//void MATRIXES_CHECK_EQUAL(vector2d matr1, vector2d matr2);
void MATRIXES_CHECK_CLOSE(vector2d matr1, vector2d matr2, double percent);

struct Fixture
{
	Fixture() {}
	~Fixture() {
        delete mcalc;
    }
    MatrCalc* mcalc = new MatrCalc();
};

BOOST_AUTO_TEST_CASE(MatrCalcCreationTest)
{
	BOOST_TEST_MESSAGE("TEST: MatrCalcCreationTest");
    MatrCalc* mcalc = new MatrCalc();
    BOOST_CHECK(mcalc != nullptr);
    delete mcalc;
}

BOOST_FIXTURE_TEST_CASE(AddRegToRegTest, Fixture)
{
    BOOST_TEST_MESSAGE("TEST: Add regular matrix to regular matrix");
    vector2d matr1 = { {1,2,1,2},
                       {3,4,3,4},
                       {5,6,5,6} },

             matr2 = { {1,1,1,1},
                       {4,3,4,3},
                       {0,0,0,0} },

             result = { {3,4,3,4},
                        {7,7,7,7},
                        {5,6,5,6} };

    MATRIXES_CHECK_CLOSE(mcalc->add(matr1,matr2),result, 0.5);
}
BOOST_FIXTURE_TEST_CASE(AddRegToNegativeTest, Fixture)
{
    BOOST_TEST_MESSAGE("TEST: Add regular matrix to negative matrix");
    vector2d matr1 = { {1,2,1,2},
                       {3,4,3,4},
                       {5,6,5,6} },

             matr2 = { {-1,-1,-1,-1},
                       {-4,-3,-4,-3},
                       {-10,-10,-10,-10} },

             result = { {0,1,0,1},
                        {-1,1,-1,1},
                        {-5,-4,-5,-4} };

    MATRIXES_CHECK_CLOSE(mcalc->add(matr1, matr2), result, 0.5);
}


BOOST_FIXTURE_TEST_CASE(SubRegFromRegTest, Fixture)
{
    BOOST_TEST_MESSAGE("TEST: Subtraction regular matrix from regular matrix");
    vector2d matr1 = { {1,2,1,2},
                       {3,4,3,4},
                       {5,6,5,6} },

            matr2 = { {1,1,2,2},
                      {2,2,3,3},
                      {4,4,5,5} },

            result = { {0,1,-1,0},
                       {1,2,0,51},
                       {1,2,0,1} };

    MATRIXES_CHECK_CLOSE(mcalc->sub(matr1, matr2), result, 0.5);
}
BOOST_FIXTURE_TEST_CASE(SubNegativeFromRegTest, Fixture)
{
    BOOST_TEST_MESSAGE("TEST: Subtraction negative matrix from regular matrix");
    vector2d matr1 = { {1,2,1,2},
                       {3,4,3,4},
                       {5,6,5,6} },

            matr2 = { {-1,-1,-2,-2},
                      {-2,-2,-3,-3},
                      {-4,-4,-5,-5} },

            result = { {2,3,3,4},
                       {5,6,6,7},
                       {9,10,10,11} };

    MATRIXES_CHECK_CLOSE(mcalc->sub(matr1, matr2), result, 0.5);
}
BOOST_FIXTURE_TEST_CASE(SubEqualMatricesTest, Fixture)
{
    BOOST_TEST_MESSAGE("TEST: Subtraction of equal matrices");
    vector2d matr1 = { {1,2,1,2},
                       {3,4,3,4},
                       {5,6,5,6} },

            matr2 = { {1,2,1,2},
                      {3,4,3,4},
                      {5,6,5,6} },

            result = { {0,0,0,0},
                       {0,0,0,0},
                       {0,0,0,0} };

    MATRIXES_CHECK_CLOSE(mcalc->sub(matr1, matr2), result, 0.5);
}


BOOST_FIXTURE_TEST_CASE(MultRegMatricesTest, Fixture)
{
    BOOST_TEST_MESSAGE("TEST: Multiplication of regular matrices");
    vector2d matr1 = { {1,2,3,4},
                       {2,3,4,5},
                       {3,4,5,6} },

             matr2 = { {2,1,2},
                       {1,2,1},
                       {2,3,3},
                       {3,4,2} },

             result = { {22,30,21},
                        {30,40,29},
                        {38,50,37} };

    MATRIXES_CHECK_CLOSE(mcalc->mult(matr1, matr2), result, 0.5);
}
BOOST_FIXTURE_TEST_CASE(MultNegativeMatricesTest, Fixture)
{
    BOOST_TEST_MESSAGE("TEST: Multiplication of negative matrices");
    vector2d matr1 = { {-1,-2,-3,-4},
                       {-2,-3,-4,-5},
                       {-3,-4,-5,-6} },

             matr2 = { {-1,-1,-1},
                       {-1,-1,-1},
                       {-1,-1,-1},
                       {-1,-1,-1} },

             result = { {10,10,10},
                        {14,14,14},
                        {18,18,18} };

    MATRIXES_CHECK_CLOSE(mcalc->mult(matr1, matr2), result, 0.5);
}


BOOST_FIXTURE_TEST_CASE(MultOnNum, Fixture)
{
    BOOST_TEST_MESSAGE("TEST: Multiplying a matrix by a number");
    vector2d matr = { {1,2,3,4},
                      {2,3,4,5},
                      {3,4,5,6} },

        result = { {3.5,7,10.5,14},
                   {7,10.5,14,17.5},
                   {10.5,14,17.5,21} };
    double num = 3.5;

    MATRIXES_CHECK_CLOSE(mcalc->multOnNum(matr, num), result, 0.5);
}
BOOST_FIXTURE_TEST_CASE(MultOnNullNum, Fixture)
{
    BOOST_TEST_MESSAGE("TEST: Multiplying a matrix by a null");
    vector2d matr = { {1,2,3,4},
                      {2,3,4,5},
                      {3,4,5,6} },

            result = { {0,0,0,0},
                       {0,0,0,0},
                       {0,0,0,0} };
    double num = 0;

    MATRIXES_CHECK_CLOSE(mcalc->multOnNum(matr, num), result, 0.5);
}


BOOST_FIXTURE_TEST_CASE(mairixT, Fixture)
{
    BOOST_TEST_MESSAGE("TEST: Matrix transpose");
    vector2d matr = { {1,2,3,4},
                      {5,6,7,8},
                      {9,10,11,12} },

            result = { {1,5,9},
                       {2,6,10},
                       {3,7,11},
                       {4,8,12} };

    MATRIXES_CHECK_CLOSE(mcalc->T(matr), result, 0.5);
}


BOOST_FIXTURE_TEST_CASE(matrixDeterminant, Fixture)
{
    BOOST_TEST_MESSAGE("TEST: Find the determinant of the matrix");
    vector2d matr = { {1,2,3},
                      {4,5,6},
                      {7,8,10} };

    double result = -3;

    BOOST_CHECK_CLOSE(mcalc->det(matr), result, 0.5);
}
BOOST_FIXTURE_TEST_CASE(singularMatrixDeterminant, Fixture)
{
    BOOST_TEST_MESSAGE("TEST: Find the determinant of the singular matrix");
    vector2d matr = { {1,2,3},
                      {4,5,6},
                      {7,8,9} };

    double result = 0;

    BOOST_CHECK_CLOSE(mcalc->det(matr), result, 0.5);
}

BOOST_FIXTURE_TEST_CASE(findInverseMatrix, Fixture)
{
    BOOST_TEST_MESSAGE("TEST: Find the inverse matrix");
    vector2d matr = { {1,2,3},
                      {4,5,6},
                      {7,8,10} },

            result = { {-2/3,-4/3,1},
                       {-2/3,11/3,-2},
                       {1,-2,1} };

    MATRIXES_CHECK_CLOSE(mcalc->inverse(matr), result, 0.5);
}


// ÏÐÎÂÅÐÊÈ ÍÀ ÄÎÏÓÑÒÈÌÎÑÒÜ ÎÏÅÐÀÍÄÎÂ ÄËß ÂÛÏÎËÍÅÍÈß ÎÏÅÐÀÖÈÉ

BOOST_FIXTURE_TEST_CASE(IsRowsAndColsNumEqual, Fixture)
{
    BOOST_TEST_MESSAGE("TEST: The number of rows and columns of the matrixes is equal");
    vector2d matr1 = { {1,2,1,2},
                       {3,4,3,4},
                       {5,6,5,6} },

             matr2 = { {1,1,1,1},
                       {4,3,4,3},
                       {0,0,0,0} };

    BOOST_CHECK(mcalc->checkRowsColsNumEqual(matr1,matr2) == true);
}
BOOST_FIXTURE_TEST_CASE(IsNotEqualRowsAndColsNumEqual, Fixture)
{
    BOOST_TEST_MESSAGE("TEST: The number of rows and columns of the matrixes is NOT equal");
    vector2d matr1 = { {1,2,3},
                       {4,5,6},
                       {7,8,9} },

             matr2 = { {1,1,1,1},
                       {4,3,4,3},
                       {0,0,0,0} };

    BOOST_CHECK(mcalc->checkRowsColsNumEqual(matr1, matr2) == false);
}

BOOST_FIXTURE_TEST_CASE(IsEqualCols1AndRows2, Fixture)
{
    BOOST_TEST_MESSAGE("TEST: The number of columns of the matrix 1 and the number of rows of the matrix 2 is equal");
    vector2d matr1 = { {1,2,3,4},
                       {2,3,4,5},
                       {3,4,5,6} },

             matr2 = { {2,1,2},
                       {1,2,1},
                       {2,3,3},
                       {3,4,2} };

    BOOST_CHECK(mcalc->checkCols1AndRows2Equal(matr1, matr2) == true);
}
BOOST_FIXTURE_TEST_CASE(IsNotEqualCols1AndRows2, Fixture)
{
    BOOST_TEST_MESSAGE("TEST: The number of columns of the matrix 1 and the number of rows of the matrix 2 is NOT equal");
    vector2d matr1 = { {1,2,3,4},
                       {2,3,4,5}},

        matr2 = { {2,1,2},
                  {1,2,1},
                  {2,3,3},
                  {3,4,2} };

    BOOST_CHECK(mcalc->checkCols1AndRows2Equal(matr1, matr2) == false);
}

BOOST_FIXTURE_TEST_CASE(IsSquare, Fixture)
{
    BOOST_TEST_MESSAGE("TEST: The matrix is square");
    vector2d matr = { {1,2,3},
                      {4,5,6},
                      {7,8,10} };

    BOOST_CHECK(mcalc->checkIsSquare(matr) == true);
}
BOOST_FIXTURE_TEST_CASE(IsNotSquare, Fixture)
{
    BOOST_TEST_MESSAGE("TEST: The matrix is NOT square");
    vector2d matr = { {1,2,3},
                      {4,5,6} };

    BOOST_CHECK(mcalc->checkIsSquare(matr) == false);
}









/*void MATRIXES_CHECK_EQUAL(vector2d matr1, vector2d matr2) {
    int n = matr1.size(),
        m = matr1[0].size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            BOOST_CHECK_EQUAL(matr1[i][j], matr2[i][j]);
}*/

void MATRIXES_CHECK_CLOSE(vector2d matr1, vector2d matr2, double percent) {
    int n = matr1.size(),
        m = matr1[0].size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            BOOST_CHECK_CLOSE(matr1[i][j], matr2[i][j], percent);
}


//	BOOST_CHECK_CLOSE(, , );
//  BOOST_CHECK_EQUAL(, );
//  BOOST_CHECK();