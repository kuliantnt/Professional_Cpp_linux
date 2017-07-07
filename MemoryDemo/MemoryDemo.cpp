//
// Created by lianlian on 17-7-6.
//

#include <iostream>
#include "MemoryDemo.h"


void *MemoryDemo::operator new(std::size_t size) {
    std::cout << "operator new" << std::endl;
    return ::operator new(size);
}

void MemoryDemo::operator delete(void *ptr) {
    std::cout << "operator delete" << std::endl;
    return ::operator delete(ptr);

}
