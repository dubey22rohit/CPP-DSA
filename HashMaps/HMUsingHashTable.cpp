#include <iostream>
#include <string>
using namespace std;

// Using seperate chaining / closed hashing to implement this Hashmap, each
// entry in an array will point to a linked list

template <typename V>
class MapNode {
   public:
    string key;
    V value;
    MapNode* next;

    MapNode(string key, V value) {
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~MapNode() { delete next; }
};

template <typename V>
class HashMap {
   private:
    MapNode<V>** buckets;  // Array with each entry pointing to the address of
                           // an LL head.
    int size;              // Number of key,value pairs
    int numBuckets;        // num of individual entry in an array

    int getBucketIndex(string key) {
        int hashCode = 0;

        int currentCoeff = 1;
        for (int i = key.length() - 1; i >= 0; i--) {
            hashCode += key[i] * currentCoeff;
            // hashCode % numBuckets so that int does not go out of bound
            // NOTE: (r1 * r2 * r3) % m = ((r1 % m) * (r2 % m) * (r3 % m)) % m
            hashCode = hashCode % numBuckets;
            currentCoeff *= 37;
            // 37 taken as a random primary number for better distribution
            // currentCoeff % numBuckets so that int does not go out of bound
            currentCoeff = currentCoeff % numBuckets;
        }

        return hashCode % numBuckets;
    }
    void rehash() {
        MapNode<V>** temp = buckets;
        buckets = new MapNode<V>*[2 * numBuckets];
        for (int i = 0; i < 2 * numBuckets; i++) {
            buckets[i] = NULL;
        }
        int oldBucketCount = numBuckets;
        numBuckets *= 2;
        size = 0;
        for (int i = 0; i < oldBucketCount; i++) {
            MapNode<V>* head = temp[i];
            while (head != NULL) {
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

   public:
    HashMap() {
        size = 0;        // Actual numbers of key value pairs
        numBuckets = 5;  // Length of array of LL pointers
        buckets = new MapNode<V>*[numBuckets];
        for (int i = 0; i < numBuckets; i++) {
            buckets[i] = NULL;
        }
    }
    ~HashMap() {
        for (int i = 0; i < numBuckets; i++) {
            delete buckets[i];
        }
        delete[] buckets;
    }

    int count() { return size; }
    double getLoadFactor() { return (1.0 * size) / numBuckets; }

    V getValue(string key) {
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        while (head != NULL) {
            if (head->key == key) {
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }
    void insert(string key, V value) {
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        while (head != NULL) {
            if (head->key == key) {
                head->value = value;
                return;
            }
            head = head->next;
        }
        head = buckets[bucketIndex];
        MapNode<V>* node = new MapNode<V>(key, value);
        node->next = head;
        buckets[bucketIndex] = node;
        size++;
        double loadFactor = (1.0 * size) / numBuckets;
        if (loadFactor > 0.7) {
            rehash();
        }
    }
    V remove(string key) {
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        MapNode<V>* prev = NULL;
        while (head != NULL) {
            if (head->key == key) {
                if (prev == NULL) {
                    buckets[bucketIndex] = head->next;
                } else {
                    prev->next = head->next;
                }
                V value = head->value;
                head->next =
                    NULL;  // So that the recursive destructor that we've
                // written does not delete the whole LL after head;
                delete head;
                size--;
                return value;
            }
            prev = head;
            head = head->next;
        }
        return 0;
    }
};

int main() {
    HashMap<int> map;
    for (int i = 0; i < 10; i++) {
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        int value = i + 1;
        map.insert(key, value);
        cout << "Load factor " << map.getLoadFactor() << endl;
    }
    cout << map.count() << endl;

    map.remove("abc5");
    map.remove("abc6");
    for (int i = 0; i < 10; i++) {
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        cout << key << " : " << map.getValue(key) << endl;
    }

    cout << map.count() << endl;
    return 0;
}