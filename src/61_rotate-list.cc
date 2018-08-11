// Given a linked list, rotate the list to the right by k places, where k is non-negative.
//
// Example 1:
//
// Input: 1->2->3->4->5->NULL, k = 2
// Output: 4->5->1->2->3->NULL
// Explanation:
// rotate 1 steps to the right: 5->1->2->3->4->NULL
// rotate 2 steps to the right: 4->5->1->2->3->NULL
// Example 2:
//
// Input: 0->1->2->NULL, k = 4
// Output: 2->0->1->NULL
// Explanation:
// rotate 1 steps to the right: 2->0->1->NULL
// rotate 2 steps to the right: 1->2->0->NULL
// rotate 3 steps to the right: 0->1->2->NULL
// rotate 4 steps to the right: 2->0->1->NULL



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
// [1]  1
// [1,2]  5
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
      if (!head || !head->next) { return head; }

      vector<ListNode *> vec;
      while (head) {
        vec.push_back(head);
        head = head->next;
      }
      if (k >= vec.size()) { k = k % vec.size(); }
      if (k == 0) { return vec[0]; }

      vec[vec.size()-k-1]->next = NULL;
      vec.back()->next = vec.front();
      return vec[vec.size()-k];
    }
};
#ifdef YOKO_DEBUG
int main() {
  ListNode *head = __natural_list_create(vector<int>({1,2,3}));
  Solution s;
  head = s.rotateRight(head, 3);
  std::cout << __natural_list_to_string(head) << std::endl;
  return 0;
}
#endif
