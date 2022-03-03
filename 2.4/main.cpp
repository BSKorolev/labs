#include <iostream>
#include <chrono>
#define N 10000
#define M 1000
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
struct T_List
{
    T_List* next;
    int age;
};
void ADD(T_List* head, int age)
{
    T_List* p = new T_List;
    p->age = age;

    p->next = head->next;
    head->next = p;
}
int Search(int k,int n, int mas[N])
{
        for (int i = 0; i < n; i++)
            if (mas[i] == k)
                return 1;
}
int ListSearch(T_List* head, int& k)
{
    T_List* p = head;
    while (p->next != nullptr)
    {
        if (p->age == k)
        {
            return 1;
        }
        p = p->next;
    }
    return -1;
}
int main()
{
    srand(time(0));
    int k;
    std::cin >> k;
    int  n;
    std::cin >> n;
    int* mas = new int[n];
    for (int i = 0; i < n; i++)
        mas[i] = rand() % N;
    T_List* head = new T_List;
    head->next = nullptr;
    for (int i = 0; i < n; i++)
        ADD(head, rand() % N);
    Timer t1;
    Search(k, n, mas);
    std::cout << t1.elapsed() << std::endl;
    Timer t2;
    ListSearch(head, k);
    std::cout << t2.elapsed() << std::endl;
    delete[] mas;
    delete head;
}
