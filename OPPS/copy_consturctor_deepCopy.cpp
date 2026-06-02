#include<bits/stdc++.h>
using namespace std;

class A {
public:
    int* ptr;


    A(int x) {
        ptr = new int(x);
    }

    // custom constructor to fix double free of the ptr pointer 
    A(const A& other) {

        // DEEP copy
        ptr = new int(*other.ptr);  // now a1.ptr and a2.ptr will be point to different memory blocks both containing 10 as value
    }

    ~A() {
        cout<<*ptr<<endl;
        delete ptr;
    }
};

int main(){

    A a1(10);
    A a2 = a1; 
    // complier generated copy constructor and does a2.ptr = a1.ptr

    /* a1.ptr and a2.ptr both point to the same memory so when object scope ends destructor is called 
    for both objects a1 and a2 
    delete ptr 
    delete ptr   --> this happens twice same block of memory cant be freed twice
    " free(): double free detected in tcache 2 " --> this will be given on terminal

    to fix this

    // DEEP COPY is used  : each object gets its own memory 
    A(const A& other) {
        ptr = new int(*other.ptr); ---> this is deep copy meaning creating spereate copy memory block
    }

    shallow copy 
    a1.ptr = a2.ptr  both object share same address 

    */
    




    return 0;
}