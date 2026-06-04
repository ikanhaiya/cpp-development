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
        this->capacity = 2*size;   // setting the capacity 
        this->data = new char[capacity];
        size_t i = 0;
        while(*tmp!='\0'){
            data[i] = *tmp;   // filling the data 
            tmp++; i++;
        }

        data[i] = '\0';
        
    }

    // to access char at any index in string like s[idx]; 

char& operator[](size_t index)
{
    if(index >= size)
    {
        throw out_of_range("Index out of range");
    }

    return data[index];
}

    // for CONCATENATION of string 

    MyString operator+(const MyString& other){

        char* tmpStr1 = data;
        char* tmpStr2 = other.data;

        size_t resCap = size + other.size + 1;      // getting the capacity for the new result string; 
        
        MyString result;
        result.data = new char[resCap];   
        result.capacity = resCap;
        result.size = size+other.size; 

        size_t idx = 0; 

        while(*tmpStr1!='\0'){
            result.data[idx] = *tmpStr1;
            tmpStr1++;
            idx++;
        }
       
        

        while(*tmpStr2!='\0'){
            result.data[idx] = *tmpStr2;
            tmpStr2++;
            idx++;
        }
       
        result.data[idx] = '\0';

        return result;


    }

   // Method to get length of the string
   
   size_t length(){
     
    return this->size;
   }

   // APPENDING Character to the string push_back

    void push_back(char ch){
        
        if(size + 1 >= capacity)
    {
        size_t newCapacity = capacity * 2; // increasing the size;

        char* newData = new char[newCapacity];

        for(size_t i = 0; i < size; i++)
        {
            newData[i] = data[i];
        }

        delete[] data;

        data = newData;
        capacity = newCapacity;
    }

    data[size] = ch;
    size++;

    data[size] = '\0';


    }

    // REMOVING LAST Character 

    void pop_back(){

        if(size>0){
            size = size - 1;
            data[size] = '\0';
            // capacity = capacity-1;   // dont reduce capacity, cause memory is still allocated just changing the variable wont do anything;
        }
        else{
            throw out_of_range("invalid memory access");
        }

    }

    // COMPARING two strings whether they are equal or not here we will == operator overloading 

    bool operator==(const MyString& other) const {

        if(size!=other.size){
            return false;
        }

        char* tmp1 = data;
        char* tmp2 = other.data;

        while(*tmp2!='\0'){
            if(*tmp2!=*tmp1){
                return false;
            }
            tmp2++;
            tmp1++;
        }

        return true;
    }

    bool operator!=(const MyString& other) const
    {
            return !(*this==other);
    }

    // Finding SUBSTRING in string whether it exists or not; 
size_t find(const MyString& pattern)
{
    if(pattern.size == 0)
        return 0;

    if(size < pattern.size)
        return static_cast<size_t>(-1);

    // Build LPS array
    size_t* lps = new size_t[pattern.size];

    lps[0] = 0;

    size_t len = 0;
    size_t i = 1;

    while(i < pattern.size)
    {
        if(pattern.data[i] == pattern.data[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if(len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }

    // KMP Search
    size_t j = 0;
    i = 0;

    while(i < size)
    {
        if(data[i] == pattern.data[j])
        {
            i++;
            j++;
        }

        if(j == pattern.size)
        {
            delete[] lps;
            return i - j;
        }
        else if(i < size && data[i] != pattern.data[j])
        {
            if(j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }

    delete[] lps;

    return static_cast<size_t>(-1);
}

    

    // doing cout<<s2; using friend function 

    friend ostream& operator<<(ostream& os, const MyString& other);  // tells compiler there is functioncl outside class that can access private data member of class

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
    MyString s4("aaaaaaaaaaabab");

    cout<<s2<<endl;
    // cout<<s; compiler converts it into operator<<(cout,s);

    MyString s3(s2);
    cout<<s3<<endl;  // s2 is copied to s3; 

    cout<<s2[0]<<endl;  // s2[0] is converted to s2.operator[](0); cause as soon as compiler sees s2 it understands its of s2 class then it converts it to s2.opertor[](0) and this
    //  returns type char and compiler already knows cout<<char

    cout<<s2+s4<<endl;

    cout<<s2<<" "<<s4<<endl;
    
    cout<<s2.length()<<endl;  // getting length of the string 

    s2.push_back('g');

    cout<<s2<<endl;

    s2.pop_back();
    cout<<s2<<endl;

    // s1.pop_back();

    cout<<s4.find("aaab");

    return 0;
}

