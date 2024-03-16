#pragma once
#include "vector"
typedef std::vector<std::vector<double>> vector2d;


class MatrCalc
{
public:
	MatrCalc();
	~MatrCalc();
	vector2d add(vector2d matr1, vector2d matr2);
	vector2d sub(vector2d matr1, vector2d matr2);

private:

};