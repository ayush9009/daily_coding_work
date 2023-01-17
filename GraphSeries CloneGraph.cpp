/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
   unordered_map<Node*,Node*>mp;
   //declarnig a map tp check whethtr a copy of node is already created or not
    Node* cloneGraph(Node* node) {
        if(node==NULL)return NULL;//if node is null then simply return null
        if(mp.find(node)==mp.end()){  //if node is  not presetn inmap then create a node,and check for this node neighbors(i.e its adjent)
            mp[node]=new Node(node->val);  //store node in map,make a copy
            for(auto adj:node->neighbors){   //traverse for node adjacent
                mp[node]->neighbors.push_back(cloneGraph(adj));  //store that node adjacents in mp,add copy
            }
        }
        return mp[node];
    }
};
