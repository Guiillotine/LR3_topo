#define BOOST_TEST_MODULE mytests
#include <boost/test/included/unit_test.hpp>
#include "MatrCalc.h"

void MATRIXES_CHECK_EQUAL(matrix matr1, matrix matr2);
void MATRIXES_CHECK_CLOSE(matrix matr1, matrix matr2, double percent);

struct Fixture
{
	Fixture() {
        MatrCalc* mcalc = new MatrCalc();
    }
	~Fixture() {
        delete mcalc;
    }
    MatrCalc* mcalc;
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