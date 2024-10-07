// Jthreads call the join() when goes out of scope 

#include<bits/stdc++.h>
#include<thread>
using namespace std;
using namespace this_thread;


void boo(int time){
    cout<<"Thread executing : "<< get_id()<<endl;  // this_thread :: get_id()   used namespace
    cout<<"Time is : "<<time<<endl;
}
int main()
{   
    vector<jthread> jthreads;
    for(int i =0;i<10;i++){
        jthreads.push_back(jthread(boo,i));
    }
    // for(int i =0;i<10;i++){
    //     jthreads[i].join();     we dont need this 
    // }
    return 0;
    // ~jthread() will call join() when it comes here (out of scope).
}