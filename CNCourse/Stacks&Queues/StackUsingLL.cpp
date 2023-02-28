// #include "Node.cpp"
class StackUsingLL {
    Node *head;
    int size;
    Node *ni;

   public:
    StackUsingLL() {
        head = NULL;
        size = 0;
        ni = NULL;
    }

    Node *getHead() { return head; }

    int getSize() { return size; }

    bool isEmpty() { return (size == 0); }

    int top() {
        if (size == 0) {
            return -1;
        }
        return ni->data;
    }

    void push(int e) {
        Node *nn = new Node(e);
        if (head == NULL) {
            head = nn;
            ni = nn;
        } else {
            ni->next = nn;
            ni = nn;
        }
        size++;
    }

    int pop() {
        if (size == 0 || head == NULL) {
            cout << "Stack Empty" << endl;
            return -1;
        }
        Node *t = head;
        while (t != NULL) {
            if (t->next->next == NULL) {
                break;
            }
        }
        int data = t->next->data;
        t->next = NULL;
        return data;
    }
};