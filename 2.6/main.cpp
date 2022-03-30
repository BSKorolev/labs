#include <iostream>

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
}
void DELETE(T_List* head,int d)
{
    T_List* tmp;
    T_List* p = head;
    while (p->next != nullptr)
    {
        if (p->next->age == d)
        {
            tmp = p->next;
            p->next = p->next->next;
            delete tmp;
        }
        else
            p = p->next;
    }
}
void Clear(T_List* head)
{
    T_List* tmp;
    T_List* p = head->next;
    while (p != nullptr)
    {
        tmp = p;
        p = p->next;
        delete tmp;
    }
}
int main()
{
    int  n;
    std::cin >> n;
    T_List* head = new T_List;
    head->next = nullptr;
    for (int i = 0; i < n; i++)
        ADD(head, rand() % 100000);
    int k, d,a;
    std::cin >> a;
    ADD(head, a);
    std::cin >>k;
    ListSearch(head,k);
    std::cin >> d;
    DELETE(head, d);
    Clear(head);
    delete head;
}
