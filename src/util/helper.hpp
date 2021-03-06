#pragma once

#ifdef YOKO_DEBUG

#include <assert.h>
#include <stdio.h>
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
#include "chef_stringify_stl.hpp"
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

static inline std::string __natural_list_to_string(ListNode *p) {
  if (!p) { return std::string(); }

  std::ostringstream oss;
  oss << "{";
  for (; p; p = p->next) {
    oss << p->val << " ";
  }
  oss << "}";
  return oss.str();
}

static inline ListNode *__natural_list_create(const std::vector<int> &v) {
  if (v.empty()) { return NULL; }

  ListNode *head = NULL;
  ListNode *p = NULL;
  for (const auto &item : v) {
    if (!p) {
      p = new ListNode(item);
      head = p;
    } else {
      p->next = new ListNode(item);
      p = p->next;
    }
  }
  return head;
}

#endif
