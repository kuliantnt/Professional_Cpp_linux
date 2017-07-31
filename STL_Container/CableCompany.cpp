//
// Created by lianlian on 17-7-31.
//

#include "CableCompany.h"

void CableCompany::addPackage(const std::string &packageName, const std::bitset<kNumChannels> &channels) {
    mPackage.insert({packageName,channels});
}

void CableCompany::removePackage(const std::string &packageName) {
    mPackage.erase(packageName);
}

void CableCompany::newCustomer(const std::string &name, const std::string &package) {
    auto it = mPackage.find(package);
    if ( it == std::end(mPackage)){
        throw std::out_of_range("Invalid package");
    }
    auto result = mCustomers.insert({name, it -> second});
    if(!result.second){
        throw  std::invalid_argument("Duplicate customer");
    }
}

void CableCompany::newCustomer(const std::string &name, const std::bitset<kNumChannels> &channels) {
    auto result = mCustomers.insert({name,channels});
    if(!result.second){
        throw std::invalid_argument("Duplicate customer");
    }
}

void CableCompany::addChannel(const std::string &name, int channel) {
    auto it = mCustomers.find(name);
    if(it != std::end(mCustomers)){
        it -> second.set(channel);
    }
    else
    {
        throw std::invalid_argument("Unknown customer");
    }
}

void CableCompany::removeChannel(const std::string &name, int channal) {
    auto it = mCustomers.find (name);
    if(it != std::end(mCustomers)){
        it ->second.reset();
    }
    else
    {
        throw std::invalid_argument("Unknown customer");
    }
}

void CableCompany::addPackageToCustomer(const std::string &name, const std::string &package) {
    auto itPack = mPackage.find(package);
    if(itPack == end(mPackage)){
        throw std::invalid_argument("Invalid package");
    }
    auto itCust = mCustomers.find(name);
    if(itCust != end(mCustomers)){
        itCust->second |= itPack->second;
    }
    else{
        throw std::invalid_argument("Unknown customer");
    }
}

void CableCompany::deleteCustomer(const std::string &name) {
    mCustomers.erase(name);
}

std::bitset<kNumChannels> &CableCompany::getCustomerChannels(const std::string &name) {
    auto it = mCustomers.find(name);
    if(it != std::end(mCustomers)){
        return it -> second;
    }
    throw std::invalid_argument("Unknown customer");
}
