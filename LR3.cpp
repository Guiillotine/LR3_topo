#include <iostream>
#include <conio.h>
#include <windows.h>

#include "MatrCalc.h"

vector2d matr1, matr2;
bool fUnary = true;
bool freset = false;

void inputMatrix(int opNum);
void printMatrix(vector2d matr);
void printMatrices(vector2d matr1, vector2d matr2);
void printUnaryOperations();
void printBinaryOperations();

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    MatrCalc mcalc;
    int choice = 0;
    double num = 0;

    while (1) {
        system("cls");
        std::cout << " МАТРИЧНЫЙ КАЛЬКУЛЯТОР\n";
        freset = false;
        fUnary = true;
        inputMatrix(1);

        do {
            system("cls");
            std::cout << " МАТРИЧНЫЙ КАЛЬКУЛЯТОР";
            std::cout << "\n\n Операнды:\n";

            if (fUnary) {
                printMatrix(matr1);
                printUnaryOperations();
            }
            else {
                printMatrices(matr1, matr2);
                printBinaryOperations();
            }

            std::cout << "\n Выберите вариант: ";
            std::cin >> choice;

            if (fUnary) {
                switch (choice) {
                case 1: std::cout << "\n Введите число: ";
                        std::cin >> num;
                        std::cout << "\n Результат:\n";
                        printMatrix(mcalc.multOnNum(matr1, num));
                        _getch();
                        break;
                case 2: printMatrix(mcalc.T(matr1));
                        _getch();
                        break;
                case 3: if (mcalc.checkIsSquare(matr1))
                        std::cout << "\n Определитель матрицы = " << mcalc.det(matr1);
                        else std::cout << "\n Вы не можете выполнить данную операцию: матрица не является квадратной.";
                        _getch();
                        break;
                case 4: if (!mcalc.checkIsSingular(matr1)) {
                            std::cout << "\n Результат:";
                            printMatrix(mcalc.inverse(matr1));
                        }
                        else std::cout << "\n Вы не можете выполнить данную операцию: матрица вырожденная.";
                        _getch();
                        break;
                case 5: inputMatrix(2);
                        fUnary = false;
                        break;
                case 6: freset = true;
                        break;
                }
            }

            else {
                switch (choice) {
                case 1: if (mcalc.checkRowsColsNumEqual(matr1,matr2)) {
                            std::cout << "\n Результат:";
                            printMatrix(mcalc.add(matr1, matr2));
                        }
                        else std::cout << "\n Вы не можете выполнить данную операцию: число строк и столбцов матриц-операндов не совпадает.";
                        _getch();
                        break;
                case 2: if (mcalc.checkRowsColsNumEqual(matr1, matr2)) {
                            std::cout << "\n Результат:";
                            printMatrix(mcalc.sub(matr1, matr2));
                        }
                        else std::cout << "\n Вы не можете выполнить данную операцию: число строк и столбцов матриц-операндов не совпадает.";
                        _getch();
                        break;
                case 3: if (mcalc.checkCols1AndRows2Equal(matr1, matr2)) {
                        std::cout << "\n Результат:";
                        printMatrix(mcalc.mult(matr1, matr2));
                        }
                        else std::cout << "\n Вы не можете выполнить данную операцию: число столбцов первой матрицы не совпадает с числом строк второй.";
                        _getch();
                        break;
                case 4: fUnary = true;
                        matr1 = matr2;
                        break;
                case 5: fUnary = true;
                        break;
                case 6: freset = true;
                        break;
                }
            }

        } while (!freset);
    };
}

void printUnaryOperations() {
    std::cout << "\n\n 1) -> * на число";
    std::cout << "\n 2) -> транспонировать";
    std::cout << "\n 3) -> определитель";
    std::cout << "\n 4) -> обратная матрица";
    std::cout << "\n\n 5) -> добавить второй операнд";
    std::cout << "\n 6) -> сброс\n";
}

void printBinaryOperations() {
    std::cout << "\n\n 1) -> +";
    std::cout << "\n 2) -> -";
    std::cout << "\n 3) -> *";
    std::cout << "\n\n 4) -> удалить 1-й операнд";
    std::cout << "\n 5) -> удалить 2-й операнд";
    std::cout << "\n 6) -> сброс\n";
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

    matr->clear();

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

void printMatrices(vector2d matr1, vector2d matr2) {
    int n1 = matr1.size(), n2 = matr2.size();
    int m1 = matr1[0].size(), m2 = matr2[0].size();
    int maxN = max(n1, n2), maxM = max(m1, m2);

    for (int i = 0; i < maxN; i++) {
        std::cout << std::endl;
        if (i < n1)
            for (int j = 0; j < m1; j++)
                printf("%7.2lf", matr1[i][j]);
        else 
            for (int j = 0; j < m1; j++)
                printf("%7s", " ");
        std::cout << "      ";

        if (i < n2)
            for (int j = 0; j < m2; j++)
                printf("%7.2lf", matr2[i][j]);
    }
}
