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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* p1 = list1;
        ListNode* p2 = list2;

        ListNode* ans = nullptr;
        ListNode* res = nullptr;

        if(p1==nullptr){
            return p2;
        }
        if(p2==nullptr){
            return p1;
        }

        while(p1!=nullptr || p2!=nullptr){
            if(p1!=nullptr && p2!=nullptr){
                if(p1->val <= p2->val){
                    if(ans==nullptr){
                        ans = p1;
                        res = ans;
                    }
                    else{
                        ans->next = p1;
                        ans = ans->next;
                    }
                    p1 = p1->next;
                }
                else if(p2->val < p1->val){
                    if(ans==nullptr){
                        ans = p2;
                        res = ans;
                    }
                    else{
                        ans->next = p2;
                        ans = ans->next;
                    }
                    p2 = p2->next;
                }
            }
            else if(p1!=nullptr){
                 while(p1!=nullptr){
                    ans->next = p1;
                    ans = ans->next;
                    p1 = p1->next;
                }
            }
            else if(p2!=nullptr){
                 while(p2!=nullptr){
                    ans->next = p2;
                    ans = ans->next;
                    p2 = p2->next;
                }
            }
        }


        return res;
    }
};