#include <iostream>
#include "SqQueueWithTag.h"

using namespace std;


int main() {
    SqQueueWithTag Q;
    InitQueue(Q);

    int e = 1;
    EnQueue(Q, e);

    char t;
    DeQueue(Q, t);

    cout << t << endl;
    return 0;
}