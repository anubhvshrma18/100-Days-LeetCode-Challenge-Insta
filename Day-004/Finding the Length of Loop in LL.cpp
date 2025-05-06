
/*
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
    int countNodes(Node* node) {
        int res = 1;
        Node* curr = node;
        while (curr->next != node) {
            res++;
            curr = curr->next;
        }
        return res;
    }
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        // Code here
        Node *slow = head, *fast = head;

        while (slow != nullptr && fast != nullptr 
               && fast->next != nullptr) {
                   
            slow = slow->next;
            fast = fast->next->next;
    
            // If slow and fast meet at
            // some point then there is a loop
            if (slow == fast)
                return countNodes(slow);
        }
    
        // Return 0 to indicate that
        //   there is no loop
        return 0;
    }
};