// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
//
// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
//
// Example:
//
// Given this linked list: 1->2->3->4->5
//
// For k = 2, you should return: 2->1->4->3->5
//
// For k = 3, you should return: 3->2->1->4->5
//
// Note:
//
// Only constant extra memory is allowed.
// You may not alter the values in the list's nodes, only nodes itself may be changed.



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#ifdef YOKO_DEBUG
#include "util/helper.hpp"
#endif

// [1,2,3,4,5]  1
// [1,2,3,4,5]  2
class Solution {
private:
  bool ensure_len(ListNode *p, int k, ListNode **last) {
    int i = 0;
    for (; p; p = p->next) {
      if (++i >= k) {
        *last = p;
        return true;
      }
    }
    return false;
  }

  // return new head if k element exist
  ListNode *helper(ListNode *p, int k, ListNode **next) {
    ListNode *block_head = NULL;
    if (!ensure_len(p, k, &block_head)) { return NULL; }

    ListNode *p1 = p;
    ListNode *p2 = p1->next;
    p->next = NULL;
    for (; ; ) {
      if (p1 == block_head) {
        *next = p2;
        break;
      }
      ListNode *p3 = p2 ? p2->next : NULL;
      p2->next = p1;
      p1 = p2;
      p2 = p3;
    }
    return block_head;
  }

public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode *p = head;
    ListNode *next;
    ListNode *prev_block_last = NULL;
    for (; ; ) {
      ListNode *block_head = helper(p, k, &next);
      if (!block_head) { // not enough
        if (p == head) {
          return head;
        } else {
          prev_block_last->next = p;
          return head;
        }
      } else {
        if (p == head) {
          head = block_head;
        }
        if (prev_block_last) {
          prev_block_last->next = block_head;
        }
        prev_block_last = p;
        p = next;
      }
    }
    return head;

  }
};

#ifdef YOKO_DEBUG
int main() {
  ListNode *head = __natural_list_create(std::vector<int>({1, 2, 3, 4, 5}));
  std::cout << __natural_list_to_string(head) << std::endl;
  Solution s;
  head = s.reverseKGroup(head, 2);
  std::cout << __natural_list_to_string(head) << std::endl;


  return 0;
}
#endif
