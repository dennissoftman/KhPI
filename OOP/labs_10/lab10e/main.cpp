#include "matrix2d.hpp"
#include <iostream>
#include <iomanip>

/*
Создать класс, описывающий двумерную матрицу.
Реализовать функции:
    – генерация массива (заполнение случайными числами);
    – вывод массива на экран;
    – поиск координат элемента с минимальными значениями;
    – получение элемента по позиции и запись по заданным координатам;
    – получение подматрицы по начальным позициям заданного размера.

Например, для матрицы размера 4х4
    01 02 03 04
    05 06 07 08
    09 10 11 12
    13 14 15 16

выделить подматрицу размером 3х2 с позиции 1х1
    06 07
    10 11
    14 15
*/

void auto_fill(Matrix2D &m)
{
    for(int i=0; i < m.GetRows(); i++)
        for(int j=0; j < m.GetCols(); j++)
            m.Set({i, j}, rand() % 100 - 50);
}

void output_matx(const Matrix2D &m)
{
    if(m.IsNull())
    {
        std::cout << "Matrix is NULL!" << std::endl;
        return;
    }

    for(int i=0; i < m.GetRows(); i++)
    {
        for(int j=0; j < m.GetCols(); j++)
            std::cout << std::setw(3) << m.Get({i, j}) << " ";
        std::cout << std::endl;
    }
}

int main()
{
    srand(time(nullptr));

    Matrix2D A(4, 4);
    auto_fill(A);

    std::cout << "Matrix A:" << std::endl;
    output_matx(A);

    Matrix2D B = A.Submat({1, 1}, 3, 2);
    std::cout << "Matrix B (submatrix of A):" << std::endl;
    output_matx(B);

    rc_t min_p = A.GetMinPos();
    std::cout << "Minimal element is at (" << min_p.r << "," << min_p.c << ")" << std::endl;

    return 0;
}
