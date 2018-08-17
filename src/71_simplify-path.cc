// Given an absolute path for a file (Unix-style), simplify it.
//
// For example,
// path = "/home/", => "/home"
// path = "/a/./b/../../c/", => "/c"
//
// Corner Cases:
//
// Did you consider the case where path = "/../"?
// In this case, you should return "/".
// Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
// In this case, you should ignore redundant slashes and return "/home/foo".



#ifdef YOKO_DEBUG
#include "util/helper.hpp"
#endif
class Solution {
public:
    string simplifyPath(string path) {
      if (path.length() <= 1) { return path; }

      std::stack<std::string> s;
      int bpos = 0;
      for (int i = 1; i < path.length(); i++) {
        if (path[i] == '/') {
          if (path[i-1] == '/') {
            bpos = i;
            continue;
          }

          std::string one = path.substr(bpos+1, i-bpos-1);
          bpos = i;
          if (one == ".") { }
          else if (one == "..") {
            if (!s.empty()) { s.pop(); }
          }
          else { s.push(one); }
        }
      }
      if (bpos != path.length()-1) {
        std::string one = path.substr(bpos+1);
        if (one == ".") {  }
        else if (one == "..") {
          if (!s.empty()) { s.pop(); }
        }
        else { s.push(one); }
      }

      if (s.empty()) { return "/"; }

      std::string ret;
      for (; !s.empty(); ) {
        ret.insert(0, s.top());
        ret.insert(0, "/");
        s.pop();
      }
      return ret;
    }
};
#ifdef YOKO_DEBUG
int main() {
  Solution s;
  std::cout << s.simplifyPath("/home/")<< std::endl;
  std::cout << s.simplifyPath("/..") << std::endl;
  std::cout << s.simplifyPath("/../") << std::endl;
  std::cout << s.simplifyPath("/abc/...") << std::endl;
  return 0;
}
#endif
