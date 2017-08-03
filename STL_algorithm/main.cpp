#include <iostream>
#include <algorithm>
#include <vector>


int main() {
    /**
     * algorithm find()
     */
    int num;
    std::vector<int> myVector;
    while(true){
        std::cout << "Enter a number to add (0 to stop): ";
        std::cin>> num;
        if(num == 0)
            break;
        myVector.push_back(num);
    }
    while(true){
        std::cout << "Enter a number to lookup (0 to stop)" ;
        std::cin >> num;
        if(num == 0){
            break;
        }
        auto endIt = std::cend(myVector);
        auto it = std::find(std::cbegin(myVector),endIt, num);
        if(it == endIt){
            std::cout << "Could not find " << num << std::endl;
        }
        else{
            std::cout << "found " << *it << std::endl;
        }
    }

    return 0;
}