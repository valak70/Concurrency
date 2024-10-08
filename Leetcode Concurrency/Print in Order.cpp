class Foo {
    condition_variable a,b;
    mutex mtx;
    bool firstdone,secondDone;
public:
    Foo() {
        firstDone= 0;
        secondDone =0;
    }

    void first(function<void()> printFirst) {
        printFirst();
        firstDone =1;
        a.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lk(mtx);
        a.wait(lk,[this](){return firstDone;});
        printSecond();
        secondDone = 1;
        b.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lk(mtx);
        b.wait(lk,[this](){return secondDone;});
        printThird();
    }
};