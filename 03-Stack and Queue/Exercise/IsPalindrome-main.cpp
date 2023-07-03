#include "IsPalindrome.h"
#include <iostream>

int main() {
    char a[] = {'a', 'b', 'd', 'b', 'a'};
    int length = sizeof(a) / sizeof(a[0]);

    if (IsPalindrome(a, length))
        std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;
    return 0;
}