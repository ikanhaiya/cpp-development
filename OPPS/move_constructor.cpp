#include<bits/stdc++.h>
using namespace std;

//A move constructor is a special constructor that transfers ownership of resources from one object to another instead of copying them.
// syntax --> ClassName(ClassName&& other);

class A {
public:
    int* data;

    A(int n) {
        data = new int(n);
        // cout<<*data;
    }

     A(A&& other){
        data = other.data;
                                // transferring the ownership of resource 
        other.data = nullptr;

     }

    ~A() {
        cout<<*data<<" is deleted"<<endl;
        delete data;
    }
};
int main(){

    A a(10);

    cout<<*a.data<<endl;

    A b(std::move(a));


    return 0;
}