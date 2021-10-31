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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* cur = head;
        int prev = -1;
        vector<int> idx;
        int i=0;
    while(cur){
        if(cur!=head && cur->next!=nullptr && ((prev<cur->val && cur->val>cur->next->val) || (prev>cur->val && cur->val<cur->next->val)) ){
                idx.push_back(i);
        }
        prev = cur->val;
        i++;
        cur=cur->next;
    }
    int n = idx.size();
    vector<int> ans;
        
    if(n>=2){
        int min_diff = INT_MAX;
        int max_diff = idx[n-1] - idx[0];
        for(int i=0;i<n-1;i++){
            min_diff = min(min_diff,abs(idx[i+1]-idx[i]));
        }
        ans.push_back(min_diff);
        ans.push_back(max_diff);
        return ans;
    }
    ans.push_back(-1);
    ans.push_back(-1);
    return ans;
    }
};