#include <iostream>
#include "Deque.h"

using namespace std;

int main() {
    Deque Q;
    InitQueue(Q);

    char laData[] = {'1', '2', '3'};
    int e = sizeof(laData) / sizeof(laData[0]);

    for (int i = 0; i < e; i++)
        EnQueue(Q, laData[i]);

    char n;
    for (int i = 0; i < e; i++) {
        DeQueue(Q, n);
        cout << n << endl;
    }
    return 0;
}