#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cmath>

bool perfectScore(int num);

int main() {
    /**
     * algorithm find()
     */
/*   int num;
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

    return 0;*/
    /**
     * algorithm find_if example
     */
    /*int num;
    std::vector<int> myVector;
    while(true){
       std::cout << "Enter a test score to add (0 to stop)";
        std::cin >> num;
        if(num == 0)
            break;
        myVector.push_back(num);
    }
    auto endIt = std::cend(myVector);
    auto it = std::find_if(std::cbegin(myVector),endIt,perfectScore);
    if(it == endIt)
        std::cout << "No perfect scores "<< std::endl;
    else
        std::cout << "Fount a \"perfect\" score of "<< *it << std::endl;
    return 0; */
    /**
     * algorithm find_if lambda example
     */
   /* int num;
    std::vector<int> myVector;
    while(true){
        std::cout << "Enter a test score to add (0 to stop):";
        std::cin>> num;
        if(num == 0)
            break;
        myVector.push_back(num);
    }
    auto endIt = std::cend(myVector);
    auto it = std::find_if(std::cbegin(myVector),endIt,[](int i){return i>100;});
    if(it == endIt)
        std::cout << "No perfect scores "<< std::endl;
    else
        std::cout << "Fount a \"perfect\" score of "<< *it << std::endl;
    return 0;*/
}
bool perfectScore(int num){
    return (num>=100);
}
double arithmeticMean(const std::vector<int>& nums){
    double sum = std::accumulate(cbegin(nums),cend(nums),0);
    return sum / nums.size();
}

int product(int num1,int num2) {
    return num1 * num2;
}
double geometricMean(const std::vector<int> & nums) {
    double mult = std::accumulate(std::cbegin(nums), std::cend(nums), 1, product);
    return pow(mult, 1 / nums.size());
}
double geometricMeanLambda(const std::vector<int> & nums) {
    double mult = std::accumulate(std::cbegin(nums), std::cend(nums), 1,
                                  [](int num1, int num2) { return num1, num2; });
    return pow(mult, 1.0 / nums.size());
}
