//
// Created by lianlian on 17-7-30.
//

#include "AccessList.h"

AccessList::AccessList(const std::initializer_list<std::string> &initlist) {
    for(auto& user : initlist){
        addUser(user);
    }
}

void AccessList::addUser(const std::string &user) {
    mAllowed.insert(user);
}

void AccessList::removeUser(const std::string &user) {
    mAllowed.erase(user);
}

bool AccessList::isAllowed(const std::string &user) const {
    return (mAllowed.count(user) != 0);
}

std::list<std::string> AccessList::getAllUsers() const{
    std::list<std::string> users;
    users.insert(std::end(users), std::begin(mAllowed), std::end(mAllowed));
    return users;
}
