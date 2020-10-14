#include <memory>
#pragma once

class Allocator
{
private:
    std::size_t offset, memsize;
    char *begin;
public:
    Allocator();
    void makeAllocator(std::size_t maxSize);
    ~Allocator();
    char* alloc(std::size_t size);
    void reset();
};