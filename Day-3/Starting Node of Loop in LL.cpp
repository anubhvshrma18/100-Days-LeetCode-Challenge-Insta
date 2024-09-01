// Leetcode - https://leetcode.com/problems/linked-list-cycle-ii/
// Part-1 Brute Force 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, bool> mp;
        ListNode* temp=head;
        while(temp!=NULL) {
            if(mp[temp]) {
                return temp;
            }
            mp[temp]=true;
            temp=temp->next;
        }
        return NULL;
        
    }
};


// Part-2 Optimal
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return NULL;
        // Detect a loop
        ListNode* small = head, *fast = head;
        while(fast && fast->next) {
            small = small -> next;
            fast = fast ->next -> next;
            if(small==fast){
                break;
            }
        }
        if(small!=fast) {return NULL;}
        // Find the Starting Point of Loop
        small = head;
        while(small!=fast){
            small=small->next;
            fast = fast->next;
        }
        return small;
        
    }
};
