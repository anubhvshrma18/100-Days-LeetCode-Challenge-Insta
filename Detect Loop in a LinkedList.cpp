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
