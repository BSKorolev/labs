#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::swap;

#define N 1000

int main()
{
    int n;
    int sum[N], umn[N];
    cin >> n;
    int* mas = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> mas[i];
        sum[i] = 0;
        int x = mas[i];
        while (x > 0)
        {
            umn[i] *= x % 10;
            sum[i] += x % 10;
            x /= 10;
        }
    }
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
        {
            if (sum[i] > sum[j])
            {
                swap(mas[i], mas[j]);
                swap(umn[i], umn[j]);
                swap(sum[i], sum[j]);
            }
            else if (sum[i] == sum[j] && umn[i] > umn[j])
            {
                swap(mas[i], mas[j]);
                swap(umn[i], umn[j]);
                swap(sum[i], sum[j]);
            }
            else if (umn[i] == umn[j] && sum[i] == sum[j] && mas[i] > mas[j])
            {
                swap(mas[i], mas[j]);
                swap(umn[i], umn[j]);
                swap(sum[i], sum[j]);
            }
        }
    for (int i = 0; i < n; i++)
        cout << mas[i] << " ";
    delete[] mas;
}
