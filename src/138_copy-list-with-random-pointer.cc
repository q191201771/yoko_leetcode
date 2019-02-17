A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.



/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
      if (!head) { return NULL; }

      map<RandomListNode *, int> m;
      vector<RandomListNode *> v;
      RandomListNode *p = head;
      int i = 0;
      while (p) {
        m[p] = i;
        v.push_back(new RandomListNode(p->label));
        if (i > 0) {
          v[i-1]->next = v[i];
        }
        p = p->next;
        i++;
      }
      i = 0;
      while (head) {
        if (head->random) {
          int index = m[head->random];
          v[i]->random = v[index];
        }
        head = head->next;
        i++;
      }
      return v[0];

    }
};
