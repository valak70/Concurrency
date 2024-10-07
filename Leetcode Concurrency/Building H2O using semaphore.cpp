class H2O {
    counting_semaphore<2> hsm{2};
    counting_semaphore<1> osm{0};
    mutex mtx;
    int hct;
public:
    H2O() {
        hct = 0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        
        hsm.acquire();
        unique_lock<mutex> lk(mtx);
        hct++;
        releaseHydrogen();
        if(hct==2){
            osm.release();
        }
    }

    void oxygen(function<void()> releaseOxygen) {
        osm.acquire();
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        hct = 0;
        hsm.release(2);
    }
};