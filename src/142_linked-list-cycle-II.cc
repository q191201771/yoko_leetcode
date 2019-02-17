// Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
//
// Note: Do not modify the linked list.
//
// Follow up:
// Can you solve it without using extra space?



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
    ListNode *detectCycle(ListNode *head) {
      ListNode *p1 = head;
      ListNode *p2 = head;
      for (; ; ) {
        if (!p1 || !p1->next || !p2 || !p2->next || !p2->next->next) { return NULL; }

        p1 = p1->next;
        p2 = p2->next->next;
        if (p1 == p2) { break; }
      }
      p1 = head;
      for (; p1 != p2; p1=p1->next,p2=p2->next);

      return p1;

    }
};
