/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==nullptr){
            return false;
        }
        ListNode* slow=head;
        ListNode* fast=slow->next;
        while(slow!=fast && fast!=nullptr && slow!=nullptr){
            slow = slow->next;
            if(fast->next!=nullptr)
                fast = fast->next->next;
            else{
                fast = nullptr;
                break;
            }
        }
        if(fast==nullptr || slow==nullptr){
            return false;
        }
        return true;
    }
};