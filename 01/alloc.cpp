#include "alloc.h"
#include <iostream>

Allocator::Allocator() {
    begin = nullptr;
    offset = 0;
    memsize = 0;
}
void Allocator::makeAllocator(size_t maxsize) {
    if (begin != nullptr) {
        ::operator delete(begin);
    }
    begin = new char[maxsize];
    offset = 0;
    memsize = maxsize;
}
Allocator::~Allocator() {
    ::operator delete(begin);
    begin = nullptr;
}
char* Allocator::alloc(std::size_t size){
    if (begin == nullptr) {
        return nullptr;
    }
    if (memsize - offset < size){
        return nullptr;
    }
    char* res = begin + offset;
    offset += size;
    return (res);
}
void Allocator::reset() {
    offset = 0;
}
