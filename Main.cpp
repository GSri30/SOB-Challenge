#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
#include "Headers/MempoolTransaction.h"
#include "Headers/Block.h"

using namespace std;

vector<MempoolTransaction> parse_mempool_csv();
void output_block_txt(vector<string>);

int main(){

    auto List_Transactions=parse_mempool_csv();
    
    auto valid_block_transactions=Block::compute_optimal_transactions(List_Transactions);

    output_block_txt(valid_block_transactions);

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

void output_block_txt(vector<string> valid_block_transactions){

    ofstream file_output;
    file_output.open("block.txt");

    for(string transaction:valid_block_transactions){
        file_output<<transaction<<endl;
    }

    file_output.close();

}