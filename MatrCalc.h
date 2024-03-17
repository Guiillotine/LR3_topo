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
	vector2d mult(vector2d matr1, vector2d matr2);
	vector2d multOnNum(vector2d matr, double num);
	vector2d T(vector2d matr);
	double det(vector2d matr);
	vector2d inverse(vector2d matr);
	bool checkRowsColsNumEqual(vector2d matr1, vector2d matr2);

private:

};