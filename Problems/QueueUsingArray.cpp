template <typename T>
class QueueUsingArray {
    T *data;
    int size;
    int front;
    int rear;
    int capacity;

   public:
    QueueUsingArray(int totalSize) {
        this->data = new T[totalSize];
        this->size = 0;
        this->front = -1;
        this->rear = 0;
        this->capacity = totalSize;
    }

    bool isEmpty() { return size == 0; }
    int getSize() { return size; }
    T top() {
        if (isEmpty()) {
            std::cout << "Queue empty";
            return 0;
        }
        return data[front];
    }
    void enqueue(T elm) {
        if (size == capacity) {
            T *newData = new T[2 * capacity];
            int j = 0;
            for (int i = front; i < capacity; i++) {
                newData[j] = data[i];
                j++;
            }
            for (int i = 0; j < front; i++) {
                newData[j] = data[i];
                j++;
            }
            delete[] data;
            data = newData;
            front = 0;
            rear = capacity;
            capacity *= 2;
        }
        data[rear] = elm;
        rear = (rear + 1) % capacity;
        size++;
        if (front == -1) {
            front = 0;
        }
    }

    T dequeue() {
        if (isEmpty()) {
            std::cout << "Queue empty";
            return 0;
        }
        T ans = data[front];
        front = (front + 1) % capacity;
        size--;
        if (size == 0) {
            front = -1;
            rear = 0;
        }
        return ans;
    }

    void printQueue() {
        std::cout << "\nPrint called: " << this->front << " " << this->rear
                  << std::endl;
        for (int i = front; i <= rear; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};