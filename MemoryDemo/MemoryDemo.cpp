//
// Created by lianlian on 17-7-6.
//

#include <iostream>
#include "MemoryDemo.h"


void *MemoryDemo::operator new(std::size_t size) {
    std::cout << "operator new" << std::endl;
    return ::operator new(size);
}

void MemoryDemo::operator delete(void *ptr) noexcept {
    std::cout << "operator delete" << std::endl;
    ::operator delete(ptr);
}

void *MemoryDemo::operator new[](std::size_t size) {
    std::cout << "operator new[]" << std::endl;
    return ::operator new[](size);
}

void MemoryDemo::operator delete[](void *ptr) noexcept {
    std::cout << "operator delete[]" << std::endl;
    ::operator delete[](ptr);
}
/*
void *MemoryDemo::operator new(std::size_t size, const std::nothrow_t &) noexcept {
    std::cout << "operator new no_throw" << std::endl;
    return ::operator new(size,nothrow);
}

void MemoryDemo::operator delete(void *ptr, const std::nothrow_t &) noexcept {
    std::cout << "operator delete no_throw" << std::endl;
    ::operator delete(ptr,nothrow);
}

void *MemoryDemo::operator new[](std::size_t size, const std::nothrow_t &) noexcept {
    std::cout << "operator new[] no_throw" << std::endl;
    return ::operator new(size,nothrow);
}

void MemoryDemo::operator delete[](void *ptr, const std::nothrow_t&) noexcept {
    std::cout << "operator delete[] no_throw" << std::endl;
    ::operator delete(ptr,nothrow);
}*/


