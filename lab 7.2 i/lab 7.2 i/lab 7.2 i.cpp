#include <iostream>
#include <iomanip>
#include <time.h>
#include <Windows.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High) {
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int rowCount, const int colCount) {
    cout << endl;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

int FindSumOfMinInEvenColumns(int** a, const int rowCount, const int colCount) {
    int sum = 0;
    for (int j = 0; j < colCount; j += 2) {
        int minElement = a[0][j];
        for (int i = 1; i < rowCount; i++) {
            if (a[i][j] < minElement) {
                minElement = a[i][j];
            }
        }
        sum += minElement;
    }
    return sum;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand((unsigned)time(NULL));

    int Low = -34;
    int High = 26;
    int rowCount;
    int colCount;

    cout << "k = "; cin >> rowCount;
    cout << "n = "; cin >> colCount;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    Create(a, rowCount, colCount, Low, High);
    Print(a, rowCount, colCount);

    int sum = FindSumOfMinInEvenColumns(a, rowCount, colCount);
    cout << "Сума мінімальних елементів по парних стовпцях: " << sum << endl;

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}