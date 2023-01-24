struct Node{
    Node* links[26];
    bool flag=false;
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);   //if it nuull then that character is not found
    }
    void put(char ch,Node *node){
        links[ch-'a']=node;        //node li uska referce new trie se jod diya
    }
    Node* get(char ch){
        return links[ch-'a'];   //jo links hai mtlb jo node character vali create hui vo jise point kar ri vo reutrn kar do
    }
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
};
class Trie{
    private:
    Node* root;                        //root bnana to jarori tree ka
    public:
    Trie(){
        root=new Node();   //creating object
    }
    void insert(string word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    bool search(string word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i]))return false;
            node=node->get(word[i]);
        }
        return node->isEnd();
    }
    bool startsWith(string prefix){
        Node* node=root;
        for(int i=0;i<prefix.size();i++){
            if(!node->containsKey(prefix[i]))return false;
            node=node->get(prefix[i]);
        }
        return true;
    }
};
