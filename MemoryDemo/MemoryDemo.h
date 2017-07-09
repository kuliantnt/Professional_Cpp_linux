//
// Created by lianlian on 17-7-6.
//

#pragma once
#include <new>

class MemoryDemo
{
public:
    void* operator new(std::size_t size);
    void operator delete (void* ptr) noexcept ;
    void* operator new[] (std::size_t size);
    void operator delete[] (void* ptr) noexcept;
//    void* operator new (std::size_t size, const std::nothrow_t&) noexcept;
//    void operator delete (void* ptr, const std::nothrow_t&) noexcept;
//    void* operator new[] (std::size_t size, const std::nothrow_t& no_throw) noexcept;
//    void operator delete[] (void* ptr, const std::nothrow_t& t) noexcept;
    MemoryDemo(){}
    virtual ~MemoryDemo(){}
};


