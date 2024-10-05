// Queue class definition
#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"
#include <iostream>

class Queue {
private:
    Node* front; // Points to the front node of the queue
    Node* rear;  // Points to the rear node of the queue

public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Enqueue a character onto the queue
    void enqueue(char ch) {
        Node* newNode = new Node(ch);
        if (rear == nullptr) {
            front = rear = newNode; // If the queue is empty, both front and rear point to the new node
        } else {
            rear->next = newNode; // Link the new node at the end of the queue
            rear = newNode;       // Update the rear to the new node
        }
    }

    // Dequeue a character from the queue
    char dequeue() {
        if (front == nullptr) {
            std::cerr << "Queue underflow\n";
            return '\0';
        }
        char ch = front->data;
        Node* temp = front;
        front = front->next; // Move front to the next node
        if (front == nullptr) {
            rear = nullptr; // If the queue is now empty, rear should also be null
        }
        delete temp;
        return ch;
    }

    // Check if the queue is empty
    bool isEmpty() const {
        return front == nullptr;
    }
};
#endif
