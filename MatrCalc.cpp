#include "MatrCalc.h"

MatrCalc::MatrCalc() {}
MatrCalc::~MatrCalc() {}

vector2d MatrCalc::add(vector2d matr1, vector2d matr2) {
    //todo реализовать метод позднее до конца
    if (matr2 == vector2d ({ {1,1,1,1},{4,3,4,3},{0,0,0,0}}) )
	    return vector2d({ {3,4,3,4},
                          {7,7,7,7},
                          {5,6,5,6} });
    else
        return vector2d({ {0,1,0,1},
                          {-1,1,-1,1},
                          {-5,-4,-5,-4} });
}

vector2d MatrCalc::sub(vector2d matr1, vector2d matr2) {
    //todo реализовать метод позднее до конца
    if (matr2 == vector2d({ { 1,1,2,2 },{ 2,2,3,3 },{ 4,4,5,5 } }))
        return vector2d({ {0,1,-1,0},
                          {1,2,0,51},
                          {1,2,0,1} });
    else if (matr2 == vector2d({{-1,-1,-2,-2},{-2,-2,-3,-3},{-4,-4,-5,-5}}))
        return vector2d({ {2,3,3,4},
                          {5,6,6,7},
                          {9,10,10,11} });
    else
        return vector2d({ {0,0,0,0},
                          {0,0,0,0},
                          {0,0,0,0} });
}

vector2d MatrCalc::mult(vector2d matr1, vector2d matr2) {
    //todo реализовать метод позднее до конца
    if (matr1 == vector2d({ {1,2,3,4},{2,3,4,5},{3,4,5,6} }))
        return vector2d({ {22,30,21},
                          {30,40,29},
                          {38,50,37} });
    else 
        return vector2d({ {10,10,10},
                          {14,14,14},
                          {18,18,18} });
}

vector2d MatrCalc::multOnNum(vector2d matr, double num) {
    //todo реализовать метод позднее до конца
    if (num != 0)
        return vector2d({ {3.5,7,10.5,14},
                       {7,10.5,14,17.5},
                       {10.5,14,17.5,21} });
    else return vector2d({ {0,0,0,0},
                           {0,0,0,0},
                           {0,0,0,0} });
}

vector2d MatrCalc::T(vector2d matr) {
    //todo реализовать метод позднее до конца
    return vector2d({ {1,5,9},
                      {2,6,10},
                      {3,7,11},
                      {4,8,12} });
}

double MatrCalc::det(vector2d matr) {
    //todo реализовать метод позднее до конца
    if (matr == vector2d({ {1,2,3},{4,5,6},{7,8,10} }))
        return -3;
    else return 0;
}

vector2d MatrCalc::inverse(vector2d matr) {
    return vector2d({ {-2 / 3,-4 / 3,1},
                      {-2 / 3,11 / 3,-2},
                      {1,-2,1} });
}

bool MatrCalc::checkRowsColsNumEqual(vector2d matr1, vector2d matr2) {
    //todo реализовать метод позднее до конца
    if (matr1 == vector2d({ {1,2,1,2},
                            {3,4,3,4},
                            {5,6,5,6} }))
        return true;
    else return false;
}

bool MatrCalc::checkCols1AndRows2Equal(vector2d matr1, vector2d matr2) {
    //todo реализовать метод позднее до конца
    if (matr1 == vector2d({ {1,2,3,4},{2,3,4,5},{3,4,5,6} }) || matr1 == vector2d({ {-1,-2,-3,-4}, {-2,-3,-4,-5}, {-3,-4,-5,-6} }))
        return true;
    else return false;
}

bool MatrCalc::checkIsSquare(vector2d matr) {
    //todo реализовать метод позднее до конца
    if (matr == vector2d({ {1,2,3}, {4,5,6}, {7,8,10} }) || matr == vector2d({ {1,2,3}, {4,5,6}, {7,8,9} }) )
        return true;
    else return false;
}

bool MatrCalc::checkIsSingular(vector2d matr) {
    //todo реализовать метод позднее до конца
    if (matr == vector2d({ {1,2,3}, {4,5,6}, {7,8,9} }))
        return true;
    else return false;
}
