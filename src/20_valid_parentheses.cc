// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
// An input string is valid if:
//
// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Note that an empty string is also considered valid.
//
// Example 1:
//
// Input: "()"
// Output: true
// Example 2:
//
// Input: "()[]{}"
// Output: true
// Example 3:
//
// Input: "(]"
// Output: false
// Example 4:
//
// Input: "([)]"
// Output: false
// Example 5:
//
// Input: "{[]}"
// Output: true
//



#define MATCH_SNIPPET(l, r) \
  if (s[i] == r) { \
    if (cs.empty() || cs.top() != l) { \
      return false; \
    } \
    cs.pop(); \
    continue; \
  }

class Solution {
public:
    bool isValid(string s) {
      // NOTICE "" -> true
      if (s.length() % 2) { return false; }

      std::stack<char> cs;
      for (std::size_t i = 0; i < s.length(); i++) {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
          cs.push(s[i]);
        } else if (s[i] == '}' || s[i] == ']' || s[i] == ')') {
          MATCH_SNIPPET('{', '}');
          MATCH_SNIPPET('[', ']');
          MATCH_SNIPPET('(', ')');
        } else {
          return false;
        }
      }

      return cs.empty();

    }
};
