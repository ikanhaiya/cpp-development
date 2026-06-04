#include<bits/stdc++.h>
using namespace std;

/*Compiler time polymorphism(Static Polymorphism):
Achieved using Function Overloading, Operator Overloading, Templates 
*/

class Animal {
public:
    void sound() {
        cout << "Animal Sound\n";
    }
};

class Dog : public Animal {
public:
    void sound() {
        cout << "Bark\n";
    }
};

// <-------------------------------------------------------->

/*Runtime polymorphism -- achieved using virtual keyword 
compiler creates vtable (virtual table) for class containing address of the virtual function each object contains hidden pointer vptr and it points to class's vtable 

virtual tells cpp wait untill runtime and see what object I'm actually pointing to

Override: it tells compiler that i intednt to override the virtual function from the base class.

when have polymorphism base class make destructor virtual 
*/



class Bird {
public:
    virtual void sound() {
        cout << "Bird Sound\n";
    }


    virtual ~Bird(){
        cout<<"Bird Destructor\n";
    }
};

class Parrot : public Bird {

int* data;
public:

    Parrot(){
        data = new int[10];
    }
    void sound() override{
        cout << "parrot sound\n";
    }
    ~Parrot(){
        cout<<"Parrot Destructor\n";
    }
};


int main(){

    Animal* ptr = new Dog();
    ptr->sound();  //ptr->sound() gives "Animal Sound" cause ptr is of type Animal* compiler decides which function to call at compile time

    Bird* bd = new Parrot();
    bd->sound(); // bd->sound() gives "Parrot Sound", At runtime bd actually points to parrot object so parrot's version is executed 

    delete bd; // to delete bd which is pointer of type bird but at runtime points to parrot object and allocated memory also to run the destructor of the parrot 
    // you have to make destructor of bird class as virtual. 

    return 0;
}