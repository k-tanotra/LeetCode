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
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* temp = nullptr;
        ListNode* prev = nullptr;
        while(cur){
            if(!prev){
                temp = cur->next;
                cur->next = nullptr;
            }
            else{
                temp = cur->next;
                cur->next = prev;
            }
            prev = cur;
            cur = temp;
        }
        return prev;
    }
};