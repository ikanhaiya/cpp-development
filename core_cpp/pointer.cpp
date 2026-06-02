#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int a = 67;

    int *ptr = &a;
    int **ptr2 = &ptr;


    cout<<"&a "<<&a<<endl;  
    cout<<"&ptr  "<<&ptr<<endl;
    cout<<"*ptr2 "<<*ptr2<<endl; 
    cout<<"ptr2 "<<ptr2<<endl;
    cout<<"&ptr2 "<<&ptr2<<endl;


    return 0;
}