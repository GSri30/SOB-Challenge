#include "../Headers/Block.h"

Block::Block(){}
Block::~Block(){
    this->transactions.clear();
}
Block::Block(const vector<MempoolTransaction>&transactions){
    this->transactions=transactions;
}
Block::Block(const Block&oldObj){
    this->transactions=oldObj.transactions;
}

vector<MempoolTransaction> Block::getTransactions(){
    return this->transactions;
}

Block Block::compute_optimal_transactions(const vector<MempoolTransaction>&transactions){
    return Block(transactions);
}