// Given a singly linked list L: L0→L1→…→Ln-1→Ln,
// reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
//
// You may not modify the values in the list's nodes, only nodes itself may be changed.
//
// Example 1:
//
// Given 1->2->3->4, reorder it to 1->4->2->3.
// Example 2:
//
// Given 1->2->3->4->5, reorder it to 1->5->2->4->3.



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
    void reorderList(ListNode* head) {
      if (!head) { return; }

      vector<ListNode *> v;
      while (head) {
        v.push_back(head);
        head = head->next;
      }
      int i = 0; int j = v.size()-1;
      for (; i != j; ) {
        v[i++]->next = v[j];
        if (i == j) { break; }
        v[j--]->next = v[i];
        if (i == j) { break; }
      }
      v[i]->next = NULL;

    }
};
#ifdef YOKO_DEBUG
int main() {
  Solution s;
  vector<int> v({1,2,3,4});
  ListNode *p = __natural_list_create(v);
  s.reorderList(p);
  std::cout << __natural_list_to_string(p) << std::endl;
  return 0;
}
#endif
