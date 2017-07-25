//#include <iostream>
//#include <list>
//#include "PacketBuffer.h"
//#include "IPPacket.h"

int main() {

    /**
     * Queue Program
     */
//    PacketBuffer<IPPacket> ipPackets(3);
//    for(int i =1;i<=4; ++i){
//        if(!ipPackets.bufferParket(IPPacket(i)))
//        {
//            std::cout << "Packet " << i << " dropped (queue is full)." << std::endl;
//        }
//    }
//    while (true){
//        try{
//            IPPacket packet = ipPackets.getNextPacket();
//            std::cout << "Processing packet "<< packet.getID() << std::endl;
//        }catch(const std::out_of_range& ){
//            std::cout << "Queue is empty." << std::endl;
//            break;
//        }
//    }
    /**
     * list program
     */
//    std::list<std::string> dictionary {"aardvark","ambulance"};
//    std::list<std::string> b_words {"bathos","balderdash"};
//    dictionary.push_back("canticle");
//    dictionary.push_back("consumerism");
//    if(b_words.size() > 0){
//        auto iterLastB = --(std::cend(b_words));
//        auto it = std::cbegin(dictionary);
//        for(;it!= std::cend(dictionary);++it){
//            if(*it > *iterLastB){
//                break;
//            }
//        }
//        dictionary.splice(it,b_words);
//    }
//    for(const auto & word : dictionary){
//        std::cout << word << std::endl;
//    }
//    return 0;
}