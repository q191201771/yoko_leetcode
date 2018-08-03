// Given a linked list, remove the n-th node from the end of list and return its head.
//
// Example:
//
// Given linked list: 1->2->3->4->5, and n = 2.
//
// After removing the second node from the end, the linked list becomes 1->2->3->5.
// Note:
//
// Given n will always be valid.
//
// Follow up:
//
// Could you do this in one pass?



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// [1, 2]  1
// [32]  1
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      if (!head || n <= 0) { return head; }

      std::vector<ListNode *> nodes;
      while (head) {
        nodes.push_back(head);
        head = head->next;
      }

      if (n > nodes.size()) {
        return head;
      } else if (n == nodes.size()) {
        return n == 1 ? NULL : nodes[1];
      }  else { // n < nodes.size()
        if (n == 1) {
          nodes[nodes.size()-2]->next = NULL;
          return nodes[0];
        }

        nodes[nodes.size()-n-1]->next = nodes[nodes.size()-n+1];
        return nodes[0];
      }

    }
};
