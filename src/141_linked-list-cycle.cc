// Given a linked list, determine if it has a cycle in it.
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
    bool hasCycle(ListNode *head) {
      ListNode *p1 = head;
      ListNode *p2 = head;
      for (; ; ) {
        if (!p1 || !p1->next || !p2 || !p2->next || !p2->next->next) { return false; }

        p1 = p1->next;
        p2 = p2->next->next;
        if (p1 == p2) { return true; }
      }
    }
};
