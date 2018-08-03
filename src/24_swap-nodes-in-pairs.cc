// Given a linked list, swap every two adjacent nodes and return its head.
//
// Example:
//
// Given 1->2->3->4, you should return the list as 2->1->4->3.
// Note:
//
// Your algorithm should use only constant extra space.
// You may not modify the values in the list's nodes, only nodes itself may be changed.



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// [1, 2, 3, 4]
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
      if (!head || !head->next) { return head; }

      ListNode *p = head;
      ListNode *k = NULL;
      while (p && p->next) {
        ListNode *q = p->next;
        p->next = q->next;
        q->next = p;

        if (k) {
          k->next = q;
        } else {
          head = q;
        }
        k = p;

        p = p->next;
      }
      return head;

    }
};
