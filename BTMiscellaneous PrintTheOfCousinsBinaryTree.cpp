class Solution
{
    // nodes with same parent and depth are siblings
    // nodes with different parent and same depth are cousins
    
//     cousins :the nodes that share same grandparent but differnet parent
//     in exmple1:  parent of 5 is 2 we cannot take 4 becasue it shares same parent 
//     can we take 3 no because 3 ka jo parent vo 5 ka grandparent
//     to 6,7 ho is possible but their parent is differnt then 5 and both 5,6,7 granodarentare same.so
    
//     aapko saaf dikra hoga hum
//     1
//   2  3
//   4 5 6 7   hum islvel pai to 4 ni le sakte i tell u resason already 6,7 le sake i tel u already
//   to level order traversal kara ja sakta hai,
//   lakin agr root->left==node || root->right==node to hum iske child na le yani :
//   2 hai to uske child  5,4 ye hume ni lene iske alava kuch h to hum le sakte hai
//   to agr child match kar ra koisa to vo root node mat consider karo koi dusri node pakad lo
//   queue mai 2,3 thai 2 pop kar diya kuki ye dikt dera tha now queu maipush hogey 6,7 aur iske bad 
//   3 pop hgya. ab jab 2 vala node mila tab counter =false kardo
//   humne sabt raverse kar liya abhi 
  
    public:
    vector<int> printCousins(Node* root, Node* node)
    {
        // cousing share grandparent but not parent
        queue<Node*>q;
        q.push(root);
        vector<int>ans;
        int counter=true;
        while(q.empty()==false && counter){
            int n=q.size();
            for(int i=0;i<n;i++){
                Node*cur=q.front();
                q.pop();
                if(cur->left==node || cur->right==node){
                    counter=false;
                }else{
                    if(cur->left)q.push(cur->left);
                    if(cur->right)q.push(cur->right);
                }
                //ab ecampl1 ki bt kare to queu mai 2,3 thai 2 ki bari as it q.front()
                // aur phir q.pop() hogya to 2->right==5 to counter=false,to queue mai kuch push nihua
                // ab n=2 tha aur i=1 to 3 kai liye chla 3 leke popkardiya 3->left!node 3->right!=node
                // to 3->left,right psh hogye ab loop khtm aur counter=fale dika to queue kai sare
                // element pprint kar do i.e your anwer
            }
        }
         if(q.empty()==true)return {-1};
            else{
                // if(q.size()==0) ans.push_back(-1);
                while(q.empty()==false){
                    ans.push_back(q.front()->data);
                    q.pop();
                }
            }
        return ans;
      
        
    }
    
};
