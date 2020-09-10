#include<bits/stdc++.h>
using namespace std;

const int sz = 26;

struct node
{
    node* arr[sz];
    bool isend;
    node()
    {
        for(int i = 0 ; i < sz ; ++i) arr[i] = NULL;
        isend = false;
    }
};

void insert(node* root , string key)
{
    node* temp = root;
    int n = key.length() ;
    for(int i = 0 ; i < n ; ++i){
        int index = key[i] - 'a' ;
        if(temp->arr[index] == NULL) temp->arr[index] = new node();
        temp = temp->arr[index];
    }
    temp->isend = true;
}

string ans = "" ;
node* global ;

void dfs(node* root , string key)
{
    if(root == NULL) return ;
    for(int i = 0 ; i < sz ; ++i){
        if(root->arr[i] != NULL){
            if(root->arr[i]->isend == true){
               char c = char(i) + 'a';
               key+=c;
               if(key.length() > ans.length()){
                ans = key ;
               }
               else if(key.length() == ans.length()){
                 if(key < ans){
                    ans = key ;
                 }
               }
               dfs(root->arr[i] , key) ;
               key.pop_back();
            }
        }
    }
    return ;
}

int_fast32_t main()
{
    vector<string> words;
    int n ;
    cin >> n ;
    global = NULL;
    node* root = new node() ;
    global = root ;
    for(int i = 1 ; i <= n ; ++i){
        string key ;
        cin >> key ;
        words.push_back(key);
        insert(root , key) ;
    }
    dfs(root , "") ;
    cout << ans << endl ;
    return 0 ;
}
