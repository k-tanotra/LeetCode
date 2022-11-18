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
    ListNode* insertionSortList(ListNode* head) {
       ListNode* h = head;
       ListNode* x = nullptr;
       while(h!=nullptr){
           ListNode* y = h->next;
           ListNode* p = nullptr;
           ListNode* f = x;
           while(f!=nullptr && h->val>f->val){
              p = f;
              f=f->next;
           }
           h->next = f;
           if(p==nullptr){
               x=h;
           }
           else{
               p->next = h;
           }
           h=y;
       }
      return x;
    }
};