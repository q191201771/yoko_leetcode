// Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
//
// Example:
//
// Input: 1->2->4, 1->3->4
// Output: 1->1->2->3->4->4



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
    /// solution 1. with new node
    // ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    //   if (!l1 && !l2) { return NULL; }

    //   ListNode *node = new ListNode(0);
    //   ListNode *head = node;
    //   while (l1 || l2) {
    //     if (l1 && !l2) {
    //       node->next = new ListNode(l1->val);
    //       node = node->next;
    //       l1 = l1->next;
    //     } else if (!l1 && l2) {
    //       node->next = new ListNode(l2->val);
    //       node = node->next;
    //       l2 = l2->next;
    //     } else { // l1 && l2
    //       if (l1->val < l2->val) {
    //         node->next = new ListNode(l1->val);
    //         node = node->next;
    //         l1 = l1->next;
    //       } else {
    //         node->next = new ListNode(l2->val);
    //         node = node->next;
    //         l2 = l2->next;
    //       }
    //     }
    //   }

    //   node = head->next;
    //   delete head;
    //   return node;

    // }

    /// solution 2. without new node
    #define MERGE_SNIPPET(l) \
      if (!node) { \
        node = l; \
        head = node; \
        l = l->next; \
      } else { \
        node->next = l; \
        node = node->next; \
        l = l->next; \
      }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      ListNode *node = NULL;
      ListNode *head = NULL;
      while (l1 || l2) {
        if (l1 && !l2) {
          MERGE_SNIPPET(l1);
        } else if (!l1 && l2) {
          MERGE_SNIPPET(l2);
        } else {
          if (l1->val < l2->val) {
            MERGE_SNIPPET(l1);
          } else {
            MERGE_SNIPPET(l2);
          }
        }
      }

      return head;

    }

};
