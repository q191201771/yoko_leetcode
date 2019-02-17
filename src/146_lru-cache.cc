// Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations:
// get and put.
//
// get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
// put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it
// should invalidate the least recently used item before inserting a new item.
//
// Follow up:
// Could you do both operations in O(1) time complexity?
//
// Example:
//
// LRUCache cache = new LRUCache( 2 /* capacity */ );
//
// cache.put(1, 1);
// cache.put(2, 2);
// cache.get(1);       // returns 1
// cache.put(3, 3);    // evicts key 2
// cache.get(2);       // returns -1 (not found)
// cache.put(4, 4);    // evicts key 1
// cache.get(1);       // returns -1 (not found)
// cache.get(3);       // returns 3
// cache.get(4);       // returns 4



class LRUCache {
private:
  typedef pair<int, int> Pair;

  int capacity_;
  list<Pair> list_;
  map<int, list<Pair>::iterator > map_;
public:
    LRUCache(int capacity) {
      capacity_ = capacity;
    }

    int get(int key) {
      auto iter = map_.find(key);
      if (iter == map_.end()) { return -1; }

      auto kv = *(iter->second);
      list_.erase(iter->second);
      list_.push_front(kv);
      map_[key] = list_.begin();
      return kv.second;
    }

    void put(int key, int value) {
      auto iter = map_.find(key);
      if (iter != map_.end()) {
        list_.erase(iter->second);
      } else {
        if (list_.size() == capacity_) {
          auto &iter2 = list_.back();
          map_.erase(iter2.first);
          list_.pop_back();
        }
      }
      list_.push_front(make_pair(key, value));
      map_[key] = list_.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
