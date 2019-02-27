#include <thread>
#include <iostream>
#include <mutex>

using namespace std;

mutex locking;

int A(){
    int a = 0;
    while(true){
        locking.lock();
        cout << "a = " << ++a << endl;
        locking.unlock();
        if(a > 100)break;
    }
}

int B(){
    int b = 0;
    while(true){
        locking.lock();
        cout << "b = " << ++b << endl;
        locking.unlock();
        if(b > 100)break;
    }
}

int main(int argc, char const *argv[])
{
    thread fA(A);
    thread fB(B);

    locking.lock();
    printf("Running");
    locking.unlock();

    fA.join();
    fB.join();

    printf("Endding");

    return 0;
}
