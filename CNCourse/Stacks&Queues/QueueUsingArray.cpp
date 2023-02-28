template <typename T>
class QueueUsingArray {
    T *data;
    int size;
    int front;
    int rear;
    int cap;

   public:
    QueueUsingArray(int totalSize) {
        this->data = new T[totalSize];
        this->size = 0;
        this->front = -1;
        this->rear = 0;
        this->cap = totalSize;
    }
    bool isEmpty() { return (size == 0); }
    int getSize() { return size; }
    void enqueue(T e) {
        if (size == cap) {
            T *newData = new T[2 * cap];
            int j = 0;
            for (int i = front; i < cap; i++) {
                newData[j] = data[i];
                j++;
            }
            for (int i = 0; i < front; i++) {
                newData[j] = data[i];
                j++;
            }
            delete[] data;
            data = newData;
            front = 0;
            rear = cap;
            cap *= 2;
        }
        data[rear] = e;
        rear = (rear + 1) % cap;
        size++;
        if (front == -1) {
            front = 0;
        }
    }
    T frontele() {
        if (isEmpty()) {
            cout << "Queue Empty";
            return 0;
        }
        return data[front];
    }
    T dequeue() {
        if (isEmpty()) {
            cout << "Queue Empty : " << endl;
            return 0;
        }
        T ans = data[front];
        front = (front + 1) % cap;
        size--;
        if (size == 0) {
            front = -1;
            rear = 0;
        }
        return ans;
    }
    void printQueue() {
        for (int i = front; i <= rear; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};
