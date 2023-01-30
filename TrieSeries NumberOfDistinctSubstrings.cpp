#include <bits/stdc++.h> 
using namespace std;
struct Node{
    Node* links[26];
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
};
int distinctSubstring(string &word) {
    //  Write your code here.
    Node* root=new Node();
    int count=0;
    int n=word.size();
    for(int i=0;i<n;i++){
        Node* node=root;
        for(int j=i;j<n;j++){
            if(!node->containsKey(word[j])){
                node->put(word[j],new Node());
                count++;
            }
            node=node->get(word[j]);
        }
    }
    return count;
}
