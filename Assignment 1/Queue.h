// Queue class definition
class Queue {
private:
    Node* front; // Points to the front node of the queue
    Node* rear;  // Points to the rear node of the queue

public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Enqueue a character onto the queue
    void enqueue(char ch) {
        Node* newNode = new Node(ch);
