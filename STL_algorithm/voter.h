//
// Created by lianlian on 17-8-8.
//

#include <map>
#include <list>
#include <set>
#include <algorithm>


using VotersMap = std::map<std::string, std::list<std::string>>;
using DistrictPair = std::pair<const std::string, std::list<std::string>>;

std::set<std::string> getDuplicates(VotersMap &votersByDistrict);

void auditVoterRolls(VotersMap& votersByDistrict, const std::list<std::string>& convictedFelons) {
    std::set<std::string> toRemove = getDuplicates(votersByDistrict);
    toRemove.insert(std::cbegin(convictedFelons), std::cend(convictedFelons));
    std::for_each(std::begin(votersByDistrict), std::end(votersByDistrict), [&toRemove](DistrictPair &district) {
        auto it = std::remove_if(std::begin(district.second), std::end(district.second),
                                 [&toRemove](const std::string &name) {
                                     return (toRemove.count(name) > 0);
                                 });
        district.second.erase(it,std::end(district.second));
    });
}

std::set<std::string> getDuplicates(VotersMap &votersByDistrict) {
    std::list<std::string> allNames;
    for(auto& district : votersByDistrict){
        allNames.insert(std::end(allNames),std::begin(district.second),std::end(district.second));
    }
    allNames.sort();
    std::set<std::string> duplicates;
    for(auto lit = std::cbegin(allNames);lit!=std::cend(allNames);++lit){
        lit = std::adjacent_find(lit,std::cend(allNames));
        if(lit == std::cend(allNames)){
            break;
        }
        duplicates.insert(*lit);
    }
    return duplicates;
}
