/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 class Solution {
    public:
        ListNode* merge2(ListNode* l1,ListNode* l2){
            ListNode* dummy = new ListNode(-1);
            ListNode* head = dummy;
            while(l1 && l2){
                if(l1->val < l2->val){
                    dummy->next = l1;
                    l1=l1->next;
                }
                else{
                    dummy->next = l2;
                    l2=l2->next;
                }
                dummy=dummy->next;
            }
            if(l1){
                dummy->next = l1;
            }
            if(l2){
                dummy->next = l2;
            }
    
            return head->next;
        }
        
        ListNode* merge(vector<ListNode*>& lists,int st,int en){
            if(st > en){
                return NULL;
            }
            if(st==en){
                return lists[st];
            }
            
            int md = st + (en-st)/2;
            ListNode* left = merge(lists,st,md);
            ListNode* right = merge(lists,md+1,en);
            
            return merge2(left,right);
            
        }
        
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            int st = 0 , en = lists.size()-1;
            return merge(lists,st,en);
        }
    };