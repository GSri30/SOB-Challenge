#ifndef BLOCK_H_
#define BLOCK_H_

#include<vector>
#include<string>
#include "MempoolTransaction.h"
#include "Graph.h"
#include<iostream>

using namespace std;

class Block{
    private:
        vector<MempoolTransaction>transactions;
        static const int MAX_WEIGHT=1000;

    public:
        Block();
        ~Block();
        Block(const vector<MempoolTransaction>&);
        Block(const Block&);

    public:
        vector<MempoolTransaction> getTransactions();
    
    public:
        static vector<string> compute_optimal_transactions(vector<MempoolTransaction>&);
};

#endif