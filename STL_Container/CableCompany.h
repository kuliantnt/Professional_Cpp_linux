//
// Created by lianlian on 17-7-31.
//

#include <string>
#include <bitset>
#include <map>

const size_t kNumChannels = 10;
class CableCompany {
public:
    void addPackage(const std::string& packageName,const std::bitset<kNumChannels>& channels);
    void removePackage(const std::string& packageName);
    void newCustomer(const std::string& name, const std::string& package);
    void newCustomer(const std::string& name, const std::bitset<kNumChannels>& channels);
    void addChannel(const std::string& name, int channel);
    void removeChannel(const std::string& name, int channal);
    void addPackageToCustomer(const std::string& name, const std::string& package);
    void deleteCustomer(const std::string& name);
    std::bitset<kNumChannels>& getCustomerChannels(const std::string& name);
private:
    typedef std::map<std::string, std::bitset<kNumChannels>> MapType;
    MapType mPackage, mCustomers;
};


