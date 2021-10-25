

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#define N 1000
int main()
{
    int n;
    bool flag=true;
    int mas[N];
    cin >> n;
    for (int i=0; i < n; i++)
    {
        cin >> mas[i];
    }
    
    for (int i=0; i < n; i++)
    {
        int x=0;
        for (int j=2; j < mas[i]; j++)
        {
            if (mas[i] % j == 0)
                x += 1;
            
        }
        
        if (x > 1)
        {
            continue;
        }
        if (x==1);
        {
            cout << "est prostoe" << endl;
            flag=false;
            break;
        }

    }
    int tmp = 0;
    if (flag==true)
    {
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
            {
                if (mas[i] > mas[j])
                {
                    tmp = mas[i];
                    mas[i] = mas[j];
                    mas[j] = tmp;

                }

            }
    }
    for (int i = 0; i < n; i++)
        cout << mas[i] << " ";
}

