#include<bits/stdc++.h>
using namespace std;

 // smart pointers deallocate the alloted memory when pointer goes out of scope;

template<typename T>
class SmartPointer{

    T* ptr;

public:

    SmartPointer(T* p){
        ptr = p;
    }

    ~SmartPointer(){
        delete ptr;
    }

    T& operator*(){
        return *ptr;
    }

    T* operator->(){
        return ptr;
    }

};


int main(){

    auto ptr = make_unique<int>(10);

    // auto ptr3 = ptr; ptr is unique cant point to other pointer;
    
    // shared pointer counts the reference, how many pointer are pointing to the resource
    auto ptr2 = make_shared<int>(20);
    auto ptr3 = ptr2;

    cout<<"ptr is unique pointer: "<<*ptr<<endl;

    auto ptr4 = move(ptr);
   
    
    weak_ptr<int> wk = ptr2;  

    cout<<"ownership of ptr(unique pointer) transfered to ptr4: "<<*ptr4<<endl;

    cout<<"2 pointers to same resource (shared pointers): "<<*ptr2<<" "<<*ptr3<<endl;

    string a = "abcsad";

    string b = move(a);
    cout<<"this is a: "<<a<<endl; // gives nothing as its ownership is transfered to string b
    cout<<"this is b: "<<b<<endl;

    return 0;
}