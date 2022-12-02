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

    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        while(fast!=nullptr){
            fast = fast->next;
            if(fast!=nullptr){
                fast=fast->next;
            }
            else{
                break;
            }
            prev = slow;
            slow = slow->next;
        }
        
        if(prev==nullptr){
            return nullptr;
        }
        
        prev->next = slow->next;
        slow->next =nullptr;
        return head;
        
    }
};