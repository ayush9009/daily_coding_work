/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
    
// Approach: therree are many linkedlist
// to humne do linkd list consider kari aur unhe merge kar diya using mergeTwoList vale fuction se ,to aise karne 
// se desired output mil jaga agr do linkede list ho sirf lakin yaha to 2 se jada hai ,to aap flatten call karte 
// rahenge jab tak last node pai na pooch jaye jaise hi paoche return root,aur do node hai jaha ye retur  hoga
// ek root,ek root->next to abb merge call hoga(root,root->next)aur do linked list merge hojagi,aur hume
// ek linkedlist milegi ,phir uske liye aur use jis fuction ne call kara uski node kai loiye merge function
// call hoga,in the end we return root
// flatten(l1)->ab merge(l1,l6)call hoga aur ek singlle node i.e l7 return hoga jo ki aapka answer hoga
// flatten(l2)-> ab merge(l2,l5) call hoga aur l6 return hojaga
// flattlen(l3)-> ab yaha aye to l3,aur l4 kai liye merge call huha jis sey ek linked list bni i.e l5
// flatten(l4) ab l4->next=NULL,to return l4 to l3
Node* mergeTwoLists(Node* a, Node* b) {
    Node *temp = new Node(0);
    Node *res = temp; 
    while(a != NULL && b != NULL) {
        if(a->data < b->data) {
            temp->bottom = a; 
            temp = temp->bottom; 
            a = a->bottom; 
        }
        else {
            temp->bottom = b;
            temp = temp->bottom; 
            b = b->bottom; 
        }
    }
    if(a) temp->bottom = a; 
    else temp->bottom = b; 
    return res -> bottom; 
}

Node *flatten(Node *root)
{
    if (root == NULL || root->next == NULL) 
            return root; 
        root->next = flatten(root->next);// recur for list on right 
        root = mergeTwoLists(root, root->next); // now merge 
        return root;      // retur the root 
        // it will be in turn merged with its left 
}
