#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex m1;
mutex m2;

void worker1()
{
    lock_guard<mutex> lock1(m1); // locks m1; 
    scoped_lock lock(m1,m2);

    this_thread::sleep_for(chrono::milliseconds(100));

    lock_guard<mutex> lock2(m2); // need m2 to move forward but m2 locked by t2;
 
    cout << "Worker 1\n"; 
}

void worker2()
{
    lock_guard<mutex> lock1(m2); // locks m2 

    this_thread::sleep_for(chrono::milliseconds(100)); 

    lock_guard<mutex> lock2(m1); // need m1 to move forward, but m1 locked by t1

    cout << "Worker 2\n";
}

// sleep is used to demonstrate the deadlock, if sleep not used its possible that any one thread might get the both locks
// then do the task and deadlock may not happen. 

int main()
{
    thread t1(worker1);
    thread t2(worker2);

    t1.join();
    t2.join();
  // this whole code freezes
    return 0;
}