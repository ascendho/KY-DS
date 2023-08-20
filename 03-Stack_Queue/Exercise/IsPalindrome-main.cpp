#include "IsPalindrome.h"
#include <iostream>

int main() {
    char a[] = {'a', 'b', 'd', 'd', 'b', 'a'};
    int length = sizeof(a) / sizeof(a[0]);

    std::cout << IsPalindrome_DP(a, length) << std::endl;
    std::cout << IsPalindrome(a, length) << std::endl;

    return 0;
}