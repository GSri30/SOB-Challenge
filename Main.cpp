#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
#include "Headers/MempoolTransaction.h"
#include "Headers/Block.h"

using namespace std;

vector<MempoolTransaction> parse_mempool_csv();
void output_block_txt(Block);

int main(){

    auto List_Transactions=parse_mempool_csv();
    
    auto valid_block=Block.compute_optimal_transactions(List_Transactions);

    output_block_txt(valid_block);

    return 0;
}


vector<MempoolTransaction> parse_mempool_csv(){
    ifstream file_input;
    file_input.open("mempool.csv");
    
    string line,column;

    vector<MempoolTransaction>List_Transactions;

    while(getline(file_input,line)){
        vector<string>current_transaction;
        stringstream _line(line);
        while(getline(_line,column,',')){
            current_transaction.push_back(column);
        }
        List_Transactions.push_back(current_transaction);
    }

    file_input.close();

    return List_Transactions;
}

void output_block_txt(Block valid_block){

    ofstream file_output;
    file_output.open("block.txt");

    for(auto transaction:valid_block.getTransactions()){
        file_output<<transaction.txid<<endl;
    }

    file_output.close();

}