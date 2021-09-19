/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * class ImmutableListNode {
 * public:
 *    void printValue(); // print the value of the node.
 *    ImmutableListNode* getNext(); // return the next node.
 * };
 */

class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        stack<ImmutableListNode*> s;
        s.push(head);
        while(head->getNext()){
            s.push(head->getNext());
            head = head->getNext();
        }
        
        while(!s.empty()){
            s.top()->printValue();
            s.pop();
        }
    }
};