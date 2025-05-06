

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
Node* merge(Node* start, Node* end){
    Node* temp = new Node(-1);
    Node* res = temp;
    while(start!=NULL && end!=NULL) {
        if(start->data < end->data) {
            temp->bottom=start;
            temp = temp->bottom;
            start = start->bottom;
        }
        else {
            temp->bottom = end;
            temp = temp->bottom;
            end=end->bottom;
        }
    }
    if(start){temp->bottom = start;}
    else {temp->bottom = end;}
    return res->bottom;
    
}

/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{
   // Your code here
   if(root==NULL || root->next == NULL) return root;
   root->next=flatten(root->next);
   root=merge(root, root->next);
   return root;
}