// Remove all elements from a linked list of integers that have value val.
//
// Example:
//
// Input:  1->2->6->3->4->5->6, val = 6
// Output: 1->2->3->4->5



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
      ListNode *ret = NULL;
      ListNode *prev = NULL;
      while (head) {
        if (head->val != val) {
          if (prev) { prev->next = head; }

          prev = head;

          if (!ret) { ret = head; }
        } else {
          if (prev) { prev->next = NULL; }
        }

        head = head->next;
      }
      return ret;
    }
};
