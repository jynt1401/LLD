#include "LinkedinManagerImpl.hpp"
LinkedinManagerImpl::LinkedinManagerImpl()
{
}

bool LinkedinManagerImpl::addMember(Member member)
{
    const std::string memberId=member.getId();
    if(MemberMap.count(memberId)) return false ;//if member is already added
    if(!member.is_valid()) return false ;
    MemberMap[member.getId()] = member;
    return true;
}

bool LinkedinManagerImpl::addConnection(std::string memberID1, std::string memberID2)
{
    if(memberID1 == memberID2) return false;

    if(!MemberMap.count(memberID1)||!MemberMap.count(memberID2)) return false;//Both members Should Exist


    if(GraphOf1Degree.is_Neighbor(memberID1, memberID2)) return false;


    if(GraphOf2Degree.is_Neighbor(memberID1, memberID2))GraphOf2Degree.removeEdge(memberID1, memberID2);



    GraphOf1Degree.addEdge(memberID1,memberID2);

    /*
    We need to Update the 2 Degree Graph as this connection made a lot of new 2 degree connections
    */

    for(std::string neighbour: GraphOf1Degree.getNeighbors(memberID1)){
        if(GraphOf1Degree.is_Neighbor(memberID2, neighbour))continue;
        GraphOf2Degree.addEdge(memberID2,neighbour);
    }
    for(std::string neighbour: GraphOf1Degree.getNeighbors(memberID2)){
        if(GraphOf1Degree.is_Neighbor(memberID1, neighbour))continue;
        GraphOf2Degree.addEdge(memberID1,neighbour);
    }
    return true;
}

int LinkedinManagerImpl::getConnectionDegree(std::string memberID1, std::string memberID2)
{   if(memberID1 == memberID2) return -1;//cannot connect to same Id
    if(MemberMap.count(memberID1)==0||MemberMap.count(memberID2)==0) return -1;//Both members Should Exist
    if(GraphOf1Degree.is_Neighbor(memberID1, memberID2)) return 1;
    if(GraphOf2Degree.is_Neighbor(memberID1,memberID2)) return 2;
    return 3;
}