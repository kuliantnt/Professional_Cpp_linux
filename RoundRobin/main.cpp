#include <iostream>
#include "quick sort.h"

int main() {
    std::size_t size = 9;
    int *array = new int[size]{9, 6, 5, 1, 3, 2, 4, 8, 7};
    quick_sort(array, (const int) size);
}