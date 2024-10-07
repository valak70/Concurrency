class Foo {
public:
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
    }

    void second(function<void()> printSecond) {
        this_thread::sleep_for(50ms);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
    }

    void third(function<void()> printThird) {
        this_thread::sleep_for(100ms);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};