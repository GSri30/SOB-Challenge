#ifndef GRAPH_H_
#define GRAPH_H_

#include<unordered_map>
#include<string>
#include<vector>

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
        void DAG();

    //Getters and Setters
    public:
        void setAL(const unordered_map<string,vector<string>>&);
        const unordered_map<string,vector<string>>&getAL();

};

#endif