#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int k, const int n, const int Low, const int High);
void Print(int** a, const int k, const int n);
void SwapMaxMinInOddCols(int** a, const int k, const int n);

int main()
{
    srand((unsigned)time(NULL));
    int Low = -10;
    int High = 10;
    int k, n;

    cout << "k = "; cin >> k;
    cout << "n = "; cin >> n;

    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    // Створюємо і виводимо початкову матрицю
    Create(a, k, n, Low, High);
    Print(a, k, n);

    // Міняємо місцями максимальний і мінімальний елементи непарних стовпців
    SwapMaxMinInOddCols(a, k, n);

    // Виводимо модифіковану матрицю
    Print(a, k, n);

    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int k, const int n, const int Low, const int High)
{
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int k, const int n)
{
    cout << endl;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

void SwapMaxMinInOddCols(int** a, const int k, const int n)
{
    for (int j = 0; j < n; j += 2) // Обробляємо тільки непарні стовпці
    {
        int minIdx = 0, maxIdx = 0;

        // Знаходимо індекси мінімального і максимального елементів у непарному стовпці
        for (int i = 1; i < k; i++)
        {
            if (a[i][j] < a[minIdx][j])
                minIdx = i;
            if (a[i][j] > a[maxIdx][j])
                maxIdx = i;
        }

        // Міняємо місцями мінімальний і максимальний елементи
        if (minIdx != maxIdx)
        {
            int temp = a[minIdx][j];
            a[minIdx][j] = a[maxIdx][j];
            a[maxIdx][j] = temp;
        }
    }
}
