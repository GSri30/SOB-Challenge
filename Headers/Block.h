#ifndef BLOCK_H_
#define BLOCK_H_

#include<vector>
#include<string>
#include "MempoolTransaction.h"

class Block{
    private:
        vector<string>transactions;

    public:
        Block();
        ~Block();
        Block(const vector<MempoolTransaction>&);
        Block(const Block&);

    public:
        vector<string> getTransacions();
    
    public:
        static Block compute_optimal_transactions();
};

#endif