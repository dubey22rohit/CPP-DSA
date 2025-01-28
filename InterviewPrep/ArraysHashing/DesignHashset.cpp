#include <iostream>
#include <vector>
using namespace std;

class MyHashSet {
  vector<int> hs;

 public:
  MyHashSet() {}

  void add(int key) {
    if (find(hs.begin(), hs.end(), key) == hs.end()) {
      hs.push_back(key);
    }
  }

  void remove(int key) {
    auto it = find(hs.begin(), hs.end(), key);
    if (it != hs.end()) {
      hs.erase(it);
    }
  }

  bool contains(int key) { return find(hs.begin(), hs.end(), key) != hs.end(); }
};

int main() { return 0; }