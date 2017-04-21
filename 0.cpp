/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* head;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int ret = head->val;
        int count = 1;
        ListNode *p = head->next;
        while (p != NULL){
            count++;
            if ((rand() % count) == 0) ret = p->val;
            p = p->next;
        }
        return ret;
    }
};

/*
Problem:
Choose k entries from n numbers. Make sure each number is selected with the probability of k/n
Basic idea:
Choose 1, 2, 3, ..., k first and put them into the reservoir.
For k+1, pick it with a probability of k/(k+1), and randomly replace a number in the reservoir.
For k+i, pick it with a probability of k/(k+i), and randomly replace a number in the reservoir.
Repeat until k+i reaches n.

Prove:
i is the number of numbers so far
for i = k + 1:
    for the ith item to stay is p = k/i
    for the prev item to stay is p = 1 - (k/i) * (1/k) = (i-1)/i = k/i
for i = j + 1, j > k;
    assume that p(each item to stay when i = j) = k/j
    then for the j+1 item to stay is k/(j+1)
    for prev any item to stay is:
        p(already stayed) * p(not replaced)
      = k/j * (1 - k/(j+1) * 1/k) = (k/j）* (j/j+1) = k/(j+1) = k/i
*/