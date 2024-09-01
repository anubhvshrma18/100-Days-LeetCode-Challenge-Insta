// Part-1 Brute Force
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> st;
        ListNode* d1=headA, *d2=headB;
        while(d1!=NULL) {
            st.insert(d1);
            d1=d1->next;
        }
        
        while(d2!=NULL) {
            if(st.find(d2) != st.end()) {
                return d2;
            }
            d2=d2->next;
        }
        return NULL;
    }
};


// Part-2 Better
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* d1=headA, *d2=headB;
        int N=0, M=0, diff=0;
        while(d1!=NULL) {
            N++;
            d1=d1->next;
        }
        while(d2!=NULL) {
            M++;
            d2=d2->next;
        }
        d1=headA, d2=headB;
        if(M>N) {
            diff = M-N;
            while(diff--){
                d2=d2->next;
            }
        } else {
            diff = N-M;
            while(diff--){
                d1=d1->next;
            }
        }
        while(d1!= NULL && d2!= NULL && d1!=d2) {
            d1=d1->next;
            d2=d2->next;
        }
        if(d1==d2) {
            return d1;
        }
        return NULL;
    }
};

// Part-3 Optimal
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        ListNode *d1 = headA , *d2=headB;
        while(d1!=d2){
        	d1 = (d1==NULL) ? headB : d1->next;
        	d2 = (d2==NULL) ? headA : d2->next;
        }

        return d1;
    }
};
