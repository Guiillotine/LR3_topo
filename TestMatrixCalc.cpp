#define BOOST_TEST_MODULE mytests
#include <boost/test/included/unit_test.hpp>
#include "MatrCalc.h"

void MATRIXES_CHECK_EQUAL(vector2d matr1, vector2d matr2);
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

    MATRIXES_CHECK_EQUAL(mcalc->add(matr1,matr2),result);
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

    MATRIXES_CHECK_EQUAL(mcalc->add(matr1, matr2), result);
}

BOOST_FIXTURE_TEST_CASE(SubRegFromRegTest, Fixture)
{
    BOOST_TEST_MESSAGE("TEST: Subtraction regular matrix from regular matrix");
    vector2d matr1 = { {1,2,3,4},
                       {5,6,7,8},
                       {9,10,11,12} },

            matr2 = { {1,1,2,2},
                      {2,2,3,3},
                      {4,4,5,5} },

            result = { {0,1,1,2},
                       {3,4,4,5},
                       {5,6,6,7} };

    MATRIXES_CHECK_EQUAL(mcalc->sub(matr1, matr2), result);
}

BOOST_FIXTURE_TEST_CASE(SubNegativeFromRegTest, Fixture)
{
    BOOST_TEST_MESSAGE("TEST: Subtraction negative matrix from regular matrix");
    vector2d matr1 = { {1,2,3,4},
                       {5,6,7,8},
                       {9,10,11,12} },

            matr2 = { {-1,-1,-2,-2},
                      {-2,-2,-3,-3},
                      {-4,-4,-5,-5} },

            result = { {1,3,5,6},
                       {7,8,10,11},
                       {13,14,16,17} };

    MATRIXES_CHECK_EQUAL(mcalc->sub(matr1, matr2), result);
}

BOOST_FIXTURE_TEST_CASE(SubEqualMatricesTest, Fixture)
{
    BOOST_TEST_MESSAGE("TEST: Subtraction of equal matrices");
    vector2d matr1 = { {1,2,3,4},
                       {5,6,7,8},
                       {9,10,11,12} },

            matr2 = {  {1,2,3,4},
                       {5,6,7,8},
                       {9,10,11,12} },

            result = { {0,0,0,0},
                       {0,0,0,0},
                       {0,0,0,0} };

    MATRIXES_CHECK_EQUAL(mcalc->sub(matr1, matr2), result);
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

    MATRIXES_CHECK_EQUAL(mcalc->mult(matr1, matr2), result);
}













void MATRIXES_CHECK_EQUAL(vector2d matr1, vector2d matr2) {
    int n = matr1.size(),
        m = matr1[0].size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            BOOST_CHECK_EQUAL(matr1[i][j], matr2[i][j]);
}

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