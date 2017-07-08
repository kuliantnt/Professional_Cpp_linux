#include <iostream>
#include "MemoryDemo.h"

int main() {
    MemoryDemo* men = new MemoryDemo();
    delete men;
    men = new MemoryDemo[10];
    delete men;
//    men = new (nothrow) MemoryDemo();
//    delete men;
//    men = new (nothrow) MemoryDemo[10];
//    delete [] men;
}