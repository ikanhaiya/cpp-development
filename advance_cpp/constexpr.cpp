#include<bits/stdc++.h>
using namespace std;

constexpr int square(int x)
{
    return x * x;
}

int main(){

    int arr[square(5)];  // before cpp 14 array size must be known at compile time but typical functions runs at runtime, declaring array like this would have given error before cpp 14

    cout<<sizeof(arr)/sizeof(arr[0]);  // output 25; 

    return 0;

}
