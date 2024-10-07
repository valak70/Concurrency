// Here we'll solve race condition problem on critical section using mutex (mutual exclusion)
#include<bits/stdc++.h>
#include<thread>
#include <mutex>
using namespace std;
using namespace this_thread;

static int resources = 1000;
mutex mtx;

/* Now what mutex will do is put a lock so only one thread can access it at a particular time,
after this thread goes out of critical section we can unlock it for other threads.
This program would always leave 0 resoures after executing.*/

void boo(){
    mtx.lock();
    resources--;             // critical section       
    mtx.unlock();
    /* or we can use
        lock_guard<mutex> lock(mtx);    // this wont need unlocking manually
        resources--;
    */
}

int main()
{   
    vector<thread> threads;
    for(int i =0;i<1000;i++){
        threads.push_back(thread(boo));
    }
    for(int i =0;i<1000;i++){
        threads[i].join();
    }
    cout<< resources<<endl;
    return 0;
}