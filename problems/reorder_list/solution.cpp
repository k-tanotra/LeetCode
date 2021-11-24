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
    int len(ListNode* head){
        int c = 0;
        while(head){
            head = head->next;
            c++;
        }
        return c;
    }
    ListNode* reverse(ListNode* head){
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
    void print(ListNode* head){
        while(head){
            cout<<head->val<<" ";
            head = head->next;
        }
    }
    void reorderList(ListNode* head) {
        int n = len(head);
        if(n==1){
            return;
        }
        int limit = n%2==0 ? n/2 : n/2+1;
        
        ListNode* h1=head;
        ListNode* cur=head;
        ListNode* h2=nullptr;
        int i = 0;
        while(cur){
            i++;
            if(i==limit){
                h2 = cur->next;
                cur->next=nullptr;
                break;
            }
            cur = cur->next;
        }
        h2 = reverse(h2);
        
        cur = h1;
        ListNode* cur2=h2;
        ListNode* ans = nullptr;
        bool flip = true;
        while(cur && cur2){
            if(!ans){
                ans = cur;
                cur = cur->next;
            }
            else if(flip){
                ans->next = cur;
                cur = cur->next;
                ans = ans->next;
            }
            else{
                ans->next = cur2;
                cur2 = cur2->next;
                ans = ans->next;
            }
            flip = !flip;
        }
        
        while(cur2){
            ans->next = cur2;
            cur2 = cur2->next;
        }
        
        while(cur){
            ans->next = cur;
            cur = cur->next;
        }
        
        head = ans;
    }
};