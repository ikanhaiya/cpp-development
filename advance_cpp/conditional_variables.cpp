#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex mtx;
condition_variable cv;

bool ready = false;

void worker()
{
    unique_lock<mutex> lock(mtx); // locks a mutex when wait() gets first time mutex its already locked 

    cv.wait(lock, [] {  // if lamda return false then cv.wait unlocks mutex and thread waits here , but before going to lamda function cv.wait locks the mutex then only check ready 

        // The mutex is already locked before the first check because
    // unique_lock<mutex> lock(mtx) acquired it.
    //
    // If the predicate returns false:
    // 1. wait() unlocks the mutex.
    // 2. The thread sleeps.
    // 3. When notified, wait() locks the mutex again.
    // 4. The predicate is checked again.
       
        return ready;
    });   
// If the predicate becomes true, wait() returns while still owning the mutex.  
// The mutex remains locked until 'lock' (unique_lock) goes out of scope.
    cout << "Worker Started\n";
}

void worker2()
{
    unique_lock<mutex> lock(mtx);

    cv.wait(lock);          // it unlocks the mutex and Wait until notified

    cout << "Worker 2 started and end: "<<ready << endl;
}

int main()
{
    thread t(worker);
    thread t2(worker2);

    {
        lock_guard<mutex> lock(mtx);  // used to lock the mtx and 
        ready = true;
    }

    cv.notify_all();   // used to wakeup the sleeping thread 
                      /*  
                    Wake Up

                    ↓

                    Lock Mutex 🔒

                    ↓

                    Execute Lambda

                    ↓

                    return ready; */

    t.join();
    t2.join();

    return 0;
}