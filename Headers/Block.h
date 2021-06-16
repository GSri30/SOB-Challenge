#ifndef BLOCK_H_
#define BLOCK_H_

#include<vector>
#include<string>
#include "MempoolTransaction.h"

class Block{
    private:
        vector<MempoolTransaction>transactions;

    public:
        Block();
        ~Block();
        Block(const vector<MempoolTransaction>&);
        Block(const Block&);

    public:
        vector<MempoolTransaction> getTransactions();
    
    public:
        static Block compute_optimal_transactions(const vector<MempoolTransaction>&);
};

#endif