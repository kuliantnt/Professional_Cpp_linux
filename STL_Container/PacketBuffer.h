//
// Created by lianlian on 17-7-22.
//

#pragma once
#include <queue>
#include <stdexcept>

template <typename T>
class PacketBuffer
{
public:
    explicit PacketBuffer(std::size_t max = 0);
    bool bufferParket (const T& packet);
    T getNextPacket();
private:
    std::queue<T> mParkets;
    std::size_t mMaxSize;
};

template <typename T>
PacketBuffer<T>::PacketBuffer(std::size_t max ) :mMaxSize(max){
}

template <typename T>
bool PacketBuffer<T>::bufferParket(const T &packet) {
    if(mMaxSize > 0 && mParkets.size() == mMaxSize){
        return false;
    }
    mParkets.push(packet);
    return true;
}

template <typename T>
T PacketBuffer<T>::getNextPacket() {
    if(mParkets.empty())
    {
        throw std::out_of_range("Buffer is empty");
    }
    T temp = mParkets.front();
    mParkets.pop();
    return temp;
}

