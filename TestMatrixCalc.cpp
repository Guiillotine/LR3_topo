#define BOOST_TEST_MODULE mytests
#include <boost/test/included/unit_test.hpp>

struct Fixture
{
	Fixture() {}
	~Fixture() {}
};

BOOST_AUTO_TEST_CASE(MatrCalcCreationTest)
{
	BOOST_TEST_MESSAGE("TEST: MatrCalcCreationTest");
    MatrCalc* mcalc = new MatrCalc();
    BOOST_CHECK(mcalc != nullptr);
    delete mcalc;
}

//	BOOST_CHECK_CLOSE(, , );
//  BOOST_CHECK_EQUAL(, );
//  BOOST_CHECK();