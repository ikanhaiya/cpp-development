#include <iostream>
using namespace std;

void print()
{
    cout << "Done\n";
}

template<typename T, typename... Args>
void print(T first, Args... rest)
{
    cout << first << " ";
    print(rest...);
}

int main()
{
    print(10, 20.5, 'A', "Hello");
}