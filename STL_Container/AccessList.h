//
// Created by lianlian on 17-7-30.
//
#pragma once

#include <initializer_list>
#include <string>
#include <set>
#include <string>
#include <list>

class AccessList {
public:
    AccessList() = default;
    AccessList(const std::initializer_list<std::string> & initlist);
    void addUser(const std::string& user);
    void removeUser(const std::string& user);
    bool isAllowed(const std::string &user) const;
    std::list<std::string> getAllUsers() const;
private:
    std::set<std::string> mAllowed;
};


