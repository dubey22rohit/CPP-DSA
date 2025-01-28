#include <iostream>
#include <vector>
using namespace std;

/*
*  Given an infinite sorted array (or an array with unknown size), find if a
given number ‘key’ is present in the array. Write a function to return the index
of the ‘key’ if it is present in the array, otherwise return -1.

Since it is not possible to define an array with infinite (unknown) size, you
will be provided with an interface ArrayReader to read elements of the array.
ArrayReader.get(index) will return the number at index; if the array’s size is
smaller than the index, it will return Integer.MAX_VALUE.
 */

class ArrayReader {
 public:
  vector<int> arr;

  ArrayReader(const vector<int> &arr) { this->arr = arr; }

  virtual int get(int index) {
    if (index >= arr.size()) {
      return numeric_limits<int>::max();
    }
    return arr[index];
  }
};

// O(logN)
int binarySearch(ArrayReader *reader, int key, int start, int end) {
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (reader->get(mid) == key) {
      return mid;
    } else if (reader->get(mid) > key) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  return -1;
}

// O(logN)
int search(ArrayReader *reader, int key) {
  int start = 0, end = 1;
  while (reader->get(end) < key) {
    int newStart = end + 1;
    end += (end - start + 1) * 2;
    start = newStart;
  }

  return binarySearch(reader, key, start, end);
}

int main() {
  ArrayReader *reader = new ArrayReader(
      vector<int>{4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30});
  cout << search(reader, 16) << endl;
  cout << search(reader, 200);
  return 0;
}