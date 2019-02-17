// Sort a linked list in O(n log n) time using constant space complexity.
//
// Example 1:
//
// Input: 4->2->1->3
// Output: 1->2->3->4
// Example 2:
//
// Input: -1->5->3->4->0
// Output: -1->0->3->4->5



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
  ListNode *mergeList(ListNode *p1, ListNode *p2) {
    ListNode *ret = NULL;
    ListNode *p = NULL;
    while (p1 && p2) {
      if (p1->val < p2->val) {
        if (p) { p->next = p1; }

        p = p1;
        p1 = p1->next;
      } else {
        if (p) { p->next = p2; }

        p = p2;
        p2 = p2->next;
      }
      if (!ret) { ret = p; }
    }

    if (p1) {
      if (p) { p->next = p1; }
      else { p = p1; }
    }
    if (p2) {
      if (p) { p->next = p2; }
      else { p = p2; }
    }

    return ret;
  }
public:
    ListNode* sortList(ListNode* head) {
      if (!head || !head->next) { return head; }

      ListNode *p1 = head;
      ListNode *p2 = head->next;

      while (p2 && p2->next) {
        p1 = p1->next;
        p2 = p2->next->next;
      }
      p2 = p1->next;
      p1->next = NULL;
      return mergeList(sortList(head), sortList(p2));
    }
};
