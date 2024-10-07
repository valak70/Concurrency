//Multiple threads running

#include<bits/stdc++.h>
#include<thread>
using namespace std;
using namespace this_thread;


void boo(int time){
    cout<<"Thread executing : "<< get_id()<<endl;  // std :: this_thread :: get_id()   used namespace
    cout<<"Time is : "<<time<<endl;
}
int main()
{   
    /* For single thread we can use something like this :
        thread t1(boo,1);
        thread t2(boo,2);
        t1.join();
        t2.join(); 
    */
    vector<thread> threads;
    for(int i =0;i<10;i++){
        threads.push_back(thread(boo,i));
    }
    for(int i =0;i<10;i++){
        threads[i].join();
    }
    return 0;
}
