#include <iostream>
#include <thread>
#include <future>

using namespace std;

// int worker(int p){
//     p=100;
//     return p;                   // cant do like this because return value is ignored in threds
// }

void worker(promise<int> p)
{
     p.set_value(100); // sets the promise to value' 
}

int main()
{
    promise<int> p;

    future<int> f = p.get_future(); // now future  points to same shared data, or future points to promise; 

    thread t(worker, move(p));  // return value is ignored in threads 

    cout << f.get() << endl; // Retrieves the value (blocks if not ready).

    t.join();

    return 0;
}