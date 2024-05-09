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
    Node *head = nullptr, *tail = nullptr;
    int data;
    std::cin >> data;
    while (data != -1) {
        Node* nn = new Node(data);
        if (head == nullptr) {
            head = nn;
            tail = head;
        } else {
            tail->next = nn;
            tail = nn;
        }
        std::cin >> data;
    }
    return head;
}

void printList(Node* head) {
    Node* t = head;
    while (t != nullptr) {
        std::cout << t->data << " ";
        t = t->next;
    }
    std::cout << std::endl;
}