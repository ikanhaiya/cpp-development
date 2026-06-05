#include<bits/stdc++.h>
using namespace std;

/*Abstract class: An abstract class is that cant be instantiated(you cant create object of it directly)
its meant to be used as base class for other classes.
class Derived : public Base

an abstract class contain at least one pure virtual function.

virtual void show() = 0; --> =0 makes it pure virtual function it means this function has no implementation here 
any derived class must implement it 
*/

class Shape{
    public:
        virtual void draw() = 0; // pure virtual function

        ~Shape(){
            cout<<"Shape Destructor"<<endl;
        }
};

// Derived class 
class Circle : public Shape{

    public: 
        void show(){
            cout<<"circle\n";
        }
        void draw(){
            cout<<"Drawing Circle"<<endl;
        }
        ~Circle(){
            cout<<"Circle destructor"<<endl;
        }

};

// Another Derived class 

class Square : public Shape{

    public:
        void draw(){
            cout<<"Drawing Square"<<endl;
        }

};



int main(){

    // Shape s;  ERROR( cant create object of abstract class shape is abstract class)

    Shape* s1 = new Circle();
    // Circle c;
    Square sq;

    
    s1->draw(); // Drawing Circle 
    delete s1;
    s1 = &sq;
    s1->draw(); // Drawing Square

    


    /*Abstract class is used to define the common interface or behaviour
    to enforce implementation in derived classes
    to suppor runtime polymorphism 
    
    If there is atleast one pure virtual function then class is abstract class*/

/* Interfaces: Has no data members.
Has only pure virtual functions.
Defines what a class can do, not how it does it.
class can implement multiple interfaces using multiple inheritance */


/*      | Feature                         | Abstract Class                                  | Interface (C++ style) |
        | ------------------------------- | ----------------------------------------------- | --------------------- |
        | Pure virtual functions          | Yes                                             | Yes                   |
        | Normal function implementations | Can have                                        | Usually no            |
        | Data members                    | Can have                                        | Usually no            |
        | Constructors                    | Can have                                        | Usually not needed    |
        | Object creation                 | Not allowed if any pure virtual function exists | Not allowed           |  */
    
    

 
    return 0;
}