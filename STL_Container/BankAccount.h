//
// Created by lianlian on 17-7-28.
//
#pragma once

#include <string>
#include <map>

class BankAccount{
public:
    BankAccount(int accNum,const std::string& name):mAcctNum(accNum),mClientName(name){}
    void setAcctNum(int accNum){
        mAcctNum = accNum;
    }
    int getAcctNum() const{
        return mAcctNum;
    }
    void setClientName(const std::string&name){
        mClientName = name;
    }
    const std::string& getCliendName(){
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
    BankAccount& findAccount(const std::string&name);
    void mergaDatabase(BankDB& db);
private:
    std::map<int,BankAccount> mAccounts;
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
        throw std::out_of_range("No account with thet number")
    }

}

BankAccount &BankDB::findAccount(const std::string &name) {
    for(auto& p : mAccounts){
        if(p.second.getCliendName() == name){
            return p.second;
        }
    }
    throw std::out_of_range("No account with the name");
}

void BankDB::mergaDatabase(BankDB &db) {
    mAccounts.insert(std::begin(db.mAccounts),std::end(db.mAccounts));
    db.mAccounts.clear();
}
