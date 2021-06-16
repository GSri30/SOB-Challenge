#ifndef MEMPOOLTRANSACTION_H_
#define MEMPOOLTRANSACTION_H_

#include<vector>
#include<string>

using namespace std;

class MempoolTransaction{
    private:
        string txid;
        int fee;
        int weight;
        vector<string>parent_transactions;

    public:
        MempoolTransaction();
        ~MempoolTransaction();
        MempoolTransaction(string,int,int,const vector<string>&);
        MempoolTransaction(const MempoolTransaction&);

    public:
        string getTXID();
        int getFee();
        int getWeight();
        vector<string> getParentTransactions();
};

#endif