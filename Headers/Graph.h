#ifndef GRAPH_H_
#define GRAPH_H_

#include<unordered_map>
#include<string>
#include<vector>
#include<algorithm>
#include "../Headers/MempoolTransaction.h"

using namespace std;

class Graph{
    //Class attributes
    private:
        unordered_map<string,vector<string>> AdjacencyList;

    //Constructors
    public:
        Graph();
        ~Graph();
        Graph(const Graph&);

    //Member functions
    public:
        void AddEdge(string ,string);
        vector<string> TopoSort();

    private:
        void DFS(const string&,vector<string>&,unordered_map<string,bool>&);

    //Getters and Setters
    public:
        void setAL(const unordered_map<string,vector<string>>&);
        const unordered_map<string,vector<string>>&getAL();

};

#endif