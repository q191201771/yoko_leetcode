// Compare two version numbers version1 and version2.
// If version1 > version2 return 1; if version1 < version2 return -1;otherwise return 0.
//
// You may assume that the version strings are non-empty and contain only digits and the . character.
// The . character does not represent a decimal point and is used to separate number sequences.
// For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the
// second first-level revision.
//
// Example 1:
//
// Input: version1 = "0.1", version2 = "1.1"
// Output: -1
// Example 2:
//
// Input: version1 = "1.0.1", version2 = "1"
// Output: 1
// Example 3:
//
// Input: version1 = "7.5.2.4", version2 = "7.5.3"
// Output: -1



#ifdef YOKO_DEBUG
#include "util/helper.hpp"
#endif
class Solution {
private:
  void help(string &v, vector<int> &ns) {
      int b = 0;
      for (int i = 0; i < v.length(); i++) {
        if (v[i] == '.') {
          ns.push_back(atoi(v.substr(b, i-b).c_str()));
          b = i+1;
        }
      }
      ns.push_back(atoi(v.substr(b).c_str()));
  }
public:
    int compareVersion(string version1, string version2) {
      vector<int> ns1; vector<int> ns2;
      help(version1, ns1);
      help(version2, ns2);
      if (ns1.size() > ns2.size()) {
        int i = 0;
        for (; i < ns2.size(); i++) {
          if (ns1[i] > ns2[i]) { return 1; }
          else if (ns1[i] < ns2[i]) { return -1; }
        }
        for (; i < ns1.size(); i++) {
          if (ns1[i] > 0) { return 1; }
        }
        return 0;
      }
      if (ns1.size() < ns2.size()) {
        int i = 0;
        for (; i < ns1.size(); i++) {
          if (ns1[i] > ns2[i]) { return 1; }
          else if (ns1[i] < ns2[i]) { return -1; }
        }
        for (; i < ns2.size(); i++) {
          if (ns2[i] > 0) { return -1; }
        }
        return 0;
      }
      if (ns1.size() == ns2.size()) {
        int i = 0;
        for (; i < ns1.size(); i++) {
          if (ns1[i] > ns2[i]) { return 1; }
          else if (ns1[i] < ns2[i]) { return -1; }
        }
        return 0;
      }

    }
};
#ifdef YOKO_DEBUG
int main() {
  Solution s;
  int ret;
  ret = s.compareVersion("0.1", "1.1");
  ret = s.compareVersion("1.0.1", "1");
  ret = s.compareVersion("7.5.2.4", "7.5.3");
  ret = s.compareVersion("1.0", "1");
  ret = s.compareVersion("1.0.1", "1");
  ret = s.compareVersion("1", "1.1");
  std::cout << "ret:" << ret << std::endl;
  return 0;
}
#endif
