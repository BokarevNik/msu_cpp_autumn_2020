#include "alloc.h"

void Allocator::makeAllocator(size_t maxsize) {
    begin = new char[maxsize];
    memsize = maxsize;
    offset = 0;
}
Allocator::~Allocator() {
    ::operator delete(begin);
    begin = nullptr;
}
char* Allocator::alloc(std::size_t size){
    if (memsize - offset < size){
        return nullptr;
    }
    offset += size;
    return (begin + offset);
}
void Allocator::reset() {
    offset = 0;
}
