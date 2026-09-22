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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode *temp2=l1;
        if(l1->val==0 && l1->next==NULL && l2->val==0 && l2->next==NULL){
            return l1;
        }
        int sum=0,carry=0;
        vector<int>d;
    while(l1!=NULL ||l2!=NULL||carry){
        sum=carry;
        if(l1){
        sum+=l1->val;
        l1=l1->next;
        }
        if(l2){
        sum+=l2->val;
        l2=l2->next;
        }
        carry=sum/10;
        d.push_back(sum%10);

    }
    ListNode dummy(0);
       ListNode *tail=&dummy;
         for(auto j:d){
            tail->next=new ListNode(j);
            tail=tail->next;
         }
         return dummy.next;
    }
};

     