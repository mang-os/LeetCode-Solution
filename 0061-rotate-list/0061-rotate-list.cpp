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
    ListNode* findNthNode(ListNode* temp,int k){
        int count=1;
        while(temp!=nullptr){
            if(count==k)return temp;count++;
            
            temp=temp->next;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
       if(head==nullptr||k==0)return head;
        ListNode* tail=head;
        int len=1;
        while(tail->next!=nullptr){
            len++;
            tail=tail->next;
        }
        k=k%len;
        if(k%len==0)return head;
        tail->next=head;
        ListNode* newTail=findNthNode(head,len-k);
        
        head=newTail->next;
        newTail->next=nullptr;

        return head;
    }
};