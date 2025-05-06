// Question - https://leetcode.com/problems/linked-list-cycle/
//Part-1 Brute Force
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*, bool> mp;
        ListNode* temp=head;
        while(temp) {
            if(mp[temp]) {
                return true;
            }
            mp[temp]=true;
            temp=temp->next;
        }
        return false;
        
    }
};


//Part-2 Optimal
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return NULL;
        ListNode* slow=head, *fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL) {
            slow=slow->next;
            fast=fast->next->next;
            if (slow==fast){return true;}
        }
        return false;
    }
};
