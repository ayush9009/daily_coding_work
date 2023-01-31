#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node* links[2];
    bool containsKey(int ind){
        return (links[ind]!=NULL);
    }
    Node* get(int ind){
        return links[ind];
    }
    void put(int ind,Node *node){
        links[ind]=node;
    }
};
class Trie{
    private:Node *root;
    public:
    Trie(){
        root=new Node();
    }
    public:
    void insert(int num){
        Node* node=root;
        // ab ek number suppose 256 to ya phir 32 bits ka hai to
        // uski har bit yani jasie 5 bits for number 8 is 0 1 0 0 0 ,to
        // ye sab bits aise hume trie ki nodes mai insert karni to
        // ab 5 hai to ye kaise pata chle iski konsi bit set hai konsi ni
        // to uske kai liye vo hi purana logic (num>>i)&1 ye bta dega ith bit set or not
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(!node->containsKey(bit)){
                // ab agr ye bit trie mai nhi hai to trie mai daldo using put 
                node->put(bit,new Node());
            }
             // aur hai ya nhi hai iska refernce pai to ab paoch jao using get
            node=node->get(bit);
        }
    }
    public:
    int max_xor(int num){
        // ab maximum chaiye xor to 1^0=1 ,0^1=1 to agr humare pas 0 to 
        // hume 1 chah ra,agr 1 hai to 0 chah ra,agr milgya to bht bdaiya
        // nhi to jo humare num yani(x) to uski jo bit hai us particular possition
        // ki jiskey liye oppoiste ni mila uske liye vaha x ki bit hi dal dena,us 
        // position ki
        Node* node=root;
         // to ab agr x=8 hai to ise pahle binary mai iski bit ka xor arr1[i]
        //  kai elements ki sath karte jange aur store karte jange
        // jis store vali value sabse jada vo hum return kar denge
        int maxNum=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(node->containsKey(!bit)){
                // mtlb agr !Bit yani opposite search karna maximum kai liye
                // for 0 we need 1 and for 1 we need 0
                // to isliey !bit lagaya
                // agr !bit hai trie mai to ise maxNUm mai store kar lo
                // aur is !bit kai reference pai chle jao
                maxNum=maxNum | (1<<i);
                node=node->get(!bit);
            }
            else{
                node=node->get(bit);//yani agr nhi hai to x ki bit jo hai uske refernce
            }
        }
        return maxNum;
    }
};
int maximumXor(vector<int> &nums)
{
   int max_ans=0;
        int n=nums.size();
        Trie* trie=new Trie();
              
        
        // TrieNode* t=new TrieNode();
        
        for(int i=0;i<n;i++)
        {
            trie->insert(nums[i]);
            max_ans=max(max_ans,trie->max_xor(nums[i]));
//           bhai deko agr arr2 hai to trie->max_xor(arr2[i]) kar dena
        }
        return max_ans;
    
}
