#include <bits/stdc++.h>
using namespace std;

//Operator Overloading allows you to define how operators (+, -, ==, <<, etc.) work for your own classes.


// overloading + for complex numbers; 

class Complex {
public:
    int real, imag;

    Complex(int r, int i) {
        real = r;
        imag = i;
    }

    Complex operator+(const Complex& other) {
        return Complex(
            real + other.real,
            imag + other.imag
        );
    }
};

// overloading '==' for any class

class Student {
 
public:
    int id;
    string name;



    Student(int ID,string name) {
        this->id = ID;
        this->name =name;
    }

    bool operator==(const Student& other) {
        return id == other.id;
    }

    ~Student(){
        cout<<name<<" object"<<" destroyed"<<endl;
    }


    // overloading * for class pointer 
    
};

int main() {
    Complex c1(2, 3);
    Complex c2(4, 5);

    Complex c3 = c1 + c2;

    /* without operator overloading we have to do 
     c3 = c1.add(c2);   
    */

    cout << c3.real << " " << c3.imag<<endl;
    

    Student s1 = Student(1,"s1");
    Student s2 = Student(2,"s2");

    cout<<s1.id<<endl;

// All above objects are created in stack 

    Student* st = &s1;
    cout<<st<<endl;

    cout<<(s1==s2)<<endl;

// Creating object in Heap;
    
    Student* s3 = new Student(3,"s3");

    // delete s3;  --> s3 will be deleted first because as soon compiler sees delete s3 it call destructor for it 

    // but all other objects will delete and destructor called when object scope ends at the end of the program 

    auto s4 = make_shared<Student>(4,"s4");

    auto s6 = move(s4);

   
    Student s7 = move(s2);

    auto s5 = make_unique<Student>(5,"s5");
    

return 0;


}