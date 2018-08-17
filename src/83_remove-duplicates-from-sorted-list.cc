Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// [1,1,2]
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
      ListNode *ret = NULL;
      ListNode *prev = NULL;
      while (head) {
        for (; head->next && head->val == head->next->val; head = head->next);

        if (!ret) { ret = head; }
        if (prev) { prev->next = head; }

        prev = head;
        head = head->next;
      }
      return ret;
    }
};
