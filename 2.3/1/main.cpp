#include <iostream>
#include <chrono>
#define N 100000
#define M 10000
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
void Quicksort(int a, int b, int mas[N])
{
    if (a >= b)
        return;
    int m = rand() * rand() % (b - a + 1) + a;
    int k = mas[m];
    int l = a - 1;
    int r = b + 1;
    while (107)
    {
        do l = l + 1; while (mas[l] < k);
        do r = r - 1; while (mas[r] > k);
        if (l >= r)
            break;
        std::swap(mas[l], mas[r]);
    }
    r = l;
    l = l - 1;
    Quicksort(a, l, mas);
    Quicksort(r, b, mas);
}
int Binarysearch(int a, int b, int f, int mas[N])
{
    Quicksort(a, b, mas);
    if (f < mas[a])
        return -1;
    if (f == mas[a])
        return a;
    if (f > mas[b])
        return -1;
    a = 0;
    b = N - 1;
    while (a + 1 < b)
    {
        int c = int((a + b) / 2);
        if (f > mas[c])
            a = c;
        else
            b = c;
    }
    if (mas[b] == f)
        return b;
    else if (mas[a] == f)
        return a;
    else
        return -1;
}
void Search(int f, int num, int mas[N])
{
    for (int i = 0; i < M; i++)
        for (int i = 0; i < N; i++)
            if (mas[i] == f)
            {
                num = i;
                break;
            }
}
int main()
{
    srand(time(0));
    int f, num = 0;
    std::cin >> f;
    int  n;
    std::cin >> n;
    int* mas = new int[n];
    for (int i = 0; i < n; i++)
        mas[i] = rand()%N;
    int a = 0;
    int b = n - 1;
    Timer t;
    Binarysearch(a, b, f, mas);
    //Search(f,num,mas);
    std::cout << t.elapsed() << std::endl;
    delete[] mas;
}