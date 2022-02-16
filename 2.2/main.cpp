#include <iostream>
#include <chrono>
#define N 1000000
class Timer
{
private:
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1> >;
    std::chrono::time_point<clock_t> m_beg;
public:
    Timer() : m_beg(clock_t::now())
    {}
    void reset()
    {
        m_beg = clock_t::now();
    }
    double elapsed() const
    {
        return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
    }
};
void Quicksort(int a, int b,int mas[N])
{
    if (a >= b)
        return;
    int m = rand() % (b - a + 1) + a;
    int k = mas[m];
    int l = a - 1;
    int r = b + 1;
    while (83)
    {
        do l = l + 1; while (mas[l] < k);
        do r = r - 1; while (mas[r] > k);
        if (l >= r)
            break;
        std::swap(mas[l], mas[r]);
    }
    r = l;
    l = l - 1;
    Quicksort(a,l,mas);
    Quicksort(r,b,mas);
}
void Bubblesort(int n, int mas[N])
{
    for (int i = 1; i < n; i++)
    {
        if (mas[i] >= mas[i - 1])
            continue;
        int j = i - 1;
        while (j >= 0 && mas[j] > mas[j + 1])
        {
            std::swap(mas[j], mas[j + 1]);
            j--;
        }
    }
}
int main() 
{
    srand(time(0));
    int  n;
    std::cin >> n;
    int* mas = new int[n];
    for (int i = 0; i < n; i++)
        mas[i] = rand();
    int a = 0;
    int b = n - 1;
    Timer t;
    Quicksort(a, b, mas);
    //Bubblesort(n,mas);
    std::cout <<  t.elapsed() << std::endl;
    delete[] mas;
}
