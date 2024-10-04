// Stack class definition
class Stack {
private:
    Node* top; // Points to the top node of the stack

public:
    Stack() : top(nullptr) {}

    // Push a character onto the stack
    void push(char ch) {
        Node* newNode = new Node(ch);
        newNode->next = top; // New node points to the current top
        top = newNode;       // Top now points to the new node
    }

    // Pop a character from the stack
    char pop() {
        if (top == nullptr) {
            // not sure how to handle underflow here
        }
        char ch = top->data;
        Node* temp = top;
        top = top->next; // Move the top to the next node
        delete temp;
        return ch;
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return top == nullptr;
    }
};
