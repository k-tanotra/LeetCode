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
    void remove(ListNode** hp,ListNode* cur,ListNode* prev,int &idx,int n){
         if(cur==nullptr){
             return;
         }
         remove(hp,cur->next,cur,idx,n);
         idx = idx+1;
         if(idx==n){
            if(cur==*hp){
                *hp = cur->next;
                cur->next =nullptr;
            }
            else{
                prev->next = cur->next;
                cur->next =  nullptr;
            }
        }
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int idx =  0;
        remove(&head,head,nullptr,idx,n);
        return head;
    }
};