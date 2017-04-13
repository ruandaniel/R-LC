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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* phead = new ListNode(0);
        phead->next = head;
        ListNode* pre = phead, *cur = head;
        while (cur != NULL){
            if (cur->val == val){
                pre->next = cur->next;
                cur = cur->next;
            }
            else{
                pre = cur;
                cur = cur->next;
            }
        }
        return phead->next;
    }
};