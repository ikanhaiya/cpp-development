#include<bits/stdc++.h>
using namespace std;

int f(int a){
    a = 10;
    cout<<a*10;

    return 1;
} 

int main(){

    // used to prevent from modifying data 

    const int a = 5;

    a = 10;

    const vector<int> v = {1,2,3,4,5,53,241,1,4,234};

    // for(int i= 0;i<v.size();i++){
    //     // v[i]=1;  // cant modify v is const 
    // }

    // for(auto &it : v){
    //     cout<<it<<" "; 
    // }

    f(5);
   
    

    return 0;
}