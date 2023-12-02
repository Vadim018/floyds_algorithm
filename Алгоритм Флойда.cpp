#include <iostream>
#include <iomanip>
using namespace std;

void Print(int** A, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            cout << setw(4) << A[i][j];
        cout << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "Ukr");

    const int size = 6;
    const int inf = 100;

    int C[size][size] =
    {
        { 0, 2, inf, 3, inf, 14 },
        { 2, 0, 6, inf, 2, inf },
        { inf, 6, 0, 2, inf, 5 },
        { 3, inf, 2, 0, 8, inf },
        { inf, 2, inf, 8, 0, 7 },
        { 14, inf, 5, inf, 7, 0 }
    };

    int** D = new int* [size];
    for (int i = 0; i < size; i++)

        D[i] = new int[size];
    for (int i = 0; i < size; i++)  // формування D0

        for (int j = 0; j < size; j++)
            D[i][j] = C[i][j];

    int** S = new int* [size];
    for (int i = 0; i < size; i++)
        S[i] = new int[size];

    for (int i = 0; i < size; i++)  // формування S0
        for (int j = 0; j < size; j++)
        {
            if ((D[i][j] == 0) || (D[i][j] == inf))
                S[i][j] = 0;
            else
                S[i][j] = i + 1;
        }

    cout << "Матриця D(0): " << endl;
    Print(D, size);

    cout << "Матрица S(0):" << endl;
    Print(S, size);

    for (int m = 0; m < size; m++)
    {
        for (int i = 0; i < size; i++)
            if ((i != m) || (D[i][m] != inf))
            {
                for (int j = 0; j < size; j++)
                    if (D[i][j] > D[i][m] + D[m][j])
                    {
                        D[i][j] = D[i][m] + D[m][j];
                        S[i][j] = S[m][j];
                    }
            }

        cout << "Матриця D: " << m + 1 << endl;
        Print(D, size);
        cout << "Матриця S: " << m + 1 << endl;
        Print(S, size);
    }

    cout << "Найкоротший шлях з вершини 1 до вершини 6: " << endl;
    cout << 6;

    int start = 0, end = 5;
    int i = S[start][end];

    while (1)
    {
        cout << " " << i;
        i = i - 1;
        i = S[start][i];

        if (i == start) 
            break;
    }
    cout << endl;
}