//#include <iostream>
//#include <list>
//#include "PacketBuffer.h"
//#include "IPPacket.h"

//#include "Error.h"

#include <map>
#include <iostream>
#include "BankAccount.h"
//#include "Data.h"

int main() {
    /**
     * Bank Test
     */
    BankDB db;
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
    }
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