class Node {
   public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
    ~Node() { delete next; }
};

Node* createList() {
    int data;
    Node *head = nullptr, *tail = nullptr, *nn = nullptr;
    while (data != -1) {
        std::cin >> data;
        nn = new Node(data);
        if (head == nullptr) {
            head = nn;
            tail = nn;
        } else {
            tail->next = nn;
            tail = nn;
        }
    }
    return head;
}

void printList(Node* head) {
    Node* t = head;
    while (t->next != nullptr) {
        std::cout << t->data << " ";
        t = t->next;
    }
    std::cout << std::endl;
}