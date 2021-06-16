#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<unordered_map>
#include<sstream>

using namespace std;

class MempoolTransaction{
    private:
        string txid;
        int fee;
        int weight;
        vector<string>parent_transactions;

    public:
        MempoolTransaction(){}
        ~MempoolTransaction(){
            this->parent_transactions.clear();
        }
        MempoolTransaction(const MempoolTransaction&oldobj){
            this->txid=oldobj.txid;
            this->fee=oldobj.fee;
            this->weight=oldobj.weight;
            this->parent_transactions=oldobj.parent_transactions;
        }
        MempoolTransaction(string txid,int fee,int weight,const vector<string>&parent_transactions){
            this->txid=txid;
            this->fee=fee;
            this->weight=weight;
            this->parent_transactions=parent_transactions;
        }

    public:
        string getTXID(){
            return this->txid;
        }
        int getFee(){
            return this->fee;
        }
        int getWeight(){
            return this->weight;
        }
        vector<string> getParentTransactions(){
            return this->parent_transactions;
        }
};

vector<MempoolTransaction> parse_mempool_csv();

int main(){

    auto List_Transactions=parse_mempool_csv();
    
    unordered_map<string,MempoolTransaction>cvt;
    for(auto z:List_Transactions){
        cvt[z.getTXID()]=z;
    }

    ifstream ans;
    ans.open("block.txt");
    set<string>obtained;
    unordered_map<string,int>position;

    string line;
    int cnt=1;
    while(getline(ans,line)){
        obtained.insert(line);
        position[line]=cnt++;
    }

    queue<string>que;

    for(auto z:obtained){
        int pos=position[z];
        que.push(z);
        while(not que.empty()){
            z=que.front();que.pop();
            for(auto parent:cvt[z].getParentTransactions()){
                que.push(parent);
            }
            if(obtained.find(z)!=obtained.end()){
                if(position[z]>pos){
                    cerr<<"Invalid Block"<<endl;
                    return 0;
                }
                pos=position[z];
            }
        }
    }

    ans.close();

    cout<<"Valid Block"<<endl;

    return 0;
}



vector<MempoolTransaction> parse_mempool_csv(){
    ifstream file_input;
    file_input.open("mempool.csv");
    
    string line,column;

    vector<MempoolTransaction>List_Transactions;

    getline(file_input,line);
    while(getline(file_input,line)){
        vector<string>current_transaction;
        stringstream _line(line);
        while(getline(_line,column,',')){
            current_transaction.push_back(column);
        }
        vector<string>current_parent_transactions;
        if (current_transaction.size()>3){
            stringstream __line(current_transaction[3]);
            while(getline(__line,column,';')){
                current_parent_transactions.push_back(column);
            }
        }
        
        List_Transactions.push_back(MempoolTransaction(current_transaction[0],stoi(current_transaction[1]),stoi(current_transaction[2]),current_parent_transactions));
    }

    file_input.close();

    return List_Transactions;
}