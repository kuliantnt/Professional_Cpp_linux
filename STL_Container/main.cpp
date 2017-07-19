#include <iostream>
#include <list>
#include <string>

int main() {
    std::list<std::string> dictionary {"aardvark","ambulance"};
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
    return 0;
}