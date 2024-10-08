class ZeroEvenOdd {
private:
    int n;
    bool zeroTurn,oddTurn;
    condition_variable o,e,z;
    mutex mtx;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        zeroTurn = 1;
        oddTurn = 0;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for(int i=0;i<n;i++){
            unique_lock<mutex> lk(mtx);
            z.wait(lk,[this](){ return zeroTurn;});
            printNumber(0);
            zeroTurn = 0;
            if(i%2){
                oddTurn = 0;
                e.notify_one();
            }else{
                oddTurn = 1;
                o.notify_one();
            }
        }
    }

    void even(function<void(int)> printNumber) {
        for(int i=2;i<=n;i+=2){
            unique_lock<mutex> lk(mtx);
            e.wait(lk,[this](){ return !oddTurn && !zeroTurn;});
            printNumber(i);
            zeroTurn = 1;
            z.notify_one();
        }
    }

    void odd(function<void(int)> printNumber) {
        for(int i=1;i<=n;i+=2){
            unique_lock<mutex> lk(mtx);
            o.wait(lk,[this](){ return oddTurn && !zeroTurn;});
            printNumber(i);
            zeroTurn = 1;
            z.notify_one();
        }
    }
};