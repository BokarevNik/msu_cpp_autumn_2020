#include "alloc.h"
#include <cassert>
#include <iostream>

void InitTest() {
    Allocator Allocator;
    Allocator.makeAllocator(10);
    char *str = nullptr;
    str = Allocator.alloc(10);
    assert(str != nullptr);
}

void OverSizeTest() {
    Allocator Allocator;
    Allocator.makeAllocator(100);
    char* ptr = Allocator.alloc(101);
    assert(ptr == nullptr);
}

void DoubleOverSizeTest() {
    Allocator Allocator;
    Allocator.makeAllocator(100);
    char* ptr = Allocator.alloc(50);
    ptr = Allocator.alloc(51);
    assert(ptr == nullptr);
}

void AllocOrderTest() {
    Allocator Allocator;
    Allocator.makeAllocator(100);
    char* first = Allocator.alloc(20);
    char* second = Allocator.alloc(30);
    assert(first + 20 == second);
}

void ResetTest() {
    Allocator Allocator;
    Allocator.makeAllocator(100);
    char* first = Allocator.alloc(50);
    Allocator.reset();
    char* second = Allocator.alloc(10);
    assert(first == second);
}

void AllocWithoutMake(){
    Allocator Allocator;
    char* first = Allocator.alloc(50);
    assert(first == nullptr);
}
void DoubleMakeAlloc(){
    Allocator Allocator;
    Allocator.makeAllocator(100);
    Allocator.makeAllocator(50);
    char* first = Allocator.alloc(5);
    assert(first != nullptr);
}

int main() {
    InitTest();
    OverSizeTest();
    DoubleOverSizeTest();
    AllocOrderTest();
    ResetTest();
    AllocWithoutMake();
    DoubleMakeAlloc();

    std::cout << "Success!\n";
}