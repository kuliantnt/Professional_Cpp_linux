//
// Created by lianlian on 17-7-28.
//
#pragma once

#include <string>
#include <unordered_map>
#include <utility>

class BankAccount{
public:
    BankAccount(int accNum, std::string name):mAcctNum(accNum),mClientName(std::move(name)){}
    void setAcctNum(int accNum){
        mAcctNum = accNum;
    }
    int getAcctNum() const{
        return mAcctNum;
    }
    void setClientName(const std::string&name){
        mClientName = name;
    }
    const std::string& getClientName(){
        return mClientName;
    }
private:
    int mAcctNum;
    std::string mClientName;
};

class BankDB{
public:
    bool addAccount(const BankAccount& acct);
    void deleteAccount(int acctNum);
    BankAccount& findAccount(int acctNum);
    BankAccount& findAccount(const std::string& name);
    void mergaDatabase(BankDB& db);
private:
    std::unordered_map<int,BankAccount> mAccounts;
};

bool BankDB::addAccount(const BankAccount &acct) {
    auto res = mAccounts.insert(std::make_pair(acct.getAcctNum(),acct));
    return res.second;
}

void BankDB::deleteAccount(int acctNum) {
    mAccounts.erase(acctNum);
}

BankAccount &BankDB::findAccount(int acctNum) {
    auto it = mAccounts.find(acctNum);
    if(it == mAccounts.end()){
        throw std::out_of_range("No account with that number");
    }
    return it->second;
}

BankAccount &BankDB::findAccount(const std::string &name) {
    for(auto& p : mAccounts){
        if(p.second.getClientName() == name){
            return p.second;
        }
    }
    throw std::out_of_range("No account with the name.");
}

void BankDB::mergaDatabase(BankDB &db) {
    mAccounts.insert(std::begin(db.mAccounts),std::end(db.mAccounts));
    db.mAccounts.clear();
}
