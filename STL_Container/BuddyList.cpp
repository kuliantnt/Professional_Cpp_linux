//
// Created by lianlian on 17-7-28.
//

#include "BuddyList.h"

void BuddyList::addBuddy(const std::string &name, const std::string &buddy)
{
    if(!isBuddy(name,buddy))
    {
        mBuddies.insert({name,buddy});
    }
}

void BuddyList::removeBuddy(const std::string &name, const std::string &buddy) {
    auto iter = mBuddies.lower_bound(name);
    auto end = mBuddies.upper_bound(name);
    for(;iter !=end;++iter){
        if(iter -> second == buddy) {
            mBuddies.erase(iter);
            break;
        }
    }
}

bool BuddyList::isBuddy(const std::string &name, const std::string &buddy) const {
    auto range = mBuddies.equal_range(name);
    auto iter = range.first;
    auto end = range.second;
    for(;iter !=end;++iter){
        if(iter -> second == buddy) {
            return true;
        }
    }
    return false;
}

std::list<std::string> BuddyList::getBuddies(const std::string &name) const {
    auto range = mBuddies.equal_range(name);
    auto iter = range.first;
    auto end = range.second;
    std::list<std::string> buddies;
    for(;iter !=end;++iter){
        buddies.push_back(iter->second);
    }
    return buddies;
}

