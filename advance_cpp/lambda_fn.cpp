#include<bits/stdc++.h>
using namespace std;

int main(){

    int a = 5;
    int b = 12;

    auto add = [=](){
        return (a+b);
    };

    cout<<add();

    auto add2 = [a,b](){
        cout<<a+b;
    };

    add2();  // when using return then use cout, lambda is not function is actually object; 
    

    return 0;
}