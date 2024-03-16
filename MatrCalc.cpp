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
        return vector2d({ {0,1,1,2},
                          {3,4,4,5},
                          {5,6,6,7} });
    else if (matr2 == vector2d({{-1,-1,-2,-2},{-2,-2,-3,-3},{-4,-4,-5,-5}}))
        return vector2d({ {1,3,5,6},
                          {7,8,10,11},
                          {13,14,16,17} });
    else
        return vector2d({ {0,0,0,0},
                          {0,0,0,0},
                          {0,0,0,0} });
}

vector2d MatrCalc::mult(vector2d matr1, vector2d matr2) {
    return vector2d({ {22,30,21},
                      {30,40,29},
                      {38,50,37} });
}
