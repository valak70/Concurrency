class FooBar {
private:
    int n;
    counting_semaphore<1> f{1},b{0};
public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            f.acquire();
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            b.release();
        }
        
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            b.acquire();
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            f.release();
        }
        
    }
};