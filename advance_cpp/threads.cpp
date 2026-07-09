#include <iostream>
#include <thread>

using namespace std;

void task(int& a) {
    for(int i = 1; i <= 50; i++)
        std::cout << "Worker: " << i << '\n';
}

int main() {

    int a = 5;

    unsigned int  n =  thread::hardware_concurrency(); // returns number of cpu cores available for concurrent execution. 
    cout<<n<<endl;

    thread t(task,ref(a)); // thread copies its argument by default if thread function accepts reference of paramenter then do ref(); 

    for(int i = 1; i <= 50; i++)
        std::cout << "Main: " << i << '\n';

    t.join();
}

/* 
Process

 ├── Main Thread
 │      |
 │      └── main()
 │
 └── Worker Thread
        |
        └── task()
        
*/