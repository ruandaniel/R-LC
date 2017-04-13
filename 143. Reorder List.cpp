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
    void reorderList(ListNode* head) {
        if (head == NULL) return;
        //find mid node
        ListNode* slow = new ListNode(0), *fast = slow;
        slow->next = head;
        while (fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
         //cut and reverse second part
        ListNode* head2 = rev(slow->next);
        slow->next = NULL;
        //merge two parts
        while (head2 != NULL){
            ListNode* next1 = head->next, *next2 = head2->next;
            head->next = head2;
            head2->next = next1;
            head = next1;
            head2 = next2;
        }
    }
    
    ListNode* rev(ListNode* head){
        if (head == NULL) return NULL;
        ListNode* pre = NULL;
        while (head != NULL){
            ListNode* next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};