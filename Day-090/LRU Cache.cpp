// Problem Link: https://leetcode.com/problems/lru-cache/
// Time Complexity: O(1) for both get and put operations
// Space Complexity: O(capacity) for storing the cache
// Approach: Using a combination of a doubly linked list and a hash map to achieve O(1) time complexity for both get and put operations.
// The doubly linked list maintains the order of usage, with the most recently used items at the front and the least recently used items at the back.

class LRUCache {
private:
    int capacity;
    list<pair<int, int>> cache; // list to store key-value pairs
    unordered_map<int, list<pair<int, int>>::iterator> map; // map to store key-iterator pairs
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (map.find(key) == map.end()) {
            return -1;
        }
        
        // Move the accessed item to front (most recently used)
        cache.splice(cache.begin(), cache, map[key]);
        return map[key]->second;
    }
    
    void put(int key, int value) {
        // If key exists, update value and move to front
        if (map.find(key) != map.end()) {
            cache.splice(cache.begin(), cache, map[key]);
            map[key]->second = value;
            return;
        }
        
        // If cache is full, remove least recently used item
        if (cache.size() == capacity) {
            map.erase(cache.back().first);
            cache.pop_back();
        }
        
        // Insert new item at front
        cache.push_front({key, value});
        map[key] = cache.begin();
    }
};