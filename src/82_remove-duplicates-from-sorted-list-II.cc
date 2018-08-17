// Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
//
// Example 1:
//
// Input: 1->2->3->3->4->4->5
// Output: 1->2->5
// Example 2:
//
// Input: 1->1->1->2->3
// Output: 2->3



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
    ListNode* deleteDuplicates(ListNode* head) {
      ListNode *ret = NULL;
      ListNode *prev = NULL;
      while (head) {
        if (head->next && head->val == head->next->val) {
          int val = head->val;
          for (; head && head->val == val; head = head->next);

          continue;
        }

        if (prev) { prev->next = head; }
        if (!ret) { ret = head; }

        prev = head;
        head = head->next;
        prev->next = NULL;
      }
      return ret;
    }
};
#ifdef YOKO_DEBUG
int main() {
  Solution s;
  //vector<int> vec({1,2,2});
  vector<int> vec({1,2,3,3,4,4,5});
  //vector<int> vec({1,2});
  ListNode *head = __natural_list_create(vec);
  head = s.deleteDuplicates(head);
  std::cout << "res:" << __natural_list_to_string(head) << std::endl;
  return 0;
}
#endif
