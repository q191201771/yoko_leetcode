Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].



/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
private:
  int __find(vector<Interval> &intervals, int val) {
    int b = 0;
    int e = intervals.size()-1;

    while (b <= e) {
      int m = (b+e)/2;
      if (val < intervals[m].start) {
        e = m-1;
      } else if (val > intervals[m].end) {
        b = m+1;
      } else {
        return m;
      }
    }
    return -1;
  }

public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
      vector<Interval> ret;
      if (intervals.empty()) { ret.push_back(newInterval); return ret; }

      if (newInterval.start > intervals.back().end) {
        intervals.push_back(newInterval);
        return intervals;
      }
      if (newInterval.end < intervals.front().start) {
        intervals.insert(intervals.begin(), newInterval);
        return intervals;
      }

      int bi = __find(intervals, newInterval.start);
      int ei = __find(intervals, newInterval.end);
      for (int i = 0; i < bi; i++) { ret.push_back(intervals[i]); }

      if (newInterval.start < intervals[bi].start) { newInterval.start = intervals[bi].start; }
      if (newInterval.end < intervals[ei].end) { newInterval.end = intervals[ei].end; }

      ret.push_back(newInterval);

      for (int i = ei+1; i < intervals.size(); i++) { ret.push_back(intervals[i]); }

      return ret;
    }
};
