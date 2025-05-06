// LeetCode link - https://leetcode.com/problems/add-two-numbers/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* d = new ListNode(-1);
        ListNode* temp = d;

        int c = 0;
        while(l1 || l2 || c>0){
            int s = 0;
            if(l1){
                s += l1->val;
                l1 = l1->next;
            }
            if(l2){
                s += l2->val;
                l2 = l2->next;
            }
            s += c;
            ListNode* n = new ListNode(s%10);
            c = s/10;
            temp->next=n;
            temp=temp->next;
            

        }

        return d->next;
    }
};
