#include "alloc.h"
#include <iostream>

void Allocator::makeAllocator(size_t maxsize) {
    try {
        begin = new char[maxsize];
        if (begin == nullptr) {
            throw "Cannot allocate memory";
        }
        offset = 0;
        memsize = maxsize;
    }
    catch(const char* exception) {
        std::cerr << "Error: " << exception << '\n';
    }
}
Allocator::~Allocator() {
    ::operator delete(begin);
    begin = nullptr;
}
char* Allocator::alloc(std::size_t size){
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
