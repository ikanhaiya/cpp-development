#include<iostream> 
using namespace std;



class MyString{

private:

char* data;
size_t size;
size_t capacity;

    public:

    

  // setting up empty string;

    MyString(){
        this->size = 0;
        this->capacity = 1;
        this->data = new char[capacity];
       data[0] = '\0';
    }

    MyString(const char* str){

        size_t cnt = 0;
        const char* tmp = str;               // str is char ptr and tmp is also char ptr tmp must be const to point to same as str pointer otherwise it will be able to change the str
      
        // calculating the size of the string 
        while(*str!='\0'){
            cnt++;
            str++;
        }

        this->size = cnt;   // setting the size to cnt; 
        this->capacity = size+1;   // setting the capacity 
        this->data = new char[capacity];
        size_t i = 0;
        while(*tmp!='\0'){
            data[i] = *tmp;   // filling the data 
            tmp++; i++;
        }

        data[i] = '\0';
        
    }

    char& operator[](size_t index)
    {
    return data[index];
    }

    

    // doing cout<<s2; using friend function 

    friend ostream& operator<<(ostream& os, const MyString& other);  // tells compiler there is fn outside class that can access private data member of class

};

// ostream 

ostream& operator<<(ostream& os, const MyString& str){
    os<<str.data;   /* os<<str.data becomes: operator<<(os, str.data); ostream& operator<<(ostream& os,const char* str); already known by compiler and 
    str.data is const char* data */
    return os;
}



int main(){

    MyString s1;
    MyString s2("abc");

    cout<<s2<<endl;
    // cout<<s; compiler converts it into operator<<(cout,s);

    MyString s3(s2);
    cout<<s3<<endl;  // s2 is copied to s3; 

    cout<<s2[0]<<endl;  // s2[0] is converted to s2.operator[](0); cause as soon as compiler sees s2 it understands its of s2 class then it converts it to s2.opertor[](0) and this
    //  returns type char and compiler already knows cout<<char

    return 0;
}