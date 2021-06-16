#include "../Headers/MempoolTransaction.h"


MempoolTransaction::MempoolTransaction(){}
MempoolTransaction::~MempoolTransaction(){
    this->parent_transactions.clear();
}
MempoolTransaction::MempoolTransaction(string txid,int fee,int weight,const vector<string>&parent_transactions){
    this->txid=txid;
    this->fee=fee;
    this->weight=weight;
    this->parent_transactions=parent_transactions;
}
MempoolTransaction::MempoolTransaction(const MempoolTransaction&oldobj){
    this->txid=oldobj.txid;
    this->fee=oldobj.fee;
    this->weight=oldobj.weight;
    this->parent_transactions=oldobj.parent_transactions;
}


string MempoolTransaction::getTXID(){
    return this->txid;
}
int MempoolTransaction::getFee(){
    return this->fee;
}
int MempoolTransaction::getWeight(){
    return this->weight;
}
vector<string> MempoolTransaction::getParentTransacions(){
    return this->parent_transactions;
}
