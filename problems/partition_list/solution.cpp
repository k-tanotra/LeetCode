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
    ListNode* partition(ListNode* head, int v) {
        ListNode* L1 = nullptr;
        ListNode* L2 = nullptr;
        ListNode* L1cur = nullptr;
        ListNode* L2cur = nullptr;
        ListNode* x;
        while(head){
            x = head->next;
            if(head->val < v){
                if(L1==nullptr){
                    head->next = nullptr;
                    L1 = head;
                    L1cur = head;
                }
                else{
                    head->next = nullptr;
                    L1cur->next = head;
                    L1cur = L1cur->next;
                }
            }
            else{
                if(L2==nullptr){
                    head->next = nullptr;
                    L2 = head;
                    L2cur = head;
                }
                else{
                    head->next = nullptr;
                    L2cur->next = head;
                    L2cur = L2cur->next;
                }
            }
            head = x;
        }
        
        if(L1!=nullptr){
            L1cur->next = L2;
            return L1;
        }
        
        return L2;
    }
};