class QueueUsingLL {
    int size;
    Node* front;
    Node* rear;

   public:
    QueueUsingLL() {
        this->size = 0;
        this->front = NULL;
        this->rear = NULL;
    }
    bool isEmpty() { return (size == 0); }
    int getSize() { return size; }
    void enqueue(int e) {
        Node* nn = new Node(e);
        if (front == NULL) {
            front = nn;
            rear = nn;
        } else {
            rear->next = nn;
            rear = nn;
        }
        size++;
    }
    int dequeue() {
        if (front == NULL) {
            cout << "Queue Empty ";
            return -1;
        }
        int ans = front->data;
        Node* temp = front;
        front = front->next;
        delete temp;
        size--;
        return ans;
    }
    int getFront() {
        if (front == NULL) {
            cout << "Queue Empty";
            return -1;
        }
        return front->data;
    }
};