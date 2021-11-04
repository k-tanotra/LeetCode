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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        ListNode* head=nullptr;
        ListNode* ans = nullptr;
        while(cur1 && cur2){
            if(cur1->val<=cur2->val){
                if(ans==nullptr){
                    ans = cur1;
                    head = cur1;
                    cur1 = cur1->next;
                }
                else{
                    head->next = cur1;
                    head = head->next;
                    cur1 = cur1->next;
                }
            }
            else{
                if(ans==nullptr){
                    ans = cur2;
                    head = cur2;
                    cur2 = cur2->next;
                }
                else{
                    head->next = cur2;
                    head = head->next;
                    cur2 =cur2->next;
                }
            }
        }
        
        while(cur1){
            if(ans==nullptr){
                ans = cur1;
                head = cur1;
                cur1 = cur1->next;
            }
            else{
                head->next = cur1;
                head = head->next;
                cur1 = cur1->next;
            }
        }
        
        while(cur2){
            if(ans==nullptr){
                ans = cur2;
                head = cur2;
                cur2  = cur2->next;
            }
            else{
                head->next = cur2;
                cur2 = cur2->next;
                head = head->next;
            }
        }
        
        return ans;
    }
    ListNode* merge(int start,int end,vector<ListNode*>& lists){
        if(start>end){
            return nullptr;
        }
        if(start==end){
            return lists[start];
        }
        int mid = start+(end-start)/2;
        ListNode* left = merge(start,mid,lists);
        ListNode* right = merge(mid+1,end,lists);
        
        return mergeTwoLists(left,right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int start =0;
        int end = lists.size();
        ListNode* ans = merge(start,end-1,lists);
        return ans;
    }
};