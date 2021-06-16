#include "../Headers/Block.h"

Block::Block(){}
Block::~Block(){
    this->transactions.clear();
}
Block::Block(const Block&oldObj){
    this->transactions=oldObj.transactions;
}

vector<string> Block::getTransacions(){
    return this->transactions;
}

static Block compute_optimal_transactions(){
    return;
}