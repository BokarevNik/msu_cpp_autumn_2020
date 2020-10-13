#include "alloc.h"
#include <cassert>
#include <iostream>

void InitTest() {
    Allocator Allocator;
    Allocator.makeAllocator(10);
    char* str = Allocator.alloc(10);
    assert(str[9] == str[9]);
}
int main() {
    InitTest();

    std::cout << "Success!\n";
}