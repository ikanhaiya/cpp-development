#include<bits/stdc++.h>
using namespace std;


class MyInt {
    int* ptr;

public:
    MyInt(int value) {
        ptr = new int(value);
        cout << "Memory allocated\n";
    }

    ~MyInt() {
        delete ptr;
        cout << "Memory released\n";
    }
};


int main(){

    MyInt a(10);

    return 0;
}