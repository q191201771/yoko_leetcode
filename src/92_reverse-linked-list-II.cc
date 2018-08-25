// Reverse a linked list from position m to n. Do it in one-pass.
//
// Note: 1 ≤ m ≤ n ≤ length of list.
//
// Example:
//
// Input: 1->2->3->4->5->NULL, m = 2, n = 4
// Output: 1->4->3->2->5->NULL



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
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
      if (!head) { return NULL; }
      if (m == n) { return head; }

      int index = 0;
      ListNode *bh = NULL;
      ListNode *bt = NULL;
      ListNode *mt = NULL;
      ListNode *prev = NULL;
      while (head) {
        ++index;
        if (index < m) {
          if (!bh) { bh = head; }

          bt = head;
          head = head->next;
        } else if (index >= m && index <= n) {
          if (index == m) { mt = head; }

          if (index == n) {
            if (bt) { bt->next = head; }
            else { bh = head; }
          }

          ListNode *curr = head;
          head = head->next;
          curr->next = prev;
          prev = curr;
        } else { // index > n
          if (index == n+1) { mt->next = head; }

          head = head->next;
        }
      }
      return bh;
    }
};
#ifdef YOKO_DEBUG
int main() {
  Solution s;
  //auto l = __natural_list_create(vector<int>({1,2,3,4,5}));
  //auto ret = s.reverseBetween(l, 2, 4);
  auto l = __natural_list_create(vector<int>({1,2,3}));
  auto ret = s.reverseBetween(l, 1, 1);
  //auto l = __natural_list_create(vector<int>({1,2,3,4,5}));
  //auto ret = s.reverseBetween(l, 1, 2);
  std::cout << __natural_list_to_string(ret) << std::endl;
  return 0;
}
#endif
