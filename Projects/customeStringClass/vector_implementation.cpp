
#include<iostream>
#include<initializer_list>

using namespace std;

template<typename T>

class vector{

    T* data;
    size_t size;
    size_t capacity;

public: 
    vector() : size(0), capacity(1){
        data = new T[capacity];
    }

    vector(initializer_list<T> lst){
        size = lst.size();
        capacity = (size == 0) ? 1 : size * 2;
        data = new T[capacity]; 

        size_t i = 0;

    for(auto element : lst){
        data[i] = element; 
        i++;
       }
    }

    T& operator[](size_t idx){

        if(idx>=size){
            throw out_of_range("idx out of range");
        }
        return data[idx];

    }

    size_t length(){
        return size;
    }

    void push_back(T x){

        if(size+1==capacity){
            capacity = capacity*2;

            vector res;
            res.data = new T[capacity];
            res.size = size+1;
            
            size_t idx = 0;
            T* it = data;

            while(idx<size){
                res.data[idx] = *it;
                it++; idx++;
            }
            res.data[idx] = x; // here idx  == res.size-1;
            this->size = res.size;
            data = res.data;

        }
        else{
            size+=1;
            data[size-1] = x;
            
        }

    }

    void pop_back(){
        
        if(size == 0) {
        throw std::out_of_range("Vector is empty");
        }
        size = size-1;
    }

    

};



int main(){

    vector<int> v = {1,2,4,5};  // compiler converts it to initializer_list of type T;
    
    cout<<v[0]<<endl;
    v.push_back(6);
    cout<<v[4]<<" "<<v.length()<<endl;;
    v.pop_back();
    cout<<v.length();    

    return 0;
}