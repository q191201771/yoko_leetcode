// Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
//
// Example:
//
// Input:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// Output: 1->1->2->3->4->4->5->6



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

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      if (lists.empty()) { return NULL; }
      else if (lists.size() == 1) { return lists[0]; }

      ListNode *ret = NULL;
      for (std::size_t i = 0; i < lists.size(); i++) {
        ret = mergeTwoLists(ret, lists[i]);
      }
      return ret;
    }
};
