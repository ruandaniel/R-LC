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
    bool isPalindrome(ListNode* head) {
        //first find the mid
        if (head == NULL || head->next == NULL) return true;
        ListNode *fast = head->next, *slow = head;
        while(fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            
        }
        //reverse the second half
        slow->next = reverse(slow->next);
        //compare one by one
        fast = slow->next;
        slow = head;
        while (fast != NULL && slow != NULL){
            if (fast->val != slow->val) return false;
            fast = fast->next;
            slow = slow->next;
        }
        return true;
    }
    
    ListNode* reverse(ListNode *p){
        ListNode *pre = NULL, *next = p->next;
        while(p != NULL){
            next = p->next;
            p->next = pre;
            pre = p;
            p = next;
        }
        return pre;
    }
};