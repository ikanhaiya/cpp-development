#include<bits/stdc++.h>
using namespace std;

class LRUCache{

    unordered_map<int, list<pair<int,int>>::iterator> mp;
    list<pair<int,int>> lru; 
    int capacity;

    public: 
        LRUCache(): capacity(10) {}

    void put(int key, int value){

        if(lru.size()<capacity || mp.count(key)){

            if(mp.count(key)){
                auto it = mp[key];
                lru.erase(it);
            }
            
            lru.push_front({key,value});
            auto it = lru.begin();
            mp[key] = it;
        }
        else{
            auto it = lru.end();
            it--;
            int k = it->first;
            mp.erase(k);
            lru.pop_back();
            lru.push_front({key,value});
            auto itt = lru.begin();
            mp[key] = itt;
        }
    }
    
    int get(int key){
        if(mp.count(key)){
            auto it = mp[key];
            lru.splice(lru.begin(),lru,it);
            return it->second;
        }
        throw out_of_range("key not found");
    }

};

int main(){

    LRUCache LRU;

    srand(time(nullptr));

    for(int i = 0;i<10;i++){
        int x  = rand();
        LRU.put(i,x%1000);
    }

    LRU.put(11,123);
    cout<<LRU.get(11);

    return 0;
}