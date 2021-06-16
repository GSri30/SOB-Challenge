#include "../Headers/Graph.h"

Graph::Graph(){}
Graph::~Graph(){
    this->AdjacencyList.clear();
}
Graph::Graph(const Graph&oldObj){
    this->AdjacencyList=oldObj.AdjacencyList;
}

void Graph::AddEdge(string node1,string node2){
    for(auto node:AdjacencyList[node1]){
        if(node==node2) return;
    }
    AdjacencyList[node1].push_back(node2);
}

void Graph::setAL(const unordered_map<string,vector<string>>&al){
    this->AdjacencyList=al;
}
const unordered_map<string,vector<string>>& Graph::getAL(){
    return this->AdjacencyList;
}

void Graph::DAG(){
    return;
}