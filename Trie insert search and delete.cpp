#include<bits/stdc++.h>
using namespace std;
#define int_fast64_t int

const int sz = 26;

struct node
{
    node *arr[sz] ;
    bool isend;
    node(){
       for(int i = 0 ; i < sz ; ++i) arr[i] = NULL;
       isend = false;
    }
};

bool search(node* root , string key)
{
    node* temp = root;
    int n = key.length();
    for(int i = 0 ; i < n ; ++i){
        int index = key[i] - 'a' ;
        if(temp->arr[index] == NULL) return false;
        temp = temp->arr[index];
    }
    if(temp != NULL and temp->isend == true) return true;
    return false;
}

void insert(node* root , string key)
{
    node* temp = root;
    int n = key.length();
    for(int i = 0 ; i < n ; ++i){
        int index = key[i] - 'a';
        if(temp->arr[index] == NULL) temp->arr[index] = new node();
        temp = temp->arr[index];
    }
    temp->isend = true;
}


bool isempty(node* root)
{
    for(int i = 0 ; i < sz ; ++i) if(root->arr[i]) return false;
    return true;
}

node* remove(node* root, string key , int depth)
{
    if(root == NULL) return NULL;
    int index = key[depth] - 'a' ;
    if(depth == key.length()){
        if(root->isend) root->isend = false;
        if(isempty(root)){
            delete(root);
            root = NULL;
        }
        return root;
    }
    root->arr[index] = remove(root->arr[index] , key , depth + 1);
    if(isempty(root) and root->isend == false){
        delete(root);
        root= NULL;
    }
    return root;

}


int_fast32_t main()
{
    string keys[] = {"the", "a", "there",
                      "answer", "any", "by",
                      "bye", "their", "hero", "heroplane" };
    int n = sizeof(keys) / sizeof(keys[0]);
    node* root = new node();
    for(int i = 0 ; i < n ; ++i) insert(root , keys[i]);
    search(root, "the") ? cout << "Yes\n" : cout << "No\n";
    search(root, "these") ? cout << "Yes\n" : cout << "No\n";
    remove(root, "heroplane" , 0 );
    search(root, "heroplane") ? cout << "Yes\n" : cout << "No\n";
    return 0;
}
