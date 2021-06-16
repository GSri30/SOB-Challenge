[![Version](https://img.shields.io/badge/version-1.0.0-green)]("#")
[![Issues](https://img.shields.io/github/issues-raw/GSri30/SOB-Challenge)](https://github.com/GSri30/SOB-Challenge/issues)
[![Closed Issues](https://img.shields.io/github/issues-closed-raw/GSri30/SOB-Challenge)](https://github.com/GSri30/SOB-Challenge/issues)
[![PR's Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=flat)]("#") 
[![Pull Requests](https://img.shields.io/github/issues-pr/GSri30/SOB-Challenge)]("#")
[![Contributors](https://img.shields.io/github/contributors/GSri30/SOB-Challenge)]("#")

## Summer of Bitcoin Code Challenge Solution

### Idea
- Using DP for calculating the max fee that can be obtained along with satisfying the block capacity condition. (0/1 knapsack)
- And for making the parent transactions to come before (in the list), the algo uses Topological sorting. (i.e. it first makes a graph of the answer obtained from dp and then applies topo sort on the list)

### Complexity
- For DP, O(nW)
- For Topological sort, O(n)

- Total Complexity : O(nW)

*Here I have considered the capacity of a block, W as 100000 as the given constraints are very huge for my algorithm*
(Given sample Input : W=4e6 and n=5e3)

### Way to Execute program
```
g++ *.cpp Src/*.cpp
./a.out
```
*Include mempool.csv in the same location where Main.cpp is present. It is also the same location where block.txt is generated.*

### Assumptions made

*These assumptions were made due to lack of clarity in the problem statement*

- I have assumed that it is not required to include all the parent transactions of a transaction (say "A") in our block, if we consider "A" in our block. The only condition to satisfy is that the parent transactions should come before their children in the final block list. (if included any)

- There won't be any cycles in the transactions. i.e. if 'A' transaction has 'B' as parent, then 'B' won't be having 'A' as parent. Or in other terms, the transactions form a DAG.

### Final Answer
- After considering the block capacity as 1e5, I was able to get a fees of 1998524. (Though this is wrong as the problem was asked for a block capacity of 4e6 which is far beyond the computational power of my laptop for the given input)


### Further optimisations
- Though it could have been possible to obtain a better fees just by using a naive algorithm (sort by fees/weight), but it only gives better results for the current given input. And there are many counter cases that are possible, where it could fail. (even for much smaller inputs). Therefore I have proceeded with the optimised algorithm itself, though it doesn't provide better results for the given input. But with a higher computational power laptop,the algo will return the best possible results (independent of input, which is not the case while using a navie approach). Hence there is always some tradeoff.