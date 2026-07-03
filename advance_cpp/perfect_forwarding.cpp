#include <iostream>
using namespace std;

void process(int& x)
{
    cout << "Lvalue\n";
}

void process(int&& x)
{
    cout << "Rvalue\n";
}

template<typename T>
void wrapper(T&& arg)
{   
    process(arg); // it will not preserve the value type (lvalue or rvalue); 
    process(std::forward<T>(arg));
}

int main()
{
    int a = 10;

    cout << "Passing Lvalue\n";
    wrapper(a);

    cout << "\nPassing Rvalue\n";
    wrapper(20);
}