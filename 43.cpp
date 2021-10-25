#include <iostream>

using std::cin;
using std::cout;
using std::endl;
#define N 100
#define M 10

int main()
{
    int n, m;
    int umn = 1;
    int index = 0;
    int matrix[N][M];
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];

    int p = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            p *= matrix[i][j];
            if (umn < p)
            {
                umn = p;
                index = i;
            }

        }
        p = 1;
    }


    for (int j = 0; j < m + 1; j++)
    {
        matrix[index][j] = umn;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << matrix[i][index] << " ";

        cout << std::endl;
    }


    
}

