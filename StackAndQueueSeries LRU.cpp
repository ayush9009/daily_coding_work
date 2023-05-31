class LRUCache {
public:
    //here we used the concept of doubly linked list and hashmap
    //doubly linked because so that we get which is recently used which one late how?
    //the node whhich is just before the tail is least reacently used and the
    //node which is just after the head is recently used
    //whenever we have to insert the node ,first of all we check if it exist in hash map or not,if it
    //exists then first of all we erase it from the hashmap,and dlete this node (how,we get the addres
    //of this node throudgh hasgmap,)and put it after the head becuaase it is recently used
    //if we have to insert whcih is not there in the hashmap ,so we put that nde after the head
    
    
    //VVIP QUESTION COMING SOON IN THE CODING ROUND
    class node{
        public:
        int key;
        int val;
        node *next;
        node *prev;
        node(int _key,int _val){
            key=_key;
            val=_val;
        }
    };
    node *head=new node(-1,-1);
    node *tail=new node(-1,-1);
    int cap;
    unordered_map<int,node*>m;   //ye vo hashmap
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head; //this is our doubly llinked list
    }
    void addnode(node *newnode){
        node *temp=head->next;
        newnode->next=temp;
        newnode->prev=head;
        head->next=newnode;
        temp->prev=newnode;
    }
     void deletenode(node *delnode){
         node *delprev=delnode->prev;
         node *delnext=delnode->next;
         delprev->next=delnext;
         delnext->prev=delprev;
     }
    int get(int key_){
        if(m.find(key_)!=m.end()){
            node *resnode=m[key_];
            int res=resnode->val;
            m.erase(key_);
            deletenode(resnode);
            addnode(resnode);
            m[key_]=head->next;
            return res;
            //get value return the value
        }
        return -1;  ///agr vohash map nhi hai to we return -1
    }
    void put(int key_,int value){
        //agr key with hai to use is vlue se update kardo agr nhi hai to insert kar do
        if(m.find(key_)!=m.end()){
            node *existingnode=m[key_];
            m.erase(key_);
            deletenode(existingnode);
        }
        if(m.size()==cap){
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key_,value));
        m[key_]=head->next;
    }
    
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
