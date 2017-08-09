#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cmath>
#include <memory>
#include <functional>
#include "voter.h"


bool perfectScore(int num);
std::function <int(void)> multiplyBy2Lambda(int x);
void testCallback(const std::vector<int>& vec,const std::function<bool(int)>& callback);

int main(){
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
    /**
     * Using auto lambda
     */
    /*std::vector<int> ints{10, 55, 101, 200};
    std::vector<double> doubles{11.1, 55.5, 200.2};

    auto isGreaterThan100 = [](auto i) { return i > 100; };

    auto it1 = std::find_if(std::cbegin(ints), std::cend(ints), isGreaterThan100);
    if (it1 != std::cend(ints)) {
        std::cout << "Found a value > 100: " << *it1 << std::endl;
    }

    auto it2 = std::find_if(std::cbegin(doubles), std::cend(doubles), isGreaterThan100);
    if (it2 != std::cend(doubles)) {
        std::cout << "Found a value > 100: " << *it2 << std::endl;
    }*/
    /**
     * Using lambda initialized list
     */
    /*const double pi = 3.1415;
    auto myPtr = std::make_unique<double>(3.1415);
    auto myLambda = [p = std::move(myPtr)]{
        std::cout << *p;
    };
//    auto myLambda = [myCapture = "pi: ", pi]{std::cout << myCapture << pi;};

    //必须要执行一遍才行嘛。。。。
    myLambda();*/
    /**
     * Using functional;
     */
/*
    std::function<int(void)>fn = multiplyBy2Lambda(2);
    std::cout << fn();*/
    /**
     * Using Parameter lambda
     */
/*    std::vector<int> vec1{1,2,3,4,5,6,7,8,9,10};
    testCallback(vec1,[](int i){return i < 6;});*/
    /**
     * voter test
     * exception using STL algorithm
     */
    VotersMap voters = {
            {"Orange",      {"Amy Aardvark",       "Bob Buffalo",
                                                                "Charles Cat", "Dwayne Dog"}},
            {"Los Angeles", {"Elizabeth Elephant", "Fred Flamingo",
                                    "Amy Aardvark"}},
            {"San Diego",   {"George Goose",       "Heidi Hen", "Fred Flamingo"}}
    };
    std::list<std::string> felons = {"Bob Buffalo","Charles Cat"};
    auto printDistrict = [](const DistrictPair& district){
        std::cout << district.first << ":";
        for(auto & str : district.second) {
            std::cout << "{" << str << "}";
        }
        std::cout << std::endl;
    };
    std::cout << "Before Audit:" << std::endl;
    std::for_each(std::cbegin(voters),std::cend(voters),printDistrict);
    std::cout << std::endl;
    auditVoterRolls(voters,felons);
    std::cout << "After Audit: " << std::endl;
    std::for_each(std::cbegin(voters),std::cend(voters),printDistrict);
    std::cout << std::endl;

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
std::function <int(void)> multiplyBy2Lambda(int x)
{
    return [x]{return 2*x;};
}
void testCallback(const std::vector<int>& vec,
        const std::function<bool(int)>& callback) {
    for (const auto &i : vec) {
        if (!callback(i))
            break;
        std::cout << i << "\t";
    }
    std::cout << std::endl;
}
