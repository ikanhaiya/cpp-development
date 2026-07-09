#include<bits/stdc++.h>
using namespace std;

int counter = 0; //read(counter)->increement(counter) -> write(counter): interleaving happens;

atomic<int> counter2(0); // counter2 is atomic (LOCK XADD) instruction used 

/* read(counter2)->increement(counter2) -> write(counter2) : happens in one go not interleaving happens
*/

void work()
{
    for(int i=0;i<10000;i++){
        counter++;
        counter2++;
    }
}

int main(){

    thread t1(work);
    thread t2(work);

    t1.join();
    t2.join();

    cout<<counter<<" "<<counter2<<endl;  // counter2 is always 20000 but counter1 varies

    return 0;
}