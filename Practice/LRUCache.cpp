#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
  int k;
  int val;
  Node *prev;
  Node *next;

  Node(int key, int value) {
    this->k = key;
    this->val = value;
    prev = NULL;
    next = NULL;
  }
};
class LRUCache {
public:
  LRUCache(int capacity) {
    this->cap = capacity;
    left = new Node(0, 0);
    right = new Node(0, 0);

    left->next = right;
    right->prev = left;
  }

  int get(int key) {
    if (cache.find(key) != cache.end()) {
      remove(cache[key]);
      insert(cache[key]);
      return cache[key]->val;
    }
    return -1;
  }

  void put(int key, int value) {
    if (cache.find(key) != cache.end()) {
      remove(cache[key]);
    }
    cache[key] = new Node(key, value);
    insert(cache[key]);
    if (cache.size() > cap) {
      Node *lru = left->next;
      remove(lru);
      cache.erase(lru->k);

      delete lru;
    }
  }

private:
  unordered_map<int, Node *> cache;
  int cap;
  Node *left;
  Node *right;

  void insert(Node *node) {
    Node *prev = right->prev;
    Node *next = right;

    prev->next = node;
    next->prev = node;

    node->prev = prev;
    node->next = next;
  }
  void remove(Node *node) {
    Node *prev = node->prev;
    Node *next = node->next;

    prev->next = next;
    next->prev = prev;
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
