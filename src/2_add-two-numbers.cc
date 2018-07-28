// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
// Example
//
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Explanation: 342 + 465 = 807.



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
      ListNode *ret = NULL;
      ListNode *node = NULL;
      bool extend = false;
      int val;
      while (l1 || l2) {
        if (!node) {
          node = new ListNode(0);
          ret = node;
        } else {
          node->next = new ListNode(0);
          node = node->next;
        }
        val = 0;
        if (l1) {
          val += l1->val;
          l1 = l1->next;
        }
        if (l2) {
          val += l2->val;
          l2 = l2->next;
        }
        if (extend) {
          val++;
        }
        if (val >= 10) {
          extend = true;
          val -=10;
        } else {
          extend = false;
        }
        node->val = val;
      }
      if (extend) {
        node->next = new ListNode(1);
      }
      return ret;

    }
};
