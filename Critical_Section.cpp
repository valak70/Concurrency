// we'll see problem of race condition in critical section

#include<bits/stdc++.h>
#include<thread>
using namespace std;
using namespace this_thread;

static int resources = 1000;

/* Race Condition --
    multiple threads may try to accesss the resources at the same time 
    if you the run the program multiple time you'll notice you are getting diffrent number of resources left each time,
    which shouldnt be the case as we had 1000 resources and 1000 people taking them.
*/ 

void boo(){
    resources--;             // critical section       
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