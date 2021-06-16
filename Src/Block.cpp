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

vector<string> Block::compute_optimal_transactions(vector<MempoolTransaction>&transactions){
    
    vector<string>output_transactions;

    int n=transactions.size();

    //unordered_map<string,int>dp;

    //int dp[n+5][MAX_WEIGHT+5];

    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=Block::MAX_WEIGHT;j++){
    //         if(!i or !j) dp[to_string(i)+" "+to_string(j)]=0;
    //         else{
    //             if(transactions[i-1].getWeight()>j) dp[to_string(i)+" "+to_string(j)]=dp[to_string(i-1)+" "+to_string(j)];
    //             else dp[to_string(i)+" "+to_string(j)]=max(dp[to_string(i-1)+" "+to_string(j)],dp[to_string(i-1)+" "+to_string(j-transactions[i-1].getWeight())]+transactions[i-1].getFee());
    //         }
    //     }
    // }

    // int result=dp[to_string(n)+" "+to_string(MAX_WEIGHT)],w=MAX_WEIGHT;

    // cout<<result<<endl;

    // vector<MempoolTransaction>_transactions;

    // for(int i=n;i>0 and result>0;i--){
    //     if(result==dp[to_string(i-1)+" "+to_string(w)]) continue;
    //     else{
    //         _transactions.push_back(transactions[i-1]);
    //         result-=transactions[i-1].getFee();
    //         w-=transactions[i-1].getWeight();
    //     }
    // }

    // Graph G;
    
    // for(auto transaction:_transactions){
    //     for(auto parent_transaction:transaction.getParentTransactions()){
    //         G.AddEdge(parent_transaction,transaction.getTXID());
    //     }
    // }

    // output_transactions=G.TopoSort();

    return output_transactions;
}