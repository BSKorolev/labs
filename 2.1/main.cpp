#include <iostream>
#include <chrono>
#include <windows.h>

#define N 10000
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

void sortS(char S[],char vowels[])
{
    bool flag = false;
    for (int i = 0; i < strlen(S); i++)
        for (int j = 0; j < 10; j++)
            if (S[i] == vowels[j])
            {
                flag = true;
                break;
            }
    if (flag)
    {
    for (int i = 0; i < strlen(S) - 1; i++)
            for (int j = i + 1; j < strlen(S); j++)
                if (S[i] > S[j])
                {
                    int tmp = S[i];
                    S[i] = S[j];
                    S[j] = tmp;
                }
    std::cout << S << std::endl;
    }
}
int main()
{
    srand(time(0));
    char eng[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's','t', 'u', 'v', 'w', 'x', 'y', 'z' };
    char vowels[6] = { 'a', 'e', 'i', 'o', 'u', 'y'};
    int a,n;
    std::cin >> n;
    char S[N];
    for (int i = 0; i < n; i++)
    {
        a = rand() % 26;
        S[i] = eng[a];
    }
    std::cout << S << std::endl;
    Timer t;
    sortS(S,vowels);
    std::cout << "Time elapsed : " << t.elapsed() << std::endl;
}
