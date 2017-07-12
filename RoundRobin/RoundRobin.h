//
// Created by lianlian on 17-7-12.
//////////

#pragma once
#include <vector>

template <typename T>
class RoundRobin
{
public:
    RoundRobin(std::size_t numExpected = 0);
    virtual ~RoundRobin();
    RoundRobin(const RoundRobin& rhs) = delete;
    RoundRobin& operator= (RoundRobin&& rhs) = delete;
    void add(const T& element);
    void remove(const T& element);
    T& getNext();
private:
    std::vector<T> mElems;
    typename std::vector<T>::iterator mCurElem;
};

template <typename T>
RoundRobin<T>::RoundRobin(std::size_t numExpected) {
    mElems.reserve(numExpected);
    mCurElem = end(mElems);
}

template <typename T>
RoundRobin<T>::~RoundRobin() {

}

template <typename T>
void RoundRobin<T>::add(const T &element) {
    int pos = (mCurElem)
}
