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

    vector<vector<int>>dp(n+5,vector<int>(MAX_WEIGHT+5));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=Block::MAX_WEIGHT;j++){
            if(!i or !j) dp[i][j]=0;
            else{
                if(transactions[i-1].getWeight()>j) dp[i][j]=dp[i-1][j];
                else dp[i][j]=max(dp[i-1][j],dp[i-1][j-transactions[i-1].getWeight()]+transactions[i-1].getFee());
            }
        }
    }

    int result=dp[n][MAX_WEIGHT],w=MAX_WEIGHT;
    vector<MempoolTransaction>_transactions;

    cout<<result<<endl;

    for(int i=n;i>0 and result>0;i--){
        if(result==dp[i-1][w]) continue;
        else{
            _transactions.push_back(transactions[i-1]);
            result-=transactions[i-1].getFee();
            w-=transactions[i-1].getWeight();
        }
    }
    
    Graph G;

    for(auto transaction:_transactions){
        G.AddEdge(transaction.getTXID(),"");
        for(auto parent_transaction:transaction.getParentTransactions()){
            G.AddEdge(parent_transaction,transaction.getTXID());
        }
    }

    output_transactions=G.TopoSort();

    return output_transactions;
}