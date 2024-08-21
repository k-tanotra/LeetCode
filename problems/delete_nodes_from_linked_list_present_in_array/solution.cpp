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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s;
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        ListNode* cur=head;
        ListNode* newHead = nullptr;
        ListNode* itr = nullptr;
        while(cur){
            if(s.find(cur->val)==s.end()){
                v.push_back(cur->val);
            }
            cur = cur->next;
        }
        
        for(int i=0;i<v.size();i++){
            if(newHead==nullptr){
                newHead = new ListNode(v[i]);
                itr = newHead;
            }
            else{
                itr->next = new ListNode(v[i]);
                itr = itr->next;
            }
        }
        return newHead;
    }
};