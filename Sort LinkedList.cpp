// Leetcode - https://leetcode.com/problems/sort-list
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* small = head, *big=head->next;
        while(big!=NULL && big->next!=NULL) {
            small=small->next;
            big=big->next->next;
        }
        return small;
    }
    ListNode* mergeSorted(ListNode* head1, ListNode* head2) {
        ListNode* d = new ListNode(-1);
        ListNode* res = d;
        while(head1 && head2){
            if(head1->val > head2->val){
                d->next=head2;
                head2=head2->next;
                d=d->next;
            } else {
                d->next=head1;
                head1=head1->next;
                d=d->next;
            }
        }
        if(head1){d->next=head1;}
        else{d->next=head2;}
        return res->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* mid = middleNode(head);
        cout << "Middle node - " << mid->val << endl;
        ListNode* nex = mid->next;
        mid->next=NULL;
        cout << "Nex node - " << nex->val << endl;
        ListNode* head1 = sortList(head);
        cout << "Head1 node - " << head1->val << endl;
        ListNode* head2 = sortList(nex);
        cout << "Head2 node - " << head1->val << endl;
        return mergeSorted(head1, head2);
    }
};
