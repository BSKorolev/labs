#include <iostream>
#include <fstream>

struct Elem
{
    int data;       
     
    Elem* left;
    Elem* right;
    Elem* parent;
};
Elem* Make(int data, Elem* p)
{
    Elem* q = new Elem;             
    q->data = data;
    q->left = nullptr;
    q->right = nullptr;
    q->parent = p;
    return q;
}
void Add(int data, Elem*& root)
{
    if (root == nullptr) {
        root = Make(data, nullptr);
        return;
    }
    Elem* v = root;
    while ((data < v->data && v->left != nullptr) || (data > v->data && v->right != nullptr))
        if (data < v->data)
            v = v->left;
        else
            v = v->right;
    if (data == v->data)
        return;
    Elem* u = Make(data, v);
    if (data < v->data)
        v->left = u;
    else
        v->right = u;
}
Elem* Search(int data, Elem* v)    
{
    if (v == nullptr)
        return v;
    if (v->data == data)
        return v;
    if (data < v->data)
        return Search(data, v->left);
    else
        return Search(data, v->right);
}
void SearchNum(int data, Elem* v, int n)
{
    if (v == nullptr)
    {
        std::cout << "n";
        return;
    }
    if (v->data == data) 
    {
        std::cout << n << std::endl;
        return;
    }
    if (data < v->data)
        SearchNum(data, v->left, n + 1);
    else
        SearchNum(data, v->right, n + 1);
}
void Delete(int data, Elem*& root)
{
    Elem* u = Search(data, root);
    if (u == nullptr)
        return;
    if (u->left == nullptr && u->right == nullptr && u == root)
    {
        delete root;
        root = nullptr;
        return;
    }
    if (u->left == nullptr && u->right != nullptr && u == root) 
    {
        Elem* t = u->right;
        while (t->left != nullptr)
            t = t->left;
        u->data = t->data;
        u = t;
    }
    if (u->left != nullptr && u->right == nullptr && u == root) 
    {
        Elem* t = u->left;
        while (t->right != nullptr)
            t = t->right;
        u->data = t->data;
        u = t;
    }
    if (u->left != nullptr && u->right != nullptr)
    {
        Elem* t = u->right;
        while (t->left != nullptr)
            t = t->left;
        u->data = t->data;
        u = t;
    }
    Elem* t;
    if (u->left == nullptr)
        t = u->right;
    else
        t = u->left;
    if (u->parent->left == u)
        u->parent->left = t;
    else
        u->parent->right = t;
    if (t != nullptr)
        t->parent = u->parent;
}
int main()
{
    Elem* root = nullptr;
    std::ifstream in("input.txt");
    char symbol;
    int date;
    while (!in.eof())
    {
        in >> symbol;
        if(symbol == '+') 
        {
            in >> date;
            Add(date, root);
        }
        if (symbol == '?')
        {
            in >> date;
            SearchNum(date,root,1);
        }
        if (symbol == '-')
        {
            in >> date;
            Delete(date, root);
        }
        if (symbol == 'E')
            break;
    }
}
