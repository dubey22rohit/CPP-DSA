class StackUsingLLTwo {
    Node* head;
    int size;

   public:
    StackUsingLLTwo() {
        head = NULL;
        size = 0;
    }
    int getSize() { return size; }
    bool isEmpty() { return (size == 0); }
    void push(int e) {
        Node* nn = new Node(e);
        if (head == NULL) {
            head = nn;
        } else {
            nn->next = head;
            head = nn;
        }
        size++;
    }
    int pop() {
        if (head == NULL) {
            return -1;
        }
        int ans = head->data;
        Node* t = head;
        head = head->next;
        delete t;
        size--;
        return ans;
    }
    Node* getHead(){
        return head;
    }
    int top(){
        if(head == NULL){
            return -1;
        }
        return head->data;
    }
};