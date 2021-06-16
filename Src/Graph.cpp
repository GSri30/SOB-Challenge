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

void Graph::DFS(const string&vertex,vector<string>&topo_ordering,unordered_map<string,bool>&visited){
    visited[vertex]=true;
    for(auto _vertex:this->AdjacencyList[vertex]){
        if(_vertex=="" or visited[_vertex]) continue;
        this->DFS(_vertex,topo_ordering,visited);
    }
    topo_ordering.push_back(vertex);
}

vector<string> Graph::TopoSort(){
    unordered_map<string,bool>visited;
    vector<string>topo_ordering;

    for(auto vertex:this->AdjacencyList){
        if(visited[vertex.first]) continue;
        this->DFS(vertex.first,topo_ordering,visited);
        for(auto _vertex:vertex.second){
            if(_vertex=="" or visited[_vertex]) continue;
            this->DFS(_vertex,topo_ordering,visited);
        }
    }

    reverse(topo_ordering.begin(),topo_ordering.end());

    return topo_ordering;
}