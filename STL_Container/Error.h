//
// Created by lianlian on 17-7-25.
//

#pragma once
#include <string>
#include <utility>

class Error{
public:
    Error(int priority, std::string errMsg): mPriority(priority),mError(std::move(errMsg)){}
private:
    int mPriority;
    std::string mError;
};
