#include <iostream>
#include <string>
using namespace std;

template <typename V>
class MapNode {
   public:
    string key;
    V value;
    MapNode* next;

    MapNode(string key, V value) {
        this->key = key;
        this->value = value;
        this->next = NULL;
    }

    ~MapNode() { delete next; }
};

template <typename V>
class HashMap {
   private:
    MapNode<V>** buckets;
    int size;
    int numBuckets;

    int getBucketIndex(string key) {
        int hashCode = 0;
        int currentCoeff = 1;
        for (int i = key.length() - 1; i >= 0; --i) {
            hashCode = key[i] * currentCoeff;
            hashCode %= numBuckets;
            currentCoeff *= 37;
            currentCoeff %= numBuckets;
        }
        return hashCode % numBuckets;
    }

    void rehash() {
        MapNode<V>** temp = buckets;
        buckets = new MapNode<V>*[numBuckets * 2];

        for (int i = 0; i < numBuckets * 2; i++) {
            buckets[i] = nullptr;
        }

        int oldBucketCount = numBuckets;
        numBuckets *= 2;
        size = 0;

        for (int i = 0; i < oldBucketCount; i++) {
            MapNode<V>* head = temp[i];
            while (head != nullptr) {
                string key = head->key;
                V value = head->value;
                insert(key, value);
                head = head->next;
            }
        }

        for (int i = 0; i < oldBucketCount; i++) {
            MapNode<V>* head = temp[i];
            delete head;
        }
        delete[] temp;
    }

    double getLoadFactor() { return (1.0 * size) / numBuckets; }

   public:
    HashMap() {
        size = 0;
        numBuckets = 5;
        buckets = new MapNode<V>*[numBuckets];
        for (int i = 0; i < numBuckets; i++) {
            buckets[i] = nullptr;
        }
    }

    ~HashMap() {
        for (int i = 0; i < numBuckets; i++) {
            delete buckets[i];
        }
        delete[] buckets;
    }

    int count() { return size; }

    void insert(string key, V value) {
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        while (head != nullptr) {
            if (head->key == key) {
                head->value = value;
                return;
            }
            head = head->next;
        }
        head = buckets[bucketIndex];
        MapNode<V>* newNode = new MapNode<V>(key, value);
        newNode->next = head;
        buckets[bucketIndex] = newNode;
        size++;
        int loadFactor = getLoadFactor();
        if (loadFactor > 0.7) {
            rehash();
        }
    }
    V getValue(string key) {
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        while (head != nullptr) {
            if (head->key == key) {
                return head->value;
            }
            head = head->next;
        }
        return -1;
    }
    V remove(string key) {
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        MapNode<V>* prev = nullptr;
        while (head != nullptr) {
            if (head->key == key) {
                if (prev == nullptr) {
                    buckets[bucketIndex] = head->next;
                } else {
                    prev->next = head->next;
                }
                V value = head->value;
                head->next = nullptr;
                delete head;
                size--;
                return value;
            }
            prev = head;
            head = head->next;
        }
        return -1;
    }
};

int main() {
    HashMap<int> map;
    for (int i = 0; i < 10; i++) {
        char c = '0' + i;
        string key = "abc";
        key += c;
        int value = i + 1;
        map.insert(key, value);
    }

    for (int i = 0; i < 10; i++) {
        char c = '0' + i;
        string key = "abc";
        key += c;
        cout << key << ": " << map.getValue(key) << endl;
    }

    cout << "Size : " << map.count() << endl;

    map.remove("abc8");
    map.remove("abc9");

    for (int i = 0; i < 10; i++) {
        char c = '0' + i;
        string key = "abc";
        key += c;
        cout << key << ": " << map.getValue(key) << endl;
    }

    cout << "Size : " << map.count() << endl;

    return 0;
}