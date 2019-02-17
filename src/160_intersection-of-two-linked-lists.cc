// Write a program to find the node at which the intersection of two singly linked lists begins.
//
//
// For example, the following two linked lists:
//
// A:          a1 → a2
//                    ↘
//                      c1 → c2 → c3
//                    ↗
// B:     b1 → b2 → b3
// begin to intersect at node c1.
//
//
// Notes:
//
// If the two linked lists have no intersection at all, return null.
// The linked lists must retain their original structure after the function returns.
// You may assume there are no cycles anywhere in the entire linked structure.
// Your code should preferably run in O(n) time and use only O(1) memory.
// Credits:
// Special thanks to @stellari for adding this problem and creating all test cases.



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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      int al = 0; int bl = 0;
      ListNode *p = headA;
      while (p) {
        al++;
        p = p->next;
      }
      p = headB;
      while (p) {
        bl++;
        p = p->next;
      }
      if (al > bl) {
        p = headA;
        for (int i = 0; i < al-bl; i++) {
          p = p->next;
        }
        while (p && headB) {
          if (p == headB) { return p; }
          else {
            p = p->next;
            headB = headB->next;
          }
        }
      } else {
        p = headB;
        for (int i = 0; i < bl-al; i++) {
          p = p->next;
        }
        while (p && headA) {
          if (p == headA) { return p; }
          else {
            p = p->next;
            headA = headA->next;
          }
        }
      }
      return NULL;

    }
};
