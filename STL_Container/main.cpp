#include <iostream>
#include "CableCompany.h"

/*
template <class T>
void printMap(const T&m){
    for(auto& p : m){
        std::cout << p.first <<" (Phone: " << p.second << ")" <<std::endl;
    }
    std::cout << "-------" <<std::endl;
}
*/

int main() {
    /**
     * using CableCompany
     */
   /* CableCompany mycc;
    auto basic_pkg = "1111000000";
    auto premium_pkg = "1111111111";
    auto sports_pkg = "0000100111";
    mycc.addPackage("basic",std::bitset<kNumChannels>(basic_pkg));
    mycc.addPackage("premium",std::bitset<kNumChannels>(premium_pkg));
    mycc.addPackage("sports",std::bitset<kNumChannels>(sports_pkg));
    mycc.newCustomer("Marc G.","basic");
    mycc.addPackageToCustomer("Marc G.","sports");
    std::cout << mycc.getCustomerChannels("Marc G.") << std::endl;*/
    /**
     * using unordered_map
     */
    /*std::unordered_map<std::string,std::string> um = {
            {"Marc G.", "123-456789"},
            {"Scott K.", "654-987432"}
    };
    printMap(um);

    um.insert(std::make_pair("Jonn D.", "321-987654"));
    um["Johan G."]="963-258147";
    um["Freddy.K."]="999-256256";
    um.erase("Freddy.K.");
    printMap(um);

    unsigned long bucket = um.bucket("Marc G.");
    std::cout << "Marc G. is in bucket " << bucket << " which contains the following "
              << um.bucket_size(bucket) << " elements:" << std::endl;
    for(auto liter = um.cbegin(bucket); liter != um.cend(bucket); ++liter){
        std::cout << "\t" << liter->first << " (Phone: " << liter -> second << ")" << std::endl;
        liter++;
    }
    std::cout << "--------" << std::endl;

    std::cout << "There are " << um.bucket_count() << " buckets." << std::endl;
    std::cout << "Average number of elements in a bucket is " << um.load_factor() << std::endl;
    return 0;*/
    /**
     * AccessList test
     */
    /*AccessList fileX = {"pvw","mgregoire","baduser"};
    fileX.removeUser("baduser");
    if(fileX.isAllowed("mgregoire")){
        std::cout << "mgregoire has permissions" << std::endl;
    }
    if(fileX.isAllowed("baduser")){
        std::cout<<"baduser has permissions" << std::endl;
    }
    auto users = fileX.getAllUsers();
    for(const auto & user : users){
        std::cout << user<< " ";
    }*/
    /**
     * BuddyList Test
     */
/*    BuddyList buddies;
    buddies.addBuddy("Harry Potter","Ron Weasley");
    buddies.addBuddy("Harry Potter","Hermione Garnger");
    buddies.addBuddy("Harry Potter","Hagrid");
    buddies.addBuddy("Harry Potter","Draco Malfoy");

    buddies.removeBuddy("Harry Potter","Draco Malfoy");
    buddies.addBuddy("Hagrid","Harry Potter");
    buddies.addBuddy("Hagrid","Hermione Garnger");
    buddies.addBuddy("Hagrid","Ron Weasley");
    auto harryBuds = buddies.getBuddies("Harry Potter");
    std::cout << "Harry's friends: "<< std::endl;
    for (const auto & name : harryBuds){
        std::cout << "\t" << name << std::endl;
    }*/
    /**
     * Bank Test
     */
    /*BankDB db;
    db.addAccount(BankAccount(100,"Nicholas Solter"));
    db.addAccount(BankAccount(200,"Scott Kleper"));
    try{
        auto& acct = db.findAccount(100);
        std::cout << "Find account 100"<< std::endl;
        acct.setClientName("Nicholas A solter");
        auto& acct2 = db.findAccount("Scott Kleper");
        std::cout << "Found account of Scott Kepler" << std::endl;
        auto& acct3 = db.findAccount(1000);
    }catch(const std::out_of_range&){
            std::cout << "Unable to find account" << std::endl;
    }catch(...){
        std::cout << "Error"<< std::endl;
    }*/
    /**
     * Map Program
     */

    /*std::map<int,Data> dataMap;
    auto ret = dataMap.insert({1,Data(4)});
    if(ret.second)
        std::cout << "Insert succeeded" << std::endl;
    else
        std::cout << "Insert failed!" << std::endl;
    ret = dataMap.insert(std::make_pair(1,Data(6)));
    if(ret.second)
        std::cout << "Insert succeeded" << std::endl;
    else
        std::cout << "Insert failed!" << std::endl;*/
    /**
     * priority_Queue Program
     */
/*
    ErrorCorrelator ec;
    ec.addError(Error(3,"Unable to read file"));
    ec.addError(Error(1,"Incorrect entry from user"));
    ec.addError(Error(10,"Unable to allocate memory"));
    while(true){
        try {
            Error e = ec.getError();
            std::cout << e << std::endl;
        }catch(std::out_of_range& e){
            std::cout << "Finished processing errors" << std::endl;
            break;
        }
    }
*/

    /**
     * Queue Program
     */
   /* PacketBuffer<IPPacket> ipPackets(3);
    for(int i =1;i<=4; ++i){
        if(!ipPackets.bufferParket(IPPacket(i)))
        {
            std::cout << "Packet " << i << " dropped (queue is full)." << std::endl;
        }
    }
    while (true){
        try{
            IPPacket packet = ipPackets.getNextPacket();
            std::cout << "Processing packet "<< packet.getID() << std::endl;
        }catch(const std::out_of_range& ){
            std::cout << "Queue is empty." << std::endl;
            break;
        }
    }*/
    /**
     * list program
     */
   /* std::list<std::string> dictionary {"aardvark","ambulance"};
    std::list<std::string> b_words {"bathos","balderdash"};
    dictionary.push_back("canticle");
    dictionary.push_back("consumerism");
    if(b_words.size() > 0){
        auto iterLastB = --(std::cend(b_words));
        auto it = std::cbegin(dictionary);
        for(;it!= std::cend(dictionary);++it){
            if(*it > *iterLastB){
                break;
            }
        }
        dictionary.splice(it,b_words);
    }
    for(const auto & word : dictionary){
        std::cout << word << std::endl;
    }
    return 0;*/
}