#include<bits/stdc++.h>
using namespace std;
vector<long long> tree1[300005] , tree2[300005];
long long  node[300005] , subtree1[300005] , subtree2[300005] , deg1[300005] , deg2[300005];
const long long p = 97;

bool leaf1(long long NODE)
{
    if(deg1[NODE] == 1 and NODE!=1) return true;
    return false;
}
void dfs3(long long curr , long long par)
{
    for(auto &child : tree1[curr]){
        if(child == par) continue;
        dfs3(child , curr);
    }
    if(leaf1(curr) == true){ /// check for leaf node
        subtree1[curr] = node[curr];
        return;
    }
    long long sum = 0 ;
    for(auto &child : tree1[curr]){
        sum = sum + subtree1[child];
    }
    subtree1[curr] = node[curr] + sum; /// store the hash value for all the subtree of current node
    return ;
}
bool leaf2(long long NODE)
{
    if(deg2[NODE] == 1 and NODE!=1 ) return true;
    return false;
}
void dfs4(long long curr , long long par)
{
    for(auto &child : tree2[curr]){
        if(child == par) continue;
        dfs4(child , curr);
    }
    if(leaf2(curr) == true){
        subtree2[curr] = node[curr];
        return;
    }
    long long sum = 0;
    for(auto &child : tree2[curr]){
        sum = sum + subtree2[child];
    }
    subtree2[curr] = node[curr] + sum;
    return;
}
long long exp(long long x , long long y)
{
    if(y == 0) return 1 ;
    else if(y&1) return x * exp(x , y/2) * exp(x , y/2);
    else return exp(x , y/2) * exp(x , y/2);
}
int main()
{
    long long n;
    srand(time(NULL));
    n = 6 ;
    /// for tree 1
    tree1[1].push_back(2); tree1[2].push_back(1);
    tree1[2].push_back(3); tree1[3].push_back(2);
    tree1[3].push_back(4); tree1[4].push_back(3);
    tree1[4].push_back(5); tree1[5].push_back(4);
    tree1[5].push_back(6); tree1[6].push_back(5);
    deg1[6] = 1 ; /// since 6 is a leaf node for tree 1 .

    /// for tree 2
    tree2[1].push_back(2); tree2[2].push_back(1);
    tree2[2].push_back(3); tree2[3].push_back(2);
    tree2[1].push_back(6); tree2[6].push_back(1);
    tree2[6].push_back(5); tree2[5].push_back(6);
    tree2[5].push_back(4); tree2[4].push_back(5);
    deg2[3] = 1 ; deg2[4] = 1;  /// since both 3 and 4 are leaf nodes of tree 2 .

    long long p = 97 * 13 * 19; /// Take a very high prime
    /// Initialize random values to each node .
    for(long long i=1;i<=n;++i){
        long long val = (rand() * rand() * rand()) + rand() * rand()  + rand();
        node[i] = val * p * rand() + p*13*19*rand() * rand()* 101 * p;
        p*=p;
        p*=p;
    }
    /// do dfs on both trees to get subtree[x] for each node.
    dfs3(1 , 0);
    dfs4(1 , 0 );
    unordered_map<long long ,long long > cnt_tree1 , cnt_tree2 ;
    vector<long long> values;
    for(long long i=1;i<=n;++i){
       long long value1 = subtree1[i];
       long long value2 = subtree2[i];
       values.push_back(value1); /// store the subtree value of tree 1 in a vector to compare it later with subtree value of tree 2.
       cnt_tree1[value1]++;
       cnt_tree2[value2]++;
    }
    long long root_tree1 = subtree1[1];
    long long root_tree2 = subtree2[1];
    cnt_tree1[root_tree1] = 0 ;
    cnt_tree2[root_tree2] = 0;
    long long answer= 0;
    for(auto &x : values){
        /// Check if for a given hash value for tree 1 is there any hash value which matches to hash value of tree 2
        /// if yes , then its possible to divide the tree for this hash value into two equal subsets.
        if(cnt_tree1[x] != 0 and cnt_tree2[x] !=0) ++answer;
    }
    cout << answer << endl;
    return 0;

}
