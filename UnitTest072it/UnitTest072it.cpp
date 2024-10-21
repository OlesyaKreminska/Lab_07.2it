#include "pch.h"
#include "CppUnitTest.h"


#include "../Lab_07.2it/Lab_07.2it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab72
{
    TEST_CLASS(UnitTestLab72)
    {
    public:

        TEST_METHOD(TestSwapMaxMinInOddCols)
        {
            // Ініціалізація матриці
            int rowCount = 4;
            int colCount = 3;
            int** a = new int* [rowCount];
            for (int i = 0; i < rowCount; i++)
                a[i] = new int[colCount];

            // Вхідні дані для тестування
            a[0][0] = 5; a[0][1] = 3; a[0][2] = 6;
            a[1][0] = 7; a[1][1] = 4; a[1][2] = 8;
            a[2][0] = 9; a[2][1] = 1; a[2][2] = 2;
            a[3][0] = 4; a[3][1] = 5; a[3][2] = 3;

            // Очікуваний результат після сортування
            int expected[4][3] = {
                {5, 3, 6},
                {7, 4, 2},
                {4, 1, 8},
                {9, 5, 3}
            };

            // Виклик функції обміну
            SwapMaxMinInOddCols(a, rowCount, colCount);

            // Перевірка результату
            for (int i = 0; i < rowCount; i++) {
                for (int j = 0; j < colCount; j++) {
                    Assert::AreEqual(expected[i][j], a[i][j]);
                }
            }

            // Звільнення пам'яті
            for (int i = 0; i < rowCount; i++)
                delete[] a[i];
            delete[] a;
        }
    };
}