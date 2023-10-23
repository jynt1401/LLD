#include "service/utils/Graph.hpp"
#include "domain/Member.hpp"
void Graph::addEdge(const std::string& m1, const std::string& m2){
    this->AdjacencyList[m1].insert(m2);
    this->AdjacencyList[m2].insert(m1);
}
bool Graph::is_Neighbor(const std::string& m1, const std::string& m2){
    auto NeighboursOf1=this->AdjacencyList[m1];
    auto Iter=NeighboursOf1.find(m2);//Iterator where the Second member lies in the set
    return Iter==NeighboursOf1.end()? false: true;//if iterator is at end that implies Second member is not a member
}
void Graph::removeEdge(const std::string& m1, const std::string& m2){
    this->AdjacencyList[m1].erase(m2);
    this->AdjacencyList[m2].erase(m1);
}
std::set<std::string> Graph::getNeighbors(const std::string &m1){
    return this->AdjacencyList[m1];
}