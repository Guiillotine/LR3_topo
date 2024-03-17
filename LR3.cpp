#include <iostream>
#include <conio.h>
#include <windows.h>

#include "MatrCalc.h"

vector2d matr1, matr2;

void inputMatrix(int opNum);
void printMatrix(vector2d matr);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << " Матричный калькулятор\n";
    inputMatrix(1);
    printMatrix(matr1);

    /*while (1) {
        std::cout << "Hello World!\n";


    };*/
}

void inputMatrix(int opNum) {
    int n, m;
    vector2d *matr;
    std::vector<double> matrStr;
    double el;

    std::cout << "\n Введите число строк: ";
    std::cin >> n;
    std::cout << "\n Введите число столбцов: ";
    std::cin >> m;

    if (opNum == 1) matr = &matr1;
    else matr = &matr2;

    std::cout << "\n Ввод матрицы: ";
    for (int i = 0; i < n; i++) {
        std::cout << "\n";
        for (int j = 0; j < m; j++) {
            std::cout << " ";
            std::cin >> el;
            matrStr.push_back(el);
        }
        matr->push_back(matrStr);
        matrStr.clear();
    }
}

void printMatrix(vector2d matr) {
    int n = matr.size();
    int m = matr[0].size();

    for (int i = 0; i < n; i++) {
        std::cout << std::endl;
        for (int j = 0; j < m; j++)
            printf("%7.2lf", matr[i][j]);
    }
}
