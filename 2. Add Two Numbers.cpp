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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *pre = new ListNode(0), *p = pre;
        int c = 0;
        while (l1 != NULL || l2 != NULL){
            int sum = c;
            if (l1 != NULL){
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL){
                sum += l2->val;
                l2 = l2->next;
            }
            c = sum / 10;
            p->next = new ListNode(sum % 10);
            p = p->next;
        }
        if (c) p->next = new ListNode(c);
        return pre->next;
    }
};