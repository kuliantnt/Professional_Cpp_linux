//
// Created by lianlian on 17-7-12.
//////////

#pragma once
#include <vector>
#include <stdexcept>

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
void RoundRobin<T>::add(const T &element)
{
    int pos = (mCurElem == std::end(mElems)? -1 : mCurElem - std::begin(mElems));
    mElems.push_back(element);
    mCurElem = (pos == -1 ? std::end(mElems) : std::begin(mElems) + pos);
}

template <typename T>
void RoundRobin<T>::remove(const T &element) {
    for(auto it = std::begin(mElems); it != std::end(mElems); ++it){
        if(*it == element)
        {
            int newPos;
            if(mCurElem <= it){
                newPos = mCurElem - std::begin(mElems);
            }else{
                newPos = mCurElem - std::begin(mElems) - 1;
            }
            mElems.erase(it);
            mCurElem = std::begin(mElems) + newPos;
            return;
        }
    }
}

template <typename T>
T &RoundRobin<T>::getNext() {
    if(mElems.empty()){
        throw std::out_of_range("No element in the list");
    }
    if(mCurElem == std::end(mElems)){
        mCurElem = std::begin(mElems);
    }
    else{
        ++mCurElem;
        if(mCurElem == std::end(mElems)){
            mCurElem = std::begin(mElems);
        }
    }
    return *mCurElem;
}
