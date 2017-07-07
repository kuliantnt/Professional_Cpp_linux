//
// Created by lianlian on 17-7-6.
//

#ifndef MEMORYDEMO_MEMORYDEMO_H
#define MEMORYDEMO_MEMORYDEMO_H

#include <new>

class MemoryDemo
{
    MemoryDemo(){}
    virtual ~MemoryDemo(){}
    void* operator new(std::size_t size);
    void operator delete (void* ptr) noexcept ;
    void* operator new[] (std::size_t size);
    void* operator delete[] (void* ptr) noexcept;
    void* operator new (std::size_t size, const std::nothrow_t&) noexcept;
    void* operator delete (void* ptr, const std::nothrow_t&) noexcept;



};


#endif //MEMORYDEMO_MEMORYDEMO_H
