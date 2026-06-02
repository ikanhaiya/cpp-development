
#include<bits/stdc++.h>
using namespace std;

int main(){

    // REFRENCE 
    int a = 10;
    int &ref = a;  // a and ref both point to the same memory only memory space is there no new int is created
    // reference must be initialised.
    int d  = 90;
    ref = d;
    cout<<a<<endl;    // 10
    cout<< ref << endl;  // 10 //  // ref is reference to a

    ref = 20; 
    cout<<ref<<" "<<a<<endl; // changing ref changes a. 


    return 0;
}