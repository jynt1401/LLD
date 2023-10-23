#ifndef LINKEDINMANAGERIMPL_HPP
#define LINKEDINMANAGERIMPL_HPP
#include<unordered_map>
#include "service/utils/Graph.hpp"
#include "service/LinkedinManager.hpp"
#include "domain/Member.hpp"
class LinkedinManagerImpl : public LinkedinManager
{
    private:
        std::unordered_map<std::string, Member> MemberMap;
        Graph GraphOf1Degree;
        Graph GraphOf2Degree;
public:
    LinkedinManagerImpl();

    bool addMember(Member member);

    bool addConnection(std::string memberID1, std::string memberID2);

    int getConnectionDegree(std::string memberID1, std::string memberID2);

private:
};

#endif