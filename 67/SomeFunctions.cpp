#pragma once
#include "SomeFunctions.hpp"
#include <iostream>
#include <math.h>

#define N 50
#define M 50

namespace mt

{
    int s = 0;
    int v = 0;
    int d = 0;
    bool isPrime(int x)
    {

        if (x < 2)

            return false;
        for (int d = 2; d <= sqrtl(x); d++)
            if (x % d == 0)
                return false;
        return true;
    }


    void max(int n, int m, int matrix[N][M])
    {

        int max = matrix[0][0];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (max < matrix[i][j])
                {
                    max = matrix[i][j];
                    s = 1;
                }
                else if (max == matrix[i][j])
                    s += 1;
            }
        }
    }
    void Read(int& n, int& m, int matrix[N][M])
    {
        std::cin >> n >> m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                std::cin >> matrix[i][j];

    }
    bool ConsistsPrime(int n, int m, int matrix[N][M])
    {

        for (int i = 0; i < n; i++)
            if (std::isPrime(matrix[i][0]))
            {
                return true;
                v += 1;
            }
        return false;
    }
    void sort(int n, int m, int matrix[N][M])
    {
        if (s > 1)
        {

            for (int i = 0; i < n; i++)
            {
                if (ConsistsPrime)
                    v += 1;
                for (int k = i + 1; k < m; k++)
                {
                    if (ConsistsPrime)
                        d += 1;
                    if (v < d)
                    {
                        for (int j = 0; j < m; j++)
                        {
                            swap(matrix[i][j], matrix[k][j]);
                        }
                    }
                }
            }
        }

    }
    void Write(int n, int m, int matrix[N][M])
    {
        if (s > 1)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                    cout << matrix[i][j] << " ";

                cout << endl;
            }

        }
        else
            cout << "ne robit";
    }

}

