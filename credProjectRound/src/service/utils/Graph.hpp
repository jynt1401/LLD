#include<map>
#include <set>
#include "domain/Member.hpp"
class Graph{
    private:
        std::map<std::string, std::set<std::string> > AdjacencyList;
    public:
        void addEdge(const std::string&m1, const std::string&m2);
        bool is_Neighbor(const std::string &m1,const std::string &m2);
        void removeEdge(const std::string&m1,const std::string  &m2);
        std::set<std::string> getNeighbors(const std::string &m1);
};
