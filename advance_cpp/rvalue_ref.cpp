#include <iostream>
using namespace std;

class MyString {
public:

    MyString() {
        cout << "Default Constructor\n";
    }

    MyString(const MyString&) {
        cout << "Copy Constructor\n";
    }

    MyString(MyString&&) {
        cout << "Move Constructor\n";
    }
};

int main() {

    MyString a;

    cout << "\nCase 1\n";
    MyString b = a;

    cout << "\nCase 2\n";
    MyString c = MyString();

    cout << "\nCase 3\n";
    MyString d = std::move(a);

    return 0;
}
