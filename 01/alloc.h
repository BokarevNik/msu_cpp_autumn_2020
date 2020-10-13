#include <memory>

class Allocator
{
private:
    std::size_t offset, memsize;
    char *begin;
public:
    void makeAllocator(std::size_t maxSize);
    ~Allocator();
    char* alloc(std::size_t size);
    void reset();
};