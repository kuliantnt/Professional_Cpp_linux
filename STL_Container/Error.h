#pragma once
#include <string>
#include <utility>
#include <iostream>
#include <queue>

bool operator<(const Error &lhs, const Error &rhs) ;
std::ostream &operator<<(std::ostream &os, const Error &err);
class Error{
public:
    Error(int priority, std::string errMsg): mPriority(priority),mError(std::move(errMsg)){}
    int getPriority()const {
        return mPriority;
    }
    const std::string getErrorstring() const {
        return mError;
    }
    friend bool operator< (const Error& lhs, const Error& rhs);
    friend std::ostream& operator<< (std::ostream& os, const Error& err);
private:
    int mPriority;
    std::string mError;
};

class ErrorCorrelator{
public:
    void addError(const Error& error);
    Error getError();
private:
    std::priority_queue<Error> mErrors;
};

void ErrorCorrelator::addError(const Error &error) {
    mErrors.push(error);
}

Error ErrorCorrelator::getError() {
    if(mErrors.empty())
    {
        throw std::out_of_range("No more errors.");
    }
    Error top = mErrors.top();
    mErrors.pop();
    return top;
}

bool operator<(const Error &lhs, const Error &rhs) {
    return (lhs.mPriority< rhs.mPriority);
}

std::ostream &operator<<(std::ostream &os, const Error &err) {
    os << err.mError << "(priority " << err.mPriority << ")";
    return os;
}
